local cls = class()
cls.CPPCLS = "cocos2d::GLProgramState"
cls.LUACLS = "cc.GLProgramState"
cls.SUPERCLS = "cc.Ref"
cls.funcs([[
    static GLProgramState* create(GLProgram* glprogram)
    static GLProgramState* getOrCreateWithGLProgram(GLProgram* glprogram)
    static GLProgramState* getOrCreateWithGLProgramName(const std::string& glProgramName )
    static GLProgramState* getOrCreateWithGLProgramName(const std::string& glProgramName, Texture2D* texture)
    static GLProgramState* getOrCreateWithShaders(const std::string& vertexShader, const std::string& fragShader, const std::string& compileTimeDefines)
    GLProgramState* clone()
    void apply(const Mat4& modelView)
    void applyGLProgram(const Mat4& modelView)
    void applyAttributes(bool applyAttribFlags = true)
    void applyUniforms()
    void setGLProgram(@ref(single glProgram) GLProgram* glprogram)
    @ref(single glProgram) GLProgram* getGLProgram()
    uint32_t getVertexAttribsFlags()
    ssize_t getVertexAttribCount()
    void setVertexAttribPointer(const std::string& name, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid *pointer)
    ssize_t getUniformCount()
    void setUniformInt(const std::string& uniformName, int value)
    void setUniformFloat(const std::string& uniformName, float value)
    // TODO void setUniformFloatv(const std::string& uniformName, ssize_t size, const float* pointer)
    void setUniformVec2(const std::string& uniformName, const Vec2& value)
    // TODO void setUniformVec2v(const std::string& uniformName, ssize_t size, const Vec2* pointer)
    void setUniformVec3(const std::string& uniformName, const Vec3& value)
    // TODO void setUniformVec3v(const std::string& uniformName, ssize_t size, const Vec3* pointer)
    void setUniformVec4(const std::string& uniformName, const Vec4& value)
    // TODO void setUniformVec4v(const std::string& uniformName, ssize_t size, const Vec4* pointer)
    void setUniformMat4(const std::string& uniformName, const Mat4& value)
    void setUniformTexture(const std::string& uniformName, Texture2D *texture)
    void setUniformInt(GLint uniformLocation, int value)
    void setUniformFloat(GLint uniformLocation, float value)
    // TODO void setUniformFloatv(GLint uniformLocation, ssize_t size, const float* pointer)
    void setUniformVec2(GLint uniformLocation, const Vec2& value)
    // TODO void setUniformVec2v(GLint uniformLocation, ssize_t size, const Vec2* pointer)
    void setUniformVec3(GLint uniformLocation, const Vec3& value)
    // TODO void setUniformVec3v(GLint uniformLocation, ssize_t size, const Vec3* pointer)
    void setUniformVec4(GLint uniformLocation, const Vec4& value)
    // TODO void setUniformVec4v(GLint uniformLocation, ssize_t size, const Vec4* pointer)
    void setUniformMat4(GLint uniformLocation, const Mat4& value)
    void setUniformTexture(GLint uniformLocation, Texture2D *texture)
    @ref(single nodeBinding) Node* getNodeBinding()
    void setNodeBinding(@ref(single nodeBinding) Node* node)
    void applyAutoBinding(const std::string& uniformName, const std::string& autoBinding)
    void setParameterAutoBinding(const std::string& uniformName, const std::string& autoBinding)
]])
cls.props [[
    glProgram
    nodeBinding
    vertexAttribsFlags
    vertexAttribCount
    uniformCount
]]

cls.callbacks [[
    void setVertexAttribCallback(const std::string& name, const std::function<void(VertexAttrib*)> &callback)
    void setUniformCallback(const std::string& uniformName, const std::function<void(GLProgram*, Uniform*)> &callback)
    void setUniformCallback(GLint uniformLocation, const std::function<void(GLProgram*, Uniform*)> &callback)
]]
return cls