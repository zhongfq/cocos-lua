---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Properties

---Defines a properties file for loading text files.
---
---A properties file has very simple syntax and can contain only namespaces and
---name/value pairs (the properties of a namespace).  
---The file can have any file extension a user specifies.
---
---Here's an example of a simple
---file that uses all the available features of the markup language:
---
---\verbatim
---This is a comment.
---
---This property is in the default namespace:
---integerProperty = 5
---
---This line defines a namespace of type "mynamespace" without an ID:
---mynamespace
---{
---This namespace can be retrieved by searching for its ID, "spriteTexture",
---or by its name "texture":
---texture spriteTexture 
---{
---fileName = sprite.png
---width = 64
---height = 64
---}
---
---This property is in the "space" namespace:
---booleanProperty = true
---
---It's legal to have a name without a value if you leave out the '=' character:
---foo
---
---In fact, the '=' character is optional if you'd rather write:
---bar 23
---
---But don't write this or you'll get an error:
---illegalProperty =
---
---Or this:
---= 15
---
---Properties objects let you retrieve values as various types.
---floatProperty = 3.333
---stringProperty = This is a string.
---vector3Property = 1.0, 5.0, 3.55
---colorProperty = 1.0, 0.4, 0.0, 1.0
---}
---\endverbatim
---
---Retrieving information out of a file like this could be done in two ways.  If the
---available namespaces and name/value pairs are known in advance they can be queried by ID or name.
---For example, if the namespace "spriteTexture" and its properties are required then they can
---be retrieved with a call to getNamespace() followed by calls to getString() and getInt().
---A namespace is stored and retrieved as a Properties object.
---Reading the spriteTexture properties out of the file above in this way could be done with the following code:
---
---\verbatim
---Create the top-level Properties object.
---Properties* properties = Properties::createNonRefCounted("example.properties");
---Retrieve the "spriteTexture" namespace.
---Properties* spriteTexture = properties->getNamespace("spriteTexture");
---
---Get the values of known texture properties out of the namespace.
---const char* fileName = spriteTexture->getString("fileName");
---int width = spriteTexture->getInt("width");
---int height = spriteTexture->getInt("height");
---
---Deleting the top-level Properties object will clean up all nested namespaces.
---SAFE_DELETE(properties);
---\endverbatim
---On the other hand, if the structure of the file is not known in advance its 
---namespaces and name/value pairs can be retrieved one by one using the getNextNamespace()
---and getNextProperty() methods.  The following method prints the contents of any properties file
---to the console:
---
---\verbatim
---void printProperties(Properties* properties)
---{
---Print the name and ID of the current namespace.
---const char* spacename = properties->getNamespace();
---const char* id = properties->getId();
---GP_WARN("Namespace: %s  ID: %s\n{", spacename, id);
---
---Print all properties in this namespace.
---const char* name = properties->getNextProperty();
---const char* value = NULL;
---while (name != NULL)
---{
---value = properties->getString(name);
---GP_WARN("%s = %s", name, value);
---name = properties->getNextProperty();
---}
---GP_WARN("}\n");
---
---Print the properties of every namespace within this one.
---Properties* space = properties->getNextNamespace();
---while (space != NULL)
---{
---printProperties(space);
---space = properties->getNextNamespace();
---}
---}
---\endverbatim
---Note that this method does not keep track of the namespace hierarchy, but could be
---modified to do so.  Also note that nothing in a properties file indicates the type
---of a property. If the type is unknown, its string can be retrieved and interpreted
---as necessary.
---@class cc.Properties 
---@field id string Get the ID of this Property's namespace. The ID should be a unique identifier, but its uniqueness is not enforced. <br><br>\return The ID of this Property's namespace.
---@field nextNamespace cc.Properties Get the next namespace.
---@field nextProperty string Get the name of the next property. <br><br>If a valid next property is returned, the value of the property can be retrieved using any of the get methods in this class, passing NULL for the property name. <br><br>\return The name of the next property, or NULL if there are no properties remaining.
local Properties = {}

---@return any
function Properties:__gc() end

---Creates a Properties runtime settings from the specified URL, where the URL is of
---the format "<file-path>.<extension>#<namespace-id>/<namespace-id>/.../<namespace-id>"
---(and "#<namespace-id>/<namespace-id>/.../<namespace-id>" is optional).
---
---@param url string # The URL to create the properties from.
---
---@return cc.Properties # The created Properties or NULL if there was an error.
---\script{create}
function Properties.createNonRefCounted(url) end

---Check if a property with the given name is specified in this Properties object.
---
---@param name string # The name of the property to query.
---
---@return boolean # True if the property exists, false otherwise.
function Properties:exists(name) end

---Interpret the value of the given property as a boolean.
---
---@param name string # The name of the property to interpret, or NULL to return the current property's value.
---@param defaultValue boolean # the default value to return if the specified property does not exist within the properties file.
---
---@return boolean # true if the property exists and its value is "true", otherwise false.
---@overload fun(self: cc.Properties): boolean
---@overload fun(self: cc.Properties, name: string): boolean
function Properties:getBool(name, defaultValue) end

---Interpret the value of the given property as an RGB color in hex and write this color to a Vector3.
---E.g. 0xff0000 represents red and sets the vector to (1, 0, 0).
---If the property does not exist, out will be set to Vector3(0.0f, 0.0f, 0.0f).
---If the property exists but could not be scanned, an error will be logged and out will be set
---to Vector3(0.0f, 0.0f, 0.0f).
---
---@param name string # The name of the property to interpret, or NULL to return the current property's value.
---@param out cc.Vec3 # The vector to set to this property's interpreted value.
---
---@return boolean # True on success, false if the property does not exist or could not be scanned.
---
---Interpret the value of the given property as an RGBA color in hex and write this color to a Vector4.
---E.g. 0xff0000ff represents opaque red and sets the vector to (1, 0, 0, 1).
---If the property does not exist, out will be set to Vector4(0.0f, 0.0f, 0.0f, 0.0f).
---If the property exists but could not be scanned, an error will be logged and out will be set
---to Vector4(0.0f, 0.0f, 0.0f, 0.0f).
---
---\param name The name of the property to interpret, or NULL to return the current property's value.
---\param out The vector to set to this property's interpreted value.
---
---\return True on success, false if the property does not exist or could not be scanned.
---@overload fun(self: cc.Properties, name: string, out: cc.Vec4): boolean
function Properties:getColor(name, out) end

---Interpret the value of the given property as a floating-point number.
---If the property does not exist, zero will be returned.
---If the property exists but could not be scanned, an error will be logged and zero will be returned.
---
---@param name string # The name of the property to interpret, or NULL to return the current property's value.
---
---@return number # The value of the given property interpreted as a float.
---Zero if the property does not exist or could not be scanned.
---@overload fun(self: cc.Properties): number
function Properties:getFloat(name) end

---Get the ID of this Property's namespace. The ID should be a unique identifier,
---but its uniqueness is not enforced.
---
---@return string # The ID of this Property's namespace.
function Properties:getId() end

---Interpret the value of the given property as an integer.
---If the property does not exist, zero will be returned.
---If the property exists but could not be scanned, an error will be logged and zero will be returned.
---
---@param name string # The name of the property to interpret, or NULL to return the current property's value.
---
---@return integer # The value of the given property interpreted as an integer.
---Zero if the property does not exist or could not be scanned.
---@overload fun(self: cc.Properties): integer
function Properties:getInt(name) end

---Interpret the value of the given property as a long integer.
---If the property does not exist, zero will be returned.
---If the property exists but could not be scanned, an error will be logged and zero will be returned.
---
---@param name string # The name of the property to interpret, or NULL to return the current property's value.
---
---@return integer # The value of the given property interpreted as a long.
---Zero if the property does not exist or could not be scanned.
---@overload fun(self: cc.Properties): integer
function Properties:getLong(name) end

---Interpret the value of the given property as a Matrix.
---If the property does not exist, out will be set to the identity matrix.
---If the property exists but could not be scanned, an error will be logged and out will be set
---to the identity matrix.
---
---@param name string # The name of the property to interpret, or NULL to return the current property's value.
---@param out cc.Mat4 # The matrix to set to this property's interpreted value.
---
---@return boolean # True on success, false if the property does not exist or could not be scanned.
function Properties:getMat4(name, out) end

---Get a specific namespace by ID or name. This method will optionally
---perform a depth-first search on all namespaces and inner namespaces
---within this Property.
---
---@param id string # The ID or name of the namespace to find.
---@param searchNames boolean # If true, namespace names are used in the search,
---instead of namespace IDs. By default this parameter is false
---and namespace IDs are searched.
---@param recurse boolean # If true, perform a depth-first search, otherwise search
---only the immediate child namespaces.
---
---@return cc.Properties # A properties object with the given ID or name.
---@overload fun(self: cc.Properties, id: string): cc.Properties
---@overload fun(self: cc.Properties, id: string, searchNames: boolean): cc.Properties
---
---Get the name of this Property's namespace.
---
---\return The name of this Property's namespace.
---@overload fun(self: cc.Properties): string
function Properties:getNamespace(id, searchNames, recurse) end

---Get the next namespace.
---@return cc.Properties
function Properties:getNextNamespace() end

---Get the name of the next property.
---
---If a valid next property is returned, the value of the property can be
---retrieved using any of the get methods in this class, passing NULL for
---the property name.
---
---@return string # The name of the next property, or NULL if there are no properties remaining.
function Properties:getNextProperty() end

---Gets the file path for the given property if the file exists.
---
---This method will first search for the file relative to the working directory.
---If the file is not found then it will search relative to the directory the bundle file is in.
---
---@param name string # The name of the property.
---@param path olua.string # The string to copy the path to if the file exists.
---
---@return boolean # True if the property exists and the file exists, false otherwise.
---
---\script{ignore}
function Properties:getPath(name, path) end

---Interpret the value of the given property as a Quaternion specified as an axis angle.
---If the property does not exist, out will be set to Quaternion().
---If the property exists but could not be scanned, an error will be logged and out will be set
---to Quaternion().
---
---@param name string # The name of the property to interpret, or NULL to return the current property's value.
---@param out cc.Quaternion # The quaternion to set to this property's interpreted value.
---
---@return boolean # True on success, false if the property does not exist or could not be scanned.
function Properties:getQuaternionFromAxisAngle(name, out) end

---Get the value of the given property as a string. This can always be retrieved,
---whatever the intended type of the property.
---
---@param name string # The name of the property to interpret, or NULL to return the current property's value.
---@param defaultValue string # The default value to return if the specified property does not exist.
---
---@return string # The value of the given property as a string, or the empty string if no property with that name exists.
---@overload fun(self: cc.Properties): string
---@overload fun(self: cc.Properties, name: string): string
function Properties:getString(name, defaultValue) end

---Returns the type of a property.
---
---@param name string # The name of the property to interpret, or NULL to return the current property's type.
---
---@return cc.Properties.Type # The type of the property.
---@overload fun(self: cc.Properties): cc.Properties.Type
function Properties:getType(name) end

---Returns the value of a variable that is set in this Properties object.
---
---Variables take on the format ${name} and are inherited from parent Property objects.
---
---@param name string # Name of the variable to get.
---@param defaultValue string # Value to return if the variable is not found.
---
---@return string # The value of the specified variable, or defaultValue if not found.
---@overload fun(self: cc.Properties, name: string): string
function Properties:getVariable(name, defaultValue) end

---Interpret the value of the given property as a Vector2.
---If the property does not exist, out will be set to Vector2(0.0f, 0.0f).
---If the property exists but could not be scanned, an error will be logged and out will be set
---to Vector2(0.0f, 0.0f).
---
---@param name string # The name of the property to interpret, or NULL to return the current property's value.
---@param out cc.Vec2 # The vector to set to this property's interpreted value.
---
---@return boolean # True on success, false if the property does not exist or could not be scanned.
function Properties:getVec2(name, out) end

---Interpret the value of the given property as a Vector3.
---If the property does not exist, out will be set to Vector3(0.0f, 0.0f, 0.0f).
---If the property exists but could not be scanned, an error will be logged and out will be set
---to Vector3(0.0f, 0.0f, 0.0f).
---
---@param name string # The name of the property to interpret, or NULL to return the current property's value.
---@param out cc.Vec3 # The vector to set to this property's interpreted value.
---
---@return boolean # True on success, false if the property does not exist or could not be scanned.
function Properties:getVec3(name, out) end

---Interpret the value of the given property as a Vector4.
---If the property does not exist, out will be set to Vector4(0.0f, 0.0f, 0.0f, 0.0f).
---If the property exists but could not be scanned, an error will be logged and out will be set
---to Vector4(0.0f, 0.0f, 0.0f, 0.0f).
---
---@param name string # The name of the property to interpret, or NULL to return the current property's value.
---@param out cc.Vec4 # The vector to set to this property's interpreted value.
---
---@return boolean # True on success, false if the property does not exist or could not be scanned.
function Properties:getVec4(name, out) end

---Attempts to parse the specified string as an axis-angle value.
---
---The specified string is expected to contain four comma-separated
---values, where the first three values represents the axis and the
---fourth value represents the angle, in degrees.
---
---On error, false is returned and the output is set to all zero values.
---
---@param str string # The string to parse.
---@param out cc.Quaternion # A Quaternion populated with the orientation of the axis-angle, if successful.
---
---@return boolean # True if a valid axis-angle was parsed, false otherwise.
function Properties.parseAxisAngle(str, out) end

---Attempts to parse the specified string as an RGB color value.
---
---@param str string # The string to parse.
---@param out cc.Vec3 # The value to populate if successful.
---
---@return boolean # True if a valid RGB color was parsed, false otherwise.
---
---Attempts to parse the specified string as an RGBA color value.
---
---\param str The string to parse.
---\param out The value to populate if successful.
---
---\return True if a valid RGBA color was parsed, false otherwise.
---@overload fun(str: string, out: cc.Vec4): boolean
function Properties.parseColor(str, out) end

---Attempts to parse the specified string as a Vector2 value.
---
---On error, false is returned and the output is set to all zero values.
---
---@param str string # The string to parse.
---@param out cc.Vec2 # The value to populate if successful.
---
---@return boolean # True if a valid Vector2 was parsed, false otherwise.
function Properties.parseVec2(str, out) end

---Attempts to parse the specified string as a Vector3 value.
---
---On error, false is returned and the output is set to all zero values.
---
---@param str string # The string to parse.
---@param out cc.Vec3 # The value to populate if successful.
---
---@return boolean # True if a valid Vector3 was parsed, false otherwise.
function Properties.parseVec3(str, out) end

---Attempts to parse the specified string as a Vector4 value.
---
---On error, false is returned and the output is set to all zero values.
---
---@param str string # The string to parse.
---@param out cc.Vec4 # The value to populate if successful.
---
---@return boolean # True if a valid Vector4 was parsed, false otherwise.
function Properties.parseVec4(str, out) end

---Rewind the getNextProperty() and getNextNamespace() iterators
---to the beginning of the file.
function Properties:rewind() end

---Sets the value of the property with the specified name.
---
---If there is no property in this namespace with the current name,
---one is added. Otherwise, the value of the first property with the
---specified name is updated.
---
---If name is NULL, the value current property (see getNextProperty) is
---set, unless there is no current property, in which case false
---is returned.
---
---@param name string # The name of the property to set.
---@param value string # The property value.
---
---@return boolean # True if the property was set, false otherwise.
function Properties:setString(name, value) end

---Sets the value of the specified variable.
---
---@param name string # Name of the variable to set.
---@param value string # The value to set.
function Properties:setVariable(name, value) end

return Properties