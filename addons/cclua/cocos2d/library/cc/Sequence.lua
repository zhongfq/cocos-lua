---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Sequence

---\class Sequence
---Runs actions sequentially, one after another.
---@class cc.Sequence : cc.ActionInterval
local Sequence = {}

---Helper constructor to create an array of sequenceable actions.
---
---@return cc.Sequence # An autoreleased Sequence object.
---@param action1 cc.FiniteTimeAction
---@overload fun(action1: cc.FiniteTimeAction, action1__1: cc.FiniteTimeAction): cc.Sequence
---@overload fun(action1: cc.FiniteTimeAction, action1__1: cc.FiniteTimeAction, action1__2: cc.FiniteTimeAction): cc.Sequence
---@overload fun(action1: cc.FiniteTimeAction, action1__1: cc.FiniteTimeAction, action1__2: cc.FiniteTimeAction, action1__3: cc.FiniteTimeAction): cc.Sequence
---@overload fun(action1: cc.FiniteTimeAction, action1__1: cc.FiniteTimeAction, action1__2: cc.FiniteTimeAction, action1__3: cc.FiniteTimeAction, action1__4: cc.FiniteTimeAction): cc.Sequence
---@overload fun(action1: cc.FiniteTimeAction, action1__1: cc.FiniteTimeAction, action1__2: cc.FiniteTimeAction, action1__3: cc.FiniteTimeAction, action1__4: cc.FiniteTimeAction, action1__5: cc.FiniteTimeAction): cc.Sequence
---@overload fun(action1: cc.FiniteTimeAction, action1__1: cc.FiniteTimeAction, action1__2: cc.FiniteTimeAction, action1__3: cc.FiniteTimeAction, action1__4: cc.FiniteTimeAction, action1__5: cc.FiniteTimeAction, action1__6: cc.FiniteTimeAction): cc.Sequence
---@overload fun(action1: cc.FiniteTimeAction, action1__1: cc.FiniteTimeAction, action1__2: cc.FiniteTimeAction, action1__3: cc.FiniteTimeAction, action1__4: cc.FiniteTimeAction, action1__5: cc.FiniteTimeAction, action1__6: cc.FiniteTimeAction, action1__7: cc.FiniteTimeAction): cc.Sequence
---@overload fun(action1: cc.FiniteTimeAction, action1__1: cc.FiniteTimeAction, action1__2: cc.FiniteTimeAction, action1__3: cc.FiniteTimeAction, action1__4: cc.FiniteTimeAction, action1__5: cc.FiniteTimeAction, action1__6: cc.FiniteTimeAction, action1__7: cc.FiniteTimeAction, action1__8: cc.FiniteTimeAction): cc.Sequence
---@overload fun(action1: cc.FiniteTimeAction, action1__1: cc.FiniteTimeAction, action1__2: cc.FiniteTimeAction, action1__3: cc.FiniteTimeAction, action1__4: cc.FiniteTimeAction, action1__5: cc.FiniteTimeAction, action1__6: cc.FiniteTimeAction, action1__7: cc.FiniteTimeAction, action1__8: cc.FiniteTimeAction, action1__9: cc.FiniteTimeAction): cc.Sequence
---@overload fun(action1: cc.FiniteTimeAction, action1__1: cc.FiniteTimeAction, action1__2: cc.FiniteTimeAction, action1__3: cc.FiniteTimeAction, action1__4: cc.FiniteTimeAction, action1__5: cc.FiniteTimeAction, action1__6: cc.FiniteTimeAction, action1__7: cc.FiniteTimeAction, action1__8: cc.FiniteTimeAction, action1__9: cc.FiniteTimeAction, action1__10: cc.FiniteTimeAction): cc.Sequence
---@overload fun(action1: cc.FiniteTimeAction, action1__1: cc.FiniteTimeAction, action1__2: cc.FiniteTimeAction, action1__3: cc.FiniteTimeAction, action1__4: cc.FiniteTimeAction, action1__5: cc.FiniteTimeAction, action1__6: cc.FiniteTimeAction, action1__7: cc.FiniteTimeAction, action1__8: cc.FiniteTimeAction, action1__9: cc.FiniteTimeAction, action1__10: cc.FiniteTimeAction, action1__11: cc.FiniteTimeAction): cc.Sequence
---@overload fun(action1: cc.FiniteTimeAction, action1__1: cc.FiniteTimeAction, action1__2: cc.FiniteTimeAction, action1__3: cc.FiniteTimeAction, action1__4: cc.FiniteTimeAction, action1__5: cc.FiniteTimeAction, action1__6: cc.FiniteTimeAction, action1__7: cc.FiniteTimeAction, action1__8: cc.FiniteTimeAction, action1__9: cc.FiniteTimeAction, action1__10: cc.FiniteTimeAction, action1__11: cc.FiniteTimeAction, action1__12: cc.FiniteTimeAction): cc.Sequence
---@overload fun(action1: cc.FiniteTimeAction, action1__1: cc.FiniteTimeAction, action1__2: cc.FiniteTimeAction, action1__3: cc.FiniteTimeAction, action1__4: cc.FiniteTimeAction, action1__5: cc.FiniteTimeAction, action1__6: cc.FiniteTimeAction, action1__7: cc.FiniteTimeAction, action1__8: cc.FiniteTimeAction, action1__9: cc.FiniteTimeAction, action1__10: cc.FiniteTimeAction, action1__11: cc.FiniteTimeAction, action1__12: cc.FiniteTimeAction, action1__13: cc.FiniteTimeAction): cc.Sequence
---@overload fun(action1: cc.FiniteTimeAction, action1__1: cc.FiniteTimeAction, action1__2: cc.FiniteTimeAction, action1__3: cc.FiniteTimeAction, action1__4: cc.FiniteTimeAction, action1__5: cc.FiniteTimeAction, action1__6: cc.FiniteTimeAction, action1__7: cc.FiniteTimeAction, action1__8: cc.FiniteTimeAction, action1__9: cc.FiniteTimeAction, action1__10: cc.FiniteTimeAction, action1__11: cc.FiniteTimeAction, action1__12: cc.FiniteTimeAction, action1__13: cc.FiniteTimeAction, action1__14: cc.FiniteTimeAction): cc.Sequence
---@overload fun(action1: cc.FiniteTimeAction, action1__1: cc.FiniteTimeAction, action1__2: cc.FiniteTimeAction, action1__3: cc.FiniteTimeAction, action1__4: cc.FiniteTimeAction, action1__5: cc.FiniteTimeAction, action1__6: cc.FiniteTimeAction, action1__7: cc.FiniteTimeAction, action1__8: cc.FiniteTimeAction, action1__9: cc.FiniteTimeAction, action1__10: cc.FiniteTimeAction, action1__11: cc.FiniteTimeAction, action1__12: cc.FiniteTimeAction, action1__13: cc.FiniteTimeAction, action1__14: cc.FiniteTimeAction, action1__15: cc.FiniteTimeAction): cc.Sequence
---@overload fun(action1: cc.FiniteTimeAction, action1__1: cc.FiniteTimeAction, action1__2: cc.FiniteTimeAction, action1__3: cc.FiniteTimeAction, action1__4: cc.FiniteTimeAction, action1__5: cc.FiniteTimeAction, action1__6: cc.FiniteTimeAction, action1__7: cc.FiniteTimeAction, action1__8: cc.FiniteTimeAction, action1__9: cc.FiniteTimeAction, action1__10: cc.FiniteTimeAction, action1__11: cc.FiniteTimeAction, action1__12: cc.FiniteTimeAction, action1__13: cc.FiniteTimeAction, action1__14: cc.FiniteTimeAction, action1__15: cc.FiniteTimeAction, action1__16: cc.FiniteTimeAction): cc.Sequence
---
---Helper constructor to create an array of sequenceable actions given an array.
---\code
---When this function bound to the js or lua,the input params changed
---in js  :var   create(var   object1,var   object2, ...)
---in lua :local create(local object1,local object2, ...)
---\endcode
---
---\param arrayOfActions An array of sequenceable actions.
---\return An autoreleased Sequence object.
---@overload fun(arrayOfActions: any): cc.Sequence
function Sequence.create(action1) end

---Creates the action.
---@param actionOne cc.FiniteTimeAction # The first sequenceable action.
---@param actionTwo cc.FiniteTimeAction # The second sequenceable action.
---@return cc.Sequence # An autoreleased Sequence object.
---\js NA
function Sequence.createWithTwoActions(actionOne, actionTwo) end

return Sequence