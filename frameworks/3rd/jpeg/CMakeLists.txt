cmake_minimum_required(VERSION 3.10)

set(PUBLIC_HEADERS)

foreach(file jconfig.h jerror.h jmorecfg.h jpeglib.h)
  configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/${file}
    ${CMAKE_CURRENT_BINARY_DIR}/include/${file}
    COPYONLY
  )
  list(APPEND PUBLIC_HEADERS ${CMAKE_CURRENT_BINARY_DIR}/include/${file})
endforeach()

set(HEADERS
  cderror.h
  cdjpeg.h
  jdct.h
  jinclude.h
  jmemsys.h
  jpegint.h
  jversion.h
  transupp.h
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
add_library(jpeg ${PUBLIC_HEADERS} ${HEADERS} ${SOURCES})
target_include_directories(jpeg PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/include)
if(APPLE)
  target_compile_options(jpeg
    PRIVATE
      -Wno-comma
  )
endif()

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${HEADERS} ${SOURCES})
source_group(TREE ${CMAKE_CURRENT_BINARY_DIR}/include FILES ${PUBLIC_HEADERS})
