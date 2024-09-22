---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.filesystem

---
---@class cclua.filesystem 
---@field builtinCacheDirectory string 
---@field cacheDirectory string 
---@field documentDirectory string 
---@field sdCardDirectory string 
---@field tmpDirectory string 
---@field writablePath string 
local filesystem = {}

---@return any
function filesystem:__gc() end

---@param path string
---@param front boolean
---@overload fun(path: string)
function filesystem.addSearchPath(path, front) end

---@param srcPath string
---@param destPath string
---@return boolean
function filesystem.copy(srcPath, destPath) end

---@param path string
---@param isFilePath boolean
---@return boolean
---@overload fun(path: string): boolean
function filesystem.createDirectory(path, isFilePath) end

---@param path string
---@return boolean
function filesystem.exist(path) end

---@param path string
---@return string
function filesystem.fullPath(path) end

---@return string
function filesystem.getBuiltinCacheDirectory() end

---@return string
function filesystem.getCacheDirectory() end

---@return string
function filesystem.getDocumentDirectory() end

---@return string
function filesystem.getSDCardDirectory() end

---@return string
function filesystem.getTmpDirectory() end

---@return string
function filesystem.getWritablePath() end

---@param path string
---@return boolean
function filesystem.isAbsolutePath(path) end

---@param path string
---@return boolean
function filesystem.isDirectory(path) end

---@param path string
---@return boolean
function filesystem.isFile(path) end

---@param path string
---@return any
function filesystem.read(path) end

---@param path string
---@return boolean
function filesystem.remove(path) end

---@param oldPath string
---@param newPath string
---@return boolean
function filesystem.rename(oldPath, newPath) end

---@param path string
---@param limit integer
---@return string
---@overload fun(path: string): string
function filesystem.trimPath(path, limit) end

---@param path string
---@param dest string
---@return boolean
function filesystem.unzip(path, dest) end

---@param path string
---@param data string
---@param len integer
---@return boolean
---@overload fun(path: string, data: any): boolean
function filesystem.write(path, data, len) end

return filesystem