CC = clang
CFLAGS = -fPIC -Wall -std=c++11

# macosx
CINCLUDES=-Illvm-mac/include
LDFLAGS = -bundle -undefined dynamic_lookup -flto -Os

# linux
# LDFLAGS = -shared -lstdc++

STATIC_LIBRARIES = -Illvm-mac/include -Lllvm-mac/lib \
-lclang \
-lclangAnalysis \
-lclangARCMigrate \
-lclangAST \
-lclangASTMatchers \
-lclangBasic \
-lclangCodeGen \
-lclangCrossTU \
-lclangDriver \
-lclangEdit \
-lclangFormat \
-lclangFrontend \
-lclangFrontendTool \
-lclangIndex \
-lclangLex \
-lclangParse \
-lclangRewrite \
-lclangRewriteFrontend \
-lclangSema \
-lclangSerialization \
-lclangStaticAnalyzerCheckers \
-lclangStaticAnalyzerCore \
-lclangStaticAnalyzerFrontend \
-lclangToolingCore \
-lclangToolingInclusions \
-lLLVMAArch64AsmParser \
-lLLVMAArch64CodeGen \
-lLLVMAArch64Desc \
-lLLVMAArch64Disassembler \
-lLLVMAArch64Info \
-lLLVMAArch64Utils \
-lLLVMAggressiveInstCombine \
-lLLVMAMDGPUAsmParser \
-lLLVMAMDGPUCodeGen \
-lLLVMAMDGPUDesc \
-lLLVMAMDGPUDisassembler \
-lLLVMAMDGPUInfo \
-lLLVMAMDGPUUtils \
-lLLVMAnalysis \
-lLLVMARMAsmParser \
-lLLVMARMCodeGen \
-lLLVMARMDesc \
-lLLVMARMDisassembler \
-lLLVMARMInfo \
-lLLVMARMUtils \
-lLLVMAsmParser \
-lLLVMAsmPrinter \
-lLLVMBinaryFormat \
-lLLVMBitReader \
-lLLVMBitstreamReader \
-lLLVMBitWriter \
-lLLVMBPFAsmParser \
-lLLVMBPFCodeGen \
-lLLVMBPFDesc \
-lLLVMBPFDisassembler \
-lLLVMBPFInfo \
-lLLVMCodeGen \
-lLLVMCore \
-lLLVMCoroutines \
-lLLVMCoverage \
-lLLVMDebugInfoCodeView \
-lLLVMDebugInfoDWARF \
-lLLVMDebugInfoMSF \
-lLLVMDemangle \
-lLLVMGlobalISel \
-lLLVMHexagonAsmParser \
-lLLVMHexagonCodeGen \
-lLLVMHexagonDesc \
-lLLVMHexagonDisassembler \
-lLLVMHexagonInfo \
-lLLVMInstCombine \
-lLLVMInstrumentation \
-lLLVMipo \
-lLLVMIRReader \
-lLLVMLanaiAsmParser \
-lLLVMLanaiCodeGen \
-lLLVMLanaiDesc \
-lLLVMLanaiDisassembler \
-lLLVMLanaiInfo \
-lLLVMLinker \
-lLLVMLTO \
-lLLVMMC \
-lLLVMMCDisassembler \
-lLLVMMCParser \
-lLLVMMipsAsmParser \
-lLLVMMipsCodeGen \
-lLLVMMipsDesc \
-lLLVMMipsDisassembler \
-lLLVMMipsInfo \
-lLLVMMIRParser \
-lLLVMMSP430AsmParser \
-lLLVMMSP430CodeGen \
-lLLVMMSP430Desc \
-lLLVMMSP430Disassembler \
-lLLVMMSP430Info \
-lLLVMNVPTXCodeGen \
-lLLVMNVPTXDesc \
-lLLVMNVPTXInfo \
-lLLVMObjCARCOpts \
-lLLVMObject \
-lLLVMOption \
-lLLVMPasses \
-lLLVMPowerPCAsmParser \
-lLLVMPowerPCCodeGen \
-lLLVMPowerPCDesc \
-lLLVMPowerPCDisassembler \
-lLLVMPowerPCInfo \
-lLLVMProfileData \
-lLLVMRemarks \
-lLLVMRISCVAsmParser \
-lLLVMRISCVCodeGen \
-lLLVMRISCVDesc \
-lLLVMRISCVDisassembler \
-lLLVMRISCVInfo \
-lLLVMRISCVUtils \
-lLLVMScalarOpts \
-lLLVMSelectionDAG \
-lLLVMSparcAsmParser \
-lLLVMSparcCodeGen \
-lLLVMSparcDesc \
-lLLVMSparcDisassembler \
-lLLVMSparcInfo \
-lLLVMSupport \
-lLLVMSystemZAsmParser \
-lLLVMSystemZCodeGen \
-lLLVMSystemZDesc \
-lLLVMSystemZDisassembler \
-lLLVMSystemZInfo \
-lLLVMTableGen \
-lLLVMTarget \
-lLLVMTransformUtils \
-lLLVMVectorize \
-lLLVMWebAssemblyAsmParser \
-lLLVMWebAssemblyCodeGen \
-lLLVMWebAssemblyDesc \
-lLLVMWebAssemblyDisassembler \
-lLLVMWebAssemblyInfo \
-lLLVMX86AsmParser \
-lLLVMX86CodeGen \
-lLLVMX86Desc \
-lLLVMX86Disassembler \
-lLLVMX86Info \
-lLLVMX86Utils \
-lLLVMXCoreCodeGen \
-lLLVMXCoreDesc \
-lLLVMXCoreDisassembler \
-lLLVMXCoreInfo \
-lcurses \
-lz
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
