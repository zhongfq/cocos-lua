---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.FileUtils

---Helper class to handle file operations.
---@class cc.FileUtils 
---@field defaultResourceRootPath string Get default resource root path.
---@field fullPathCache { [string]: string } Returns the full path cache.
---@field instance cc.FileUtils Gets the instance of FileUtils.
---@field originalSearchPaths string[] Gets the original search path array set by 'setSearchPaths' or 'addSearchPath'. \return The array of the original search paths
---@field popupNotify boolean Checks whether to pop up a message box when failed to load an image. \return True if pop up a message box when failed to load an image, false if not.
---@field searchPaths string[] Gets the array of search paths. <br><br>\return The array of search paths which may contain the prefix of default resource root path.  \note In best practise, getter function should return the value of setter function passes in. But since we should not break the compatibility, we keep using the old logic.  Therefore, If you want to get the original search paths, please call 'getOriginalSearchPaths()' instead. \see fullPathForFilename(const char*). \lua NA
---@field searchResolutionsOrder string[] Gets the array that contains the search order of the resources. <br><br>\see setSearchResolutionsOrder(const std::vector<std::string>&), fullPathForFilename(const char*). \since v2.1 \lua NA
---@field writablePath string Gets the writable path. \return  The path that can be write/read a file in
local FileUtils = {}

---@return any
function FileUtils:__gc() end

---Add search path.
---
---\since v2.1
---@param path string
---@param front boolean
---@overload fun(self: cc.FileUtils, path: string)
function FileUtils:addSearchPath(path, front) end

---Append search order of the resources.
---
---\see setSearchResolutionsOrder(), fullPathForFilename().
---\since v2.1
---@param order string
---@param front boolean
---@overload fun(self: cc.FileUtils, order: string)
function FileUtils:addSearchResolutionsOrder(order, front) end

---Creates a directory.
---
---@param dirPath string # The path of the directory, it must be an absolute path.
---@return boolean # True if the directory have been created successfully, false if not.
---
---Create a directory, async off the main cocos thread.
---
---\param dirPath the path of the directory, it must be an absolute path
---\param callback The function that will be called when the operation is complete. Will have one boolean
---argument, true if the directory was successfully, false otherwise.
---@overload fun(self: cc.FileUtils, dirPath: string, callback: fun(arg1: boolean))
function FileUtils:createDirectory(dirPath) end

---Destroys the instance of FileUtils.
function FileUtils.destroyInstance() end

---Returns the fullpath for a given filename.
---First it will try to get a new filename from the "filenameLookup" dictionary.
---If a new filename can't be found on the dictionary, it will use the original filename.
---Then it will try to obtain the full path of the filename using the FileUtils search rules: resolutions, and search paths.
---The file search is based on the array element order of search paths and resolution directories.
---For instance:
---We set two elements("/mnt/sdcard/", "internal_dir/") to search paths vector by setSearchPaths,
---and set three elements("resources-ipadhd/", "resources-ipad/", "resources-iphonehd")
---to resolutions vector by setSearchResolutionsOrder. The "internal_dir" is relative to "Resources/".
---If we have a file named 'sprite.png', the mapping in fileLookup dictionary contains `key: sprite.png -> value: sprite.pvr.gz`.
---Firstly, it will replace 'sprite.png' with 'sprite.pvr.gz', then searching the file sprite.pvr.gz as follows:
---mnt/sdcard/resources-ipadhd/sprite.pvr.gz      (if not found, search next)
---mnt/sdcard/resources-ipad/sprite.pvr.gz        (if not found, search next)
---mnt/sdcard/resources-iphonehd/sprite.pvr.gz    (if not found, search next)
---mnt/sdcard/sprite.pvr.gz                       (if not found, search next)
---internal_dir/resources-ipadhd/sprite.pvr.gz     (if not found, search next)
---internal_dir/resources-ipad/sprite.pvr.gz       (if not found, search next)
---internal_dir/resources-iphonehd/sprite.pvr.gz   (if not found, search next)
---internal_dir/sprite.pvr.gz                      (if not found, return "sprite.png")
---If the filename contains relative path like "gamescene/uilayer/sprite.png",
---and the mapping in fileLookup dictionary contains `key: gamescene/uilayer/sprite.png -> value: gamescene/uilayer/sprite.pvr.gz`.
---The file search order will be:
---mnt/sdcard/gamescene/uilayer/resources-ipadhd/sprite.pvr.gz      (if not found, search next)
---mnt/sdcard/gamescene/uilayer/resources-ipad/sprite.pvr.gz        (if not found, search next)
---mnt/sdcard/gamescene/uilayer/resources-iphonehd/sprite.pvr.gz    (if not found, search next)
---mnt/sdcard/gamescene/uilayer/sprite.pvr.gz                       (if not found, search next)
---internal_dir/gamescene/uilayer/resources-ipadhd/sprite.pvr.gz     (if not found, search next)
---internal_dir/gamescene/uilayer/resources-ipad/sprite.pvr.gz       (if not found, search next)
---internal_dir/gamescene/uilayer/resources-iphonehd/sprite.pvr.gz   (if not found, search next)
---internal_dir/gamescene/uilayer/sprite.pvr.gz                      (if not found, return "gamescene/uilayer/sprite.png")
---If the new file can't be found on the file system, it will return the parameter filename directly.
---This method was added to simplify multiplatform support. Whether you are using cocos2d-js or any cross-compilation toolchain like StellaSDK or Apportable,
---you might need to load different resources for a given file in the different platforms.
---\since v2.1
---@param filename string
---@return string
function FileUtils:fullPathForFilename(filename) end

---Gets full path from a file name and the path of the relative file.
---@param filename string # The file name.
---@param relativeFile string # The path of the relative file.
---@return string # The full path.
---e.g. filename: hello.png, pszRelativeFile: /User/path1/path2/hello.plist
---Return: /User/path1/path2/hello.pvr (If there a a key(hello.png)-value(hello.pvr) in FilenameLookup dictionary. )
function FileUtils:fullPathFromRelativeFile(filename, relativeFile) end

---@param filename string
---@param buffer cc.ResizableBuffer
---@return cc.FileUtils.Status
function FileUtils:getContents(filename, buffer) end

---Creates binary data from a file.
---@return any # A data object.
---@param filename string
---
---Gets a binary data object from a file, async off the main cocos thread.
---
---\param filename filepath for the data to be read. Can be relative or absolute path
---\param callback Function that will be called when file is read. Will be called 
---on the main cocos thread.
---@overload fun(self: cc.FileUtils, filename: string, callback: fun(arg1: any))
function FileUtils:getDataFromFile(filename) end

---Get default resource root path.
---@return string
function FileUtils:getDefaultResourceRootPath() end

---Gets resource file data from a zip file.
---
---\param[in]  filename The resource file name which contains the relative path of the zip file.
---\param[out] size If the file read operation succeeds, it will be the data size, otherwise 0.
---@return string # Upon success, a pointer to the data is returned, otherwise nullptr.
---\warning Recall: you are responsible for calling free() on any Non-nullptr pointer returned.
---@param zipFilePath string
---@param filename string
---@param size olua.ssize_t
---@overload fun(obj: cc.FileUtils, zipPath: string, name: string): any
function FileUtils:getFileDataFromZip(zipFilePath, filename, size) end

---Gets filename extension is a suffix (separated from the base filename by a dot) in lower case.
---Examples of filename extensions are .png, .jpeg, .exe, .dmg and .txt.
---@param filePath string # The path of the file, it could be a relative or absolute path.
---@return string # suffix for filename in lower case or empty if a dot not found.
function FileUtils:getFileExtension(filePath) end

---Retrieve the file size.
---
---\note If a relative path was passed in, it will be inserted a default root path at the beginning.
---@param filepath string # The path of the file, it could be a relative or absolute path.
---@return integer # The file size.
---
---Retrieve the file size, async off the main cocos thread.
---
---\note If a relative path was passed in, it will be inserted a default root path at the beginning.
---\param filepath The path of the file, it could be a relative or absolute path.
---\param callback The function that will be called when the operation is complete. Will have one long
---argument, the file size.
---@overload fun(self: cc.FileUtils, filepath: string, callback: fun(arg1: integer))
function FileUtils:getFileSize(filepath) end

---Returns the full path cache.
---@return { [string]: string }
function FileUtils:getFullPathCache() end

---Gets the instance of FileUtils.
---@return cc.FileUtils
function FileUtils.getInstance() end

---Gets the new filename from the filename lookup dictionary.
---It is possible to have a override names.
---@param filename string # The original filename.
---@return string # The new filename after searching in the filename lookup dictionary.
---If the original filename wasn't in the dictionary, it will return the original filename.
function FileUtils:getNewFilename(filename) end

---Gets the original search path array set by 'setSearchPaths' or 'addSearchPath'.
---@return string[] # The array of the original search paths
function FileUtils:getOriginalSearchPaths() end

---Gets the array of search paths.
---
---@return string[] # The array of search paths which may contain the prefix of default resource root path. 
---\note In best practise, getter function should return the value of setter function passes in.
---But since we should not break the compatibility, we keep using the old logic. 
---Therefore, If you want to get the original search paths, please call 'getOriginalSearchPaths()' instead.
---\see fullPathForFilename(const char*).
---\lua NA
function FileUtils:getSearchPaths() end

---Gets the array that contains the search order of the resources.
---
---\see setSearchResolutionsOrder(const std::vector<std::string>&), fullPathForFilename(const char*).
---\since v2.1
---\lua NA
---@return string[]
function FileUtils:getSearchResolutionsOrder() end

---Gets string from a file.
---@param filename string
---@return string
---
---Gets string from a file, async off the main cocos thread
---
---\param path filepath for the string to be read. Can be relative or absolute path
---\param callback Function that will be called when file is read. Will be called 
---on the main cocos thread.
---@overload fun(self: cc.FileUtils, path: string, callback: fun(arg1: string))
function FileUtils:getStringFromFile(filename) end

---Windows fopen can't support UTF-8 filename
---Need convert all parameters fopen and other 3rd-party libs
---
---@param filenameUtf8 string # std::string name file for conversion from utf-8
---@return string # std::string ansi filename in current locale
function FileUtils:getSuitableFOpen(filenameUtf8) end

---Converts the contents of a file to a ValueMap.
---This method is used internally.
---@param filedata string
---@param filesize integer
---@return any
function FileUtils:getValueMapFromData(filedata, filesize) end

---Converts the contents of a file to a ValueMap.
---@param filename string # The filename of the file to gets content.
---@return any # ValueMap of the file contents.
---\note This method is used internally.
function FileUtils:getValueMapFromFile(filename) end

---@param filename string
---@return any
function FileUtils:getValueVectorFromFile(filename) end

---Gets the writable path.
---@return string # The path that can be write/read a file in
function FileUtils:getWritablePath() end

---Checks whether the path is an absolute path.
---
---\note On Android, if the parameter passed in is relative to "assets/", this method will treat it as an absolute path.
---Also on Blackberry, path starts with "app/native/Resources/" is treated as an absolute path.
---
---@param path string # The path that needs to be checked.
---@return boolean # True if it's an absolute path, false if not.
function FileUtils:isAbsolutePath(path) end

---Checks whether the path is a directory.
---
---@param dirPath string # The path of the directory, it could be a relative or an absolute path.
---@return boolean # True if the directory exists, false if not.
---
---Checks whether the absoulate path is a directory, async off of the main cocos thread.
---
---\param dirPath The path of the directory, it must be an absolute path
---\param callback that will accept a boolean, true if the file exists, false otherwise. 
---Callback will happen on the main cocos thread.
---@overload fun(self: cc.FileUtils, fullPath: string, callback: fun(arg1: boolean))
function FileUtils:isDirectoryExist(dirPath) end

---Checks whether a file exists.
---
---\note If a relative path was passed in, it will be inserted a default root path at the beginning.
---@param filename string # The path of the file, it could be a relative or absolute path.
---@return boolean # True if the file exists, false if not.
---
---Checks if a file exists, done async off the main cocos thread.
---
---Use this function if you need to check if a file exists while not blocking the main cocos thread.
---
---\note If a relative path was passed in, it will be inserted a default root path at the beginning.
---\param filename The path of the file, it could be a relative or absolute path.
---\param callback The function that will be called when the operation is complete. Will have one boolean
---argument, true if the file exists, false otherwise.
---@overload fun(self: cc.FileUtils, filename: string, callback: fun(arg1: boolean))
function FileUtils:isFileExist(filename) end

---Checks whether to pop up a message box when failed to load an image.
---@return boolean # True if pop up a message box when failed to load an image, false if not.
function FileUtils:isPopupNotify() end

---List all files in a directory.
---
---@param dirPath string # The path of the directory, it could be a relative or an absolute path.
---@return string[] # File paths in a string vector
function FileUtils:listFiles(dirPath) end

---List all files in a directory async, off of the main cocos thread.
---
---@param dirPath string # The path of the directory, it could be a relative or an absolute path.
---@param callback fun(arg1: string[]) # The callback to be called once the list operation is complete. Will be called on the main cocos thread.
---\js NA
---\lua NA
function FileUtils:listFilesAsync(dirPath, callback) end

---List all files recursively in a directory.
---
---@param dirPath string # The path of the directory, it could be a relative or an absolute path.
---\return File paths in a string vector
---@param files cc.types.VectorString
function FileUtils:listFilesRecursively(dirPath, files) end

---List all files recursively in a directory, async off the main cocos thread.
---
---@param dirPath string # The path of the directory, it could be a relative or an absolute path.
---@param callback fun(arg1: string[]) # The callback to be called once the list operation is complete. 
---Will be called on the main cocos thread.
---\js NA
---\lua NA
function FileUtils:listFilesRecursivelyAsync(dirPath, callback) end

---Loads the filenameLookup dictionary from the contents of a filename.
---
---\note The plist file name should follow the format below:
---
---\code
---<?xml version="1.0" encoding="UTF-8"?>
---<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
---<plist version="1.0">
---<dict>
---<key>filenames</key>
---<dict>
---<key>sounds/click.wav</key>
---<string>sounds/click.caf</string>
---<key>sounds/endgame.wav</key>
---<string>sounds/endgame.caf</string>
---<key>sounds/gem-0.wav</key>
---<string>sounds/gem-0.caf</string>
---</dict>
---<key>metadata</key>
---<dict>
---<key>version</key>
---<integer>1</integer>
---</dict>
---</dict>
---</plist>
---\endcode
---@param filename string # The plist file name.
---
---\since v2.1
---\js loadFilenameLookup
---\lua loadFilenameLookup
function FileUtils:loadFilenameLookupDictionaryFromFile(filename) end

---Purges full path caches.
function FileUtils:purgeCachedEntries() end

---Removes a directory.
---
---@param dirPath string # The full path of the directory, it must be an absolute path.
---@return boolean # True if the directory have been removed successfully, false if not.
---
---Removes a directory, async off the main cocos thread.
---
---\param dirPath the path of the directory, it must be an absolute path
---\param callback The function that will be called when the operation is complete. Will have one boolean
---argument, true if the directory was successfully removed, false otherwise.
---@overload fun(self: cc.FileUtils, dirPath: string, callback: fun(arg1: boolean))
function FileUtils:removeDirectory(dirPath) end

---Removes a file.
---
---@param filepath string # The full path of the file, it must be an absolute path.
---@return boolean # True if the file have been removed successfully, false if not.
---
---Removes a file, async off the main cocos thread.
---
---\param filepath the path of the file to remove, it must be an absolute path
---\param callback The function that will be called when the operation is complete. Will have one boolean
---argument, true if the file was successfully removed, false otherwise.
---@overload fun(self: cc.FileUtils, filepath: string, callback: fun(arg1: boolean))
function FileUtils:removeFile(filepath) end

---Renames a file under the given directory.
---
---@param path string # The parent directory path of the file, it must be an absolute path.
---@param oldname string # The current name of the file.
---@param name string # The new name of the file.
---@return boolean # True if the file have been renamed successfully, false if not.
---
---Renames a file under the given directory, async off the main cocos thread.
---
---\param path     The parent directory path of the file, it must be an absolute path.
---\param oldname  The current name of the file.
---\param name     The new name of the file.
---\param callback The function that will be called when the operation is complete. Will have one boolean
---argument, true if the file was successfully renamed, false otherwise.
---@overload fun(self: cc.FileUtils, path: string, oldname: string, name: string, callback: fun(arg1: boolean))
---
---Renames a file under the given directory.
---
---\param oldfullpath  The current fullpath of the file. Includes path and name.
---\param newfullpath  The new fullpath of the file. Includes path and name.
---\return True if the file have been renamed successfully, false if not.
---@overload fun(self: cc.FileUtils, oldfullpath: string, newfullpath: string): boolean
---
---Renames a file under the given directory, async off the main cocos thread.
---
---\param oldfullpath  The current fullpath of the file. Includes path and name.
---\param newfullpath  The new fullpath of the file. Includes path and name.
---\param callback The function that will be called when the operation is complete. Will have one boolean
---argument, true if the file was successfully renamed, false otherwise.
---@overload fun(self: cc.FileUtils, oldfullpath: string, newfullpath: string, callback: fun(arg1: boolean))
function FileUtils:renameFile(path, oldname, name) end

---Set default resource root path.
---@param path string
function FileUtils:setDefaultResourceRootPath(path) end

---You can inherit from platform dependent implementation of FileUtils, such as FileUtilsAndroid,
---and use this function to set delegate, then FileUtils will invoke delegate's implementation.
---For example, your resources are encrypted, so you need to decrypt it after reading data from
---resources, then you can implement all getXXX functions, and engine will invoke your own getXX
---functions when reading data of resources.
---
---If you don't want to system default implementation after setting delegate, you can just pass nullptr
---to this function.
---
---\warning It will delete previous delegate
---\lua NA
---@param delegate cc.FileUtils
function FileUtils.setDelegate(delegate) end

---Sets the filenameLookup dictionary.
---
---@param filenameLookupDict any # The dictionary for replacing filename.
---\since v2.1
function FileUtils:setFilenameLookupDictionary(filenameLookupDict) end

---Sets whether to pop-up a message box when failed to load an image.
---@param notify boolean
function FileUtils:setPopupNotify(notify) end

---Sets the array of search paths.
---
---You can use this array to modify the search path of the resources.
---If you want to use "themes" or search resources in the "cache", you can do it easily by adding new entries in this array.
---
---\note This method could access relative path and absolute path.
---If the relative path was passed to the vector, FileUtils will add the default resource directory before the relative path.
---For instance:
---On Android, the default resource root path is "assets/".
---If "/mnt/sdcard/" and "resources-large" were set to the search paths vector,
---"resources-large" will be converted to "assets/resources-large" since it was a relative path.
---
---@param searchPaths string[] # The array contains search paths.
---\see fullPathForFilename(const char*)
---\since v2.1
---In js:var setSearchPaths(var jsval);
---\lua NA
function FileUtils:setSearchPaths(searchPaths) end

---Sets the array that contains the search order of the resources.
---
---@param searchResolutionsOrder string[] # The source array that contains the search order of the resources.
---\see getSearchResolutionsOrder(), fullPathForFilename(const char*).
---\since v2.1
---In js:var setSearchResolutionsOrder(var jsval)
---\lua NA
function FileUtils:setSearchResolutionsOrder(searchResolutionsOrder) end

---Sets writable path.
---@param writablePath string
function FileUtils:setWritablePath(writablePath) end

---write Data into a file
---
---@param data any # the data want to save
---@param fullPath string # The full path to the file you want to save a string
---@return boolean # bool
---
---Write Data into a file, done async off the main cocos thread.
---
---Use this function if you need to write Data while not blocking the main cocos thread.
---
---This function takes Data by value on purpose, to leverage move sematics.
---If you want to avoid a copy of your data, use std::move/std::forward if appropriate
---
---\param data The data that will be written to disk
---\param fullPath The absolute file path that the data will be written to
---\param callback The function that will be called when data is written to disk. This
---function will be executed on the main cocos thread. It will have on boolean argument 
---signifying if the write was successful.
---@overload fun(self: cc.FileUtils, data: any, fullPath: string, callback: fun(arg1: boolean))
function FileUtils:writeDataToFile(data, fullPath) end

---write a string into a file
---
---@param dataStr string # the string want to save
---@param fullPath string # The full path to the file you want to save a string
---@return boolean # bool True if write success
---
---Write a string to a file, done async off the main cocos thread
---Use this function if you need file access without blocking the main thread.
---
---This function takes a std::string by value on purpose, to leverage move sematics.
---If you want to avoid a copy of your datastr, use std::move/std::forward if appropriate
---
---\param dataStr the string want to save
---\param fullPath The full path to the file you want to save a string
---\param callback The function called once the string has been written to a file. This
---function will be executed on the main cocos thread. It will have on boolean argument 
---signifying if the write was successful.
---@overload fun(self: cc.FileUtils, dataStr: string, fullPath: string, callback: fun(arg1: boolean))
function FileUtils:writeStringToFile(dataStr, fullPath) end

---write a ValueMap into a plist file
---
---@param dict any # the ValueMap want to save
---@param fullPath string # The full path to the file you want to save a string
---@return boolean # bool
function FileUtils:writeToFile(dict, fullPath) end

---write ValueMap into a plist file
---
---@param dict any # the ValueMap want to save
---@param fullPath string # The full path to the file you want to save a string
---@return boolean # bool
---
---Write a ValueMap into a file, done async off the main cocos thread.
---
---Use this function if you need to write a ValueMap while not blocking the main cocos thread.
---
---This function takes ValueMap by value on purpose, to leverage move sematics.
---If you want to avoid a copy of your dict, use std::move/std::forward if appropriate
---
---\param dict The ValueMap that will be written to disk
---\param fullPath The absolute file path that the data will be written to
---\param callback The function that will be called when dict is written to disk. This
---function will be executed on the main cocos thread. It will have on boolean argument 
---signifying if the write was successful.
---@overload fun(self: cc.FileUtils, dict: any, fullPath: string, callback: fun(arg1: boolean))
function FileUtils:writeValueMapToFile(dict, fullPath) end

---write ValueVector into a plist file
---
---@param vecData any # the ValueVector want to save
---@param fullPath string # The full path to the file you want to save a string
---@return boolean # bool
---
---Write a ValueVector into a file, done async off the main cocos thread.
---
---Use this function if you need to write a ValueVector while not blocking the main cocos thread.
---
---This function takes ValueVector by value on purpose, to leverage move sematics.
---If you want to avoid a copy of your dict, use std::move/std::forward if appropriate
---
---\param vecData The ValueVector that will be written to disk
---\param fullPath The absolute file path that the data will be written to
---\param callback The function that will be called when vecData is written to disk. This
---function will be executed on the main cocos thread. It will have on boolean argument 
---signifying if the write was successful.
---@overload fun(self: cc.FileUtils, vecData: any, fullPath: string, callback: fun(arg1: boolean))
function FileUtils:writeValueVectorToFile(vecData, fullPath) end

return FileUtils