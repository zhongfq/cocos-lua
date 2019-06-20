local cls = class()
cls.CPPCLS = "cocos2d::GLProgramCache"
cls.LUACLS = "cc.GLProgramCache"
cls.SUPERCLS = "cc.Ref"
cls.funcs [[
    static GLProgramCache* getInstance()
    static void destroyInstance()
    void loadDefaultGLPrograms()
    void reloadDefaultGLPrograms()
    GLProgram * getGLProgram(const std::string &key)
    void addGLProgram(GLProgram* program, const std::string &key)
    void reloadDefaultGLProgramsRelativeToLights()
]]
cls.props [[
    instance
]]
return cls