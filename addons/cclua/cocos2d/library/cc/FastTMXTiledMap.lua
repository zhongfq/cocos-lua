---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.FastTMXTiledMap

---FastTMXTiledMap knows how to parse and render a TMX map.
---It adds support for the TMX tiled map format used by http://www.mapeditor.org.
---It supports isometric, hexagonal and orthogonal tiles.
---It also supports object groups, objects, and properties.
---Features:
---- Each tile will be treated as an Sprite.
---- The sprites are created on demand. They will be created only when you call "layer->tileAt(position)".
---- Each tile can be rotated / moved / scaled / tinted / "opaqued", since each tile is a Sprite.
---- Tiles can be added/removed in runtime.
---- The z-order of the tiles can be modified in runtime.
---- Each tile has an anchorPoint of (0,0).
---- The anchorPoint of the TMXTileMap is (0,0).
---- The TMX layers will be added as a child.
---- The TMX layers will be aliased by default.
---- The tileset image will be loaded using the TextureCache.
---- Each tile will have a unique tag.
---- Each tile will have a unique z value. top-left: z=1, bottom-right: z=max z.
---- Each object group will be treated as an MutableArray.
---- Object class which will contain all the properties in a dictionary.
---- Properties can be assigned to the Map, Layer, Object Group, and Object.
---Limitations:
---- It only supports one tileset per layer.
---- Embedded images are not supported.
---- It only supports the XML format (the JSON format is not supported).
---Technical description:
---Each layer is created using an FastTMXLayer (subclass of SpriteBatchNode). If you have 5 layers, then 5 FastTMXLayer will be created,
---unless the layer visibility is off. In that case, the layer won't be created at all.
---You can obtain the layers (FastTMXLayer objects) at runtime by:
---- map->getChildByTag(tag_number);  // 0=1st layer, 1=2nd layer, 2=3rd layer, etc...
---- map->getLayer(name_of_the_layer);
---Each object group is created using a TMXObjectGroup which is a subclass of MutableArray.
---You can obtain the object groups at runtime by:
---- map->getObjectGroup(name_of_the_object_group);
---Each object is a TMXObject.
---Each property is stored as a key-value pair in an MutableDictionary.
---You can obtain the properties at runtime by:
---map->getProperty(name_of_the_property);
---layer->getProperty(name_of_the_property);
---objectGroup->getProperty(name_of_the_property);
---object->getProperty(name_of_the_property);
---\since v3.2
---\js NA
---@class cc.FastTMXTiledMap : cc.Node
---@field mapOrientation integer Get map orientation.  <br><br>\return The map orientation.
---@field mapSize cc.Size The map's size property measured in tiles.  <br><br>\return The map's size property measured in tiles.
---@field objectGroups any Get object groups.  <br><br>\return Object groups.
---@field properties any Get properties. <br><br>\return Properties.
---@field tileSize cc.Size The tiles's size property measured in pixels. <br><br>\return The tiles's size property measured in pixels.
local FastTMXTiledMap = {}

---Creates a TMX Tiled Map with a TMX file.
---
---@return cc.FastTMXTiledMap # An autorelease object.
---@param tmxFile string
function FastTMXTiledMap.create(tmxFile) end

---Initializes a TMX Tiled Map with a TMX formatted XML string and a path to TMX resources. 
---
---@param tmxString string # A TMX formatted XML string.
---@param resourcePath string # A path to TMX resources.
---@return cc.FastTMXTiledMap # An autorelease object.
function FastTMXTiledMap.createWithXML(tmxString, resourcePath) end

---Return the FastTMXLayer for the specific layer. 
---
---@return cc.FastTMXLayer # Return the FastTMXLayer for the specific layer.
---@param layerName string
function FastTMXTiledMap:getLayer(layerName) end

---Get map orientation. 
---
---@return integer # The map orientation.
function FastTMXTiledMap:getMapOrientation() end

---The map's size property measured in tiles. 
---
---@return cc.Size # The map's size property measured in tiles.
function FastTMXTiledMap:getMapSize() end

---Return the TMXObjectGroup for the specific group. 
---
---@return cc.TMXObjectGroup # Return the TMXObjectGroup for the specific group.
---@param groupName string
function FastTMXTiledMap:getObjectGroup(groupName) end

---Get object groups. 
---
---@return any # Object groups.
function FastTMXTiledMap:getObjectGroups() end

---Get properties.
---
---@return any # Properties.
function FastTMXTiledMap:getProperties() end

---Return properties dictionary for tile GID.
---
---@return any # Return properties dictionary for tile GID.
---@param GID integer
function FastTMXTiledMap:getPropertiesForGID(GID) end

---Return the value for the specific property name.
---
---@return any # Return the value for the specific property name.
---@param propertyName string
function FastTMXTiledMap:getProperty(propertyName) end

---The tiles's size property measured in pixels.
---
---@return cc.Size # The tiles's size property measured in pixels.
function FastTMXTiledMap:getTileSize() end

---Set map orientation. 
---
---@param mapOrientation integer # The map orientation.
function FastTMXTiledMap:setMapOrientation(mapOrientation) end

---Set the map's size property measured in tiles.
---
---@param mapSize cc.Size # The map's size property measured in tiles.
function FastTMXTiledMap:setMapSize(mapSize) end

---Set object groups. 
---
---@param groups any # An object groups.
function FastTMXTiledMap:setObjectGroups(groups) end

---Set properties. 
---
---@param properties any # An ValueMap Properties.
function FastTMXTiledMap:setProperties(properties) end

---Set the tiles's size property measured in pixels. 
---
---@param tileSize cc.Size # The tiles's size property measured in pixels.
function FastTMXTiledMap:setTileSize(tileSize) end

return FastTMXTiledMap