---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TMXTiledMap

---TMXTiledMap knows how to parse and render a TMX map.
---It adds support for the TMX tiled map format used by http://www.mapeditor.org
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
---Each layer is created using an TMXLayer (subclass of SpriteBatchNode). If you have 5 layers, then 5 TMXLayer will be created,
---unless the layer visibility is off. In that case, the layer won't be created at all.
---You can obtain the layers (TMXLayer objects) at runtime by:
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
---\since v0.8.1
---@class cc.TMXTiledMap : cc.Node
---@field layerNum integer 
---@field mapOrientation integer Map orientation.  <br><br>\return Map orientation.
---@field mapSize cc.Size The map's size property measured in tiles.  <br><br>\return The map's size property measured in tiles.
---@field objectGroups any Get the Object groups.  <br><br>\return The object groups.
---@field properties cc.types.ValueMap Properties.  <br><br>\return Properties.
---@field resourceFile string 
---@field tileSize cc.Size The tiles's size property measured in pixels.  <br><br>\return The tiles's size property measured in pixels.
local TMXTiledMap = {}

---Creates a TMX Tiled Map with a TMX file.
---
---@param tmxFile string # A TMX file.
---@return cc.TMXTiledMap # An autorelease object.
function TMXTiledMap.create(tmxFile) end

---Initializes a TMX Tiled Map with a TMX formatted XML string and a path to TMX resources. 
---
---@param tmxString string # A TMX formatted XML string.
---@param resourcePath string # The path to TMX resources.
---@return cc.TMXTiledMap # An autorelease object.
---\js NA
function TMXTiledMap.createWithXML(tmxString, resourcePath) end

---Return the TMXLayer for the specific layer. 
---
---@param layerName string # A specific layer.
---@return cc.TMXLayer # The TMXLayer for the specific layer.
function TMXTiledMap:getLayer(layerName) end

---@return integer
function TMXTiledMap:getLayerNum() end

---Map orientation. 
---
---@return integer # Map orientation.
function TMXTiledMap:getMapOrientation() end

---The map's size property measured in tiles. 
---
---@return cc.Size # The map's size property measured in tiles.
function TMXTiledMap:getMapSize() end

---Return the TMXObjectGroup for the specific group. 
---
---@param groupName string # The group Name.
---@return cc.TMXObjectGroup # A Type of TMXObjectGroup.
function TMXTiledMap:getObjectGroup(groupName) end

---Get the Object groups. 
---
---@return any # The object groups.
function TMXTiledMap:getObjectGroups() end

---Properties. 
---
---@return cc.types.ValueMap # Properties.
function TMXTiledMap:getProperties() end

---Return properties dictionary for tile GID. 
---
---@param GID integer # The tile GID.
---@return any # Return properties dictionary for tile GID.
function TMXTiledMap:getPropertiesForGID(GID) end

---Return the value for the specific property name. 
---
---@param propertyName string # The specific property name.
---@return any # Return the value for the specific property name.
function TMXTiledMap:getProperty(propertyName) end

---@return string
function TMXTiledMap:getResourceFile() end

---The tiles's size property measured in pixels. 
---
---@return cc.Size # The tiles's size property measured in pixels.
function TMXTiledMap:getTileSize() end

---initializes a TMX Tiled Map with a TMX file
---@param tmxFile string
---@return boolean
function TMXTiledMap:initWithTMXFile(tmxFile) end

---initializes a TMX Tiled Map with a TMX formatted XML string and a path to TMX resources
---@param tmxString string
---@param resourcePath string
---@return boolean
function TMXTiledMap:initWithXML(tmxString, resourcePath) end

---\js ctor
---@return cc.TMXTiledMap
function TMXTiledMap.new() end

---Set map orientation. 
---
---@param mapOrientation integer # The map orientation.
function TMXTiledMap:setMapOrientation(mapOrientation) end

---Set the map's size property measured in tiles. 
---
---@param mapSize cc.Size # The map's size property measured in tiles.
function TMXTiledMap:setMapSize(mapSize) end

---Set the object groups. 
---
---@param groups any # The object groups.
function TMXTiledMap:setObjectGroups(groups) end

---Set the properties.
---
---@param properties any # A  Type of ValueMap to set the properties.
function TMXTiledMap:setProperties(properties) end

---Set the tiles's size property measured in pixels. 
---
---@param tileSize cc.Size # The tiles's size property measured in pixels.
function TMXTiledMap:setTileSize(tileSize) end

return TMXTiledMap