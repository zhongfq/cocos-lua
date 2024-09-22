---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TileMapAtlas

---TileMapAtlas is a subclass of AtlasNode.
---
---It knows how to render a map based of tiles.
---The tiles must be in a .PNG format while the map must be a .TGA file.
---
---For more information regarding the format, please see this post:
---http://www.cocos2d-iphone.org/archives/27
---
---All features from AtlasNode are valid in TileMapAtlas
---
---IMPORTANT:
---This class is deprecated. It is maintained for compatibility reasons only.
---You SHOULD not use this class.
---Instead, use the newer TMX file format: TMXTiledMap
---\js NA
---@class cc.TileMapAtlas : cc.AtlasNode
---@field tgaInfo cc.sImageTGA Query TGA image info. \return The TGA image info.
local TileMapAtlas = {}

---creates a TileMap with a tile file (atlas) with a map file and the width and height of each tile in points.
---The tile file will be loaded using the TextureMgr.
---@param tile string
---@param mapFile string
---@param tileWidth integer
---@param tileHeight integer
---@return cc.TileMapAtlas
function TileMapAtlas.create(tile, mapFile, tileWidth, tileHeight) end

---Query TGA image info.
---@return cc.sImageTGA # The TGA image info.
function TileMapAtlas:getTGAInfo() end

---Returns a tile from position x,y.
---For the moment only channel R is used
---@param position cc.Vec2
---@return any
function TileMapAtlas:getTileAt(position) end

---initializes a TileMap with a tile file (atlas) with a map file and the width and height of each tile in points.
---The file will be loaded using the TextureMgr.
---@param tile string
---@param mapFile string
---@param tileWidth integer
---@param tileHeight integer
---@return boolean
function TileMapAtlas:initWithTileFile(tile, mapFile, tileWidth, tileHeight) end

---\js ctor
---@return cc.TileMapAtlas
function TileMapAtlas.new() end

---dealloc the map from memory
function TileMapAtlas:releaseMap() end

---Set the TGA image info for TileMapAtlas
---@param TGAInfo cc.sImageTGA # The TGA info in sImageTGA.
function TileMapAtlas:setTGAInfo(TGAInfo) end

---sets a tile at position x,y.
---For the moment only channel R is used
---@param tile any
---@param position cc.Vec2
function TileMapAtlas:setTile(tile, position) end

return TileMapAtlas