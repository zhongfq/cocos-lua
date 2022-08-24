//
// AUTO BUILD, DON'T MODIFY!
//
#ifndef __AUTO_GEN_LUA_CONV_H__
#define __AUTO_GEN_LUA_CONV_H__

#include "cclua/xlua.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "network/WebSocket.h"

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_conv(lua_State *L);
OLUA_END_DECLS

// cocos2d::Vec2
int olua_push_cocos2d_Vec2(lua_State *L, const cocos2d::Vec2 *value);
void olua_check_cocos2d_Vec2(lua_State *L, int idx, cocos2d::Vec2 *value);
bool olua_is_cocos2d_Vec2(lua_State *L, int idx);
void olua_pack_cocos2d_Vec2(lua_State *L, int idx, cocos2d::Vec2 *value);
int olua_unpack_cocos2d_Vec2(lua_State *L, const cocos2d::Vec2 *value);
bool olua_canpack_cocos2d_Vec2(lua_State *L, int idx);

// cocos2d::Vec3
int olua_push_cocos2d_Vec3(lua_State *L, const cocos2d::Vec3 *value);
void olua_check_cocos2d_Vec3(lua_State *L, int idx, cocos2d::Vec3 *value);
bool olua_is_cocos2d_Vec3(lua_State *L, int idx);
void olua_pack_cocos2d_Vec3(lua_State *L, int idx, cocos2d::Vec3 *value);
int olua_unpack_cocos2d_Vec3(lua_State *L, const cocos2d::Vec3 *value);
bool olua_canpack_cocos2d_Vec3(lua_State *L, int idx);

// cocos2d::Vec4
int olua_push_cocos2d_Vec4(lua_State *L, const cocos2d::Vec4 *value);
void olua_check_cocos2d_Vec4(lua_State *L, int idx, cocos2d::Vec4 *value);
bool olua_is_cocos2d_Vec4(lua_State *L, int idx);
void olua_pack_cocos2d_Vec4(lua_State *L, int idx, cocos2d::Vec4 *value);
int olua_unpack_cocos2d_Vec4(lua_State *L, const cocos2d::Vec4 *value);
bool olua_canpack_cocos2d_Vec4(lua_State *L, int idx);

// cocos2d::Size
int olua_push_cocos2d_Size(lua_State *L, const cocos2d::Size *value);
void olua_check_cocos2d_Size(lua_State *L, int idx, cocos2d::Size *value);
bool olua_is_cocos2d_Size(lua_State *L, int idx);
void olua_pack_cocos2d_Size(lua_State *L, int idx, cocos2d::Size *value);
int olua_unpack_cocos2d_Size(lua_State *L, const cocos2d::Size *value);
bool olua_canpack_cocos2d_Size(lua_State *L, int idx);

// cocos2d::Texture2D::TexParams
int olua_push_cocos2d_Texture2D_TexParams(lua_State *L, const cocos2d::Texture2D::TexParams *value);
void olua_check_cocos2d_Texture2D_TexParams(lua_State *L, int idx, cocos2d::Texture2D::TexParams *value);
bool olua_is_cocos2d_Texture2D_TexParams(lua_State *L, int idx);
void olua_pack_cocos2d_Texture2D_TexParams(lua_State *L, int idx, cocos2d::Texture2D::TexParams *value);
int olua_unpack_cocos2d_Texture2D_TexParams(lua_State *L, const cocos2d::Texture2D::TexParams *value);
bool olua_canpack_cocos2d_Texture2D_TexParams(lua_State *L, int idx);

// cocos2d::experimental::Viewport
int olua_push_cocos2d_experimental_Viewport(lua_State *L, const cocos2d::experimental::Viewport *value);
void olua_check_cocos2d_experimental_Viewport(lua_State *L, int idx, cocos2d::experimental::Viewport *value);
bool olua_is_cocos2d_experimental_Viewport(lua_State *L, int idx);
void olua_pack_cocos2d_experimental_Viewport(lua_State *L, int idx, cocos2d::experimental::Viewport *value);
int olua_unpack_cocos2d_experimental_Viewport(lua_State *L, const cocos2d::experimental::Viewport *value);
bool olua_canpack_cocos2d_experimental_Viewport(lua_State *L, int idx);

// cocos2d::Quaternion
int olua_push_cocos2d_Quaternion(lua_State *L, const cocos2d::Quaternion *value);
void olua_check_cocos2d_Quaternion(lua_State *L, int idx, cocos2d::Quaternion *value);
bool olua_is_cocos2d_Quaternion(lua_State *L, int idx);
void olua_pack_cocos2d_Quaternion(lua_State *L, int idx, cocos2d::Quaternion *value);
int olua_unpack_cocos2d_Quaternion(lua_State *L, const cocos2d::Quaternion *value);
bool olua_canpack_cocos2d_Quaternion(lua_State *L, int idx);

// cocos2d::AffineTransform
int olua_push_cocos2d_AffineTransform(lua_State *L, const cocos2d::AffineTransform *value);
void olua_check_cocos2d_AffineTransform(lua_State *L, int idx, cocos2d::AffineTransform *value);
bool olua_is_cocos2d_AffineTransform(lua_State *L, int idx);
void olua_pack_cocos2d_AffineTransform(lua_State *L, int idx, cocos2d::AffineTransform *value);
int olua_unpack_cocos2d_AffineTransform(lua_State *L, const cocos2d::AffineTransform *value);
bool olua_canpack_cocos2d_AffineTransform(lua_State *L, int idx);

// cocos2d::ccBezierConfig
int olua_push_cocos2d_ccBezierConfig(lua_State *L, const cocos2d::ccBezierConfig *value);
void olua_check_cocos2d_ccBezierConfig(lua_State *L, int idx, cocos2d::ccBezierConfig *value);
bool olua_is_cocos2d_ccBezierConfig(lua_State *L, int idx);
void olua_pack_cocos2d_ccBezierConfig(lua_State *L, int idx, cocos2d::ccBezierConfig *value);
int olua_unpack_cocos2d_ccBezierConfig(lua_State *L, const cocos2d::ccBezierConfig *value);
bool olua_canpack_cocos2d_ccBezierConfig(lua_State *L, int idx);

// GLContextAttrs
int olua_push_GLContextAttrs(lua_State *L, const GLContextAttrs *value);
void olua_check_GLContextAttrs(lua_State *L, int idx, GLContextAttrs *value);
bool olua_is_GLContextAttrs(lua_State *L, int idx);
void olua_pack_GLContextAttrs(lua_State *L, int idx, GLContextAttrs *value);
int olua_unpack_GLContextAttrs(lua_State *L, const GLContextAttrs *value);
bool olua_canpack_GLContextAttrs(lua_State *L, int idx);

// cocos2d::Tex2F
int olua_push_cocos2d_Tex2F(lua_State *L, const cocos2d::Tex2F *value);
void olua_check_cocos2d_Tex2F(lua_State *L, int idx, cocos2d::Tex2F *value);
bool olua_is_cocos2d_Tex2F(lua_State *L, int idx);
void olua_pack_cocos2d_Tex2F(lua_State *L, int idx, cocos2d::Tex2F *value);
int olua_unpack_cocos2d_Tex2F(lua_State *L, const cocos2d::Tex2F *value);
bool olua_canpack_cocos2d_Tex2F(lua_State *L, int idx);

// cocos2d::T2F_Quad
int olua_push_cocos2d_T2F_Quad(lua_State *L, const cocos2d::T2F_Quad *value);
void olua_check_cocos2d_T2F_Quad(lua_State *L, int idx, cocos2d::T2F_Quad *value);
bool olua_is_cocos2d_T2F_Quad(lua_State *L, int idx);
void olua_pack_cocos2d_T2F_Quad(lua_State *L, int idx, cocos2d::T2F_Quad *value);
int olua_unpack_cocos2d_T2F_Quad(lua_State *L, const cocos2d::T2F_Quad *value);
bool olua_canpack_cocos2d_T2F_Quad(lua_State *L, int idx);

// cocos2d::TTFConfig
int olua_push_cocos2d_TTFConfig(lua_State *L, const cocos2d::TTFConfig *value);
void olua_check_cocos2d_TTFConfig(lua_State *L, int idx, cocos2d::TTFConfig *value);
bool olua_is_cocos2d_TTFConfig(lua_State *L, int idx);
void olua_pack_cocos2d_TTFConfig(lua_State *L, int idx, cocos2d::TTFConfig *value);
int olua_unpack_cocos2d_TTFConfig(lua_State *L, const cocos2d::TTFConfig *value);
bool olua_canpack_cocos2d_TTFConfig(lua_State *L, int idx);

// cocos2d::BlendFunc
int olua_push_cocos2d_BlendFunc(lua_State *L, const cocos2d::BlendFunc *value);
void olua_check_cocos2d_BlendFunc(lua_State *L, int idx, cocos2d::BlendFunc *value);
bool olua_is_cocos2d_BlendFunc(lua_State *L, int idx);
void olua_pack_cocos2d_BlendFunc(lua_State *L, int idx, cocos2d::BlendFunc *value);
int olua_unpack_cocos2d_BlendFunc(lua_State *L, const cocos2d::BlendFunc *value);
bool olua_canpack_cocos2d_BlendFunc(lua_State *L, int idx);

// cocos2d::ui::Margin
int olua_push_cocos2d_ui_Margin(lua_State *L, const cocos2d::ui::Margin *value);
void olua_check_cocos2d_ui_Margin(lua_State *L, int idx, cocos2d::ui::Margin *value);
bool olua_is_cocos2d_ui_Margin(lua_State *L, int idx);
void olua_pack_cocos2d_ui_Margin(lua_State *L, int idx, cocos2d::ui::Margin *value);
int olua_unpack_cocos2d_ui_Margin(lua_State *L, const cocos2d::ui::Margin *value);
bool olua_canpack_cocos2d_ui_Margin(lua_State *L, int idx);

// cocos2d::ResourceData
int olua_push_cocos2d_ResourceData(lua_State *L, const cocos2d::ResourceData *value);
void olua_check_cocos2d_ResourceData(lua_State *L, int idx, cocos2d::ResourceData *value);
bool olua_is_cocos2d_ResourceData(lua_State *L, int idx);
void olua_pack_cocos2d_ResourceData(lua_State *L, int idx, cocos2d::ResourceData *value);
int olua_unpack_cocos2d_ResourceData(lua_State *L, const cocos2d::ResourceData *value);
bool olua_canpack_cocos2d_ResourceData(lua_State *L, int idx);

// cocos2d::Quad3
int olua_push_cocos2d_Quad3(lua_State *L, const cocos2d::Quad3 *value);
void olua_check_cocos2d_Quad3(lua_State *L, int idx, cocos2d::Quad3 *value);
bool olua_is_cocos2d_Quad3(lua_State *L, int idx);
void olua_pack_cocos2d_Quad3(lua_State *L, int idx, cocos2d::Quad3 *value);
int olua_unpack_cocos2d_Quad3(lua_State *L, const cocos2d::Quad3 *value);
bool olua_canpack_cocos2d_Quad3(lua_State *L, int idx);

// cocos2d::Controller::KeyStatus
int olua_push_cocos2d_Controller_KeyStatus(lua_State *L, const cocos2d::Controller::KeyStatus *value);
void olua_check_cocos2d_Controller_KeyStatus(lua_State *L, int idx, cocos2d::Controller::KeyStatus *value);
bool olua_is_cocos2d_Controller_KeyStatus(lua_State *L, int idx);
void olua_pack_cocos2d_Controller_KeyStatus(lua_State *L, int idx, cocos2d::Controller::KeyStatus *value);
int olua_unpack_cocos2d_Controller_KeyStatus(lua_State *L, const cocos2d::Controller::KeyStatus *value);
bool olua_canpack_cocos2d_Controller_KeyStatus(lua_State *L, int idx);

#endif