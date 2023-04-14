# CMakeLists.txt
#
# Copyright (C) 2013-2022 by
# David Turner, Robert Wilhelm, and Werner Lemberg.
#
# Written originally by John Cary <cary@txcorp.com>
#
# This file is part of the FreeType project, and may only be used, modified,
# and distributed under the terms of the FreeType project license,
# LICENSE.TXT.  By continuing to use, modify, or distribute this file you
# indicate that you have read the license and understand and accept it
# fully.
#
#
# The following will (1) create a build directory, and (2) change into it and
# call cmake to configure the build with default parameters as a static
# library.  See
#
#   https://cmake.org/cmake/help/latest/variable/CMAKE_BUILD_TYPE.html
#
# for information about debug or release builds, for example
#
#   cmake -B build -D CMAKE_BUILD_TYPE=Release
#
#
# For a dynamic library, use
#
#   cmake -B build -D BUILD_SHARED_LIBS=true -D CMAKE_BUILD_TYPE=Release
#
# For a framework on OS X, use
#
#   cmake -E chdir build cmake -G Xcode -D BUILD_FRAMEWORK:BOOL=true ..
#
# For an iOS static library, use
#
#   cmake -E chdir build cmake -G Xcode -D IOS_PLATFORM=OS ..
#
# or
#
#   cmake -E chdir build cmake -G Xcode -D IOS_PLATFORM=SIMULATOR ..
#
# or
#
#   cmake -E chdir build cmake -G Xcode -D IOS_PLATFORM=SIMULATOR64 ..
#
#
# Finally, build the project with
#
#   cmake --build build
#
# Install it with
#
#   (sudo) cmake --build build --target install
#
# A binary distribution can be made with
#
#   cmake --build build --config Release --target package
#
# Please refer to the cmake manual for further options, in particular, how
# to modify compilation and linking parameters.
#
# Some notes.
#
# - `cmake' creates configuration files in
#
#     <build-directory>/include/freetype/config
#
#   which should be further modified if necessary.
#
# - You can use `cmake' directly on a freshly cloned FreeType git
#   repository.
#
# - `CMakeLists.txt' is provided as-is since it is normally not used by the
#   developer team.
#
# - Set the `FT_REQUIRE_ZLIB', `FT_REQUIRE_BZIP2', `FT_REQUIRE_PNG',
#   `FT_REQUIRE_HARFBUZZ', and `FT_REQUIRE_BROTLI' CMake variables to `ON'
#   or `TRUE' to force using a dependency.  Leave a variable undefined
#   (which is the default) to use the dependency only if it is available.
#   Example:
#
#     cmake -B build -D FT_REQUIRE_ZLIB=TRUE \
#                    -D FT_REQUIRE_BZIP2=TRUE \
#                    -D FT_REQUIRE_PNG=TRUE \
#                    -D FT_REQUIRE_HARFBUZZ=TRUE \
#                    -D FT_REQUIRE_BROTLI=TRUE [...]
#
# - Set `FT_DISABLE_XXX=TRUE' to disable a dependency completely (where
#   `XXX' is a CMake package name like `BZip2').  Example for disabling all
#   dependencies:
#
#     cmake -B build -D FT_DISABLE_ZLIB=TRUE \
#                    -D FT_DISABLE_BZIP2=TRUE \
#                    -D FT_DISABLE_PNG=TRUE \
#                    -D FT_DISABLE_HARFBUZZ=TRUE \
#                    -D FT_DISABLE_BROTLI=TRUE [...]
#
# - NOTE: If a package is set as DISABLED, it cannot be set as REQUIRED
#   without unsetting the DISABLED value first.  For example, if
#   `FT_DISABLE_HARFBUZZ=TRUE' has been set (Cache is present), you need to
#   call `FT_DISABLE_HARFBUZZ=FALSE' before calling
#   `FT_REQUIRE_HARFBUZZ=TRUE'.
#
# - Installation of FreeType can be controlled with the CMake variables
#   `SKIP_INSTALL_HEADERS', `SKIP_INSTALL_LIBRARIES', and `SKIP_INSTALL_ALL'
#   (this is compatible with the same CMake variables in zlib's CMake
#   support).

# To minimize the number of cmake_policy() workarounds,
# CMake >= 3 is requested.
cmake_minimum_required(VERSION 3.16)

if (NOT CMAKE_VERSION VERSION_LESS 3.3)
  # Allow symbol visibility settings also on static libraries. CMake < 3.3
  # only sets the property on a shared library build.
  cmake_policy(SET CMP0063 NEW)

  # Support new IN_LIST if() operator.
  cmake_policy(SET CMP0057 NEW)
endif ()

include(CheckIncludeFile)
include(CMakeDependentOption)
include(FindPkgConfig)

# CMAKE_TOOLCHAIN_FILE must be set before `project' is called, which
# configures the base build environment and references the toolchain file
if (APPLE)
  if (DEFINED IOS_PLATFORM)
    if (NOT "${IOS_PLATFORM}" STREQUAL "OS"
        AND NOT "${IOS_PLATFORM}" STREQUAL "SIMULATOR"
        AND NOT "${IOS_PLATFORM}" STREQUAL "SIMULATOR64")
      message(FATAL_ERROR
        "IOS_PLATFORM must be set to either OS, SIMULATOR, or SIMULATOR64")
    endif ()
    if (NOT "${CMAKE_GENERATOR}" STREQUAL "Xcode")
      message(AUTHOR_WARNING
        "You should use Xcode generator with IOS_PLATFORM enabled to get Universal builds.")
    endif ()
    if (BUILD_SHARED_LIBS)
      message(FATAL_ERROR
        "BUILD_SHARED_LIBS can not be on with IOS_PLATFORM enabled")
    endif ()

    # iOS only uses static libraries
    set(BUILD_SHARED_LIBS OFF)

    set(CMAKE_TOOLCHAIN_FILE
      ${CMAKE_CURRENT_SOURCE_DIR}/builds/cmake/iOS.cmake)
  endif ()
else ()
  if (DEFINED IOS_PLATFORM)
    message(FATAL_ERROR "IOS_PLATFORM is not supported on this platform")
  endif ()
endif ()


project(freetype C)

set(VERSION_MAJOR "2")
set(VERSION_MINOR "12")
set(VERSION_PATCH "1")

# External dependency library detection is automatic.  See the notes at the
# top of this file, for how to force or disable dependencies completely.
option(FT_DISABLE_ZLIB
  "Disable use of system zlib and use internal zlib library instead." OFF)
cmake_dependent_option(FT_REQUIRE_ZLIB
  "Require system zlib instead of internal zlib library." OFF
  "NOT FT_DISABLE_ZLIB" OFF)

option(FT_DISABLE_BZIP2
  "Disable support of bzip2 compressed fonts." OFF)
cmake_dependent_option(FT_REQUIRE_BZIP2
  "Require support of bzip2 compressed fonts." OFF
  "NOT FT_DISABLE_BZIP2" OFF)

option(FT_DISABLE_PNG
  "Disable support of PNG compressed OpenType embedded bitmaps." OFF)
cmake_dependent_option(FT_REQUIRE_PNG
  "Require support of PNG compressed OpenType embedded bitmaps." OFF
  "NOT FT_DISABLE_PNG" OFF)

option(FT_DISABLE_HARFBUZZ
  "Disable HarfBuzz (used for improving auto-hinting of OpenType fonts)." OFF)
cmake_dependent_option(FT_REQUIRE_HARFBUZZ
  "Require HarfBuzz for improving auto-hinting of OpenType fonts." OFF
  "NOT FT_DISABLE_HARFBUZZ" OFF)

option(FT_DISABLE_BROTLI
  "Disable support of compressed WOFF2 fonts." OFF)
cmake_dependent_option(FT_REQUIRE_BROTLI
  "Require support of compressed WOFF2 fonts." OFF
  "NOT FT_DISABLE_BROTLI" OFF)

# Disallow in-source builds
if ("${CMAKE_CURRENT_BINARY_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
  message(FATAL_ERROR
    "In-source builds are not permitted!  Make a separate folder for"
    " building, e.g.,\n"
    "  cmake -E make_directory build\n"
    "  cmake -E chdir build cmake ..\n"
    "Before that, remove the files created by this failed run with\n"
    "  cmake -E remove CMakeCache.txt\n"
    "  cmake -E remove_directory CMakeFiles")
endif ()


# Add local cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/builds/cmake)

# Create the configuration file
if (UNIX)
  check_include_file("unistd.h" HAVE_UNISTD_H)
  check_include_file("fcntl.h" HAVE_FCNTL_H)

  file(READ "${CMAKE_CURRENT_SOURCE_DIR}/builds/unix/ftconfig.h.in"
    FTCONFIG_H)
  if (HAVE_UNISTD_H)
    string(REGEX REPLACE
      "#undef +(HAVE_UNISTD_H)" "#define \\1 1"
      FTCONFIG_H "${FTCONFIG_H}")
  endif ()
  if (HAVE_FCNTL_H)
    string(REGEX REPLACE
      "#undef +(HAVE_FCNTL_H)" "#define \\1 1"
      FTCONFIG_H "${FTCONFIG_H}")
  endif ()
else ()
  file(READ "${CMAKE_CURRENT_SOURCE_DIR}/include/freetype/config/ftconfig.h"
    FTCONFIG_H)
endif ()

set(FTCONFIG_H_NAME "${PROJECT_BINARY_DIR}/include/freetype/config/ftconfig.h")
if (EXISTS "${FTCONFIG_H_NAME}")
  file(READ "${FTCONFIG_H_NAME}" ORIGINAL_FTCONFIG_H)
else ()
  set(ORIGINAL_FTCONFIG_H "")
endif ()
if (NOT (ORIGINAL_FTCONFIG_H STREQUAL FTCONFIG_H))
  file(WRITE "${FTCONFIG_H_NAME}" "${FTCONFIG_H}")
endif ()


# Create the options file
file(READ "${CMAKE_CURRENT_SOURCE_DIR}/include/freetype/config/ftoption.h"
  FTOPTION_H)
if (BZIP2_FOUND)
  string(REGEX REPLACE
    "/\\* +(#define +FT_CONFIG_OPTION_USE_BZIP2) +\\*/" "\\1"
    FTOPTION_H "${FTOPTION_H}")
endif ()
if (BROTLIDEC_FOUND)
  string(REGEX REPLACE
    "/\\* +(#define +FT_CONFIG_OPTION_USE_BROTLI) +\\*/" "\\1"
    FTOPTION_H "${FTOPTION_H}")
endif ()

set(FTOPTION_H_NAME "${PROJECT_BINARY_DIR}/include/freetype/config/ftoption.h")
if (EXISTS "${FTOPTION_H_NAME}")
  file(READ "${FTOPTION_H_NAME}" ORIGINAL_FTOPTION_H)
else ()
  set(ORIGINAL_FTOPTION_H "")
endif ()
if (NOT (ORIGINAL_FTOPTION_H STREQUAL FTOPTION_H))
  file(WRITE "${FTOPTION_H_NAME}" "${FTOPTION_H}")
endif ()


file(GLOB PUBLIC_HEADERS "include/ft2build.h" "include/freetype/*.h")
file(GLOB PUBLIC_CONFIG_HEADERS "include/freetype/config/*.h")
file(GLOB PRIVATE_HEADERS "include/freetype/internal/*.h")

set(BASE_SRCS
  src/autofit/autofit.c
  src/base/ftbase.c
  src/base/ftbbox.c
  src/base/ftbdf.c
  src/base/ftbitmap.c
  src/base/ftcid.c
  src/base/ftfstype.c
  src/base/ftgasp.c
  src/base/ftglyph.c
  src/base/ftgxval.c
  src/base/ftinit.c
  src/base/ftmm.c
  src/base/ftotval.c
  src/base/ftpatent.c
  src/base/ftpfr.c
  src/base/ftstroke.c
  src/base/ftsynth.c
  src/base/fttype1.c
  src/base/ftwinfnt.c
  src/bdf/bdf.c
  src/bzip2/ftbzip2.c
  src/cache/ftcache.c
  src/cff/cff.c
  src/cid/type1cid.c
  src/gzip/ftgzip.c
  src/lzw/ftlzw.c
  src/pcf/pcf.c
  src/pfr/pfr.c
  src/psaux/psaux.c
  src/pshinter/pshinter.c
  src/psnames/psnames.c
  src/raster/raster.c
  src/sdf/sdf.c
  src/sfnt/sfnt.c
  src/smooth/smooth.c
  src/svg/svg.c
  src/truetype/truetype.c
  src/type1/type1.c
  src/type42/type42.c
  src/winfonts/winfnt.c
)

if (UNIX)
  list(APPEND BASE_SRCS "builds/unix/ftsystem.c")
elseif (WIN32)
  list(APPEND BASE_SRCS "builds/windows/ftsystem.c")
else ()
  list(APPEND BASE_SRCS "src/base/ftsystem.c")
endif ()

if (WIN32)
  enable_language(RC)
  list(APPEND BASE_SRCS builds/windows/ftdebug.c src/base/ftver.rc)
elseif (WINCE)
  list(APPEND BASE_SRCS builds/wince/ftdebug.c)
else ()
  list(APPEND BASE_SRCS src/base/ftdebug.c)
endif ()

if (NOT DISABLE_FORCE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif ()


add_library(freetype
  ${PUBLIC_HEADERS}
  ${PUBLIC_CONFIG_HEADERS}
  ${PRIVATE_HEADERS}
  ${BASE_SRCS}
)

set_target_properties(freetype PROPERTIES C_VISIBILITY_PRESET hidden)
target_compile_definitions(freetype PRIVATE FT2_BUILD_LIBRARY)

if (WIN32)
  target_compile_definitions(freetype PRIVATE _CRT_SECURE_NO_WARNINGS _CRT_NONSTDC_NO_WARNINGS)
  if (BUILD_SHARED_LIBS)
    target_compile_definitions(freetype PRIVATE DLL_EXPORT)
  endif ()
endif ()

# Pick up ftconfig.h and ftoption.h generated above, first.
target_include_directories(freetype
  PUBLIC
    $<INSTALL_INTERFACE:include/freetype2>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include

    # Make <ftconfig.h> available for builds/unix/ftsystem.c.
    ${CMAKE_CURRENT_BINARY_DIR}/include/freetype/config
)

if(APPLE)
  target_compile_options(freetype
    PRIVATE
      -Wno-shorten-64-to-32
  )
endif()

target_link_libraries(freetype PRIVATE zlib bz2 png)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${BASE_SRCS})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/include FILES ${PUBLIC_HEADERS} ${PUBLIC_CONFIG_HEADERS} ${PRIVATE_HEADERS})
