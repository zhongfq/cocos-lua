CC = clang
CFLAGS = -fPIC -Wall -std=c++11

# macosx
CINCLUDES=-Illvm-mac/include
LDFLAGS = -bundle -undefined dynamic_lookup

# linux
# LDFLAGS = -shared -lstdc++

STATIC_LIBRARIES = -Illvm-mac/include -Lllvm-mac/lib -lclangAST -lclang -lclangAnalysis -lclangARCMigrate -lclangASTMatchers -lclangBasic -lclangCodeGen -lclangDriver -lclangDynamicASTMatchers -lclangEdit -lclangFormat -lclangFrontend -lclangFrontendTool -lclangIndex -lclangLex -lclangParse -lclangRewrite -lclangRewriteFrontend -lclangSema -lclangSerialization -lclangStaticAnalyzerCheckers -lclangStaticAnalyzerCore -lclangStaticAnalyzerFrontend -lclangTooling -lclangToolingCore -lLLVMBitReader -lLLVMCore -lLLVMMC -lLLVMMCParser -lLLVMOption -lLLVMSupport -lcurses -lz
TARGET = clang.so

.PHONY : all clean

OBJS = lua_clang.o

.cpp.o:
	$(CC) -c $(CFLAGS) $(CINCLUDES) -o $@ $<

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(STATIC_LIBRARIES) -o $@ $(OBJS)

clean:
	rm -f *.o $(TARGET)

# gcc -fPIC -bundle -undefined dynamic_lookup -o clang.so lua_clang.cpp -Illvm-mac/include -Lllvm-mac/lib -lclangAST -lclang -lclangAnalysis -lclangARCMigrate -lclangASTMatchers -lclangBasic -lclangCodeGen -lclangDriver -lclangDynamicASTMatchers -lclangEdit -lclangFormat -lclangFrontend -lclangFrontendTool -lclangIndex -lclangLex -lclangParse -lclangRewrite -lclangRewriteFrontend -lclangSema -lclangSerialization -lclangStaticAnalyzerCheckers -lclangStaticAnalyzerCore -lclangStaticAnalyzerFrontend -lclangTooling -lclangToolingCore -lLLVMBitReader -lLLVMCore -lLLVMMC -lLLVMMCParser -lLLVMOption -lLLVMSupport -lcurses -lz