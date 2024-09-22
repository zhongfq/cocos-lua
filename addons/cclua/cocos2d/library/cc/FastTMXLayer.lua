---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.FastTMXLayer

---FastTMXLayer represents the TMX layer.
---It is a subclass of SpriteBatchNode. By default the tiles are rendered using a TextureAtlas.
---If you modify a tile on runtime, then, that tile will become a Sprite, otherwise no Sprite objects are created.
---The benefits of using Sprite objects as tiles are:
---- tiles (Sprite) can be rotated/scaled/moved with a nice API.
---If the layer contains a property named "cc_vertexz" with an integer (in can be positive or negative),
---then all the tiles belonging to the layer will use that value as their OpenGL vertex Z for depth.
---On the other hand, if the "cc_vertexz" property has the "automatic" value, then the tiles will use an automatic vertex Z value.
---Also before drawing the tiles, GL_ALPHA_TEST will be enabled, and disabled after drawing them. The used alpha func will be:
---glAlphaFunc( GL_GREATER, value ).
---"value" by default is 0, but you can change it from Tiled by adding the "cc_alpha_func" property to the layer.
---The value 0 should work for most cases, but if you have tiles that are semi-transparent, then you might want to use a different
---value, like 0.5.
---
---For further information, please see the programming guide:
---http://www.cocos2d-iphone.org/wiki/doku.php/prog_guide:tiled_maps
---
---\since v3.2
---\js NA
---@class cc.FastTMXLayer : cc.Node
---@field layerName string Get the tile layer name. <br><br>\return The tile layer name.
---@field layerOrientation integer Layer orientation, which is the same as the map orientation. <br><br>\return Layer orientation, which is the same as the map orientation.
---@field layerSize cc.Size Size of the layer in tiles. <br><br>\return Size of the layer in tiles.
---@field mapTileSize cc.Size Size of the map's tile (could be different from the tile's size). <br><br>\return Size of the map's tile (could be different from the tile's size).
---@field properties any Properties from the layer. They can be added using Tiled.  <br><br>\return Properties from the layer. They can be added using Tiled.
---@field tileSet cc.TMXTilesetInfo Tileset information for the layer. <br><br>\return Tileset information for the layer.
---@field tiles olua.uint32 Pointer to the map of tiles. \js NA \lua NA \return The pointer to the map of tiles.
---@field FAST_TMX_ORIENTATION_HEX integer
---@field FAST_TMX_ORIENTATION_ISO integer
---@field FAST_TMX_ORIENTATION_ORTHO integer
local FastTMXLayer = {}

---Creates a FastTMXLayer with an tileset info, a layer info and a map info.
---
---@param tilesetInfo cc.TMXTilesetInfo # An tileset info.
---@param layerInfo cc.TMXLayerInfo # A layer info.
---@param mapInfo cc.TMXMapInfo # A map info.
---@return cc.FastTMXLayer # Return an autorelease object.
function FastTMXLayer.create(tilesetInfo, layerInfo, mapInfo) end

---Get the tile layer name.
---
---@return string # The tile layer name.
function FastTMXLayer:getLayerName() end

---Layer orientation, which is the same as the map orientation.
---
---@return integer # Layer orientation, which is the same as the map orientation.
function FastTMXLayer:getLayerOrientation() end

---Size of the layer in tiles.
---
---@return cc.Size # Size of the layer in tiles.
function FastTMXLayer:getLayerSize() end

---Size of the map's tile (could be different from the tile's size).
---
---@return cc.Size # Size of the map's tile (could be different from the tile's size).
function FastTMXLayer:getMapTileSize() end

---Returns the position in points of a given tile coordinate.
---
---@param tileCoordinate cc.Vec2 # The tile Coordinate.
---@return cc.Vec2 # The position in points of a given tile coordinate.
function FastTMXLayer:getPositionAt(tileCoordinate) end

---Properties from the layer. They can be added using Tiled. 
---
---@return any # Properties from the layer. They can be added using Tiled.
function FastTMXLayer:getProperties() end

---Return the value for the specific property name.
---
---@param propertyName string # The value for the specific property name.
---@return any # The value for the specific property name.
function FastTMXLayer:getProperty(propertyName) end

---Returns the tile (Sprite) at a given a tile coordinate.
---The returned Sprite will be already added to the TMXLayer. Don't add it again.
---The Sprite can be treated like any other Sprite: rotated, scaled, translated, opacity, color, etc.
---You can remove either by calling:
---- layer->removeChild(sprite, cleanup);
---
---@return cc.Sprite # Returns the tile (Sprite) at a given a tile coordinate.
---@param tileCoordinate cc.Vec2
function FastTMXLayer:getTileAt(tileCoordinate) end

---Returns the tile gid at a given tile coordinate. It also returns the tile flags.
---
---@param tileCoordinate cc.Vec2 # The tile coordinate.
---@param flags cc.types.TMXTileFlags # A TMXTileFlags.
---@return integer # The tile gid at a given tile coordinate. It also returns the tile flags.
---@overload fun(self: cc.FastTMXLayer, tileCoordinate: cc.Vec2): integer
function FastTMXLayer:getTileGIDAt(tileCoordinate, flags) end

---Tileset information for the layer.
---
---@return cc.TMXTilesetInfo # Tileset information for the layer.
function FastTMXLayer:getTileSet() end

---Pointer to the map of tiles.
---\js NA
---\lua NA
---@return olua.uint32 # The pointer to the map of tiles.
function FastTMXLayer:getTiles() end

---\js ctor
---@return cc.FastTMXLayer
function FastTMXLayer.new() end

---Removes a tile at given tile coordinate.
---
---@param tileCoordinate cc.Vec2 # The tile Coordinate.
function FastTMXLayer:removeTileAt(tileCoordinate) end

---Set the tile layer name.
---
---@param layerName string # The new layer name.
function FastTMXLayer:setLayerName(layerName) end

---Set Layer orientation, which is the same as the map orientation. 
---
---@param orientation integer # Layer orientation, which is the same as the map orientation.
function FastTMXLayer:setLayerOrientation(orientation) end

---Set the size of the layer in tiles. 
---
---@param size cc.Size # The new size of the layer in tiles.
function FastTMXLayer:setLayerSize(size) end

---Set the size of the map's tile. 
---
---@param size cc.Size # The new size of the map's tile.
function FastTMXLayer:setMapTileSize(size) end

---Set the properties to the layer.
---
---@param properties any # The properties to the layer.
function FastTMXLayer:setProperties(properties) end

---Sets the tile gid (gid = tile global id) at a given tile coordinate.
---The Tile GID can be obtained by using the method "tileGIDAt" or by using the TMX editor -> Tileset Mgr +1.
---If a tile is already placed at that position, then it will be removed.
---@param gid integer # The gid value.
---@param tileCoordinate cc.Vec2 # The tile coordinate.
---
---Sets the tile gid (gid = tile global id) at a given tile coordinate.
---The Tile GID can be obtained by using the method "tileGIDAt" or by using the TMX editor -> Tileset Mgr +1.
---If a tile is already placed at that position, then it will be removed.
---Use withFlags if the tile flags need to be changed as well.
---
---\param gid A integer value,it will be sets the tile gid.
---\param tileCoordinate The tile coordinate.
---\param flags A TMXTileFlags.
---@overload fun(self: cc.FastTMXLayer, gid: integer, tileCoordinate: cc.Vec2, flags: cc.TMXTileFlags)
function FastTMXLayer:setTileGID(gid, tileCoordinate) end

---Set the tileset information for the layer. 
---
---@param info cc.TMXTilesetInfo # The new tileset information for the layer.
function FastTMXLayer:setTileSet(info) end

---Set the pointer to the map of tiles.
---
---@param tiles olua.uint32 # The pointer to the map of tiles.
function FastTMXLayer:setTiles(tiles) end

---Set an sprite to the tile,with the tile coordinate and gid.
---
---@param sprite cc.Sprite # A Sprite.
---@param pos cc.Vec2 # The tile coordinate.
---@param gid integer # The tile gid.
function FastTMXLayer:setupTileSprite(sprite, pos, gid) end

---Creates the tiles.
function FastTMXLayer:setupTiles() end

return FastTMXLayer