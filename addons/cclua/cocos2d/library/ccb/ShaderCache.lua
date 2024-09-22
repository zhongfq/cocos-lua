---AUTO GENERATED, DO NOT MODIFY!
---@meta ccb.ShaderCache

---Create and reuse shader module.
---@class ccb.ShaderCache : cc.Ref
---@field instance ccb.ShaderCache returns the shared instance
local ShaderCache = {}

---purges the cache. It releases the retained instance.
function ShaderCache.destroyInstance() end

---returns the shared instance
---@return ccb.ShaderCache
function ShaderCache.getInstance() end

---Create a fragment shader module.
---If it is created before, then just return the cached shader module.
---@param shaderSource string # The source code of the shader.
---@return ccb.ShaderModule
function ShaderCache.newFragmentShaderModule(shaderSource) end

---Create a vertex shader module and add it to cache.
---If it is created before, then just return the cached shader module.
---@param shaderSource string # The source code of the shader.
---@return ccb.ShaderModule
function ShaderCache.newVertexShaderModule(shaderSource) end

---Remove all unused shaders.
function ShaderCache:removeUnusedShader() end

return ShaderCache