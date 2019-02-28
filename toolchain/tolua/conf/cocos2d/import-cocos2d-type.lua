REG_TYPE {
    NAME = 'cocos2d::Data', 
    CONV = "xluacv_$ACTION_ccdata",
}

REG_TYPE {
    NAME = 'cocos2d::UserDefault *',
    CONV = "xluacv_$ACTION_obj",
    LUACLS = function (name)
        name = string.gsub(name, "cocos2d::", "cc.")
        name = string.gsub(name, "[ *]*$", '')
        return name
    end
}

REG_TYPE {
    NAME = table.concat({
        'cocos2d::Ref *',
        'cocos2d::Node *',
    }, '|'),
    CONV = "xluacv_$ACTION_ccobj",
    LUACLS = function (name)
        name = string.gsub(name, "cocos2d::", "cc.")
        name = string.gsub(name, "[ *]*$", '')
        return name
    end
}