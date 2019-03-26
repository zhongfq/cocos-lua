local cls = class()
cls.CPPCLS = "cocos2d::GLProgram"
cls.LUACLS = "cc.GLProgram"
cls.SUPERCLS = "cc.Ref"
cls.funcs [[
    static GLProgram* createWithByteArrays(const GLchar* vShaderByteArray, const GLchar* fShaderByteArray)
    static GLProgram* createWithByteArrays(const GLchar* vShaderByteArray, const GLchar* fShaderByteArray, const std::string& compileTimeDefines)
    static GLProgram* createWithByteArrays(const GLchar* vShaderByteArray, const GLchar* fShaderByteArray, const std::string& compileTimeHeaders, const std::string& compileTimeDefines)
    static GLProgram* createWithFilenames(const std::string& vShaderFilename, const std::string& fShaderFilename)
    static GLProgram* createWithFilenames(const std::string& vShaderFilename, const std::string& fShaderFilename, const std::string& compileTimeDefines)
    static GLProgram* createWithFilenames(const std::string& vShaderFilename, const std::string& fShaderFilename, const std::string& compileTimeHeaders, const std::string& compileTimeDefines)
    Uniform* getUniform(const std::string& name)
    VertexAttrib* getVertexAttrib(const std::string& name)
    void bindAttribLocation(const std::string& attributeName, GLuint index)
    GLint getAttribLocation(const std::string& attributeName)
    GLint getUniformLocation(const std::string& attributeName)
    bool link()
    void use()
    void updateUniforms()
    GLint getUniformLocationForName(const char* name)
    void setUniformLocationWith1i(GLint location, GLint i1)
    void setUniformLocationWith2i(GLint location, GLint i1, GLint i2)
    void setUniformLocationWith3i(GLint location, GLint i1, GLint i2, GLint i3)
    void setUniformLocationWith4i(GLint location, GLint i1, GLint i2, GLint i3, GLint i4)
    // void setUniformLocationWith2iv(GLint location, GLint* ints, unsigned int numberOfArrays)
    // void setUniformLocationWith3iv(GLint location, GLint* ints, unsigned int numberOfArrays)
    // void setUniformLocationWith4iv(GLint location, GLint* ints, unsigned int numberOfArrays)
    void setUniformLocationWith1f(GLint location, GLfloat f1)
    void setUniformLocationWith2f(GLint location, GLfloat f1, GLfloat f2)
    void setUniformLocationWith3f(GLint location, GLfloat f1, GLfloat f2, GLfloat f3)
    void setUniformLocationWith4f(GLint location, GLfloat f1, GLfloat f2, GLfloat f3, GLfloat f4)
    // void setUniformLocationWith1fv(GLint location, const GLfloat* floats, unsigned int numberOfArrays)
    // void setUniformLocationWith2fv(GLint location, const GLfloat* floats, unsigned int numberOfArrays)
    // void setUniformLocationWith3fv(GLint location, const GLfloat* floats, unsigned int numberOfArrays)
    // void setUniformLocationWith4fv(GLint location, const GLfloat* floats, unsigned int numberOfArrays)
    // void setUniformLocationWithMatrix2fv(GLint location, const GLfloat* matrixArray, unsigned int numberOfMatrices)
    // void setUniformLocationWithMatrix3fv(GLint location, const GLfloat* matrixArray, unsigned int numberOfMatrices)
    // void setUniformLocationWithMatrix4fv(GLint location, const GLfloat* matrixArray, unsigned int numberOfMatrices)
    void setUniformsForBuiltins()
    void setUniformsForBuiltins(const Mat4 &modelView)
    void reset()
    std::string getVertexShaderLog()
    std::string getFragmentShaderLog()
    std::string getProgramLog()
    GLuint getProgram()
]]
cls.props [[
    vertexShaderLog
    fragmentShaderLog
    programLog
    program
]]
return cls