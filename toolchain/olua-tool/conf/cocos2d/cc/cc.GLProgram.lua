local cls = class()
cls.CPPCLS = "cocos2d::GLProgram"
cls.LUACLS = "cc.GLProgram"
cls.SUPERCLS = "cc.Ref"
cls.prop('vertexShaderLog', 'std::string getVertexShaderLog()')
cls.prop('fragmentShaderLog', 'std::string getFragmentShaderLog()')
cls.prop('programLog', 'std::string getProgramLog()')
cls.prop('program', 'GLuint getProgram()')
cls.func(nil,
    'static GLProgram* createWithByteArrays(const GLchar* vShaderByteArray, const GLchar* fShaderByteArray)',
    'static GLProgram* createWithByteArrays(const GLchar* vShaderByteArray, const GLchar* fShaderByteArray, const std::string& compileTimeDefines)',
    'static GLProgram* createWithByteArrays(const GLchar* vShaderByteArray, const GLchar* fShaderByteArray, const std::string& compileTimeHeaders, const std::string& compileTimeDefines)')
cls.func(nil,
    'static GLProgram* createWithFilenames(const std::string& vShaderFilename, const std::string& fShaderFilename)',
    'static GLProgram* createWithFilenames(const std::string& vShaderFilename, const std::string& fShaderFilename, const std::string& compileTimeDefines)',
    'static GLProgram* createWithFilenames(const std::string& vShaderFilename, const std::string& fShaderFilename, const std::string& compileTimeHeaders, const std::string& compileTimeDefines)')
cls.func(nil, 'Uniform* getUniform(const std::string& name)')
cls.func(nil, 'VertexAttrib* getVertexAttrib(const std::string& name)')
cls.func(nil, 'void bindAttribLocation(const std::string& attributeName, GLuint index)')
cls.func(nil, 'GLint getAttribLocation(const std::string& attributeName)')
cls.func(nil, 'GLint getUniformLocation(const std::string& attributeName)')
cls.func(nil, 'bool link()')
cls.func(nil, 'void use()')
cls.func(nil, 'void updateUniforms()')
cls.func(nil, 'GLint getUniformLocationForName(const char* name)')
cls.func(nil, 'void setUniformLocationWith1i(GLint location, GLint i1)')
cls.func(nil, 'void setUniformLocationWith2i(GLint location, GLint i1, GLint i2)')
cls.func(nil, 'void setUniformLocationWith3i(GLint location, GLint i1, GLint i2, GLint i3)')
cls.func(nil, 'void setUniformLocationWith4i(GLint location, GLint i1, GLint i2, GLint i3, GLint i4)')
-- cls.func(nil, 'void setUniformLocationWith2iv(GLint location, GLint* ints, unsigned int numberOfArrays)')
-- cls.func(nil, 'void setUniformLocationWith3iv(GLint location, GLint* ints, unsigned int numberOfArrays)')
-- cls.func(nil, 'void setUniformLocationWith4iv(GLint location, GLint* ints, unsigned int numberOfArrays)')
cls.func(nil, 'void setUniformLocationWith1f(GLint location, GLfloat f1)')
cls.func(nil, 'void setUniformLocationWith2f(GLint location, GLfloat f1, GLfloat f2)')
cls.func(nil, 'void setUniformLocationWith3f(GLint location, GLfloat f1, GLfloat f2, GLfloat f3)')
cls.func(nil, 'void setUniformLocationWith4f(GLint location, GLfloat f1, GLfloat f2, GLfloat f3, GLfloat f4)')
-- cls.func(nil, 'void setUniformLocationWith1fv(GLint location, const GLfloat* floats, unsigned int numberOfArrays)')
-- cls.func(nil, 'void setUniformLocationWith2fv(GLint location, const GLfloat* floats, unsigned int numberOfArrays)')
-- cls.func(nil, 'void setUniformLocationWith3fv(GLint location, const GLfloat* floats, unsigned int numberOfArrays)')
-- cls.func(nil, 'void setUniformLocationWith4fv(GLint location, const GLfloat* floats, unsigned int numberOfArrays)')
-- cls.func(nil, 'void setUniformLocationWithMatrix2fv(GLint location, const GLfloat* matrixArray, unsigned int numberOfMatrices)')
-- cls.func(nil, 'void setUniformLocationWithMatrix3fv(GLint location, const GLfloat* matrixArray, unsigned int numberOfMatrices)')
-- cls.func(nil, 'void setUniformLocationWithMatrix4fv(GLint location, const GLfloat* matrixArray, unsigned int numberOfMatrices)')
cls.func(nil, 'void setUniformsForBuiltins()', 'void setUniformsForBuiltins(const Mat4 &modelView)')
cls.func(nil, 'void reset()')
return cls