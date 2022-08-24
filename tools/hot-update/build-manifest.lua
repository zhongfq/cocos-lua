return function (conf)
    local toolset = require "toolset"
    local lfs   = require "lfs"
    local md5   = require "md5"

    print("start build manifest")
    print("  setting name: " .. conf.NAME)
    print("    build path: " .. conf.BUILD_PATH)
    print("  publish path: " .. (conf.PUBLISH_PATH))
    print("           url: " .. conf.URL)
    print("       version: " .. conf.VERSION)
    print("       runtime: " .. conf.RUNTIME)
    print("         debug: " .. tostring(conf.DEBUG))

    local ASSETS_PATH = conf.ASSETS_PATH
    local SHOULD_BUILD = conf.SHOULD_BUILD or function () return true end
    local IS_BUILTIN = conf.IS_BUILTIN or function () return false end

    local latestManifest = assert(conf.LATEST_MANIFEST)
    local currentManifest = {assets = {}}
    local newPaths = {}
    local hasUpdate = false

    for _, path in ipairs(toolset.list(ASSETS_PATH)) do
        if path == 'builtin.manifest' or not SHOULD_BUILD(path) then
            goto continue
        end

        local fullPath = ASSETS_PATH .. "/" .. path
        local modified = lfs.attributes(fullPath, "modification")
        local last = latestManifest.assets[path]
        local curr

        if conf.DEBUG and last and last.modified == modified then
            curr = {
                path = path,
                date = last.date,
                builtin = last.builtin,
                md5 = last.md5,
                modified = last.modified,
            }
        else
            curr = {
                path = path,
                date = os.time(),
                modified = modified,
                md5 = md5.sumhexa(fullPath, true),
            }
        end

        newPaths[path] = true

        currentManifest.assets[#currentManifest.assets + 1] = curr
        curr.builtin = IS_BUILTIN(path) and true or false
        if last and last.md5 == curr.md5 and last.builtin == curr.builtin then
            curr.date = last.date
        else
            print('update path: ' .. path)
            hasUpdate = true
        end

        ::continue::
    end

    for path in pairs(latestManifest.assets) do
        if not newPaths[path] then
            hasUpdate = true
            break
        end
    end

    if not hasUpdate then
        print("manifest is up-to-date")
    else
        table.sort(currentManifest.assets, function (v1, v2)
            return v1.path < v2.path
        end)

        local data = {}
        local function writeline(fmt, ...)
            data[#data + 1] = string.format(fmt, ...)
            data[#data + 1] = '\n'
        end

        writeline('{')
        writeline('  "package_url":"%s",', conf.URL .. '/assets')
        writeline('  "manifest_url":"%s",', conf.URL .. '/assets.manifest')
        writeline('  "date":"%s",', os.date("!%Y-%m-%d %H:%M:%S", os.time() + 8 * 60 * 60))
        writeline('  "version":"%s",', conf.VERSION)

        local assets = {}
        for _, entry in ipairs(currentManifest.assets) do
            local t = {}
            t[#t + 1] = string.format('"md5":"%s"', entry.md5)
            t[#t + 1] = string.format('"date":%d', entry.date)
            t[#t + 1] = string.format('"builtin":%s', entry.builtin)
            if conf.DEBUG then
                t[#t + 1] = string.format('"modified":%d', entry.modified)
            end
            assets[#assets + 1] = string.format('    "%s":{%s}', entry.path, table.concat(t, ', '))
        end
        writeline('  "assets": {')
        writeline(table.concat(assets, ',\n'))
        writeline('  }')
        writeline('}')

        toolset.write_manifest(conf.ASSETS_MANIFEST_PATH, table.concat(data, ''), conf)

        if conf.VERSION_MANIFEST_PATH then
            toolset.write(conf.VERSION_MANIFEST_PATH, toolset.format [[
                {
                    "runtime": "${conf.RUNTIME}",
                    "assets": [
                        {"name": "main", "url":"${conf.URL}/assets.manifest", "version":"${conf.VERSION}"}
                    ]
                }
            ]])
        end
    end

    return hasUpdate
end