local shell = require "core.shell"

local function writeManifest(conf, name, shard)
    local manifestPath = conf.BUILD_PATH .. '/' .. name
    local hasUpdate = false
    local data = {}
    local function writeline(fmt, ...)
        data[#data + 1] = string.format(fmt, ...)
        data[#data + 1] = '\n'
    end

    table.sort(shard.assets, function (v1, v2)
        return v1.path < v2.path
    end)

    local latestManifest = shell.readManifest(conf.PUBLISH_PATH .. '/current/' .. name, conf)

    writeline('{')
    writeline('  "package_url":"%s",', shard.package_url)
    writeline('  "manifest_url":"%s",', shard.manifest_url)

    local assets = {}
    for _, entry in ipairs(shard.assets) do
        local latest = latestManifest.assets[entry.path]
        if not latest or latest.md5 ~= entry.md5 or latest.builtin ~= entry.builtin then
            hasUpdate = true
        else
            entry.date = latest.date
        end
        local t = {}
        t[#t + 1] = string.format('"md5":"%s"', entry.md5)
        t[#t + 1] = string.format('"date":%d', entry.date)
        t[#t + 1] = string.format('"builtin":%s', entry.builtin)
        assets[#assets + 1] = string.format('    "%s":{%s}', entry.path, table.concat(t, ', '))
        latestManifest.assets[entry.path] = nil
    end

    if hasUpdate or next(latestManifest.assets) then
        writeline('  "date":"%s",', os.date("!%Y-%m-%d %H:%M:%S", os.time() + 8 * 60 * 60))
        writeline('  "version":"%s",', shard.version)
    else
        writeline('  "date":"%s",', latestManifest.date)
        writeline('  "version":"%s",', latestManifest.version)
        print("update-to-date: " .. manifestPath)
    end

    writeline('  "assets": {')
    writeline(table.concat(assets, ',\n'))
    writeline('  }')
    writeline('}')

    shell.writeManifest(manifestPath, table.concat(data, ''), conf)
end

local function writeVersions(conf)
    local data = {}
    local function writeline(fmt, ...)
        data[#data + 1] = string.format(fmt, ...)
        data[#data + 1] = '\n'
    end

    local assets = {}
    for _, m in ipairs(conf.SHARDS) do
        local manifest = shell.readManifest(conf.BUILD_PATH .. '/' .. m.NAME .. '.metadata', conf)
        assets[#assets + 1] = shell.format [[
            {"name":"${m.NAME}", "url":"${manifest.manifest_url}", "version":"${manifest.version}"}
        ]]
    end

    assets = table.concat(assets, ',\n')
    shell.write(conf.VERSION_MANIFEST_PATH, shell.format [[
        {
            "runtime": "${conf.RUNTIME}",
            "assets": [
                ${assets}
            ]
        }
    ]])
end

return function (conf)
    print("start build shards:")

    local manifest = shell.readManifest(conf.ASSETS_MANIFEST_PATH, conf)
    for _, m in ipairs(conf.SHARDS) do
        local shard = {
            assets = {},
            name = m.NAME,
            version = manifest.version,
            package_url = manifest.package_url,
            manifest_url = string.gsub(manifest.manifest_url, 'assets.metadata$', m.NAME .. '.metadata'),
        }
        for path, info in pairs(manifest.assets) do
            for p in string.gmatch(m.PATTERN, '[^;]+') do
                if string.match(path, p) then
                    info.path = path
                    shard.assets[#shard.assets + 1] = info
                    manifest.assets[path] = nil
                end
            end
        end
        writeManifest(conf, m.NAME .. '.metadata', shard)
    end

    if next(manifest.assets) then
        for path in pairs(manifest.assets) do
            print("no pattern for path: " .. path)
        end
        error("build sharding error")
    end

    writeVersions(conf)
end