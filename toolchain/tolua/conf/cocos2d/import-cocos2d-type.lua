REG_TYPE {
    NAME = 'cocos2d::Data', 
    CONV = "xluacv_$ACTION_ccdata",
}

local function make_luacls(cppname)
    cppname = string.gsub(cppname, "cocos2d::", "cc.")
    cppname = string.gsub(cppname, "[ *]*$", '')
    return cppname
end

REG_TYPE {
    NAME = 'cocos2d::UserDefault *',
    CONV = "tolua_$ACTION_obj",
    LUACLS = make_luacls,
}

REG_TYPE {
    NAME = 'cocos2d::Vec2',
    CONV = "xluacv_$ACTION_ccvec2",
    INIT = false,
    VARS = 2,
}

REG_TYPE {
    NAME = table.concat({
        'cocos2d::Ref *',
        'cocos2d::Director *',
        'cocos2d::Node *',
        'cocos2d::Sprite *',
        'cocos2d::Scene *',
    }, '|'),
    CONV = "xluacv_$ACTION_ccobj",
    LUACLS = make_luacls,
}