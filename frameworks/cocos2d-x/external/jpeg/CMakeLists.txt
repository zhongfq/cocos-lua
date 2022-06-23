cmake_minimum_required(VERSION 3.10)

set(HEADERS
    jconfig.h
    jerror.h
    jmorecfg.h
    jpeglib.h
)
set(SOURCES
    jaricom.c
    jcapimin.c
    jcapistd.c
    jcarith.c
    jccoefct.c
    jccolor.c
    jcdctmgr.c
    jchuff.c
    jcinit.c
    jcmainct.c
    jcmarker.c
    jcmaster.c
    jcomapi.c
    jcparam.c
    jcprepct.c
    jcsample.c
    jctrans.c
    jdapimin.c
    jdapistd.c
    jdarith.c
    jdatadst.c
    jdatasrc.c
    jdcoefct.c
    jdcolor.c
    jddctmgr.c
    jdhuff.c
    jdinput.c
    jdmainct.c
    jdmarker.c
    jdmaster.c
    jdmerge.c
    jdpostct.c
    jdsample.c
    jdtrans.c
    jerror.c
    jfdctflt.c
    jfdctfst.c
    jfdctint.c
    jidctflt.c
    jidctfst.c
    jidctint.c
    jmemmgr.c
    jmemnobs.c
    jquant1.c
    jquant2.c
    jutils.c
)
add_library(ext_jpeg ${HEADERS} ${SOURCES})
target_include_directories(ext_jpeg
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
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
    cocos_mark_code_files("ext_jpeg" GROUPBASE "${CMAKE_CURRENT_SOURCE_DIR}")
endif()