---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TMXMapInfo

---TMXMapInfo contains the information about the map like:
---- Map orientation (hexagonal, isometric or orthogonal)
---- Tile size
---- Map size
---
---And it also contains:
---- Layers (an array of TMXLayerInfo objects)
---- Tilesets (an array of TMXTilesetInfo objects)
---- ObjectGroups (an array of TMXObjectGroupInfo objects)
---
---This information is obtained from the TMX file.
---@class cc.TMXMapInfo : cc.Ref
---@field currentString string 
---@field externalTilesetFileName string 
---@field hexSideLength integer map hexsidelength
---@field layerAttribs integer layer attribs
---@field layers any Layers
---@field mapSize cc.Size map width & height
---@field objectGroups any ObjectGroups
---@field orientation integer map orientation
---@field parentElement integer parent element
---@field parentGID integer parent GID
---@field properties any properties
---@field staggerAxis integer map staggeraxis
---@field staggerIndex integer map stagger index
---@field storingCharacters boolean is storing characters?
---@field tileProperties any 
---@field tileSize cc.Size tiles width & height
---@field tilesets any tilesets
---@field tmxFileName string 
local TMXMapInfo = {}

---@param cls string
---@return any
function TMXMapInfo:as(cls) end

---creates a TMX Format with a tmx file
---@param tmxFile string
---@return cc.TMXMapInfo
function TMXMapInfo.create(tmxFile) end

---creates a TMX Format with an XML string and a TMX resource path
---@param tmxString string
---@param resourcePath string
---@return cc.TMXMapInfo
function TMXMapInfo.createWithXML(tmxString, resourcePath) end

---\js NA
---\lua NA
---@param ctx any
---@param name string
function TMXMapInfo:endElement(ctx, name) end

---@return string
function TMXMapInfo:getCurrentString() end

---@return string
function TMXMapInfo:getExternalTilesetFileName() end

---map hexsidelength
---@return integer
function TMXMapInfo:getHexSideLength() end

---layer attribs
---@return integer
function TMXMapInfo:getLayerAttribs() end

---Layers
---@return any
function TMXMapInfo:getLayers() end

---map width & height
---@return cc.Size
function TMXMapInfo:getMapSize() end

---ObjectGroups
---@return any
function TMXMapInfo:getObjectGroups() end

---map orientation
---@return integer
function TMXMapInfo:getOrientation() end

---parent element
---@return integer
function TMXMapInfo:getParentElement() end

---parent GID
---@return integer
function TMXMapInfo:getParentGID() end

---properties
---@return any
function TMXMapInfo:getProperties() end

---map staggeraxis
---@return integer
function TMXMapInfo:getStaggerAxis() end

---map stagger index
---@return integer
function TMXMapInfo:getStaggerIndex() end

---@return string
function TMXMapInfo:getTMXFileName() end

---@return any
function TMXMapInfo:getTileProperties() end

---tiles width & height
---@return cc.Size
function TMXMapInfo:getTileSize() end

---tilesets
---@return any
function TMXMapInfo:getTilesets() end

---initializes a TMX format with a  tmx file
---@param tmxFile string
---@return boolean
function TMXMapInfo:initWithTMXFile(tmxFile) end

---initializes a TMX format with an XML string and a TMX resource path
---@param tmxString string
---@param resourcePath string
---@return boolean
function TMXMapInfo:initWithXML(tmxString, resourcePath) end

---is storing characters?
---@return boolean
function TMXMapInfo:isStoringCharacters() end

---\js ctor
---@return cc.TMXMapInfo
function TMXMapInfo.new() end

---initializes parsing of an XML file, either a tmx (Map) file or tsx (Tileset) file
---@param xmlFilename string
---@return boolean
function TMXMapInfo:parseXMLFile(xmlFilename) end

---@param xmlString string
---@return boolean
function TMXMapInfo:parseXMLString(xmlString) end

---@param currentString string
function TMXMapInfo:setCurrentString(currentString) end

---@param hexSideLength integer
function TMXMapInfo:setHexSideLength(hexSideLength) end

---@param layerAttribs integer
function TMXMapInfo:setLayerAttribs(layerAttribs) end

---@param layers any
function TMXMapInfo:setLayers(layers) end

---@param mapSize cc.Size
function TMXMapInfo:setMapSize(mapSize) end

---@param groups any
function TMXMapInfo:setObjectGroups(groups) end

---@param orientation integer
function TMXMapInfo:setOrientation(orientation) end

---@param element integer
function TMXMapInfo:setParentElement(element) end

---@param gid integer
function TMXMapInfo:setParentGID(gid) end

---@param properties any
function TMXMapInfo:setProperties(properties) end

---@param staggerAxis integer
function TMXMapInfo:setStaggerAxis(staggerAxis) end

---@param staggerIndex integer
function TMXMapInfo:setStaggerIndex(staggerIndex) end

---@param storingCharacters boolean
function TMXMapInfo:setStoringCharacters(storingCharacters) end

---@param fileName string
function TMXMapInfo:setTMXFileName(fileName) end

---@param tileProperties any
function TMXMapInfo:setTileProperties(tileProperties) end

---@param tileSize cc.Size
function TMXMapInfo:setTileSize(tileSize) end

---@param tilesets any
function TMXMapInfo:setTilesets(tilesets) end

---\js NA
---\lua NA
---@param ctx any
---@param ch string
---@param len integer
function TMXMapInfo:textHandler(ctx, ch, len) end

return TMXMapInfo