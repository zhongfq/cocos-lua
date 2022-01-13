//
// AUTO BUILD, DON'T MODIFY!
//
#ifndef __AUTO_GEN_LUA_FAIRYGUI_H__
#define __AUTO_GEN_LUA_FAIRYGUI_H__

#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/xlua.h"
#include "FairyGUI.h"
#include "GLoader3D.h"
#include "tween/EaseManager.h"
#include "tween/GPath.h"
#include "display/FUISprite.h"
#include "utils/html/HtmlElement.h"
#include "utils/html/HtmlObject.h"
#include "utils/html/HtmlParser.h"

int luaopen_fairygui(lua_State *L);

// fairygui::Margin
int olua_push_fairygui_Margin(lua_State *L, const fairygui::Margin *value);
void olua_check_fairygui_Margin(lua_State *L, int idx, fairygui::Margin *value);
bool olua_is_fairygui_Margin(lua_State *L, int idx);
void olua_pack_fairygui_Margin(lua_State *L, int idx, fairygui::Margin *value);
int olua_unpack_fairygui_Margin(lua_State *L, const fairygui::Margin *value);
bool olua_canpack_fairygui_Margin(lua_State *L, int idx);

// fairygui::HtmlParseOptions
int olua_push_fairygui_HtmlParseOptions(lua_State *L, const fairygui::HtmlParseOptions *value);
void olua_check_fairygui_HtmlParseOptions(lua_State *L, int idx, fairygui::HtmlParseOptions *value);
bool olua_is_fairygui_HtmlParseOptions(lua_State *L, int idx);
void olua_pack_fairygui_HtmlParseOptions(lua_State *L, int idx, fairygui::HtmlParseOptions *value);
int olua_unpack_fairygui_HtmlParseOptions(lua_State *L, const fairygui::HtmlParseOptions *value);
bool olua_canpack_fairygui_HtmlParseOptions(lua_State *L, int idx);

// fairygui::TweenValue
int olua_push_fairygui_TweenValue(lua_State *L, const fairygui::TweenValue *value);
void olua_check_fairygui_TweenValue(lua_State *L, int idx, fairygui::TweenValue *value);
bool olua_is_fairygui_TweenValue(lua_State *L, int idx);
void olua_pack_fairygui_TweenValue(lua_State *L, int idx, fairygui::TweenValue *value);
int olua_unpack_fairygui_TweenValue(lua_State *L, const fairygui::TweenValue *value);
bool olua_canpack_fairygui_TweenValue(lua_State *L, int idx);

// fairygui::EventCallback
bool olua_is_fairygui_EventCallback(lua_State *L, int idx);
int olua_push_fairygui_EventCallback(lua_State *L, const fairygui::EventCallback *value);
void olua_check_fairygui_EventCallback(lua_State *L, int idx, fairygui::EventCallback *value);

// fairygui::InputProcessor::CaptureEventCallback
bool olua_is_fairygui_InputProcessor_CaptureEventCallback(lua_State *L, int idx);
int olua_push_fairygui_InputProcessor_CaptureEventCallback(lua_State *L, const fairygui::InputProcessor::CaptureEventCallback *value);
void olua_check_fairygui_InputProcessor_CaptureEventCallback(lua_State *L, int idx, fairygui::InputProcessor::CaptureEventCallback *value);

// fairygui::GTweener::GTweenCallback
bool olua_is_fairygui_GTweener_GTweenCallback(lua_State *L, int idx);
int olua_push_fairygui_GTweener_GTweenCallback(lua_State *L, const fairygui::GTweener::GTweenCallback *value);
void olua_check_fairygui_GTweener_GTweenCallback(lua_State *L, int idx, fairygui::GTweener::GTweenCallback *value);

// fairygui::GTweener::GTweenCallback0
bool olua_is_fairygui_GTweener_GTweenCallback0(lua_State *L, int idx);
int olua_push_fairygui_GTweener_GTweenCallback0(lua_State *L, const fairygui::GTweener::GTweenCallback0 *value);
void olua_check_fairygui_GTweener_GTweenCallback0(lua_State *L, int idx, fairygui::GTweener::GTweenCallback0 *value);

// fairygui::GList::ListItemRenderer
bool olua_is_fairygui_GList_ListItemRenderer(lua_State *L, int idx);
int olua_push_fairygui_GList_ListItemRenderer(lua_State *L, const fairygui::GList::ListItemRenderer *value);
void olua_check_fairygui_GList_ListItemRenderer(lua_State *L, int idx, fairygui::GList::ListItemRenderer *value);

// fairygui::GList::ListItemProvider
bool olua_is_fairygui_GList_ListItemProvider(lua_State *L, int idx);
int olua_push_fairygui_GList_ListItemProvider(lua_State *L, const fairygui::GList::ListItemProvider *value);
void olua_check_fairygui_GList_ListItemProvider(lua_State *L, int idx, fairygui::GList::ListItemProvider *value);

// fairygui::Transition::PlayCompleteCallback
bool olua_is_fairygui_Transition_PlayCompleteCallback(lua_State *L, int idx);
int olua_push_fairygui_Transition_PlayCompleteCallback(lua_State *L, const fairygui::Transition::PlayCompleteCallback *value);
void olua_check_fairygui_Transition_PlayCompleteCallback(lua_State *L, int idx, fairygui::Transition::PlayCompleteCallback *value);

// fairygui::Transition::TransitionHook
bool olua_is_fairygui_Transition_TransitionHook(lua_State *L, int idx);
int olua_push_fairygui_Transition_TransitionHook(lua_State *L, const fairygui::Transition::TransitionHook *value);
void olua_check_fairygui_Transition_TransitionHook(lua_State *L, int idx, fairygui::Transition::TransitionHook *value);

// fairygui::UIObjectFactory::GLoaderCreator
bool olua_is_fairygui_UIObjectFactory_GLoaderCreator(lua_State *L, int idx);
int olua_push_fairygui_UIObjectFactory_GLoaderCreator(lua_State *L, const fairygui::UIObjectFactory::GLoaderCreator *value);
void olua_check_fairygui_UIObjectFactory_GLoaderCreator(lua_State *L, int idx, fairygui::UIObjectFactory::GLoaderCreator *value);

// fairygui::UIObjectFactory::GComponentCreator
bool olua_is_fairygui_UIObjectFactory_GComponentCreator(lua_State *L, int idx);
int olua_push_fairygui_UIObjectFactory_GComponentCreator(lua_State *L, const fairygui::UIObjectFactory::GComponentCreator *value);
void olua_check_fairygui_UIObjectFactory_GComponentCreator(lua_State *L, int idx, fairygui::UIObjectFactory::GComponentCreator *value);

// fairygui::GTree::TreeNodeRenderFunction
bool olua_is_fairygui_GTree_TreeNodeRenderFunction(lua_State *L, int idx);
int olua_push_fairygui_GTree_TreeNodeRenderFunction(lua_State *L, const fairygui::GTree::TreeNodeRenderFunction *value);
void olua_check_fairygui_GTree_TreeNodeRenderFunction(lua_State *L, int idx, fairygui::GTree::TreeNodeRenderFunction *value);

// fairygui::GTree::TreeNodeWillExpandFunction
bool olua_is_fairygui_GTree_TreeNodeWillExpandFunction(lua_State *L, int idx);
int olua_push_fairygui_GTree_TreeNodeWillExpandFunction(lua_State *L, const fairygui::GTree::TreeNodeWillExpandFunction *value);
void olua_check_fairygui_GTree_TreeNodeWillExpandFunction(lua_State *L, int idx, fairygui::GTree::TreeNodeWillExpandFunction *value);

#endif