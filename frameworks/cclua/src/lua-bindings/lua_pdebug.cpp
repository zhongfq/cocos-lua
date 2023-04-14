/****************************************************************************
Copyright (C) 2019 THL A29 Limited, a Tencent company. All rights reserved.
Licensed under the BSD 3-Clause License (the "License"); you may not use 
this file except in compliance with the License. You may obtain a copy of 
the License at
https://opensource.org/licenses/BSD-3-Clause
Unless required by applicable law or agreed to in writing, software 
distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the 
License for the specific language governing permissions and limitations 
under the License.
****************************************************************************/

#include "lua_pdebug.h"
#include <ctime>
#include <list>
#include <map>
#include <string>


#define LUA_DEBUGGER_NAME     "LuaPanda"    
#define HOOK_LIB_VERSION      "3.2.0"       
#define USE_SOURCE_CODE                        

static int cur_run_state = 0;       
static int cur_hook_state = 0;      
static int logLevel = 1;            
static int pathCaseSensitivity = 1; 
static int BPhit = 0;               
static int stackdeep_counter = 0;   
static char hookLog[1024] = { 0 };
const char* debug_file_path;        
int debug_file_path_len;
const char* tools_file_path;        
int tools_file_path_len;
char config_ext[32] = "";           
const char* config_cwd = "";        
const char* config_tempfile_path = "";
time_t recvMsgSeconds = 0;
const char* last_source;
int ar_current_line = 0;
int ar_def_line = 0;
int ar_lastdef_line = 0;
int bp_twice_check_res = 1;
int lua_debugger_ver = 0;             
struct path_transfer_node;
struct breakpoint;

std::list<path_transfer_node*> getinfo_to_format_cache;

std::map<std::string, std::map<int, breakpoint>> all_breakpoint_map;

enum run_state
{
    DISCONNECT = 0,
    WAIT_CMD = 1,
    STOP_ON_ENTRY = 2,
    RUN = 3,
    STEPOVER = 4,
    STEPIN = 5,
    STEPOUT = 6,
    STEPOVER_STOP = 7,
    STEPIN_STOP = 8,
    STEPOUT_STOP = 9,
    HIT_BREAKPOINT = 10
};

enum hook_state
{
    DISCONNECT_HOOK = 0,
    LITE_HOOK = 1,              
    MID_HOOK = 2,               
    ALL_HOOK = 3,
};

enum hook_event
{
    CALL = 0,
    RETURN = 1,
    LINE = 2,
    TAILRET = 4
};

enum breakpoint_type
{
    CONDITION_BREAKPOINT = 0,
    LOG_POINT,
    LINE_BREAKPOINT
};


struct path_transfer_node {
    std::string src;
    std::string dst;
    path_transfer_node(std::string _src, std::string _dst) {
        src = _src;
        dst = _dst;
    }
};


struct breakpoint {
    breakpoint_type type;
    std::string info;
};

struct debug_auto_stack {
    explicit debug_auto_stack(lua_State* l) {
        this->L = l;
        this->top = lua_gettop(L);
    }
    ~debug_auto_stack() {
        lua_settop(this->L, this->top);
    }
    lua_State* L;
    int top;
};


void debug_hook_c(lua_State* L, lua_Debug* ar);
void check_hook_state(lua_State* L, const char* source, int current_line, int def_line, int last_line, int event = -1);
void print_to_vscode(lua_State* L, const char* msg, int level = 0);


void print_all_breakpoint_map(lua_State* L, int print_level = 0) {
    if (print_level < logLevel) {
        return;
    }
    std::map<std::string, std::map<int, breakpoint>>::iterator iter1;
    std::map<int, breakpoint>::iterator iter2;
    std::string log_message = "[breakpoints in chook:]\n";
    for (iter1 = all_breakpoint_map.begin(); iter1 != all_breakpoint_map.end(); ++iter1) {
        log_message += iter1->first;
        log_message += '\n';
        for (iter2 = iter1->second.begin(); iter2 != iter1->second.end(); ++iter2) {
            log_message += std::string("    line: ");
            log_message += std::to_string(iter2->first);
            log_message += std::string("  type: ");
            switch (iter2->second.type) {
            case CONDITION_BREAKPOINT:
                log_message += std::string("condition breakpoint  info: ");
                log_message += iter2->second.info;
                break;

            case LOG_POINT:
                log_message += std::string("log point  info: ");
                log_message += iter2->second.info;
                break;

            case LINE_BREAKPOINT:
                log_message += std::string("line breakpoint  info: ");
                log_message += iter2->second.info;
                break;

            default:
                log_message += std::string("Invalid breakpoint type!");
                log_message += std::to_string(iter2->second.type);
                break;
            }
            log_message += '\n';
        }
    }
    print_to_vscode(L, log_message.c_str(), print_level);
}


template <typename T>
void push_arg(lua_State* L, T value);

template <>
void push_arg(lua_State* L, int value) {
    lua_pushnumber(L, value);
}

template <>
void push_arg(lua_State* L, double value) {
    lua_pushnumber(L, value);
}

template <>
void push_arg(lua_State* L, const char* value) {
    lua_pushstring(L, value);
}

void push_args(lua_State* L) {}


template <typename T>
void push_arg(lua_State* L, T value) {
    push_arg<T>(L, value);
}

template <typename T, typename ... ARGS>
void push_args(lua_State* L, T value, ARGS... args) {
    push_arg<T>(L, value);
    push_args(L, std::forward<ARGS>(args) ...);
}


template <typename ... ARGS>
int call_lua_function(lua_State* L, const char* lua_function_name, int retCount, ARGS... args) {
    lua_getglobal(L, LUA_DEBUGGER_NAME);
    if (!lua_istable(L, -1)) {
        const char* err_msg = "[C Module Error]:call_lua_function Get LUA_DEBUGGER_NAME error.\n";
        print_to_vscode(L, err_msg, 2);
        return -1;
    }

    lua_getfield(L, -1, lua_function_name);
    if (!lua_isfunction(L, -1)) {
        char err_msg[100];
        snprintf(err_msg, sizeof(err_msg), "[C Module Error]:call_lua_function Get lua function '%s' error\n.", lua_function_name);
        print_to_vscode(L, err_msg, 2);
        return -1;
    }

    push_args(L, args...);
    int err_code = lua_pcall(L, sizeof...(args), retCount, 0);
    if (err_code) {
        char err_msg[1024];
        const char* lua_error = lua_tostring(L, -1);
        snprintf(err_msg, sizeof(err_msg), "[C Module Error]:call_lua_function Call '%s' error. ErrorCode: %d, ErrorMessage: %s.\n", lua_function_name, err_code, lua_error);
        print_to_vscode(L, err_msg, 2);
        lua_pop(L, 1);
        return err_code;
    }

    return 0;
}




static int clear_pathcache(lua_State* L)
{
    getinfo_to_format_cache.clear();
    return 0;
}


static int get_libhook_state(lua_State* L)
{
    lua_pushnumber(L, cur_hook_state);
    return 1;
}


static int get_last_source(lua_State* L)
{
    lua_pushstring(L, last_source);
    return 1;
}


static int sync_lua_debugger_ver(lua_State* L)
{
    lua_debugger_ver = static_cast<int>(luaL_checkinteger(L, 1));
    return 0;
}


static int sync_bp_hit(lua_State* L) {
    if (cur_hook_state == DISCONNECT_HOOK) {
        
        return 0;
    }

    BPhit = static_cast<int>(luaL_checkinteger(L, 1));
    return 0;
}


static int sync_config(lua_State* L) {
    logLevel = static_cast<int>(luaL_checkinteger(L, 1));
    pathCaseSensitivity = static_cast<int>(luaL_checkinteger(L, 2));
    
    return 0;
}


static int sync_tempfile_path(lua_State* L) {
    config_tempfile_path = luaL_checkstring(L, 1);
    return 0;
}



static int set_bp_twice_check_res(lua_State* L) {
    bp_twice_check_res = luaL_checknumber(L, 1);
    return 0;
}


static int sync_getLibVersion(lua_State* L) {
    lua_pushstring(L, HOOK_LIB_VERSION);
    lua_pushnumber(L, LUA_VERSION_NUM);
    return 2;
}


static int sync_file_ext(lua_State* L) {
    const char* ext = luaL_checkstring(L, 1);
    snprintf(config_ext, sizeof(config_ext), ".%s", ext);
    return 0;
}


static int sync_debugger_path(lua_State* L) {
    debug_file_path = luaL_checkstring(L, 1);
    debug_file_path_len = (int)strlen(debug_file_path);
    return 0;
}


static int sync_tools_path(lua_State* L) {
    tools_file_path = luaL_checkstring(L, 1);
    tools_file_path_len = (int)strlen(tools_file_path);
    return 0;
}


static int sync_cwd(lua_State* L) {
    config_cwd = luaL_checkstring(L, 1);
    return 0;
}


void sync_runstate_toLua(lua_State* L, int state) {
    debug_auto_stack _tt(L);
    cur_run_state = state;
    call_lua_function(L, "changeRunState", 0, state, 1);
    return;
}


static int lua_set_runstate(lua_State* L) {
    cur_run_state = static_cast<int>(luaL_checkinteger(L, 1));
    return 0;
}


void sethookstate(lua_State* L, int state) {
    cur_hook_state = state;
    switch (state) {
    case DISCONNECT_HOOK:
        lua_sethook(L, debug_hook_c, LUA_MASKRET, 1000000);
        break;
    case LITE_HOOK:
        lua_sethook(L, debug_hook_c, LUA_MASKRET, 0);
        break;
    case MID_HOOK:
        lua_sethook(L, debug_hook_c, LUA_MASKCALL | LUA_MASKRET, 0);
        break;
    case ALL_HOOK:
        lua_sethook(L, debug_hook_c, LUA_MASKCALL | LUA_MASKRET | LUA_MASKLINE, 0);
        break;
    }
}


static int lua_set_hookstate(lua_State* L) {
    cur_hook_state = static_cast<int>(luaL_checkinteger(L, 1));
    sethookstate(L, cur_hook_state);
    return 0;
}

void print_to_vscode(lua_State* L, const char* msg, int level) {
    if (DISCONNECT != cur_run_state && level >= logLevel) {
        
        call_lua_function(L, "printToVSCode", 0, msg, level);
    }
}


const char* getPath(lua_State* L, const char* source) {
    debug_auto_stack _tt(L);

    if (source == nullptr) {
        print_to_vscode(L, "[C Module Error]: getPath Exception: source == nullptr", 2);
        return "";
    }

    
    for (auto iter = getinfo_to_format_cache.begin(); iter != getinfo_to_format_cache.end(); iter++)
    {
        if (!strcmp((*iter)->src.c_str(), source)) {
            return (*iter)->dst.c_str();
        }
    }

    
    int lua_ret = call_lua_function(L, "getPath", 1, source);
    if (lua_ret != 0) {
        return "";
    }
    const char* retSource = lua_tostring(L, -1);
    
    path_transfer_node* nd = new path_transfer_node(source, retSource);
    getinfo_to_format_cache.push_back(nd);

    return retSource;
}


const int checkRealHitBreakpoint(lua_State* L, const char* source, int line) {
    debug_auto_stack _tt(L);

    if (source == nullptr) {
        print_to_vscode(L, "[C Module Error]: checkRealHitBreakpoint Exception: source == nullptr", 2);
        return 0;
    }

    
    int lua_ret = call_lua_function(L, "checkRealHitBreakpoint", 1, source, line);
    if (lua_ret != 0) {
        return 0;
    }
    int realHit = lua_toboolean(L, -1);
    return realHit;
}


static int sync_breakpoints(lua_State* L) {
    debug_auto_stack _tt(L);
    
    lua_getglobal(L, LUA_DEBUGGER_NAME);     
    if (!lua_istable(L, -1)) {
        print_to_vscode(L, "[C Module Error] debug_ishit_bk get LUA_DEBUGGER_NAME error", 2);
        return -1;
    }

    lua_getfield(L, -1, "breaks");
    if (!lua_istable(L, -1)) {
        print_to_vscode(L, "[C Module Error] debug_ishit_bk get breaks error", 2);
        return -1;
    }

    
    all_breakpoint_map.clear();
    lua_pushnil(L);
    while (lua_next(L, -2)) {
        
        const char* source = luaL_checkstring(L, -2);

        std::map<int, breakpoint> file_breakpoint_map;
        lua_pushnil(L);
        while (lua_next(L, -2)) {
            if (lua_debugger_ver >= 30150) {
                lua_pushnil(L);
                while (lua_next(L, -2)) {
                    
                    lua_getfield(L, -1, "line");            
                    int line = (int)lua_tointeger(L, -1);
                    lua_pop(L, 1); 

                    lua_getfield(L, -1, "type");
                    int type = (int)lua_tointeger(L, -1);
                    lua_pop(L, 1); 

                    struct breakpoint bp;
                    switch (type) {
                    case CONDITION_BREAKPOINT: {
                        bp.type = CONDITION_BREAKPOINT;

                        lua_getfield(L, -1, "condition");
                        const char* condition = luaL_checkstring(L, -1);
                        lua_pop(L, 1); 
                        bp.info = condition;
                        break;
                    }

                    case LOG_POINT: {
                        bp.type = LOG_POINT;

                        lua_getfield(L, -1, "logMessage");
                        const char* log_message = luaL_checkstring(L, -1);
                        lua_pop(L, 1); 
                        bp.info = log_message;
                        break;
                    }

                    case LINE_BREAKPOINT:
                        bp.type = LINE_BREAKPOINT;

                        bp.info = std::to_string(line);
                        break;

                    default:
                        print_to_vscode(L, "[C Module Error] Invalid breakpoint type!", 2);
                        return -1;
                    }

                    file_breakpoint_map[line] = bp;

                    lua_pop(L, 1);
                    
                }
                lua_pop(L, 1);
            }
            else {
                

                
                lua_getfield(L, -1, "line");            
                int line = (int)lua_tointeger(L, -1);
                lua_pop(L, 1); 

                lua_getfield(L, -1, "type");
                int type = (int)lua_tointeger(L, -1);
                lua_pop(L, 1); 

                struct breakpoint bp;
                switch (type) {
                case CONDITION_BREAKPOINT: {
                    bp.type = CONDITION_BREAKPOINT;

                    lua_getfield(L, -1, "condition");
                    const char* condition = luaL_checkstring(L, -1);
                    lua_pop(L, 1); 
                    bp.info = condition;
                    break;
                }

                case LOG_POINT: {
                    bp.type = LOG_POINT;

                    lua_getfield(L, -1, "logMessage");
                    const char* log_message = luaL_checkstring(L, -1);
                    lua_pop(L, 1); 
                    bp.info = log_message;
                    break;
                }

                case LINE_BREAKPOINT:
                    bp.type = LINE_BREAKPOINT;

                    bp.info = std::to_string(line);
                    break;

                default:
                    print_to_vscode(L, "[C Module Error] Invalid breakpoint type!", 2);
                    return -1;
                }

                file_breakpoint_map[line] = bp;

                lua_pop(L, 1);

            }
        }
        all_breakpoint_map[std::string(source)] = file_breakpoint_map;
        
        lua_pop(L, 1);
        
    }
    lua_pop(L, 1);

    print_all_breakpoint_map(L);
    check_hook_state(L, last_source, ar_current_line, ar_def_line, ar_lastdef_line);
    return 0;
}


int debug_ishit_bk(lua_State* L, const char* curPath, int current_line) {
    debug_auto_stack _tt(L);
    
    const char* standardPath = getPath(L, curPath);
    
    std::map<std::string, std::map<int, struct breakpoint>>::const_iterator const_iter1 = all_breakpoint_map.find(std::string(standardPath));
    if (const_iter1 == all_breakpoint_map.end()) {
        return 0;
    }

    
    
    std::map<int, struct breakpoint>::const_iterator const_iter2 = const_iter1->second.find(current_line);
    if (const_iter2 == const_iter1->second.end()) {
        return 0;
    }

    if (lua_debugger_ver >= 30160) {
        
        
        int lua_ret = call_lua_function(L, "isHitBreakpoint", 1, standardPath, curPath, current_line);
        if (lua_ret != 0) {
            
            return 1;
        }

        int realHit = lua_toboolean(L, -1);
        return realHit;
    }
    else {
        
        
        if (const_iter2->second.type == CONDITION_BREAKPOINT) {
            std::string condition = const_iter2->second.info;
            int lua_ret = call_lua_function(L, "IsMeetCondition", 1, condition.c_str());
            if (lua_ret != 0) {
                return 0;
            }
            
            
            
            
            int is_meet_condition = lua_toboolean(L, -1);
            lua_pop(L, 1);
            return is_meet_condition;
        }

        
        if (const_iter2->second.type == LOG_POINT) {
            std::string log_message = "[log point output]: ";
            log_message.append(const_iter2->second.info);
            print_to_vscode(L, log_message.c_str(), 1);
            return 0;
        }
        return 1;
    }
}


int isCodeSection(char* str) {
    if (strlen(str) > 9) {
        if (str[0] == '[' && str[7] == ' ' && str[8] == '"') {
            return 1;
        }
    }
    return 0;
}


int breakpoint_process(lua_State* L, lua_Debug* ar) {
    int is_hit = 0;
    if (ar->event == LINE) {
        is_hit = debug_ishit_bk(L, ar->source, ar->currentline);
        
        if (is_hit && lua_debugger_ver >= 30160) {
            
            is_hit = checkRealHitBreakpoint(L, ar->source, ar->currentline);
        }

        if (is_hit == 1 || BPhit) {
            print_to_vscode(L, "[C Module] Breakpoint hit!");
            int record_stackdeep_counter = stackdeep_counter;
            int record_cur_run_state = cur_run_state;
            stackdeep_counter = 0;
            sync_runstate_toLua(L, HIT_BREAKPOINT);
            bp_twice_check_res = 1;
            
            
            if (BPhit) {
                BPhit = 0;
                call_lua_function(L, "SendMsgWithStack", 0, "stopOnCodeBreakpoint");
            }
            else {
                call_lua_function(L, "SendMsgWithStack", 0, "stopOnBreakpoint");
                if (bp_twice_check_res == 0) {
                    is_hit = 0;
                    stackdeep_counter = record_stackdeep_counter;
                    sync_runstate_toLua(L, record_cur_run_state);
                }
            }
        }
    }
    return is_hit;
}


void step_process(lua_State* L, lua_Debug* ar) {
    
    if (cur_run_state == STEPOVER) {
        if (ar->event == LINE && stackdeep_counter <= 0) {
            sync_runstate_toLua(L, STEPOVER_STOP);
            call_lua_function(L, "SendMsgWithStack", 0, "stopOnStep");
        }
        else if (ar->event == CALL) {
            stackdeep_counter++;
        }
        
        else if (ar->event == RETURN) {
            if (stackdeep_counter != 0) {
                stackdeep_counter--;
            }
        }
    }
    else if (cur_run_state == STEPIN) {
        if (ar->event == LINE) {
            sync_runstate_toLua(L, STEPIN_STOP);
            call_lua_function(L, "SendMsgWithStack", 0, "stopOnStepIn");
        }

    }
    else if (cur_run_state == STEPOUT) {
        if (ar->event == LINE) {
            if (stackdeep_counter <= -1) {
                stackdeep_counter = 0;
                sync_runstate_toLua(L, STEPOUT_STOP);
                call_lua_function(L, "SendMsgWithStack", 0, "stopOnStepOut");
            }
        }
        else if (ar->event == CALL) {
            stackdeep_counter++;
        }
        
        else if (ar->event == RETURN) {
            stackdeep_counter--;
        }
    }
}


int hook_process_reconnect(lua_State* L) {
    time_t currentSecs = time(static_cast<time_t*>(NULL));
    if (cur_hook_state == DISCONNECT_HOOK) {
        if (currentSecs - recvMsgSeconds > 1) {
            call_lua_function(L, "reConnect", 0);
            recvMsgSeconds = currentSecs;
        }
        return 0;
    }
    return 1;
}

void litehook_recv_message(lua_State* L) {
    time_t currentSecs = time(static_cast<time_t*>(NULL));
    
    if (cur_hook_state == LITE_HOOK && currentSecs - recvMsgSeconds > 1) {
        call_lua_function(L, "debugger_wait_msg", 0);
        recvMsgSeconds = currentSecs;
    }
}

void hook_process_recv_message(lua_State* L) {
    time_t currentSecs = time(static_cast<time_t*>(NULL));
    if ((cur_run_state == RUN ||
        cur_run_state == STEPOVER ||
        cur_run_state == STEPIN ||
        cur_run_state == STEPOUT)
        && currentSecs - recvMsgSeconds > 1) {
        call_lua_function(L, "debugger_wait_msg", 0);
        recvMsgSeconds = currentSecs;
    }
}

int hook_process_cfunction(lua_State* L, lua_Debug* ar) {
    if (!(strcmp(ar->what, "C")) || ar->currentline < 0) {
        
        if (!(strcmp(ar->source, "=(tail call)")) && ar->event == TAILRET && (cur_run_state == STEPOVER || cur_run_state == STEPOUT)) {
            stackdeep_counter--;
        }
        
        return 0;
    }
    return 1;
}

int hook_process_code_section(lua_State* L, lua_Debug* ar) {
    
    int isCodeSec = isCodeSection(ar->short_src);
    if (isCodeSec == 1) {
        
        if (strchr(ar->source, '\n') || strchr(ar->source, ';') || strchr(ar->source, '=')) {
            print_to_vscode(L, "hook jump Code String");
            return 0;
        }
    }
    return 1;
}


int checkHasBreakpoint(lua_State* L, const char* src1, int current_line, int sline, int eline) {
    debug_auto_stack tt(L);

    const char* src = getPath(L, src1);
    if (!strcmp(src, "")) {
        
        return ALL_HOOK;
    }

    if (all_breakpoint_map.empty() == true) {
        
        return LITE_HOOK;
    }

    std::map<std::string, std::map<int, breakpoint>>::iterator iter1;
    for (iter1 = all_breakpoint_map.begin(); iter1 != all_breakpoint_map.end(); ++iter1) {
        if (iter1->first == std::string(src)) {
            
            return ALL_HOOK;
        }
    }

    
    return MID_HOOK;
}

void check_hook_state(lua_State* L, const char* source, int current_line, int def_line, int last_line, int event) {
    if (source == NULL) {
        return;
    }
    if (cur_run_state == RUN && cur_hook_state != DISCONNECT_HOOK) {
        int stats = checkHasBreakpoint(L, source, current_line, def_line, last_line);
        if (stats == LITE_HOOK) {
            sethookstate(L, LITE_HOOK);
        }
        else if (stats == MID_HOOK) {
            sethookstate(L, MID_HOOK);
        }
        else if (stats == ALL_HOOK) {
            sethookstate(L, ALL_HOOK);
        }

        if ((event == RETURN || event == TAILRET) && cur_hook_state == MID_HOOK) {
            sethookstate(L, ALL_HOOK);
        }
    }
}


void debug_hook_c(lua_State* L, lua_Debug* ar) {
    debug_auto_stack _tt(L);
    if (!hook_process_reconnect(L)) return;
    if (cur_hook_state == LITE_HOOK) {
        litehook_recv_message(L);
        return;
    }

    hook_process_recv_message(L);

    if (lua_getinfo(L, "Slf", ar) != 0) {
        
        if (!hook_process_cfunction(L, ar)) return;
        
        int source_len = (int)strlen(ar->source);
        if (debug_file_path_len == source_len) {
            if (!strcmp(debug_file_path, ar->source))	return;
        }
        if (tools_file_path_len == source_len) {
            if (!strcmp(tools_file_path, ar->source))	return;
        }
        
        if (11 == source_len) {
            if (!strcmp("temp buffer", ar->source))	return;
        }
        
        if (5 == source_len) {
            if (!strcmp("chunk", ar->source))	return;
        }

        
        if (!hook_process_code_section(L, ar)) return;

        
        if (logLevel == 0) {
            snprintf(hookLog, sizeof(hookLog), "[hook state] event:%d | source: %s | short_src: %s | line:%d | defined:%d | laseDefined:%d | currentState:%d | currentHookState:%d \n", ar->event, ar->source, ar->short_src, ar->currentline, ar->linedefined, ar->lastlinedefined, cur_run_state, cur_hook_state);
            print_to_vscode(L, hookLog);
        }

        
        last_source = ar->source;
        ar_def_line = ar->linedefined;
        ar_lastdef_line = ar->lastlinedefined;
        ar_current_line = ar->currentline;

        int is_hit = breakpoint_process(L, ar);  

        
        int stop_on_entry = 0;
        if (cur_run_state == STOP_ON_ENTRY && is_hit != 1) {
            
            if (ar->event == LINE) {
                
                stop_on_entry = 1;
                stackdeep_counter = 0;
                call_lua_function(L, "SendMsgWithStack", 0, "stopOnEntry");
            }
        }
        if (is_hit == 1 || stop_on_entry == 1) {
            return;
        }
        step_process(L, ar);
        check_hook_state(L, last_source, ar_current_line, ar_def_line, ar_lastdef_line, ar->event);
    }
}


static int endHook(lua_State* L)
{
    cur_hook_state = DISCONNECT_HOOK;
    lua_sethook(L, NULL, 0, 0);
    all_breakpoint_map.clear();
    return 0;
}

OLUA_LIB int luaopen_pdebug(lua_State* L) {
    oluacls_class(L, "pdebug", nullptr);
    oluacls_func(L, "sync_breakpoints", sync_breakpoints);
    oluacls_func(L, "lua_set_hookstate", lua_set_hookstate);
    oluacls_func(L, "lua_set_runstate", lua_set_runstate);
    oluacls_func(L, "sync_debugger_path", sync_debugger_path);
    oluacls_func(L, "sync_tools_path", sync_tools_path);
    oluacls_func(L, "sync_config", sync_config);
    oluacls_func(L, "sync_cwd", sync_cwd);
    oluacls_func(L, "sync_file_ext", sync_file_ext);
    oluacls_func(L, "sync_getLibVersion", sync_getLibVersion);
    oluacls_func(L, "sync_bp_hit", sync_bp_hit);
    oluacls_func(L, "sync_tempfile_path", sync_tempfile_path);
    oluacls_func(L, "endHook", endHook);
    oluacls_func(L, "get_libhook_state", get_libhook_state);
    oluacls_func(L, "get_last_source", get_last_source);
    oluacls_func(L, "clear_pathcache", clear_pathcache);
    oluacls_func(L, "set_bp_twice_check_res", set_bp_twice_check_res);
    oluacls_func(L, "sync_lua_debugger_ver", sync_lua_debugger_ver);
    lua_pushvalue(L, -1);
    lua_setglobal(L, "luapanda_chook");
    return 0;
}
