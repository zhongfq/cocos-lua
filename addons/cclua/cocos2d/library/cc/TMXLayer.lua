---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TMXLayer

---TMXLayer represents the TMX layer.
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
---For further information, please see the programming guide:
---http://www.cocos2d-iphone.org/wiki/doku.php/prog_guide:tiled_maps
---\since v0.8.1
---Tiles can have tile flags for additional properties. At the moment only flip horizontal and flip vertical are used. These bit flags are defined in TMXXMLParser.h.
---\since 1.1
---@class cc.TMXLayer : cc.SpriteBatchNode
---@field layerName string Get the layer name.  <br><br>\return The layer name.
---@field layerOrientation integer Layer orientation, which is the same as the map orientation. <br><br>\return Layer orientation, which is the same as the map orientation.
---@field layerSize cc.Size Size of the layer in tiles. <br><br>\return Size of the layer in tiles.
---@field mapTileSize cc.Size Size of the map's tile (could be different from the tile's size). <br><br>\return The size of the map's tile.
---@field properties any Properties from the layer. They can be added using Tiled. <br><br>\return Properties from the layer. They can be added using Tiled.
---@field tileSet cc.TMXTilesetInfo Tileset information for the layer.  <br><br>\return Tileset information for the layer.
---@field tiles olua.uint32 Pointer to the map of tiles. \js NA \lua NA \return Pointer to the map of tiles.
local TMXLayer = {}

---Creates a TMXLayer with an tileset info, a layer info and a map info.
---
---@param tilesetInfo cc.TMXTilesetInfo # An tileset info.
---@param layerInfo cc.TMXLayerInfo # A layer info.
---@param mapInfo cc.TMXMapInfo # A map info.
---@return cc.TMXLayer # An autorelease object.
function TMXLayer.create(tilesetInfo, layerInfo, mapInfo) end

---Get the layer name. 
---
---@return string # The layer name.
function TMXLayer:getLayerName() end

---Layer orientation, which is the same as the map orientation.
---
---@return integer # Layer orientation, which is the same as the map orientation.
function TMXLayer:getLayerOrientation() end

---Size of the layer in tiles.
---
---@return cc.Size # Size of the layer in tiles.
function TMXLayer:getLayerSize() end

---Size of the map's tile (could be different from the tile's size).
---
---@return cc.Size # The size of the map's tile.
function TMXLayer:getMapTileSize() end

---Returns the position in points of a given tile coordinate.
---
---@param tileCoordinate cc.Vec2 # The tile coordinate.
---@return cc.Vec2 # The position in points of a given tile coordinate.
function TMXLayer:getPositionAt(tileCoordinate) end

---Properties from the layer. They can be added using Tiled.
---
---@return any # Properties from the layer. They can be added using Tiled.
function TMXLayer:getProperties() end

---Return the value for the specific property name.
---
---@param propertyName string # The specific property name.
---@return any # Return the value for the specific property name.
function TMXLayer:getProperty(propertyName) end

---Returns the tile (Sprite) at a given a tile coordinate.
---The returned Sprite will be already added to the TMXLayer. Don't add it again.
---The Sprite can be treated like any other Sprite: rotated, scaled, translated, opacity, color, etc.
---You can remove either by calling:
---- layer->removeChild(sprite, cleanup);
---- or layer->removeTileAt(Vec2(x,y));
---
---@param tileCoordinate cc.Vec2 # A tile coordinate.
---@return cc.Sprite # Returns the tile (Sprite) at a given a tile coordinate.
function TMXLayer:getTileAt(tileCoordinate) end

---Returns the tile gid at a given tile coordinate. It also returns the tile flags.
---This method requires the tile map has not been previously released (eg. don't call [layer releaseMap]).
---
---@param tileCoordinate cc.Vec2 # The tile coordinate.
---@param flags cc.types.TMXTileFlags # Tile flags.
---@return integer # Returns the tile gid at a given tile coordinate. It also returns the tile flags.
---@overload fun(self: cc.TMXLayer, tileCoordinate: cc.Vec2): integer
function TMXLayer:getTileGIDAt(tileCoordinate, flags) end

---Tileset information for the layer. 
---
---@return cc.TMXTilesetInfo # Tileset information for the layer.
function TMXLayer:getTileSet() end

---Pointer to the map of tiles.
---\js NA
---\lua NA
---@return olua.uint32 # Pointer to the map of tiles.
function TMXLayer:getTiles() end

---Initializes a TMXLayer with a tileset info, a layer info and a map info.
---
---@param tilesetInfo cc.TMXTilesetInfo # An tileset info.
---@param layerInfo cc.TMXLayerInfo # A layer info.
---@param mapInfo cc.TMXMapInfo # A map info.
---@return boolean # If initializes successfully, it will return true.
function TMXLayer:initWithTilesetInfo(tilesetInfo, layerInfo, mapInfo) end

---\js ctor
---@return cc.TMXLayer
function TMXLayer.new() end

---Dealloc the map that contains the tile position from memory.
---Unless you want to know at runtime the tiles positions, you can safely call this method.
---If you are going to call layer->tileGIDAt() then, don't release the map.
function TMXLayer:releaseMap() end

---Removes a tile at given tile coordinate. 
---
---@param tileCoordinate cc.Vec2 # The tile coordinate.
function TMXLayer:removeTileAt(tileCoordinate) end

---Set the layer name.
---
---@param layerName string # The layer name.
function TMXLayer:setLayerName(layerName) end

---Set layer orientation, which is the same as the map orientation.
---
---@param orientation integer # Layer orientation,which is the same as the map orientation.
function TMXLayer:setLayerOrientation(orientation) end

---Set size of the layer in tiles.
---
---@param size cc.Size # Size of the layer in tiles.
function TMXLayer:setLayerSize(size) end

---Set the size of the map's tile.
---
---@param size cc.Size # The size of the map's tile.
function TMXLayer:setMapTileSize(size) end

---Set an Properties from to layer.
---
---@param properties any # It is used to set the layer Properties.
function TMXLayer:setProperties(properties) end

---Sets the tile gid (gid = tile global id) at a given tile coordinate.
---The Tile GID can be obtained by using the method "tileGIDAt" or by using the TMX editor -> Tileset Mgr +1.
---If a tile is already placed at that position, then it will be removed.
---
---@param gid integer # The tile gid.
---@param tileCoordinate cc.Vec2 # The tile coordinate.
---
---Sets the tile gid (gid = tile global id) at a given tile coordinate.
---The Tile GID can be obtained by using the method "tileGIDAt" or by using the TMX editor -> Tileset Mgr +1.
---If a tile is already placed at that position, then it will be removed.
---Use withFlags if the tile flags need to be changed as well.
---
---\param gid The tile gid.
---\param tileCoordinate The tile coordinate.
---\param flags The tile flags.
---@overload fun(self: cc.TMXLayer, gid: integer, tileCoordinate: cc.Vec2, flags: cc.TMXTileFlags)
function TMXLayer:setTileGID(gid, tileCoordinate) end

---Set tileset information for the layer.
---
---@param info cc.TMXTilesetInfo # The tileset information for the layer.
---\js NA
function TMXLayer:setTileSet(info) end

---Set a pointer to the map of tiles.
---
---@param tiles olua.uint32 # A pointer to the map of tiles.
function TMXLayer:setTiles(tiles) end

---Creates the tiles.
function TMXLayer:setupTiles() end

return TMXLayer