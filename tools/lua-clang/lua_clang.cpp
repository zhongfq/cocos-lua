// LICENSE: https://github.com/mkottman/luaclang-parser

#include "clang-c/Index.h"
#include "lua.hpp"

#define LCM_INDEX  "ClangIndex"
#define LCM_TU     "ClangTU"
#define LCM_CURSOR "ClangCursor"
#define LCM_TYPE   "ClangType"
#define LCM_FILE   "ClangFile"

static CXIndex * newIndex(lua_State *L) {
    CXIndex *idx = (CXIndex*) lua_newuserdata(L, sizeof(CXIndex));
    luaL_getmetatable(L, LCM_INDEX);
    lua_setmetatable(L, -2);
    return idx;
}

static CXIndex toIndex(lua_State *L, int n) {
    CXIndex * idx = (CXIndex*) luaL_checkudata(L, n, LCM_INDEX);
    return *idx;
}

static CXTranslationUnit * newTU(lua_State *L) {
    CXTranslationUnit *tu = (CXTranslationUnit*) lua_newuserdata(L, sizeof(CXTranslationUnit));
    luaL_getmetatable(L, LCM_TU);
    lua_setmetatable(L, -2);
    return tu;
}

static CXTranslationUnit toTU(lua_State *L, int n) {
    CXTranslationUnit * tu = (CXTranslationUnit*) luaL_checkudata(L, n, LCM_TU);
    return *tu;
}

static CXCursor * newCursor(lua_State *L) {
    CXCursor *c = (CXCursor*) lua_newuserdata(L, sizeof(CXCursor));
    luaL_getmetatable(L, LCM_CURSOR);
    lua_setmetatable(L, -2);
    return c;
}

static CXCursor toCursor(lua_State *L, int n) {
    CXCursor * c = (CXCursor*) luaL_checkudata(L, n, LCM_CURSOR);
    return *c;
}

static CXType * newType(lua_State *L) {
    CXType *t = (CXType*) lua_newuserdata(L, sizeof(CXType));
    luaL_getmetatable(L, LCM_TYPE);
    lua_setmetatable(L, -2);
    return t;
}

static CXType toType(lua_State *L, int n) {
    CXType *t = (CXType*) luaL_checkudata(L, n, LCM_TYPE);
    return *t;
}

static void pushCXString(lua_State *L, CXString s) {
    if (s.data == NULL)
        lua_pushnil(L);
    else {
        lua_pushstring(L, clang_getCString(s));
        clang_disposeString(s);
    }
}

static void pushDiagnostic(lua_State *L, CXDiagnostic diag) {
    lua_createtable(L, 0, 0);

    pushCXString(L, clang_getDiagnosticCategoryText(diag));
    lua_setfield(L, -2, "category");

    pushCXString(L, clang_formatDiagnostic(diag, clang_defaultDiagnosticDisplayOptions()));
    lua_setfield(L, -2, "text");

    clang_disposeDiagnostic(diag);
}

/****** CLANG ******/

static int l_createIndex(lua_State *L) {
    int excludePch = lua_toboolean(L, 1);
    int diagnostics = lua_toboolean(L, 2);
    CXIndex *idx = newIndex(L);
    *idx = clang_createIndex(excludePch, diagnostics);
    return 1;
}

static luaL_Reg clang_functions[] = {
    {"createIndex", l_createIndex},
    {NULL, NULL}
};

/****** INDEX ******/

static int l_loadTU(lua_State *L) {
    CXIndex idx = toIndex(L, 1);
    const char *astFile = luaL_checkstring(L, 2);

    CXTranslationUnit *tu = newTU(L);
    *tu = clang_createTranslationUnit(idx, astFile);
    if (*tu == NULL) {
        lua_pushnil(L);
        lua_pushliteral(L, "Failed to open file: ");
        lua_pushvalue(L, 2);
        lua_concat(L, 2);
        return 2;
    }

    return 1;
}

static int l_parseTU(lua_State *L) {
    CXIndex idx = toIndex(L, 1);
    int tabIndex;
    const char *sourceFile;

    if (lua_type(L, 2) == LUA_TTABLE) {
        sourceFile = NULL;
        tabIndex = 2;
    } else {
        sourceFile = luaL_checkstring(L, 2);
        luaL_checktype(L, 3, LUA_TTABLE);
        tabIndex = 3;
    }

    int nArgs = (int)lua_rawlen(L, tabIndex);
    lua_checkstack(L, nArgs);
    char const ** args = new char const *[nArgs];
    for (int i=0; i<nArgs; i++) {
        lua_rawgeti(L, tabIndex, i+1);
        args[i] = lua_tostring(L, -1);
    }

    CXTranslationUnit *tu = newTU(L);
    *tu = clang_parseTranslationUnit(idx, sourceFile, args, nArgs, NULL, 0, CXTranslationUnit_SkipFunctionBodies);
    delete [] args;

    if (*tu == NULL) {
        lua_pushnil(L);
        lua_pushliteral(L, "Failed to parse");
        return 2;
    }

    return 1;
}

static int l_indexGc(lua_State *L) {
    CXIndex idx = toIndex(L, 1);
    clang_disposeIndex(idx);
    return 0;
}

static luaL_Reg index_functions[] = {
    {"load", l_loadTU},
    {"parse", l_parseTU},
    {"__gc", l_indexGc},
    {NULL, NULL}
};

/****** TRANSLATION UNIT ******/

static int l_tuGc(lua_State *L) {
    CXTranslationUnit tu = toTU(L, 1);
    clang_disposeTranslationUnit(tu);
    return 0;
}

static int l_cursor(lua_State *L) {
    CXTranslationUnit tu = toTU(L, 1);
    CXCursor *cur = newCursor(L);
    *cur = clang_getTranslationUnitCursor(tu);
    if (clang_Cursor_isNull(*cur)) {
        lua_pushnil(L);
    }
    return 1;
}

static int l_file(lua_State *L) {
    CXTranslationUnit tu = toTU(L, 1);
    const char * file = luaL_checkstring(L, 2);
    CXFile f = clang_getFile(tu, file);
    pushCXString(L, clang_getFileName(f));
    lua_pushnumber(L, clang_getFileTime(f));
    return 2;
}

static int l_diagnostics(lua_State *L) {
    CXTranslationUnit tu = toTU(L, 1);
    int nDiag = clang_getNumDiagnostics(tu);
    lua_createtable(L, nDiag, 0);
    for (int i=0; i<nDiag; i++) {
        pushDiagnostic(L, clang_getDiagnostic(tu, i));
        lua_rawseti(L, -2, i+1);
    }
    return 1;
}

static const char * completionKindName(CXCompletionChunkKind kind) {
    switch(kind) {
  case CXCompletionChunk_Optional: return "Optional";
  case CXCompletionChunk_TypedText: return "TypedText";
  case CXCompletionChunk_Text: return "Text";
  case CXCompletionChunk_Placeholder: return "Placeholder";
  case CXCompletionChunk_Informative: return "Informative";
  case CXCompletionChunk_CurrentParameter: return "CurrentParameter";
  case CXCompletionChunk_LeftParen: return "LeftParen";
  case CXCompletionChunk_RightParen: return "RightParen";
  case CXCompletionChunk_LeftBracket: return "LeftBracket";
  case CXCompletionChunk_RightBracket: return "RightBracket";
  case CXCompletionChunk_LeftBrace: return "LeftBrace";
  case CXCompletionChunk_RightBrace: return "RightBrace";
  case CXCompletionChunk_LeftAngle: return "LeftAngle";
  case CXCompletionChunk_RightAngle: return "RightAngle";
  case CXCompletionChunk_Comma: return "Comma";
  case CXCompletionChunk_ResultType: return "ResultType";
  case CXCompletionChunk_Colon: return "Colon";
  case CXCompletionChunk_SemiColon: return "SemiColon";
  case CXCompletionChunk_Equal: return "Equal";
  case CXCompletionChunk_HorizontalSpace: return "HorizontalSpace";
  case CXCompletionChunk_VerticalSpace: return "VerticalSpace";
  default: return "???";
    }
}

static int l_codeComplete(lua_State *L) {
    CXTranslationUnit tu = toTU(L, 1);
    const char *file = luaL_checkstring(L, 2);
    int line = (int)luaL_checkinteger(L, 3);
    int col = (int)luaL_checkinteger(L, 4);

    CXCodeCompleteResults* results = clang_codeCompleteAt(
        tu, file, line, col, NULL, 0, clang_defaultCodeCompleteOptions());

    unsigned int nResults = results ? results->NumResults : 0;
    // clang_sortCodeCompletionResults(results, nResults);
    lua_createtable(L, nResults, 0);
    for (int i=0; results && i<nResults; i++) {
        CXCompletionResult res = results->Results[i];
        CXCompletionString com = res.CompletionString;

        lua_createtable(L, 0, 2);
        
        lua_pushinteger(L, clang_getCompletionPriority(com));
        lua_setfield(L, -2, "priority");

        int nChunks = clang_getNumCompletionChunks(com);
        if (nChunks > 0) {
            lua_createtable(L, nChunks, 0);
            for (int j=0; j<nChunks; j++) {
                lua_createtable(L, 0, 2);
                pushCXString(L, clang_getCompletionChunkText(com, j));
                lua_setfield(L, -2, "text");
                CXCompletionChunkKind kind = clang_getCompletionChunkKind(com, j);
                lua_pushstring(L, completionKindName(kind));
                lua_setfield(L, -2, "kind");
                lua_rawseti(L, -2, j+1);
            }
            lua_setfield(L, -2, "chunks");            
        }

        int nAnnot = clang_getCompletionNumAnnotations(com);
        if (nAnnot > 0) {
            lua_createtable(L, nAnnot, 0);
            for (int j=0; j<nAnnot; j++) {
                pushCXString(L, clang_getCompletionAnnotation(com, j));
                lua_rawseti(L, -2, j+1);
            }
            lua_setfield(L, -2, "annotations");                        
        }

        lua_rawseti(L, -2, i+1);
    }

    unsigned int nDiagnostics = results ? clang_codeCompleteGetNumDiagnostics(results) : 0;
    lua_createtable(L, nDiagnostics, 0);
    for (int i=0; results && i<nDiagnostics; i++) {
        CXDiagnostic diag = clang_codeCompleteGetDiagnostic(results, i);
        pushDiagnostic(L, diag);
        lua_rawseti(L, -2, i+1);
    }

    if (results)
        clang_disposeCodeCompleteResults(results);
    
    return 2;
}

static luaL_Reg tu_functions[] = {
    {"cursor", l_cursor},
    {"file", l_file},
    {"diagnostics", l_diagnostics},
    {"codeCompleteAt", l_codeComplete},
    {"__gc", l_tuGc},
    {NULL, NULL}
};

/****** CURSOR ******/

enum CXChildVisitResult LuaTableVisitor(CXCursor cursor,
                                   CXCursor parent,
                                   CXClientData client_data)
{
    lua_State *L = (lua_State*) client_data;
    CXCursor *c = newCursor(L);
    *c = cursor;
    int tablen = (int)lua_rawlen(L, -2);
    lua_rawseti(L, -2, tablen+1);
    return CXChildVisit_Continue;
}

static int l_children(lua_State *L) {
    CXCursor cur = toCursor(L, 1);
    lua_createtable(L,0,0);
    clang_visitChildren(cur, LuaTableVisitor, L);
    return 1;
}

static const char * cursorKindStr(CXCursorKind kind) {
    switch (kind) {
    case CXCursor_UnexposedDecl: return "UnexposedDecl";
    case CXCursor_StructDecl: return "StructDecl";
    case CXCursor_UnionDecl: return "UnionDecl";
    case CXCursor_ClassDecl: return "ClassDecl";
    case CXCursor_EnumDecl: return "EnumDecl";
    case CXCursor_FieldDecl: return "FieldDecl";
    case CXCursor_EnumConstantDecl: return "EnumConstantDecl";
    case CXCursor_FunctionDecl: return "FunctionDecl";
    case CXCursor_VarDecl: return "VarDecl";
    case CXCursor_ParmDecl: return "ParmDecl";
    case CXCursor_ObjCInterfaceDecl: return "ObjCInterfaceDecl";
    case CXCursor_ObjCCategoryDecl: return "ObjCCategoryDecl";
    case CXCursor_ObjCProtocolDecl: return "ObjCProtocolDecl";
    case CXCursor_ObjCPropertyDecl: return "ObjCPropertyDecl";
    case CXCursor_ObjCIvarDecl: return "ObjCIvarDecl";
    case CXCursor_ObjCInstanceMethodDecl: return "ObjCInstanceMethodDecl";
    case CXCursor_ObjCClassMethodDecl: return "ObjCClassMethodDecl";
    case CXCursor_ObjCImplementationDecl: return "ObjCImplementationDecl";
    case CXCursor_ObjCCategoryImplDecl: return "ObjCCategoryImplDecl";
    case CXCursor_TypedefDecl: return "TypedefDecl";
    case CXCursor_CXXMethod: return "CXXMethod";
    case CXCursor_Namespace: return "Namespace";
    case CXCursor_LinkageSpec: return "LinkageSpec";
    case CXCursor_Constructor: return "Constructor";
    case CXCursor_Destructor: return "Destructor";
    case CXCursor_ConversionFunction: return "ConversionFunction";
    case CXCursor_TemplateTypeParameter: return "TemplateTypeParameter";
    case CXCursor_NonTypeTemplateParameter: return "NonTypeTemplateParameter";
    case CXCursor_TemplateTemplateParameter: return "TemplateTemplateParameter";
    case CXCursor_FunctionTemplate: return "FunctionTemplate";
    case CXCursor_ClassTemplate: return "ClassTemplate";
    case CXCursor_ClassTemplatePartialSpecialization: return "ClassTemplatePartialSpecialization";
    case CXCursor_NamespaceAlias: return "NamespaceAlias";
    case CXCursor_UsingDirective: return "UsingDirective";
    case CXCursor_UsingDeclaration: return "UsingDeclaration";
    case CXCursor_TypeAliasDecl: return "TypeAliasDecl";
    case CXCursor_ObjCSynthesizeDecl: return "ObjCSynthesizeDecl";
    case CXCursor_ObjCDynamicDecl: return "ObjCDynamicDecl";
    case CXCursor_CXXAccessSpecifier: return "CXXAccessSpecifier";
    case CXCursor_ObjCSuperClassRef: return "ObjCSuperClassRef";
    case CXCursor_ObjCProtocolRef: return "ObjCProtocolRef";
    case CXCursor_ObjCClassRef: return "ObjCClassRef";
    case CXCursor_TypeRef: return "TypeRef";
    case CXCursor_CXXBaseSpecifier: return "CXXBaseSpecifier";
    case CXCursor_TemplateRef: return "TemplateRef";
    case CXCursor_NamespaceRef: return "NamespaceRef";
    case CXCursor_MemberRef: return "MemberRef";
    case CXCursor_LabelRef: return "LabelRef";
    case CXCursor_OverloadedDeclRef: return "OverloadedDeclRef";
    case CXCursor_VariableRef: return "VariableRef";
    case CXCursor_InvalidFile: return "InvalidFile";
    case CXCursor_NoDeclFound: return "NoDeclFound";
    case CXCursor_NotImplemented: return "NotImplemented";
    case CXCursor_InvalidCode: return "InvalidCode";
    case CXCursor_UnexposedExpr: return "UnexposedExpr";
    case CXCursor_DeclRefExpr: return "DeclRefExpr";
    case CXCursor_MemberRefExpr: return "MemberRefExpr";
    case CXCursor_CallExpr: return "CallExpr";
    case CXCursor_ObjCMessageExpr: return "ObjCMessageExpr";
    case CXCursor_BlockExpr: return "BlockExpr";
    case CXCursor_IntegerLiteral: return "IntegerLiteral";
    case CXCursor_FloatingLiteral: return "FloatingLiteral";
    case CXCursor_ImaginaryLiteral: return "ImaginaryLiteral";
    case CXCursor_StringLiteral: return "StringLiteral";
    case CXCursor_CharacterLiteral: return "CharacterLiteral";
    case CXCursor_ParenExpr: return "ParenExpr";
    case CXCursor_UnaryOperator: return "UnaryOperator";
    case CXCursor_ArraySubscriptExpr: return "ArraySubscriptExpr";
    case CXCursor_BinaryOperator: return "BinaryOperator";
    case CXCursor_CompoundAssignOperator: return "CompoundAssignOperator";
    case CXCursor_ConditionalOperator: return "ConditionalOperator";
    case CXCursor_CStyleCastExpr: return "CStyleCastExpr";
    case CXCursor_CompoundLiteralExpr: return "CompoundLiteralExpr";
    case CXCursor_InitListExpr: return "InitListExpr";
    case CXCursor_AddrLabelExpr: return "AddrLabelExpr";
    case CXCursor_StmtExpr: return "StmtExpr";
    case CXCursor_GenericSelectionExpr: return "GenericSelectionExpr";
    case CXCursor_GNUNullExpr: return "GNUNullExpr";
    case CXCursor_CXXStaticCastExpr: return "CXXStaticCastExpr";
    case CXCursor_CXXDynamicCastExpr: return "CXXDynamicCastExpr";
    case CXCursor_CXXReinterpretCastExpr: return "CXXReinterpretCastExpr";
    case CXCursor_CXXConstCastExpr: return "CXXConstCastExpr";
    case CXCursor_CXXFunctionalCastExpr: return "CXXFunctionalCastExpr";
    case CXCursor_CXXTypeidExpr: return "CXXTypeidExpr";
    case CXCursor_CXXBoolLiteralExpr: return "CXXBoolLiteralExpr";
    case CXCursor_CXXNullPtrLiteralExpr: return "CXXNullPtrLiteralExpr";
    case CXCursor_CXXThisExpr: return "CXXThisExpr";
    case CXCursor_CXXThrowExpr: return "CXXThrowExpr";
    case CXCursor_CXXNewExpr: return "CXXNewExpr";
    case CXCursor_CXXDeleteExpr: return "CXXDeleteExpr";
    case CXCursor_UnaryExpr: return "UnaryExpr";
    case CXCursor_ObjCStringLiteral: return "ObjCStringLiteral";
    case CXCursor_ObjCEncodeExpr: return "ObjCEncodeExpr";
    case CXCursor_ObjCSelectorExpr: return "ObjCSelectorExpr";
    case CXCursor_ObjCProtocolExpr: return "ObjCProtocolExpr";
    case CXCursor_ObjCBridgedCastExpr: return "ObjCBridgedCastExpr";
    case CXCursor_PackExpansionExpr: return "PackExpansionExpr";
    case CXCursor_SizeOfPackExpr: return "SizeOfPackExpr";
    case CXCursor_LambdaExpr: return "LambdaExpr";
    case CXCursor_ObjCBoolLiteralExpr: return "ObjCBoolLiteralExpr";
    case CXCursor_LabelStmt: return "LabelStmt";
    case CXCursor_CompoundStmt: return "CompoundStmt";
    case CXCursor_CaseStmt: return "CaseStmt";
    case CXCursor_DefaultStmt: return "DefaultStmt";
    case CXCursor_IfStmt: return "IfStmt";
    case CXCursor_SwitchStmt: return "SwitchStmt";
    case CXCursor_WhileStmt: return "WhileStmt";
    case CXCursor_DoStmt: return "DoStmt";
    case CXCursor_ForStmt: return "ForStmt";
    case CXCursor_GotoStmt: return "GotoStmt";
    case CXCursor_IndirectGotoStmt: return "IndirectGotoStmt";
    case CXCursor_ContinueStmt: return "ContinueStmt";
    case CXCursor_BreakStmt: return "BreakStmt";
    case CXCursor_ReturnStmt: return "ReturnStmt";
    case CXCursor_AsmStmt: return "AsmStmt";
    case CXCursor_ObjCAtTryStmt: return "ObjCAtTryStmt";
    case CXCursor_ObjCAtCatchStmt: return "ObjCAtCatchStmt";
    case CXCursor_ObjCAtFinallyStmt: return "ObjCAtFinallyStmt";
    case CXCursor_ObjCAtThrowStmt: return "ObjCAtThrowStmt";
    case CXCursor_ObjCAtSynchronizedStmt: return "ObjCAtSynchronizedStmt";
    case CXCursor_ObjCAutoreleasePoolStmt: return "ObjCAutoreleasePoolStmt";
    case CXCursor_ObjCForCollectionStmt: return "ObjCForCollectionStmt";
    case CXCursor_CXXCatchStmt: return "CXXCatchStmt";
    case CXCursor_CXXTryStmt: return "CXXTryStmt";
    case CXCursor_CXXForRangeStmt: return "CXXForRangeStmt";
    case CXCursor_SEHTryStmt: return "SEHTryStmt";
    case CXCursor_SEHExceptStmt: return "SEHExceptStmt";
    case CXCursor_SEHFinallyStmt: return "SEHFinallyStmt";
    case CXCursor_NullStmt: return "NullStmt";
    case CXCursor_DeclStmt: return "DeclStmt";
    case CXCursor_TranslationUnit: return "TranslationUnit";
    case CXCursor_UnexposedAttr: return "UnexposedAttr";
    case CXCursor_IBActionAttr: return "IBActionAttr";
    case CXCursor_IBOutletAttr: return "IBOutletAttr";
    case CXCursor_IBOutletCollectionAttr: return "IBOutletCollectionAttr";
    case CXCursor_CXXFinalAttr: return "CXXFinalAttr";
    case CXCursor_CXXOverrideAttr: return "CXXOverrideAttr";
    case CXCursor_AnnotateAttr: return "AnnotateAttr";
    case CXCursor_AsmLabelAttr: return "AsmLabelAttr";
    case CXCursor_PreprocessingDirective: return "PreprocessingDirective";
    case CXCursor_MacroDefinition: return "MacroDefinition";
    case CXCursor_MacroExpansion: return "MacroExpansion";
    case CXCursor_InclusionDirective: return "InclusionDirective";
    default: return "Unknown";
    }
}

static int l_kind(lua_State *L) {
    CXCursor cur = toCursor(L, 1);
    lua_pushstring(L, cursorKindStr(clang_getCursorKind(cur)));
    return 1;
}

static int l_name(lua_State *L) {
    CXCursor cur = toCursor(L, 1);
    CXString name = clang_getCursorSpelling(cur);
    lua_pushstring(L, clang_getCString(name));
    clang_disposeString(name);
    return 1;
}

static int l_displayName(lua_State *L) {
    CXCursor cur = toCursor(L, 1);
    CXString name = clang_getCursorDisplayName(cur);
    lua_pushstring(L, clang_getCString(name));
    clang_disposeString(name);
    return 1;
}

static int l_parent(lua_State *L) {
    CXCursor cur = toCursor(L, 1);
    CXCursor *parent = newCursor(L);
    *parent = clang_getCursorSemanticParent(cur);
    if (clang_Cursor_isNull(*parent))
        lua_pushnil(L);
    return 1;
}

static int l_arguments(lua_State *L) {
    CXCursor cur = toCursor(L, 1);
    unsigned int nArgs = clang_Cursor_getNumArguments(cur);
    lua_createtable(L, nArgs, 0);
    for (unsigned int i=0; i<nArgs; i++) {
        CXCursor *arg = newCursor(L);
        *arg = clang_Cursor_getArgument(cur, i);
        lua_rawseti(L, -2, i+1);
    }
    return 1;
}

static int l_type(lua_State *L) {
    CXCursor cur = toCursor(L, 1);
    CXType *type = newType(L);
    *type = clang_getCursorType(cur);
    if (type->kind == CXType_Invalid)
        lua_pushnil(L);
    return 1;
}

static int l_access(lua_State *L) {
    CXCursor cur = toCursor(L, 1);
    CX_CXXAccessSpecifier spec = clang_getCXXAccessSpecifier(cur);
    switch (spec) {
    case CX_CXXInvalidAccessSpecifier: lua_pushnil(L); break;
    case CX_CXXPublic: lua_pushliteral(L, "public"); break;
    case CX_CXXProtected: lua_pushliteral(L, "protected"); break;
    case CX_CXXPrivate: lua_pushliteral(L, "private"); break;
    }
    return 1;
}

static int l_location(lua_State *L) {
    CXCursor cur = toCursor(L, 1);
    CXSourceRange range = clang_getCursorExtent(cur);

    CXFile file;
    unsigned int line, col;

    CXSourceLocation loc = clang_getRangeStart(range);
    clang_getSpellingLocation(loc, &file, &line, &col, NULL);
    CXString fileName = clang_getFileName(file);
    lua_pushstring(L, clang_getCString(fileName));
    clang_disposeString(fileName);
    lua_pushinteger(L, line);
    lua_pushinteger(L, col);

    loc = clang_getRangeEnd(range);
    clang_getSpellingLocation(loc, &file, &line, &col, NULL);
    lua_pushinteger(L, line);
    lua_pushinteger(L, col);
    return 5;
}

static int l_usr(lua_State *L) {
    CXCursor cur = toCursor(L, 1);
    CXString str = clang_getCursorUSR(cur);
    lua_pushstring(L, clang_getCString(str));
    clang_disposeString(str);
    return 1;
}

static int l_referenced(lua_State *L) {
    CXCursor cur = toCursor(L, 1);
    CXCursor *res = newCursor(L);
    *res = clang_getCursorReferenced(cur);
    if (clang_Cursor_isNull(*res))
        lua_pushnil(L);
    return 1;
}

static int l_definition(lua_State *L) {
    CXCursor cur = toCursor(L, 1);
    CXCursor *res = newCursor(L);
    *res = clang_getCursorDefinition(cur);
    if (clang_Cursor_isNull(*res))
        lua_pushnil(L);
    return 1;
}

static int l_isStatic(lua_State *L) {
    CXCursor cur = toCursor(L, 1);
    lua_pushboolean(L, clang_CXXMethod_isStatic(cur));
    return 1;
}

static int l_isVirtual(lua_State *L) {
    CXCursor cur = toCursor(L, 1);
    lua_pushboolean(L, clang_CXXMethod_isVirtual(cur));
    return 1;
}

static int l_isConstType(lua_State *L) {
    CXCursor cur = toCursor(L, 1);
    lua_pushboolean(L, clang_CXXMethod_isConst(cur));
    return 1;
}

static int l_resultType(lua_State *L) {
    CXCursor cur = toCursor(L, 1);
    CXType *type = newType(L);
    *type = clang_getCursorResultType(cur);
    if (type->kind == CXType_Invalid)
        lua_pushnil(L);
    return 1;
}

static int l_cursorEqual(lua_State *L) {
    CXCursor cur1 = toCursor(L, 1);
    CXCursor cur2 = toCursor(L, 2);
    lua_pushboolean(L, clang_equalCursors(cur1, cur2));
    return 1;
}

static luaL_Reg cursor_functions[] = {
    {"children", l_children},
    {"kind", l_kind},
    {"name", l_name},
    {"__tostring", l_name},
    {"displayName", l_displayName},
    {"parent", l_parent},
    {"arguments", l_arguments},
    {"type", l_type},
    {"access", l_access},
    {"location", l_location},
    {"usr", l_usr},
    {"referenced", l_referenced},
    {"definition", l_definition},
    {"isStatic", l_isStatic},
    {"isVirtual", l_isVirtual},
    {"isConst", l_isConstType},
    {"resultType", l_resultType},
    {"__eq", l_cursorEqual},
    {NULL, NULL}
};

/******** TYPE ********/

static int l_typeToString(lua_State *L) {
    CXType type = toType(L, 1);
    CXTypeKind kind = type.kind;
    CXString str = clang_getTypeKindSpelling(kind);
    lua_pushstring(L, clang_getCString(str));
    clang_disposeString(str);
    return 1;
}

static int l_canonical(lua_State *L) {
    CXType type = toType(L, 1);
    CXType *can = newType(L);
    if (type.kind == CXType_Pointer) {
        *can = clang_getPointeeType(type);
    } else
        *can = clang_getCanonicalType(type);
    if (can->kind == CXType_Invalid)
        lua_pushnil(L);
    return 1;
}

static int l_isPod(lua_State *L) {
    CXType type = toType(L, 1);
    lua_pushboolean(L, clang_isPODType(type));
    return 1;
}

static int l_typeEq(lua_State *L) {
    CXType type = toType(L, 1);
    CXType type2 = toType(L, 2);
    lua_pushboolean(L, clang_equalTypes(type, type2));
    return 1;
}

static int l_declaration(lua_State *L) {
    CXType type = toType(L, 1);
    CXCursor *cur = newCursor(L);
    *cur = clang_getTypeDeclaration(type);
    if (clang_Cursor_isNull(*cur))
        lua_pushnil(L);
    return 1;
}

static int l_pointee(lua_State *L) {
    CXType type = toType(L, 1);
    CXType *res = newType(L);
    *res = clang_getPointeeType(type);
    if (res->kind == CXType_Invalid)
        lua_pushnil(L);
    return 1;
}

static int l_isConst(lua_State *L) {
    CXType type = toType(L, 1);
    int isConst = clang_isConstQualifiedType(type);
    lua_pushboolean(L, isConst);
    return 1;
}

static luaL_Reg type_functions[] = {
    {"__tostring", l_typeToString},
    {"name", l_typeToString},
    {"canonical", l_canonical},
    {"pointee", l_pointee},
    {"isPod", l_isPod},
    {"isConst", l_isConst},
    {"declaration", l_declaration},
    {"__eq", l_typeEq},
    {NULL, NULL}
};

/******** API ********/

void newMetatable(lua_State *L, const char * name, luaL_Reg *reg) {
    luaL_newmetatable(L, name);
    luaL_setfuncs(L, reg, 0);
    lua_pushvalue(L, -1);
    lua_setfield(L, -2, "__index");
}

extern "C" {

LUALIB_API int luaopen_clang(lua_State *L) {
    newMetatable(L, LCM_INDEX, index_functions);
    newMetatable(L, LCM_TU, tu_functions);
    newMetatable(L, LCM_CURSOR, cursor_functions);
    newMetatable(L, LCM_TYPE, type_functions);

    lua_newtable(L);
    luaL_setfuncs(L, clang_functions, 0);
    return 1;
}

}
