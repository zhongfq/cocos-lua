cmake_minimum_required(VERSION 3.10)

set(HEADERS
    src/jconfig.h
    src/jerror.h
    src/jmorecfg.h
    src/jpeglib.h
)
set(SOURCES
    src/jaricom.c
    src/jcapimin.c
    src/jcapistd.c
    src/jcarith.c
    src/jccoefct.c
    src/jccolor.c
    src/jcdctmgr.c
    src/jchuff.c
    src/jcinit.c
    src/jcmainct.c
    src/jcmarker.c
    src/jcmaster.c
    src/jcomapi.c
    src/jcparam.c
    src/jcprepct.c
    src/jcsample.c
    src/jctrans.c
    src/jdapimin.c
    src/jdapistd.c
    src/jdarith.c
    src/jdatadst.c
    src/jdatasrc.c
    src/jdcoefct.c
    src/jdcolor.c
    src/jddctmgr.c
    src/jdhuff.c
    src/jdinput.c
    src/jdmainct.c
    src/jdmarker.c
    src/jdmaster.c
    src/jdmerge.c
    src/jdpostct.c
    src/jdsample.c
    src/jdtrans.c
    src/jerror.c
    src/jfdctflt.c
    src/jfdctfst.c
    src/jfdctint.c
    src/jidctflt.c
    src/jidctfst.c
    src/jidctint.c
    src/jmemmgr.c
    src/jmemnobs.c
    src/jquant1.c
    src/jquant2.c
    src/jutils.c
)
add_library(ext_jpeg ${HEADERS} ${SOURCES})
target_include_directories(ext_jpeg
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
set_target_properties(ext_jpeg
  PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "External"
)
if(APPLE)
    target_compile_options(ext_jpeg
      PRIVATE
        -Wno-comma
    )
endif()
if(XCODE OR VS)
    set_xcode_debug(ext_jpeg)
    cocos_mark_code_files("ext_jpeg" GROUPBASE "${CMAKE_CURRENT_SOURCE_DIR}/src")
endif()