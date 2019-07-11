local typemod = require "olua.typemod"
local M = typemod 'exclude-type'

M.EXCLUDE_TYPE 'cocos2d::Console *'
M.EXCLUDE_TYPE 'cocos2d::Font *'
M.EXCLUDE_TYPE 'cocos2d::FontDefinition'
M.EXCLUDE_TYPE 'cocos2d::FontLetterDefinition'
M.EXCLUDE_TYPE 'cocos2d::GroupCommandManager *'
M.EXCLUDE_TYPE 'cocos2d::Mat4 *'
M.EXCLUDE_TYPE 'cocos2d::MipmapInfo *'
M.EXCLUDE_TYPE 'cocos2d::Physics3DWorld *'  -- TDDO
M.EXCLUDE_TYPE 'cocos2d::NavMesh *'         -- TDDO
M.EXCLUDE_TYPE 'cocos2d::PolygonInfo'
M.EXCLUDE_TYPE 'cocos2d::RenderCommand *'
M.EXCLUDE_TYPE 'cocos2d::SEL_SCHEDULE'
M.EXCLUDE_TYPE 'cocos2d::V3F_C4B_T2F_Quad *'
M.EXCLUDE_TYPE 'cocos2d::V3F_C4B_T2F_Quad'
M.EXCLUDE_TYPE 'cocos2d::IMEKeyboardNotificationInfo'
M.EXCLUDE_TYPE 'cocos2d::Vec2 *'
M.EXCLUDE_TYPE 'cocos2d::Vec3 *'            -- TODO
M.EXCLUDE_TYPE 'cocos2d::Vec4 *'
M.EXCLUDE_TYPE 'cocos2d::Tile *'
M.EXCLUDE_TYPE 'cocos2d::Grabber *'
M.EXCLUDE_TYPE 'float *'
M.EXCLUDE_TYPE 'GLfloat *'
M.EXCLUDE_TYPE 'unsigned int *'
M.EXCLUDE_TYPE 'GLint *'
M.EXCLUDE_TYPE 'int *'
M.EXCLUDE_TYPE 'int16_t *'
M.EXCLUDE_TYPE 'uint16_t *'

M.EXCLUDE_TYPE 'cpBody *'
M.EXCLUDE_TYPE 'cocos2d::PhysicsContactData *'

return M.EXCLUDE_TYPE