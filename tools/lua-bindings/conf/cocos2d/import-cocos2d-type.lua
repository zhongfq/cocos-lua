local function make_luacls(cppname)
    cppname = string.gsub(cppname, '^cocos2d::experimental::ui::', 'ccui.')
    cppname = string.gsub(cppname, '^cocos2d::experimental::', 'cc.')
    cppname = string.gsub(cppname, '^cocos2d::ui::', 'ccui.')
    cppname = string.gsub(cppname, "^cocos2d::", "cc.")
    cppname = string.gsub(cppname, "^CocosDenshion::", "cc.")
    cppname = string.gsub(cppname, "^spine::", "sp.")
    cppname = string.gsub(cppname, "^dragonBones::CC", "db.")
    cppname = string.gsub(cppname, "^dragonBones::", "db.")
    cppname = string.gsub(cppname, "::", ".")
    cppname = string.gsub(cppname, "[ *]*$", '')
    return cppname
end

local function make_auto_conv_func(cppname)
    cppname = string.gsub(cppname, '::', '_')
    cppname = string.gsub(cppname, '[ *]*$', '')
    return 'auto_luacv_$$_' .. cppname
end

local function make_manual_conv_func(cppname)
    cppname = string.gsub(cppname, '::', '_')
    cppname = string.gsub(cppname, '[ *]*$', '')
    return 'manual_luacv_$$_' .. cppname
end

REG_TYPE {
    TYPENAME = 'cocos2d::Data', 
    CONV_FUNC = make_manual_conv_func,
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = [[
        cocos2d::Vec2
        cocos2d::Point
    ]],
    CONV_FUNC = 'auto_luacv_$$_cocos2d_Vec2',
    INIT_VALUE = false,
    VARS = 2,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Vec3',
    CONV_FUNC = make_auto_conv_func,
    INIT_VALUE = false,
    VARS = 3,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Vec4',
    CONV_FUNC = make_auto_conv_func,
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Size',
    CONV_FUNC = make_auto_conv_func,
    INIT_VALUE = false,
    VARS = 2,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Rect',
    CONV_FUNC = make_manual_conv_func,
    VARS = 4,
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = 'cocos2d::ccBezierConfig',
    CONV_FUNC =  make_manual_conv_func,
    INIT_VALUE = false,
    VARS = 3,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Mat4',
    CONV_FUNC = make_manual_conv_func,
    INIT_VALUE = false,
    VALUE_TYPE = true,
}

REG_TYPE {
    TYPENAME = 'cocos2d::Vector',
    IS_ARRAY = true,
    CONV_FUNC = make_manual_conv_func,
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = [[
        cocos2d::Color3B
        cocos2d::Color4B
        cocos2d::Color4F
        cocos2d::Value
        cocos2d::ValueMap
        cocos2d::ValueVector
    ]],
    CONV_FUNC = make_manual_conv_func,
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = 'cocos2d::EventListener::ListenerID',
    INIT_VALUE = false,
    DECL_TYPE = 'std::string',
    CONV_FUNC = 'olua_$$_std_string',
}

REG_TYPE {
    TYPENAME = [[
        cocos2d::AffineTransform
        cocos2d::BlendFunc
        cocos2d::experimental::Viewport
        cocos2d::Quaternion
        cocos2d::ResourceData
        cocos2d::T2F_Quad
        cocos2d::Tex2F
        cocos2d::Texture2D::TexParams
        cocos2d::TTFConfig
        cocos2d::ui::Margin
        cocos2d::Uniform *
        cocos2d::VertexAttrib *
        GLContextAttrs
        cocos2d::Quad3
    ]],
    CONV_FUNC = make_auto_conv_func,
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = [[
        cocos2d::ui::CheckBox::EventType
        cocos2d::ui::EditBox::InputFlag
        cocos2d::ui::EditBox::InputMode
        cocos2d::ui::EditBox::KeyboardReturnType
        cocos2d::ui::EditBoxDelegate::EditBoxEndAction
        cocos2d::ui::Layout::BackGroundColorType
        cocos2d::ui::Layout::ClippingType
        cocos2d::ui::Layout::Type
        cocos2d::ui::LayoutComponent::HorizontalEdge
        cocos2d::ui::LayoutComponent::VerticalEdge
        cocos2d::ui::LayoutParameter::Type
        cocos2d::ui::LinearLayoutParameter::LinearGravity
        cocos2d::ui::ListView::EventType
        cocos2d::ui::ListView::Gravity
        cocos2d::ui::ListView::MagneticType
        cocos2d::ui::LoadingBar::Direction
        cocos2d::ui::PageView::EventType
        cocos2d::ui::PageView::TouchDirection
        cocos2d::ui::RadioButton::EventType
        cocos2d::ui::RadioButtonGroup::EventType
        cocos2d::ui::RelativeLayoutParameter::RelativeAlign
        cocos2d::ui::RichElement::Type
        cocos2d::ui::RichText::HorizontalAlignment
        cocos2d::ui::RichText::WrapMode
        cocos2d::ui::Scale9Sprite::RenderingType
        cocos2d::ui::Scale9Sprite::State
        cocos2d::ui::ScrollView::Direction
        cocos2d::ui::ScrollView::EventType
        cocos2d::ui::Slider::EventType
        cocos2d::ui::TabControl::Dock
        cocos2d::Touch::DispatchMode
        cocos2d::ui::TabControl::EventType
        cocos2d::ui::TabHeader::EventType
        cocos2d::ui::Text::Type
        cocos2d::ui::TextField::EventType
        cocos2d::ui::Widget::BrightStyle
        cocos2d::ui::Widget::FocusDirection
        cocos2d::ui::Widget::PositionType
        cocos2d::ui::Widget::SizeType
        cocos2d::ui::Widget::TextureResType
        cocos2d::ui::Widget::TouchEventType
        spAttachmentType
        spEventType
        dragonBones::AnimationFadeOutMode
        dragonBones::DisplayType
        dragonBones::OffsetMode
    ]],
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = "olua_$$_uint",
    VALUE_TYPE = true,
    LUACLS = make_luacls,
}

REG_TYPE {
    TYPENAME = [[
        
        cocos2d::ui::AbstractCheckButton *
        cocos2d::ui::Button *
        cocos2d::ui::CheckBox *
        cocos2d::ui::EditBox *
        cocos2d::ui::EditBoxDelegate *
        cocos2d::ui::HBox *
        cocos2d::ui::ImageView *
        cocos2d::ui::MaskLayout *
        cocos2d::ui::Layout *
        cocos2d::ui::LayoutComponent *
        cocos2d::ui::LayoutParameter *
        cocos2d::ui::LinearLayoutParameter *
        cocos2d::ui::ListView *
        cocos2d::ui::LoadingBar *
        cocos2d::ui::LuaEditBoxDelegate *
        cocos2d::ui::PageView *
        cocos2d::ui::PageViewIndicator *
        cocos2d::ui::RadioButton *
        cocos2d::ui::RadioButtonGroup *
        cocos2d::ui::RelativeBox *
        cocos2d::ui::RelativeLayoutParameter *
        cocos2d::ui::RichElement *
        cocos2d::ui::RichElementCustomNode *
        cocos2d::ui::RichElementImage *
        cocos2d::ui::RichElementNewLine *
        cocos2d::ui::RichElementText *
        cocos2d::ui::RichText *
        cocos2d::ui::Scale9Sprite *
        cocos2d::ui::ScrollView *
        cocos2d::ui::ScrollViewBar *
        cocos2d::ui::Slider *
        cocos2d::ui::TabControl *
        cocos2d::ui::TabHeader *
        cocos2d::ui::Text *
        cocos2d::ui::TextAtlas *
        cocos2d::ui::TextBMFont *
        cocos2d::ui::TextField *
        cocos2d::ui::UICCTextField *
        cocos2d::ui::VBox *
        cocos2d::ui::Widget *
        spine::SkeletonAnimation *
        spine::SkeletonRenderer *
        dragonBones::CCFactory *
        dragonBones::DragonBonesData *
        dragonBones::TextureAtlasData *
        dragonBones::CCArmatureDisplay *
        dragonBones::Armature *
        dragonBones::Animation *
        dragonBones::BaseObject *
        dragonBones::EventObject *
        dragonBones::BaseFactory *
        dragonBones::TransformObject *
        dragonBones::Slot *
        dragonBones::Bone *
        dragonBones::DragonBonesData *
        dragonBones::DisplayData *
        dragonBones::TextureAtlasData *
        dragonBones::TextureData *
        dragonBones::ArmatureData *
        dragonBones::SkinData *
        dragonBones::BoneData *
        dragonBones::SlotData *
        dragonBones::AnimationState *
        dragonBones::AnimationData *
        dragonBones::AnimationConfig *
        dragonBones::Armature *
        dragonBones::Animation *
        dragonBones::Point *
    ]],
    CONV_FUNC = "olua_$$_cppobj",
    LUACLS = make_luacls,
}

REG_TYPE {
    TYPENAME = [[
        spAnimation *
        spAnimationState *
        spAnimationStateData *
        spAtlas *
        spAttachment *
        spBone *
        spEvent *
        spEventData *
        spSkeleton *
        spSkeletonData *
        spSlot *
        spTrackEntry *
        spVertexEffect *
    ]],
    CONV_FUNC = "olua_$$_obj",
    LUACLS = function (name)
        name = string.gsub(name, 'sp', 'sp.')
        name = string.gsub(name, '[ *]+', '')
        return name
    end,
}
