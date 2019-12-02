/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated May 1, 2019. Replaces all prior versions.
 *
 * Copyright (c) 2013-2019, Esoteric Software LLC
 *
 * Integration of the Spine Runtimes into software or otherwise creating
 * derivative works of the Spine Runtimes is permitted under the terms and
 * conditions of Section 2 of the Spine Editor License Agreement:
 * http://esotericsoftware.com/spine-editor-license
 *
 * Otherwise, it is permitted to integrate the Spine Runtimes into software
 * or otherwise create derivative works of the Spine Runtimes (collectively,
 * "Products"), provided that each user of the Products must obtain their own
 * Spine Editor license and redistribution of the Products in any form must
 * include this license and copyright notice.
 *
 * THIS SOFTWARE IS PROVIDED BY ESOTERIC SOFTWARE LLC "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN
 * NO EVENT SHALL ESOTERIC SOFTWARE LLC BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, BUSINESS
 * INTERRUPTION, OR LOSS OF USE, DATA, OR PROFITS) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#include "spine/spine-cocos2dx.h"
#include "spine/SkeletonRenderer.h"
#include "spine/Extension.h"
#include "spine/SkeletonBatch.h"
#include "spine/SkeletonTwoColorBatch.h"
#include "spine/AttachmentVertices.h"
#include <algorithm>

#include "renderer/backend/Types.h"

#define INITIAL_WORLD_VERTICES_LENGTH 1000
// Used for transforming attachments for bounding boxes & debug rendering
static float* worldVertices = nullptr;
static size_t worldVerticesLength = 0;

void ensureWorldVerticesCapacity(size_t capacity) {
	if (worldVerticesLength < capacity) {
		float* newWorldVertices = new float[capacity];
		memcpy(newWorldVertices, worldVertices, capacity * sizeof(float));
		delete[] worldVertices;
		worldVertices = newWorldVertices;
		worldVerticesLength = capacity;
	}
}

USING_NS_CC;
using std::min;
using std::max;

namespace spine {

	namespace {
		Cocos2dTextureLoader textureLoader;

		int computeTotalCoordCount(Skeleton& skeleton, int startSlotIndex, int endSlotIndex);
		cocos2d::Rect computeBoundingRect(const float* coords, int vertexCount);
		void interleaveCoordinates(float* dst, const float* src, int vertexCount, int dstStride);
		BlendFunc makeBlendFunc(int blendMode, bool premultipliedAlpha);
		void transformWorldVertices(float* dstCoord, int coordCount, Skeleton& skeleton, int startSlotIndex, int endSlotIndex);
		bool cullRectangle(Renderer* renderer, const Mat4& transform, const cocos2d::Rect& rect);
			Color4B ColorToColor4B(const Color& color);
		bool slotIsOutRange(Slot& slot, int startSlotIndex, int endSlotIndex);
	}

// C Variable length array
#ifdef _MSC_VER
	// VLA not supported, use _malloca
	#define VLA(type, arr, count) \
		type* arr = static_cast<type*>( _malloca(sizeof(type) * count) )
	#define VLA_FREE(arr) do { _freea(arr); } while(false)
#else
	#define VLA(type, arr, count) \
		type arr[count]
   #define VLA_FREE(arr)
#endif

    void SkeletonRenderer::destroyScratchBuffers() {
        if (worldVertices) {
            delete[] worldVertices;
            worldVertices = nullptr;
            worldVerticesLength = 0;
        }
    }

	SkeletonRenderer* SkeletonRenderer::createWithSkeleton(Skeleton* skeleton, bool ownsSkeleton, bool ownsSkeletonData) {
		SkeletonRenderer* node = new SkeletonRenderer(skeleton, ownsSkeleton, ownsSkeletonData);
		node->autorelease();
		return node;
	}

	SkeletonRenderer* SkeletonRenderer::createWithData (SkeletonData* skeletonData, bool ownsSkeletonData) {
		SkeletonRenderer* node = new SkeletonRenderer(skeletonData, ownsSkeletonData);
		node->autorelease();
		return node;
	}

	SkeletonRenderer* SkeletonRenderer::createWithFile (const std::string& skeletonDataFile, Atlas* atlas, float scale) {
		SkeletonRenderer* node = new SkeletonRenderer(skeletonDataFile, atlas, scale);
		node->autorelease();
		return node;
	}

	SkeletonRenderer* SkeletonRenderer::createWithFile (const std::string& skeletonDataFile, const std::string& atlasFile, float scale) {
		SkeletonRenderer* node = new SkeletonRenderer(skeletonDataFile, atlasFile, scale);
		node->autorelease();
		return node;
	}

	void SkeletonRenderer::initialize () {
		if (!worldVertices) {
			worldVertices = new float[INITIAL_WORLD_VERTICES_LENGTH];
			worldVerticesLength = INITIAL_WORLD_VERTICES_LENGTH;
		}
		
		_clipper = new (__FILE__, __LINE__) SkeletonClipping();

		_blendFunc = BlendFunc::ALPHA_PREMULTIPLIED;
		setOpacityModifyRGB(true);

		setupGLProgramState(false);

		_skeleton->setToSetupPose();
		_skeleton->updateWorldTransform();
	}

	void SkeletonRenderer::setupGLProgramState (bool twoColorTintEnabled) {

        _twoColorTintEnabled = twoColorTintEnabled;
		if (twoColorTintEnabled) {
			return;
		}
		
		Texture2D *texture = nullptr;
		for (int i = 0, n = (int)_skeleton->getSlots().size(); i < n; i++) {
			Slot* slot = _skeleton->getDrawOrder()[i];
			if (!slot->getAttachment()) continue;
			if (slot->getAttachment()->getRTTI().isExactly(RegionAttachment::rtti)) {
				RegionAttachment* attachment = (RegionAttachment*)slot->getAttachment();
				texture = static_cast<AttachmentVertices*>(attachment->getRendererObject())->_texture;
			} else if (slot->getAttachment()->getRTTI().isExactly(RegionAttachment::rtti)) {
				MeshAttachment* attachment = (MeshAttachment*)slot->getAttachment();
				texture = static_cast<AttachmentVertices*>(attachment->getRendererObject())->_texture;
			} else {
				continue;
			}
			
			if (texture != nullptr) {
				break;
			}
		}
		//setGLProgramState(GLProgramState::getOrCreateWithGLProgramName(GLProgram::SHADER_NAME_POSITION_TEXTURE_COLOR_NO_MVP, texture));
	}

	void SkeletonRenderer::setSkeletonData (SkeletonData *skeletonData, bool ownsSkeletonData) {
		_skeleton = new (__FILE__, __LINE__) Skeleton(skeletonData);
		_ownsSkeletonData = ownsSkeletonData;
	}

	SkeletonRenderer::SkeletonRenderer ()
		: _atlas(nullptr), _attachmentLoader(nullptr), _debugSlots(false), _debugBones(false), _debugMeshes(false), _debugBoundingRect(false), _timeScale(1), _effect(nullptr), _startSlotIndex(0), _endSlotIndex(std::numeric_limits<int>::max()) {
	}

	SkeletonRenderer::SkeletonRenderer(Skeleton* skeleton, bool ownsSkeleton, bool ownsSkeletonData, bool ownsAtlas)
		: _atlas(nullptr), _attachmentLoader(nullptr), _debugSlots(false), _debugBones(false), _debugMeshes(false), _debugBoundingRect(false), _timeScale(1), _effect(nullptr), _startSlotIndex(0), _endSlotIndex(std::numeric_limits<int>::max()) {
		initWithSkeleton(skeleton, ownsSkeleton, ownsSkeletonData, ownsAtlas);
	}

	SkeletonRenderer::SkeletonRenderer (SkeletonData *skeletonData, bool ownsSkeletonData)
		: _atlas(nullptr), _attachmentLoader(nullptr), _debugSlots(false), _debugBones(false), _debugMeshes(false), _debugBoundingRect(false), _timeScale(1), _effect(nullptr), _startSlotIndex(0), _endSlotIndex(std::numeric_limits<int>::max()) {
		initWithData(skeletonData, ownsSkeletonData);
	}

	SkeletonRenderer::SkeletonRenderer (const std::string& skeletonDataFile, Atlas* atlas, float scale)
		: _atlas(nullptr), _attachmentLoader(nullptr), _debugSlots(false), _debugBones(false), _debugMeshes(false), _debugBoundingRect(false), _timeScale(1), _effect(nullptr), _startSlotIndex(0), _endSlotIndex(std::numeric_limits<int>::max()) {
		initWithJsonFile(skeletonDataFile, atlas, scale);
	}

	SkeletonRenderer::SkeletonRenderer (const std::string& skeletonDataFile, const std::string& atlasFile, float scale)
		: _atlas(nullptr), _attachmentLoader(nullptr), _debugSlots(false), _debugBones(false), _debugMeshes(false), _debugBoundingRect(false), _timeScale(1), _effect(nullptr), _startSlotIndex(0), _endSlotIndex(std::numeric_limits<int>::max()) {
		initWithJsonFile(skeletonDataFile, atlasFile, scale);
	}

	SkeletonRenderer::~SkeletonRenderer () {
		if (_ownsSkeletonData) delete _skeleton->getData();
		if (_ownsSkeleton) delete _skeleton;
		if (_ownsAtlas) delete _atlas;
		delete _attachmentLoader;
		delete _clipper;
	}

	void SkeletonRenderer::initWithSkeleton(Skeleton* skeleton, bool ownsSkeleton, bool ownsSkeletonData, bool ownsAtlas) {
		_skeleton = skeleton;
		_ownsSkeleton = ownsSkeleton;
		_ownsSkeletonData = ownsSkeletonData;
		_ownsAtlas = ownsAtlas;
		initialize();
	}

	void SkeletonRenderer::initWithData (SkeletonData* skeletonData, bool ownsSkeletonData) {
		_ownsSkeleton = true;
		setSkeletonData(skeletonData, ownsSkeletonData);
		initialize();
	}

	void SkeletonRenderer::initWithJsonFile (const std::string& skeletonDataFile, Atlas* atlas, float scale) {
		_atlas = atlas;
		_attachmentLoader = new (__FILE__, __LINE__) Cocos2dAtlasAttachmentLoader(_atlas);

		SkeletonJson json(_attachmentLoader);
		json.setScale(scale);
		SkeletonData* skeletonData = json.readSkeletonDataFile(skeletonDataFile.c_str());
		CCASSERT(skeletonData, !json.getError().isEmpty() ? json.getError().buffer() : "Error reading skeleton data.");

		_ownsSkeleton = true;
		setSkeletonData(skeletonData, true);

		initialize();
	}

	void SkeletonRenderer::initWithJsonFile (const std::string& skeletonDataFile, const std::string& atlasFile, float scale) {
		_atlas = new (__FILE__, __LINE__) Atlas(atlasFile.c_str(), &textureLoader, true);
		CCASSERT(_atlas, "Error reading atlas file.");

		_attachmentLoader = new (__FILE__, __LINE__) Cocos2dAtlasAttachmentLoader(_atlas);

		SkeletonJson json(_attachmentLoader);
		json.setScale(scale);
		SkeletonData* skeletonData = json.readSkeletonDataFile(skeletonDataFile.c_str());
		CCASSERT(skeletonData, !json.getError().isEmpty() ? json.getError().buffer() : "Error reading skeleton data.");

		_ownsSkeleton = true;
		_ownsAtlas = true;
		setSkeletonData(skeletonData, true);

		initialize();
	}

	void SkeletonRenderer::initWithBinaryFile (const std::string& skeletonDataFile, Atlas* atlas, float scale) {
		_atlas = atlas;
		_attachmentLoader = new (__FILE__, __LINE__) Cocos2dAtlasAttachmentLoader(_atlas);

		SkeletonBinary binary(_attachmentLoader);
		binary.setScale(scale);
		SkeletonData* skeletonData = binary.readSkeletonDataFile(skeletonDataFile.c_str());
		CCASSERT(skeletonData, !binary.getError().isEmpty() ? binary.getError().buffer() : "Error reading skeleton data.");
		_ownsSkeleton = true;
		setSkeletonData(skeletonData, true);

		initialize();
	}

	void SkeletonRenderer::initWithBinaryFile (const std::string& skeletonDataFile, const std::string& atlasFile, float scale) {
		_atlas = new (__FILE__, __LINE__) Atlas(atlasFile.c_str(), &textureLoader, true);
		CCASSERT(_atlas, "Error reading atlas file.");

		_attachmentLoader = new (__FILE__, __LINE__) Cocos2dAtlasAttachmentLoader(_atlas);

		SkeletonBinary binary(_attachmentLoader);
		binary.setScale(scale);
		SkeletonData* skeletonData = binary.readSkeletonDataFile(skeletonDataFile.c_str());
		CCASSERT(skeletonData, !binary.getError().isEmpty() ? binary.getError().buffer() : "Error reading skeleton data.");
		_ownsSkeleton = true;
		_ownsAtlas = true;
		setSkeletonData(skeletonData, true);

		initialize();
	}


	void SkeletonRenderer::update (float deltaTime) {
		Node::update(deltaTime);
		if (_ownsSkeleton) _skeleton->update(deltaTime * _timeScale);
	}

	void SkeletonRenderer::draw (Renderer* renderer, const Mat4& transform, uint32_t transformFlags) {
		SkeletonBatch* batch = SkeletonBatch::getInstance();
		SkeletonTwoColorBatch* twoColorBatch = SkeletonTwoColorBatch::getInstance();
		bool isTwoColorTint = this->isTwoColorTint();
		
		// Early exit if the skeleton is invisible
		if (getDisplayedOpacity() == 0 || _skeleton->getColor().a == 0){
			return;
		}
		
		if (_effect) {
			_effect->begin(*_skeleton);
		}
		
		const Color3B displayedColor = getDisplayedColor();
		Color nodeColor;
		nodeColor.r = displayedColor.r / 255.f;
		nodeColor.g = displayedColor.g / 255.f;
		nodeColor.b = displayedColor.b / 255.f;
		nodeColor.a = getDisplayedOpacity() / 255.f;
		
		Color4F color;
		Color4F darkColor;
		float darkPremultipliedAlpha = _premultipliedAlpha ? 255 : 0;
		AttachmentVertices* attachmentVertices = nullptr;
		TwoColorTrianglesCommand* lastTwoColorTrianglesCommand = nullptr;
		for (int i = 0, n = _skeleton->getSlots().size(); i < n; ++i) {
			Slot* slot = _skeleton->getDrawOrder()[i];

			if (slotIsOutRange(*slot, _startSlotIndex, _endSlotIndex)) {
				_clipper->clipEnd(*slot);
				continue;
			}

			if (!slot->getAttachment()) {
				_clipper->clipEnd(*slot);
				continue;
			}

			// Early exit if slot is invisible
			if (slot->getColor().a == 0 || !slot->getBone().isActive()) {
				_clipper->clipEnd(*slot);
				continue;
			}

			cocos2d::TrianglesCommand::Triangles triangles;
			TwoColorTriangles trianglesTwoColor;

			if (slot->getAttachment()->getRTTI().isExactly(RegionAttachment::rtti)) {
				RegionAttachment* attachment = static_cast<RegionAttachment*>(slot->getAttachment());
				attachmentVertices = static_cast<AttachmentVertices*>(attachment->getRendererObject());

				// Early exit if attachment is invisible
				if (attachment->getColor().a == 0) {
					_clipper->clipEnd(*slot);
					continue;
				}
				
				if (!isTwoColorTint) {
					triangles.indices = attachmentVertices->_triangles->indices;
					triangles.indexCount = attachmentVertices->_triangles->indexCount;
					triangles.verts = batch->allocateVertices(attachmentVertices->_triangles->vertCount);
					triangles.vertCount = attachmentVertices->_triangles->vertCount;
					memcpy(triangles.verts, attachmentVertices->_triangles->verts, sizeof(cocos2d::V3F_C4B_T2F) * attachmentVertices->_triangles->vertCount);
					attachment->computeWorldVertices(slot->getBone(), (float*)triangles.verts, 0, 6);
				} else {
					trianglesTwoColor.indices = attachmentVertices->_triangles->indices;
					trianglesTwoColor.indexCount = attachmentVertices->_triangles->indexCount;
					trianglesTwoColor.verts = twoColorBatch->allocateVertices(attachmentVertices->_triangles->vertCount);
					trianglesTwoColor.vertCount = attachmentVertices->_triangles->vertCount;
					for (int i = 0; i < trianglesTwoColor.vertCount; i++) {
						trianglesTwoColor.verts[i].texCoords = attachmentVertices->_triangles->verts[i].texCoords;
					}
					attachment->computeWorldVertices(slot->getBone(), (float*)trianglesTwoColor.verts, 0, 7);
				}
				
				color.r = attachment->getColor().r;
				color.g = attachment->getColor().g;
				color.b = attachment->getColor().b;
				color.a = attachment->getColor().a;
			}
			else if (slot->getAttachment()->getRTTI().isExactly(MeshAttachment::rtti)) {
				MeshAttachment* attachment = (MeshAttachment*)slot->getAttachment();
				attachmentVertices = (AttachmentVertices*)attachment->getRendererObject();
				
				// Early exit if attachment is invisible
				if (attachment->getColor().a == 0) {
					_clipper->clipEnd(*slot);
					continue;
				}
				
				if (!isTwoColorTint) {
					triangles.indices = attachmentVertices->_triangles->indices;
					triangles.indexCount = attachmentVertices->_triangles->indexCount;
					triangles.verts = batch->allocateVertices(attachmentVertices->_triangles->vertCount);
					triangles.vertCount = attachmentVertices->_triangles->vertCount;
					memcpy(triangles.verts, attachmentVertices->_triangles->verts, sizeof(cocos2d::V3F_C4B_T2F) * attachmentVertices->_triangles->vertCount);
					attachment->computeWorldVertices(*slot, 0, attachment->getWorldVerticesLength(), (float*)triangles.verts, 0, 6);
				} else {
					trianglesTwoColor.indices = attachmentVertices->_triangles->indices;
					trianglesTwoColor.indexCount = attachmentVertices->_triangles->indexCount;
					trianglesTwoColor.verts = twoColorBatch->allocateVertices(attachmentVertices->_triangles->vertCount);
					trianglesTwoColor.vertCount = attachmentVertices->_triangles->vertCount;
					for (int i = 0; i < trianglesTwoColor.vertCount; i++) {
						trianglesTwoColor.verts[i].texCoords = attachmentVertices->_triangles->verts[i].texCoords;
					}
					attachment->computeWorldVertices(*slot, 0,  attachment->getWorldVerticesLength(), (float*)trianglesTwoColor.verts, 0, 7);
				}
				
				color.r = attachment->getColor().r;
				color.g = attachment->getColor().g;
				color.b = attachment->getColor().b;
				color.a = attachment->getColor().a;
			}
			else if (slot->getAttachment()->getRTTI().isExactly(ClippingAttachment::rtti)) {
				ClippingAttachment* clip = (ClippingAttachment*)slot->getAttachment();
				_clipper->clipStart(*slot, clip);
				continue;
			} else {
				_clipper->clipEnd(*slot);
				continue;
			}
			
			float alpha = nodeColor.a * _skeleton->getColor().a * slot->getColor().a * color.a * 255;
			// skip rendering if the color of this attachment is 0
			if (alpha == 0){
				_clipper->clipEnd(*slot);
				continue;
			}
			float multiplier = _premultipliedAlpha ? alpha : 255;
			float red = nodeColor.r * _skeleton->getColor().r * color.r * multiplier;
			float green = nodeColor.g * _skeleton->getColor().g * color.g * multiplier;
			float blue = nodeColor.b * _skeleton->getColor().b * color.b * multiplier;
			
			color.r = red * slot->getColor().r;
			color.g = green * slot->getColor().g;
			color.b = blue * slot->getColor().b;
			color.a = alpha;
			
			if (slot->hasDarkColor()) {
				darkColor.r = red * slot->getDarkColor().r;
				darkColor.g = green * slot->getDarkColor().g;
				darkColor.b = blue * slot->getDarkColor().b;
			} else {
				darkColor.r = 0;
				darkColor.g = 0;
				darkColor.b = 0;
			}
			darkColor.a = darkPremultipliedAlpha;
			
			BlendFunc blendFunc;
			switch (slot->getData().getBlendMode()) {
				case BlendMode_Additive:
					blendFunc.src = _premultipliedAlpha ? backend::BlendFactor::ONE : backend::BlendFactor::SRC_ALPHA;
					blendFunc.dst = backend::BlendFactor::ONE;
					break;
				case BlendMode_Multiply:
					blendFunc.src = backend::BlendFactor::DST_COLOR;
					blendFunc.dst = backend::BlendFactor::ONE_MINUS_SRC_ALPHA;
					break;
				case BlendMode_Screen:
					blendFunc.src = backend::BlendFactor::ONE;
					blendFunc.dst = backend::BlendFactor::ONE_MINUS_SRC_COLOR;
					break;
				default:
					blendFunc.src = _premultipliedAlpha ? backend::BlendFactor::ONE : backend::BlendFactor::SRC_ALPHA;
					blendFunc.dst = backend::BlendFactor::ONE_MINUS_SRC_ALPHA;
			}
			
			if (!isTwoColorTint) {
				if (_clipper->isClipping()) {
					_clipper->clipTriangles((float*)&triangles.verts[0].vertices, triangles.indices, triangles.indexCount, (float*)&triangles.verts[0].texCoords, sizeof(cocos2d::V3F_C4B_T2F) / 4);
					batch->deallocateVertices(triangles.vertCount);
					
					if (_clipper->getClippedTriangles().size() == 0){
						_clipper->clipEnd(*slot);
						continue;
					}
					
					triangles.vertCount = _clipper->getClippedVertices().size() >> 1;
					triangles.verts = batch->allocateVertices(triangles.vertCount);
					triangles.indexCount = _clipper->getClippedTriangles().size();
					triangles.indices = batch->allocateIndices(triangles.indexCount);
					memcpy(triangles.indices, _clipper->getClippedTriangles().buffer(), sizeof(unsigned short) * _clipper->getClippedTriangles().size());
					
					cocos2d::TrianglesCommand* batchedTriangles = batch->addCommand(renderer, _globalZOrder, attachmentVertices->_texture, blendFunc, triangles, transform, transformFlags);
					
					float* verts = _clipper->getClippedVertices().buffer();
					float* uvs = _clipper->getClippedUVs().buffer();
					if (_effect) {
						Color light;
						Color dark;
						light.r = color.r / 255.0f;
						light.g = color.g / 255.0f;
						light.b = color.b / 255.0f;
						light.a = color.a / 255.0f;
						dark.r = dark.g = dark.b = dark.a = 0;
						for (int v = 0, vn = batchedTriangles->getTriangles().vertCount, vv = 0; v < vn; ++v, vv+=2) {
							V3F_C4B_T2F* vertex = batchedTriangles->getTriangles().verts + v;
							Color lightCopy = light;
							Color darkCopy = dark;
							vertex->vertices.x = verts[vv];
							vertex->vertices.y = verts[vv + 1];
							vertex->texCoords.u = uvs[vv];
							vertex->texCoords.v = uvs[vv + 1];
							_effect->transform(vertex->vertices.x, vertex->vertices.y, vertex->texCoords.u, vertex->texCoords.v, lightCopy, darkCopy);
							vertex->colors.r = (uint8_t)(lightCopy.r * 255);
							vertex->colors.g = (uint8_t)(lightCopy.g * 255);
							vertex->colors.b = (uint8_t)(lightCopy.b * 255);
							vertex->colors.a = (uint8_t)(lightCopy.a * 255);
						}
					} else {
						for (int v = 0, vn = batchedTriangles->getTriangles().vertCount, vv = 0; v < vn; ++v, vv+=2) {
							V3F_C4B_T2F* vertex = batchedTriangles->getTriangles().verts + v;
							vertex->vertices.x = verts[vv];
							vertex->vertices.y = verts[vv + 1];
							vertex->texCoords.u = uvs[vv];
							vertex->texCoords.v = uvs[vv + 1];
							vertex->colors.r = (uint8_t)color.r;
							vertex->colors.g = (uint8_t)color.g;
							vertex->colors.b = (uint8_t)color.b;
							vertex->colors.a = (uint8_t)color.a;
						}
					}
				} else {
					cocos2d::TrianglesCommand* batchedTriangles = batch->addCommand(renderer, _globalZOrder, attachmentVertices->_texture, blendFunc, triangles, transform, transformFlags);
					
					if (_effect) {
						Color light;
						Color dark;
						light.r = color.r / 255.0f;
						light.g = color.g / 255.0f;
						light.b = color.b / 255.0f;
						light.a = color.a / 255.0f;
						dark.r = dark.g = dark.b = dark.a = 0;
						for (int v = 0, vn = batchedTriangles->getTriangles().vertCount; v < vn; ++v) {
							V3F_C4B_T2F* vertex = batchedTriangles->getTriangles().verts + v;
							Color lightCopy = light;
							Color darkCopy = dark;
							_effect->transform(vertex->vertices.x, vertex->vertices.y, vertex->texCoords.u, vertex->texCoords.v, lightCopy,  darkCopy);
							vertex->colors.r = (uint8_t)(lightCopy.r * 255);
							vertex->colors.g = (uint8_t)(lightCopy.g * 255);
							vertex->colors.b = (uint8_t)(lightCopy.b * 255);
							vertex->colors.a = (uint8_t)(lightCopy.a * 255);
						}
					} else {
						for (int v = 0, vn = batchedTriangles->getTriangles().vertCount; v < vn; ++v) {
							V3F_C4B_T2F* vertex = batchedTriangles->getTriangles().verts + v;
							vertex->colors.r = (uint8_t)color.r;
							vertex->colors.g = (uint8_t)color.g;
							vertex->colors.b = (uint8_t)color.b;
							vertex->colors.a = (uint8_t)color.a;
						}
					}
				}
			} else {
				// Two tints

				if (_clipper->isClipping()) {
					_clipper->clipTriangles((float*)&trianglesTwoColor.verts[0].position, trianglesTwoColor.indices, trianglesTwoColor.indexCount, (float*)&trianglesTwoColor.verts[0].texCoords, sizeof(V3F_C4B_C4B_T2F) / 4);
					twoColorBatch->deallocateVertices(trianglesTwoColor.vertCount);
					
					if (_clipper->getClippedTriangles().size() == 0){
						_clipper->clipEnd(*slot);
						continue;
					}
					
					trianglesTwoColor.vertCount = _clipper->getClippedVertices().size() >> 1;
					trianglesTwoColor.verts = twoColorBatch->allocateVertices(trianglesTwoColor.vertCount);
					trianglesTwoColor.indexCount = _clipper->getClippedTriangles().size();
					trianglesTwoColor.indices = twoColorBatch->allocateIndices(trianglesTwoColor.indexCount);
					memcpy(trianglesTwoColor.indices, _clipper->getClippedTriangles().buffer(), sizeof(unsigned short) * _clipper->getClippedTriangles().size());
					
					TwoColorTrianglesCommand* batchedTriangles = lastTwoColorTrianglesCommand = twoColorBatch->addCommand(renderer, _globalZOrder, attachmentVertices->_texture, blendFunc, trianglesTwoColor, transform, transformFlags);
					
					float* verts = _clipper->getClippedVertices().buffer();
					float* uvs = _clipper->getClippedUVs().buffer();
					
					if (_effect) {
						Color light;
						Color dark;
						light.r = color.r / 255.0f;
						light.g = color.g / 255.0f;
						light.b = color.b / 255.0f;
						light.a = color.a / 255.0f;
						dark.r = darkColor.r / 255.0f;
						dark.g = darkColor.g / 255.0f;
						dark.b = darkColor.b / 255.0f;
						dark.a = darkColor.a / 255.0f;
						for (int v = 0, vn = batchedTriangles->getTriangles().vertCount, vv = 0; v < vn; ++v, vv += 2) {
							V3F_C4B_C4B_T2F* vertex = batchedTriangles->getTriangles().verts + v;
							Color lightCopy = light;
							Color darkCopy = dark;
							vertex->position.x = verts[vv];
							vertex->position.y = verts[vv + 1];
							vertex->texCoords.u = uvs[vv];
							vertex->texCoords.v = uvs[vv + 1];
							_effect->transform(vertex->position.x, vertex->position.y, vertex->texCoords.u, vertex->texCoords.v, lightCopy, darkCopy);
							vertex->color.r = (uint8_t)(lightCopy.r * 255);
							vertex->color.g = (uint8_t)(lightCopy.g * 255);
							vertex->color.b = (uint8_t)(lightCopy.b * 255);
							vertex->color.a = (uint8_t)(lightCopy.a * 255);
							vertex->color2.r = (uint8_t)(darkCopy.r * 255);
							vertex->color2.g = (uint8_t)(darkCopy.g * 255);
							vertex->color2.b = (uint8_t)(darkCopy.b * 255);
							vertex->color2.a = (uint8_t)darkColor.a;
						}
					} else {
						for (int v = 0, vn = batchedTriangles->getTriangles().vertCount, vv = 0; v < vn; ++v, vv += 2) {
							V3F_C4B_C4B_T2F* vertex = batchedTriangles->getTriangles().verts + v;
							vertex->position.x = verts[vv];
							vertex->position.y = verts[vv + 1];
							vertex->texCoords.u = uvs[vv];
							vertex->texCoords.v = uvs[vv + 1];
							vertex->color.r = (uint8_t)color.r;
							vertex->color.g = (uint8_t)color.g;
							vertex->color.b = (uint8_t)color.b;
							vertex->color.a = (uint8_t)color.a;
							vertex->color2.r = (uint8_t)darkColor.r;
							vertex->color2.g = (uint8_t)darkColor.g;
							vertex->color2.b = (uint8_t)darkColor.b;
							vertex->color2.a = (uint8_t)darkColor.a;
						}
					}
				} else {
					TwoColorTrianglesCommand* batchedTriangles = lastTwoColorTrianglesCommand = twoColorBatch->addCommand(renderer, _globalZOrder, attachmentVertices->_texture, blendFunc, trianglesTwoColor, transform, transformFlags);
					
					if (_effect) {
						Color light;
						Color dark;
						light.r = color.r / 255.0f;
						light.g = color.g / 255.0f;
						light.b = color.b / 255.0f;
						light.a = color.a / 255.0f;
						dark.r = darkColor.r / 255.0f;
						dark.g = darkColor.g / 255.0f;
						dark.b = darkColor.b / 255.0f;
						dark.a = darkColor.a / 255.0f;
						
						for (int v = 0, vn = batchedTriangles->getTriangles().vertCount; v < vn; ++v) {
							V3F_C4B_C4B_T2F* vertex = batchedTriangles->getTriangles().verts + v;
							Color lightCopy = light;
							Color darkCopy = dark;
							_effect->transform(vertex->position.x, vertex->position.y, vertex->texCoords.u, vertex->texCoords.v, lightCopy, darkCopy);
							vertex->color.r = (uint8_t)(lightCopy.r * 255);
							vertex->color.g = (uint8_t)(lightCopy.g * 255);
							vertex->color.b = (uint8_t)(lightCopy.b * 255);
							vertex->color.a = (uint8_t)(lightCopy.a * 255);
							vertex->color2.r = (uint8_t)(darkCopy.r * 255);
							vertex->color2.g = (uint8_t)(darkCopy.g * 255);
							vertex->color2.b = (uint8_t)(darkCopy.b * 255);
							vertex->color2.a = (uint8_t)darkColor.a;
						}
					} else {
						for (int v = 0, vn = batchedTriangles->getTriangles().vertCount; v < vn; ++v) {
							V3F_C4B_C4B_T2F* vertex = batchedTriangles->getTriangles().verts + v;
							vertex->color.r = (uint8_t)color.r;
							vertex->color.g = (uint8_t)color.g;
							vertex->color.b = (uint8_t)color.b;
							vertex->color.a = (uint8_t)color.a;
							vertex->color2.r = (uint8_t)darkColor.r;
							vertex->color2.g = (uint8_t)darkColor.g;
							vertex->color2.b = (uint8_t)darkColor.b;
							vertex->color2.a = (uint8_t)darkColor.a;
						}
					}
				}
			}
		_clipper->clipEnd(*slot);
		}
		_clipper->clipEnd();

		if (lastTwoColorTrianglesCommand) {
			Node* parent = this->getParent();

			// We need to decide if we can postpone flushing the current
			// batch. We can postpone if the next sibling node is a
			// two color tinted skeleton with the same global-z.
			// The parent->getChildrenCount() > 100 check is a hack
			// as checking for a sibling is an O(n) operation, and if
			// all children of this nodes parent are skeletons, we
			// are in O(n2) territory.
			if (!parent || parent->getChildrenCount() > 100 || getChildrenCount() != 0) {
				lastTwoColorTrianglesCommand->setForceFlush(true);
			} else {
				const cocos2d::Vector<Node*>& children = parent->getChildren();
				Node* sibling = nullptr;
				for (ssize_t i = 0; i < children.size(); i++) {
					if (children.at(i) == this) {
						if (i < children.size() - 1) {
							sibling = children.at(i+1);
							break;
						}
					}
				}
				if (!sibling) {
					lastTwoColorTrianglesCommand->setForceFlush(true);
				} else {
					SkeletonRenderer* siblingSkeleton = dynamic_cast<SkeletonRenderer*>(sibling);
					if (!siblingSkeleton || // flush is next sibling isn't a SkeletonRenderer
						!siblingSkeleton->isTwoColorTint() || // flush if next sibling isn't two color tinted
						!siblingSkeleton->isVisible() || // flush if next sibling is two color tinted but not visible
						(siblingSkeleton->getGlobalZOrder() != this->getGlobalZOrder())) { // flush if next sibling is two color tinted but z-order differs
						lastTwoColorTrianglesCommand->setForceFlush(true);
					}
				}
			}
		}

		if (_effect) _effect->end();

		if (_debugBoundingRect || _debugSlots || _debugBones || _debugMeshes) {
			drawDebug(renderer, transform, transformFlags);
		}
	}


	void SkeletonRenderer::drawDebug (Renderer* renderer, const Mat4 &transform, uint32_t transformFlags) {

	 #if !defined(USE_MATRIX_STACK_PROJECTION_ONLY)
		Director* director = Director::getInstance();
		director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
		director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, transform);
	#endif

		DrawNode* drawNode = DrawNode::create();

		// Draw bounding rectangle
		if (_debugBoundingRect) {
			drawNode->setLineWidth(2.0f);
			const cocos2d::Rect brect = getBoundingBox();
			const Vec2 points[4] =
			{
				brect.origin,
				{ brect.origin.x + brect.size.width, brect.origin.y },
				{ brect.origin.x + brect.size.width, brect.origin.y + brect.size.height },
				{ brect.origin.x, brect.origin.y + brect.size.height }
			};
			drawNode->drawPoly(points, 4, true, Color4F::GREEN);
		}

		if (_debugSlots) {
			// Slots.
			// DrawPrimitives::setDrawColor4B(0, 0, 255, 255);
            drawNode->setLineWidth(1.0f);
			Vec2 points[4];
			V3F_C4B_T2F_Quad quad;
			for (int i = 0, n = _skeleton->getSlots().size(); i < n; i++) {
				Slot* slot = _skeleton->getDrawOrder()[i];

				if (!slot->getBone().isActive()) continue;
				if (!slot->getAttachment() || !slot->getAttachment()->getRTTI().isExactly(RegionAttachment::rtti)) continue;

				if (slotIsOutRange(*slot, _startSlotIndex, _endSlotIndex)) {
					continue;
				}

				RegionAttachment* attachment = (RegionAttachment*)slot->getAttachment();
				attachment->computeWorldVertices(slot->getBone(), worldVertices, 0, 2);
				points[0] = Vec2(worldVertices[0], worldVertices[1]);
				points[1] = Vec2(worldVertices[2], worldVertices[3]);
				points[2] = Vec2(worldVertices[4], worldVertices[5]);
				points[3] = Vec2(worldVertices[6], worldVertices[7]);
				drawNode->drawPoly(points, 4, true, Color4F::BLUE);
			}
		}

		if (_debugBones) {
			// Bone lengths.
            drawNode->setLineWidth(2.0f);
			for (int i = 0, n = _skeleton->getBones().size(); i < n; i++) {
				Bone *bone = _skeleton->getBones()[i];
				if (!bone->isActive()) continue;
				float x = bone->getData().getLength() * bone->getA() + bone->getWorldX();
				float y = bone->getData().getLength() * bone->getC() + bone->getWorldY();
				drawNode->drawLine(Vec2(bone->getWorldX(), bone->getWorldY()), Vec2(x, y), Color4F::RED);
			}
			// Bone origins.
			auto color = Color4F::BLUE; // Root bone is blue.
			for (int i = 0, n = _skeleton->getBones().size(); i < n; i++) {
				Bone *bone = _skeleton->getBones()[i];
				if (!bone->isActive()) continue;
				drawNode->drawPoint(Vec2(bone->getWorldX(), bone->getWorldY()), 4, color);
				if (i == 0) color = Color4F::GREEN;
			}
		}

		if (_debugMeshes) {
			// Meshes.
            drawNode->setLineWidth(1.0f);
			for (int i = 0, n = _skeleton->getSlots().size(); i < n; ++i) {
				Slot* slot = _skeleton->getDrawOrder()[i];
				if (!slot->getAttachment() || !slot->getAttachment()->getRTTI().isExactly(MeshAttachment::rtti)) continue;
				MeshAttachment* attachment = (MeshAttachment*)slot->getAttachment();
				ensureWorldVerticesCapacity(attachment->getWorldVerticesLength());
				attachment->computeWorldVertices(*slot, 0, attachment->getWorldVerticesLength(), worldVertices, 0, 2);
				for (int ii = 0; ii < attachment->getTriangles().size();) {
					Vec2 v1(worldVertices + (attachment->getTriangles()[ii++] * 2));
					Vec2 v2(worldVertices + (attachment->getTriangles()[ii++] * 2));
					Vec2 v3(worldVertices + (attachment->getTriangles()[ii++] * 2));
					drawNode->drawLine(v1, v2, Color4F::YELLOW);
					drawNode->drawLine(v2, v3, Color4F::YELLOW);
					drawNode->drawLine(v3, v1, Color4F::YELLOW);
				}
			}
			
		}

		drawNode->draw(renderer, transform, transformFlags);
	#if !defined(USE_MATRIX_STACK_PROJECTION_ONLY)
		director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
	#endif
	}

	cocos2d::Rect SkeletonRenderer::getBoundingBox () const {
		const int coordCount = computeTotalCoordCount(*_skeleton, _startSlotIndex, _endSlotIndex);
		if (coordCount == 0) return { 0, 0, 0, 0 };
		VLA(float, worldCoords, coordCount);
		transformWorldVertices(worldCoords, coordCount, *_skeleton, _startSlotIndex, _endSlotIndex);
		const cocos2d::Rect bb = computeBoundingRect(worldCoords, coordCount / 2);
		VLA_FREE(worldCoords);
		return bb;
	}

	// --- Convenience methods for Skeleton_* functions.

	void SkeletonRenderer::updateWorldTransform() {
		_skeleton->updateWorldTransform();
	}

	void SkeletonRenderer::setToSetupPose () {
		_skeleton->setToSetupPose();
	}
	void SkeletonRenderer::setBonesToSetupPose () {
		_skeleton->setBonesToSetupPose();
	}
	void SkeletonRenderer::setSlotsToSetupPose () {
		_skeleton->setSlotsToSetupPose();
	}

	Bone* SkeletonRenderer::findBone (const std::string& boneName) const {
		return _skeleton->findBone(boneName.c_str());
	}

	Slot* SkeletonRenderer::findSlot (const std::string& slotName) const {
		return _skeleton->findSlot( slotName.c_str());
	}

	void SkeletonRenderer::setSkin (const std::string& skinName) {
		_skeleton->setSkin(skinName.empty() ? 0 : skinName.c_str());
	}
	void SkeletonRenderer::setSkin (const char* skinName) {
		_skeleton->setSkin(skinName);
	}

	Attachment* SkeletonRenderer::getAttachment (const std::string& slotName, const std::string& attachmentName) const {
		return _skeleton->getAttachment(slotName.c_str(), attachmentName.c_str());
	}
	bool SkeletonRenderer::setAttachment (const std::string& slotName, const std::string& attachmentName) {
		return _skeleton->getAttachment(slotName.c_str(), attachmentName.empty() ? 0 : attachmentName.c_str()) ? true : false;
	}
	bool SkeletonRenderer::setAttachment (const std::string& slotName, const char* attachmentName) {
		return _skeleton->getAttachment(slotName.c_str(), attachmentName) ? true : false;
	}

	void SkeletonRenderer::setTwoColorTint(bool enabled) {
		setupGLProgramState(enabled);
	}

	bool SkeletonRenderer::isTwoColorTint() {
        return _twoColorTintEnabled;
	}

	void SkeletonRenderer::setVertexEffect(VertexEffect *effect) {
		this->_effect = effect;
	}

	void SkeletonRenderer::setSlotsRange(int startSlotIndex, int endSlotIndex) {
		_startSlotIndex = startSlotIndex == -1 ? 0 : startSlotIndex;
		_endSlotIndex = endSlotIndex == -1 ? std::numeric_limits<int>::max() : endSlotIndex;
	}

	Skeleton* SkeletonRenderer::getSkeleton () const {
		return _skeleton;
	}

	void SkeletonRenderer::setTimeScale (float scale) {
		_timeScale = scale;
	}
	float SkeletonRenderer::getTimeScale () const {
		return _timeScale;
	}

	void SkeletonRenderer::setDebugSlotsEnabled (bool enabled) {
		_debugSlots = enabled;
	}
	bool SkeletonRenderer::getDebugSlotsEnabled () const {
		return _debugSlots;
	}

	void SkeletonRenderer::setDebugBonesEnabled (bool enabled) {
		_debugBones = enabled;
	}
	bool SkeletonRenderer::getDebugBonesEnabled () const {
		return _debugBones;
	}

	void SkeletonRenderer::setDebugMeshesEnabled (bool enabled) {
		_debugMeshes = enabled;
	}
	bool SkeletonRenderer::getDebugMeshesEnabled () const {
		return _debugMeshes;
	}

	void SkeletonRenderer::setDebugBoundingRectEnabled(bool enabled) {
		_debugBoundingRect = enabled;
	}

	bool SkeletonRenderer::getDebugBoundingRectEnabled() const {
		return _debugBoundingRect;
	}

	void SkeletonRenderer::onEnter () {
	#if CC_ENABLE_SCRIPT_BINDING
		if (_scriptType == kScriptTypeJavascript && ScriptEngineManager::sendNodeEventToJSExtended(this, kNodeOnEnter)) return;
	#endif
		Node::onEnter();
		scheduleUpdate();
	}

	void SkeletonRenderer::onExit () {
	#if CC_ENABLE_SCRIPT_BINDING
		if (_scriptType == kScriptTypeJavascript && ScriptEngineManager::sendNodeEventToJSExtended(this, kNodeOnExit)) return;
	#endif
		Node::onExit();
		unscheduleUpdate();
	}

	// --- CCBlendProtocol

	const BlendFunc& SkeletonRenderer::getBlendFunc () const {
		return _blendFunc;
	}

	void SkeletonRenderer::setBlendFunc (const BlendFunc &blendFunc) {
		_blendFunc = blendFunc;
	}

	void SkeletonRenderer::setOpacityModifyRGB (bool value) {
		_premultipliedAlpha = value;
	}

	bool SkeletonRenderer::isOpacityModifyRGB () const {
		return _premultipliedAlpha;
	}

	namespace {
		cocos2d::Rect computeBoundingRect(const float* coords, int vertexCount) {
			assert(coords);
			assert(vertexCount > 0);

			const float* v = coords;
			float minX = v[0];
			float minY = v[1];
			float maxX = minX;
			float maxY = minY;
			for (int i = 1; i < vertexCount; ++i) {
				v += 2;
				float x = v[0];
				float y = v[1];
				minX = std::min(minX, x);
				minY = std::min(minY, y);
				maxX = std::max(maxX, x);
				maxY = std::max(maxY, y);
			}
			return { minX, minY, maxX - minX, maxY - minY };
		}

		bool slotIsOutRange(Slot& slot, int startSlotIndex, int endSlotIndex) {
			const int index = slot.getData().getIndex();
			return startSlotIndex > index || endSlotIndex < index;
		}

		int computeTotalCoordCount(Skeleton& skeleton, int startSlotIndex, int endSlotIndex) {
			int coordCount = 0;
			for (size_t i = 0; i < skeleton.getSlots().size(); ++i) {
				Slot& slot = *skeleton.getSlots()[i];
				Attachment* const attachment = slot.getAttachment();
				if (!attachment) {
					continue;
				}
				if (slotIsOutRange(slot, startSlotIndex, endSlotIndex)) {
					continue;
				}
					// Early exit if slot is invisible
				if (slot.getColor().a == 0) {
					continue;
				}
				if (attachment->getRTTI().isExactly(RegionAttachment::rtti)) {
					coordCount += 8;
				}
				else if (attachment->getRTTI().isExactly(MeshAttachment::rtti)) {
					MeshAttachment* const mesh = static_cast<MeshAttachment*>(attachment);
					coordCount += mesh->getWorldVerticesLength();
				}
			}
			return coordCount;
		}


		void transformWorldVertices(float* dstCoord, int coordCount, Skeleton& skeleton, int startSlotIndex, int endSlotIndex) {
			float* dstPtr = dstCoord;
	#ifndef NDEBUG
			float* const dstEnd = dstCoord + coordCount;
	#endif
			for (size_t i = 0; i < skeleton.getSlots().size(); ++i) {
				/*const*/ Slot& slot = *skeleton.getDrawOrder()[i]; // match the draw order of SkeletonRenderer::Draw
				Attachment* const attachment = slot.getAttachment();
				if (!attachment) {
					continue;
				}
				if (slotIsOutRange(slot, startSlotIndex, endSlotIndex)) {
					continue;
				}
				if (slot.getColor().a == 0) {
					continue;
				}
				if (attachment->getRTTI().isExactly(RegionAttachment::rtti)) {
					RegionAttachment* const regionAttachment = static_cast<RegionAttachment*>(attachment);
					assert(dstPtr + 8 <= dstEnd);
					regionAttachment->computeWorldVertices(slot.getBone(), dstPtr, 0, 2);
					dstPtr += 8;
				} else if (attachment->getRTTI().isExactly(MeshAttachment::rtti)) {
					MeshAttachment* const mesh = static_cast<MeshAttachment*>(attachment);
					assert(dstPtr + mesh->getWorldVerticesLength() <= dstEnd);
					mesh->computeWorldVertices(slot, 0, mesh->getWorldVerticesLength(), dstPtr, 0, 2);
					dstPtr += mesh->getWorldVerticesLength();
				}
			}
			assert(dstPtr == dstEnd);
		}

		void interleaveCoordinates(float* dst, const float* src, int count, int dstStride) {
			if (dstStride == 2) {
				memcpy(dst, src, sizeof(float) * count * 2);
			} else {
				for (int i = 0; i < count; ++i) {
					dst[0] = src[0];
					dst[1] = src[1];
					dst += dstStride;
					src += 2;
				}
			}

		}

		BlendFunc makeBlendFunc(int blendMode, bool premultipliedAlpha) {
			BlendFunc blendFunc;
			switch (blendMode) {
			case BlendMode_Additive:
				blendFunc.src = premultipliedAlpha ? backend::BlendFactor::ONE : backend::BlendFactor::SRC_ALPHA;
				blendFunc.dst = backend::BlendFactor::ONE;
				break;
			case BlendMode_Multiply:
				blendFunc.src = backend::BlendFactor::DST_COLOR;
				blendFunc.dst = backend::BlendFactor::ONE_MINUS_SRC_ALPHA;
				break;
			case BlendMode_Screen:
				blendFunc.src = backend::BlendFactor::ONE;
				blendFunc.dst = backend::BlendFactor::ONE_MINUS_SRC_COLOR;
				break;
			default:
				blendFunc.src = premultipliedAlpha ? backend::BlendFactor::ONE : backend::BlendFactor::SRC_ALPHA;
				blendFunc.dst = backend::BlendFactor::ONE_MINUS_SRC_ALPHA;
				break;
			}
			return blendFunc;
		}


		bool cullRectangle(Renderer* renderer, const Mat4& transform, const cocos2d::Rect& rect) {
			if (Camera::getVisitingCamera() == nullptr)
				return true;
			
			auto director = Director::getInstance();
			auto scene = director->getRunningScene();
						
			if (!scene || (scene && Camera::getDefaultCamera() != Camera::getVisitingCamera()))
				return false;

			Rect visibleRect(director->getVisibleOrigin(), director->getVisibleSize());
			
			// transform center point to screen space
			float hSizeX = rect.size.width/2;
			float hSizeY = rect.size.height/2;
			Vec3 v3p(rect.origin.x + hSizeX, rect.origin.y + hSizeY, 0);
			transform.transformPoint(&v3p);
			Vec2 v2p = Camera::getVisitingCamera()->projectGL(v3p);

			// convert content size to world coordinates
			float wshw = std::max(fabsf(hSizeX * transform.m[0] + hSizeY * transform.m[4]), fabsf(hSizeX * transform.m[0] - hSizeY * transform.m[4]));
			float wshh = std::max(fabsf(hSizeX * transform.m[1] + hSizeY * transform.m[5]), fabsf(hSizeX * transform.m[1] - hSizeY * transform.m[5]));
			
			// enlarge visible rect half size in screen coord
			visibleRect.origin.x -= wshw;
			visibleRect.origin.y -= wshh;
			visibleRect.size.width += wshw * 2;
			visibleRect.size.height += wshh * 2;
			return !visibleRect.containsPoint(v2p);
		}


		Color4B ColorToColor4B(const Color& color) {
			return { (uint8_t)(color.r * 255.f), (uint8_t)(color.g * 255.f), (uint8_t)(color.b * 255.f), (uint8_t)(color.a * 255.f) };
		}
	}

}
