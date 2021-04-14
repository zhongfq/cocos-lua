//
// AUTO BUILD, DON'T MODIFY!
//
#ifndef __AUTO_GEN_LUA_COCOS2D_UI_H__
#define __AUTO_GEN_LUA_COCOS2D_UI_H__

#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "lua-bindings/LuaCocosAdapter.h"
#include "cclua/xlua.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ui/UIScrollViewBar.h"

int luaopen_cocos2d_ui(lua_State *L);

// cocos2d::ui::Widget::ccWidgetTouchCallback
bool olua_is_cocos2d_ui_Widget_ccWidgetTouchCallback(lua_State *L, int idx);
int olua_push_cocos2d_ui_Widget_ccWidgetTouchCallback(lua_State *L, const cocos2d::ui::Widget::ccWidgetTouchCallback *value);
void olua_check_cocos2d_ui_Widget_ccWidgetTouchCallback(lua_State *L, int idx, cocos2d::ui::Widget::ccWidgetTouchCallback *value);

// cocos2d::ui::Widget::ccWidgetClickCallback
bool olua_is_cocos2d_ui_Widget_ccWidgetClickCallback(lua_State *L, int idx);
int olua_push_cocos2d_ui_Widget_ccWidgetClickCallback(lua_State *L, const cocos2d::ui::Widget::ccWidgetClickCallback *value);
void olua_check_cocos2d_ui_Widget_ccWidgetClickCallback(lua_State *L, int idx, cocos2d::ui::Widget::ccWidgetClickCallback *value);

// cocos2d::ui::Widget::ccWidgetEventCallback
bool olua_is_cocos2d_ui_Widget_ccWidgetEventCallback(lua_State *L, int idx);
int olua_push_cocos2d_ui_Widget_ccWidgetEventCallback(lua_State *L, const cocos2d::ui::Widget::ccWidgetEventCallback *value);
void olua_check_cocos2d_ui_Widget_ccWidgetEventCallback(lua_State *L, int idx, cocos2d::ui::Widget::ccWidgetEventCallback *value);

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)
// cocos2d::ui::WebView::ccWebViewCallback
bool olua_is_cocos2d_ui_WebView_ccWebViewCallback(lua_State *L, int idx);
int olua_push_cocos2d_ui_WebView_ccWebViewCallback(lua_State *L, const cocos2d::ui::WebView::ccWebViewCallback *value);
void olua_check_cocos2d_ui_WebView_ccWebViewCallback(lua_State *L, int idx, cocos2d::ui::WebView::ccWebViewCallback *value);
#endif

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)
// cocos2d::ui::VideoPlayer::ccVideoPlayerCallback
bool olua_is_cocos2d_ui_VideoPlayer_ccVideoPlayerCallback(lua_State *L, int idx);
int olua_push_cocos2d_ui_VideoPlayer_ccVideoPlayerCallback(lua_State *L, const cocos2d::ui::VideoPlayer::ccVideoPlayerCallback *value);
void olua_check_cocos2d_ui_VideoPlayer_ccVideoPlayerCallback(lua_State *L, int idx, cocos2d::ui::VideoPlayer::ccVideoPlayerCallback *value);
#endif

// cocos2d::ui::TabControl::ccTabControlCallback
bool olua_is_cocos2d_ui_TabControl_ccTabControlCallback(lua_State *L, int idx);
int olua_push_cocos2d_ui_TabControl_ccTabControlCallback(lua_State *L, const cocos2d::ui::TabControl::ccTabControlCallback *value);
void olua_check_cocos2d_ui_TabControl_ccTabControlCallback(lua_State *L, int idx, cocos2d::ui::TabControl::ccTabControlCallback *value);

// cocos2d::ui::ScrollView::ccScrollViewCallback
bool olua_is_cocos2d_ui_ScrollView_ccScrollViewCallback(lua_State *L, int idx);
int olua_push_cocos2d_ui_ScrollView_ccScrollViewCallback(lua_State *L, const cocos2d::ui::ScrollView::ccScrollViewCallback *value);
void olua_check_cocos2d_ui_ScrollView_ccScrollViewCallback(lua_State *L, int idx, cocos2d::ui::ScrollView::ccScrollViewCallback *value);

// cocos2d::ui::ListView::ccListViewCallback
bool olua_is_cocos2d_ui_ListView_ccListViewCallback(lua_State *L, int idx);
int olua_push_cocos2d_ui_ListView_ccListViewCallback(lua_State *L, const cocos2d::ui::ListView::ccListViewCallback *value);
void olua_check_cocos2d_ui_ListView_ccListViewCallback(lua_State *L, int idx, cocos2d::ui::ListView::ccListViewCallback *value);

// cocos2d::ui::PageView::ccPageViewCallback
bool olua_is_cocos2d_ui_PageView_ccPageViewCallback(lua_State *L, int idx);
int olua_push_cocos2d_ui_PageView_ccPageViewCallback(lua_State *L, const cocos2d::ui::PageView::ccPageViewCallback *value);
void olua_check_cocos2d_ui_PageView_ccPageViewCallback(lua_State *L, int idx, cocos2d::ui::PageView::ccPageViewCallback *value);

// cocos2d::ui::RichText::OpenUrlHandler
bool olua_is_cocos2d_ui_RichText_OpenUrlHandler(lua_State *L, int idx);
int olua_push_cocos2d_ui_RichText_OpenUrlHandler(lua_State *L, const cocos2d::ui::RichText::OpenUrlHandler *value);
void olua_check_cocos2d_ui_RichText_OpenUrlHandler(lua_State *L, int idx, cocos2d::ui::RichText::OpenUrlHandler *value);

// cocos2d::ui::Slider::ccSliderCallback
bool olua_is_cocos2d_ui_Slider_ccSliderCallback(lua_State *L, int idx);
int olua_push_cocos2d_ui_Slider_ccSliderCallback(lua_State *L, const cocos2d::ui::Slider::ccSliderCallback *value);
void olua_check_cocos2d_ui_Slider_ccSliderCallback(lua_State *L, int idx, cocos2d::ui::Slider::ccSliderCallback *value);

// cocos2d::ui::TextField::ccTextFieldCallback
bool olua_is_cocos2d_ui_TextField_ccTextFieldCallback(lua_State *L, int idx);
int olua_push_cocos2d_ui_TextField_ccTextFieldCallback(lua_State *L, const cocos2d::ui::TextField::ccTextFieldCallback *value);
void olua_check_cocos2d_ui_TextField_ccTextFieldCallback(lua_State *L, int idx, cocos2d::ui::TextField::ccTextFieldCallback *value);

// cocos2d::ui::CheckBox::ccCheckBoxCallback
bool olua_is_cocos2d_ui_CheckBox_ccCheckBoxCallback(lua_State *L, int idx);
int olua_push_cocos2d_ui_CheckBox_ccCheckBoxCallback(lua_State *L, const cocos2d::ui::CheckBox::ccCheckBoxCallback *value);
void olua_check_cocos2d_ui_CheckBox_ccCheckBoxCallback(lua_State *L, int idx, cocos2d::ui::CheckBox::ccCheckBoxCallback *value);

// cocos2d::ui::RadioButton::ccRadioButtonCallback
bool olua_is_cocos2d_ui_RadioButton_ccRadioButtonCallback(lua_State *L, int idx);
int olua_push_cocos2d_ui_RadioButton_ccRadioButtonCallback(lua_State *L, const cocos2d::ui::RadioButton::ccRadioButtonCallback *value);
void olua_check_cocos2d_ui_RadioButton_ccRadioButtonCallback(lua_State *L, int idx, cocos2d::ui::RadioButton::ccRadioButtonCallback *value);

// cocos2d::ui::RadioButtonGroup::ccRadioButtonGroupCallback
bool olua_is_cocos2d_ui_RadioButtonGroup_ccRadioButtonGroupCallback(lua_State *L, int idx);
int olua_push_cocos2d_ui_RadioButtonGroup_ccRadioButtonGroupCallback(lua_State *L, const cocos2d::ui::RadioButtonGroup::ccRadioButtonGroupCallback *value);
void olua_check_cocos2d_ui_RadioButtonGroup_ccRadioButtonGroupCallback(lua_State *L, int idx, cocos2d::ui::RadioButtonGroup::ccRadioButtonGroupCallback *value);

#endif