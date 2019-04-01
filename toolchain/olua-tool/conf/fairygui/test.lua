for k in string.gmatch(io.popen('find fui -name "*.lua"'):read('*a'), '[^\n\r]+') do
    os.execute(string.format('mv %s %s', k, string.gsub(k, 'fgui', 'fui')))
end