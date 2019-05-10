return function (setting)
    local shell = require "core.shell"
    local cjson = require "cjson.safe"
    local lfs   = require "lfs"

    require "core.simulator"

    print("start build manifest")
    print("        setting name: " .. setting.NAME)
    print("        project path: " .. setting.PROJECT_PATH)
    print("           work path: " .. setting.WORK_PATH)
    print("         assets path: " .. setting.ASSETS_PATH)
    print("       manifest path: " .. setting.MANIFEST_PATH)
    print("  last manifest path: " .. setting.LAST_MANIFEST_PATH)
    print("         package url: " .. setting.PACKAGE_URL)
    print("        manifest url: " .. setting.MANIFEST_URL)
    print("             version: " .. setting.VERSION)
    print("               debug: " .. tostring(setting.DEBUG))

    local SHOULD_BUILD = setting.SHOULD_BUILD or function () return true end
    local IS_BUILTIN = setting.IS_BUILTIN or function () return false end

    local lastManifest = shell.exist(setting.LAST_MANIFEST_PATH) and cjson.decode(shell.read(setting.LAST_MANIFEST_PATH)) or {assets = {}}
    local currManifest = {assets = {}}
    local hasUpdate = false

    for _, path in ipairs(shell.list(setting.ASSETS_PATH)) do
        if path == 'src/builtin.manifest' or not SHOULD_BUILD(path) then
            goto continue
        end

        local fullPath = setting.ASSETS_PATH .. "/" .. path
        local modified = lfs.attributes(fullPath, "modification")
        local last = lastManifest.assets[path]
        local curr

        if DEBUG and last and last.modified == modified then
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
                md5 = shell.md5sum(fullPath),
            }
        end

        currManifest.assets[#currManifest.assets + 1] = curr
        curr.builtin = IS_BUILTIN(path) and true or false
        if last and last.md5 == curr.md5 and last.builtin == curr.builtin then
            curr.date = last.date
        else
            print('update path: ' .. path)
            hasUpdate = true
        end

        ::continue::
    end

    if not hasUpdate then
        print("manifest is up-to-date")
    else
        table.sort(currManifest.assets, function (v1, v2)
            return v1.path < v2.path
        end)

        local data = {}
        local function writeline(fmt, ...)
            data[#data + 1] = string.format(fmt, ...)
            data[#data + 1] = '\n'
        end

        writeline('{')
        writeline('  "package_url":"%s",', setting.PACKAGE_URL)
        writeline('  "manifest_url":"%s",', setting.MANIFEST_URL)
        writeline('  "date":"%s",', os.date("!%Y-%m-%d %H:%M:%S", os.time() + 8 * 60 * 60))
        writeline('  "version":"%s",', setting.VERSION)

        local assets = {}
        for _, entry in ipairs(currManifest.assets) do
            local t = {}
            t[#t + 1] = string.format('"md5":"%s"', entry.md5)
            t[#t + 1] = string.format('"date":"%s"', entry.date)
            t[#t + 1] = string.format('"builtin":%s', entry.builtin)
            if DEBUG then
                t[#t + 1] = string.format('"modified":%d', entry.modified)
            end
            assets[#assets + 1] = string.format('    "%s":{%s}', entry.path, table.concat(t, ', '))
        end
        writeline('  "assets": {')
        writeline(table.concat(assets, ',\n'))
        writeline('  }')
        writeline('}')
        shell.write(setting.MANIFEST_PATH, table.concat(data, ''))
    end
end