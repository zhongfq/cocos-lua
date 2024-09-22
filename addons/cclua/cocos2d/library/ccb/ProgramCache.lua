---AUTO GENERATED, DO NOT MODIFY!
---@meta ccb.ProgramCache

---Cache and reuse program object.
---@class ccb.ProgramCache : cc.Ref
---@field instance ccb.ProgramCache returns the shared instance
local ProgramCache = {}

---Add custom program to the cache.
---@param key string # Specifies the key used to store the program.
---@param program ccb.Program # Specifies the program to store in the cache.
function ProgramCache:addCustomProgram(key, program) end

---purges the cache. It releases the retained instance.
function ProgramCache.destroyInstance() end

---get built-in program
---@param type ccb.ProgramType
---@return ccb.Program
function ProgramCache:getBuiltinProgram(type) end

---Get custom program from cache.
---@param key string
---@return ccb.Program
function ProgramCache:getCustomProgram(key) end

---returns the shared instance
---@return ccb.ProgramCache
function ProgramCache.getInstance() end

---Remove all program objects from cache.
function ProgramCache:removeAllPrograms() end

---Remove a program object from cache.
---@param program ccb.Program # Specifies the program object to move.
function ProgramCache:removeProgram(program) end

---Remove all unused program objects from cache.
function ProgramCache:removeUnusedProgram() end

return ProgramCache