local shell = require "core.shell"

local function writeManifest(conf, name, module)
    local manifestPath = conf.BUILD_PATH .. '/' .. name
    local hasUpdate = false
    local data = {}
    local function writeline(fmt, ...)
        data[#data + 1] = string.format(fmt, ...)
        data[#data + 1] = '\n'
    end

    table.sort(module.assets, function (v1, v2)
        return v1.path < v2.path
    end)

    local latestManifest = shell.readJson(conf.PUBLISH_PATH .. '/current/' .. name, {assets = {}})

    writeline('{')
    writeline('  "package_url":"%s",', module.package_url)
    writeline('  "manifest_url":"%s",', module.manifest_url)
    writeline('  "date":"%s",', os.date("!%Y-%m-%d %H:%M:%S", os.time() + 8 * 60 * 60))
    writeline('  "version":"%s",', module.version)

    local assets = {}
    for _, entry in ipairs(module.assets) do
        local latest = latestManifest.assets[entry.path]
        if not latest or latest.md5 ~= entry.md5 or latest.builtin ~= entry.builtin then
            hasUpdate = true
        else
            entry.date = latest.date
        end
        local t = {}
        t[#t + 1] = string.format('"md5":"%s"', entry.md5)
        t[#t + 1] = string.format('"date":"%s"', entry.date)
        t[#t + 1] = string.format('"builtin":%s', entry.builtin)
        assets[#assets + 1] = string.format('    "%s":{%s}', entry.path, table.concat(t, ', '))
        latestManifest.assets[entry.path] = nil
    end
    writeline('  "assets": {')
    writeline(table.concat(assets, ',\n'))
    writeline('  }')
    writeline('}')

    if hasUpdate or next(latestManifest.assets) then
        shell.write(manifestPath, table.concat(data, ''))
    else
        print("update-to-date: " .. manifestPath)
    end
end

local function writeVersions(conf)
    local data = {}
    local function writeline(fmt, ...)
        data[#data + 1] = string.format(fmt, ...)
        data[#data + 1] = '\n'
    end

    local t = {}
    for _, m in ipairs(conf.MODULES) do
        local manifest = shell.readJson(conf.BUILD_PATH .. '/' .. m.NAME .. '.manifest')
        t[#t + 1] = string.format('  "%s":{"url":"%s", "version":"%s"}',
            m.NAME, manifest.manifest_url, manifest.version)
    end

    writeline('{')
    writeline('%s', table.concat(t, ',\n'))
    writeline('}')
    shell.write(conf.BUILD_PATH .. '/version.manifest', table.concat(data, ''))
end

return function (conf)
    print("start build modules:")

    local manifest = shell.readJson(conf.ASSETS_MANIFEST_PATH)
    for _, m in ipairs(conf.MODULES) do
        local module = {
            assets = {},
            name = m.NAME,
            version = manifest.version,
            package_url = manifest.package_url,
            manifest_url = string.gsub(manifest.manifest_url, 'assets.manifest$', m.NAME .. '.manifest'),
        }
        for path, info in pairs(manifest.assets) do
            for p in string.gmatch(m.PATTERN, '[^;]+') do
                if string.match(path, p) then
                    info.path = path
                    module.assets[#module.assets + 1] = info
                    manifest.assets[path] = nil
                end
            end
        end
        writeManifest(conf, m.NAME .. '.manifest', module)
    end

    if next(manifest.assets) then
        for path in pairs(manifest.assets) do
            print("no pattern for path: " .. path)
        end
        error("build module error")
    end

    writeVersions(conf)
end