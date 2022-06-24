cmake_minimum_required(VERSION 3.10)

include(GNUInstallDirs)

option(PNG_HARDWARE_OPTIMIZATIONS "Enable hardware optimizations" ON)

if(UNIX AND NOT APPLE AND NOT BEOS AND NOT HAIKU)
    find_library(M_LIBRARY m)
else()
    set(M_LIBRARY "")
endif()

if(PNG_HARDWARE_OPTIMIZATIONS)
    if(IOS)
        if(CMAKE_SYSTEM_PROCESSOR STREQUAL "")
            set(CMAKE_SYSTEM_PROCESSOR "arm64")
        endif()
        set(PNG_ARM_NEON "on" CACHE STRING "")
    endif()
    # set definitions and sources for arm
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "^arm" OR CMAKE_SYSTEM_PROCESSOR MATCHES "^aarch64")
        set(PNG_ARM_NEON_POSSIBLE_VALUES check on off)
        set(PNG_ARM_NEON "check" CACHE STRING "Enable ARM NEON optimizations:
            check: (default) use internal checking code;
            off: disable the optimizations;
            on: turn on unconditionally.")
        set_property(CACHE PNG_ARM_NEON PROPERTY STRINGS ${PNG_ARM_NEON_POSSIBLE_VALUES})
        list(FIND PNG_ARM_NEON_POSSIBLE_VALUES ${PNG_ARM_NEON} index)
        if(index EQUAL -1)
            message(FATAL_ERROR "PNG_ARM_NEON must be one of [${PNG_ARM_NEON_POSSIBLE_VALUES}]")
        elseif(NOT ${PNG_ARM_NEON} STREQUAL "off")
            set(ARM_SOURCES
                arm/arm_init.c
                arm/filter_neon.S
                arm/filter_neon_intrinsics.c
                arm/palette_neon_intrinsics.c
            )
            if(${PNG_ARM_NEON} STREQUAL "on")
                add_definitions(-DPNG_ARM_NEON_OPT=2)
            elseif(${PNG_ARM_NEON} STREQUAL "check")
                add_definitions(-DPNG_ARM_NEON_CHECK_SUPPORTED)
            endif()
        else()
            add_definitions(-DPNG_ARM_NEON_OPT=0)
        endif()
    endif()

    # set definitions and sources for powerpc
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "^powerpc*" OR CMAKE_SYSTEM_PROCESSOR MATCHES "^ppc64*")
        set(PNG_POWERPC_VSX_POSSIBLE_VALUES on off)
        set(PNG_POWERPC_VSX "on" CACHE STRING "Enable POWERPC VSX optimizations:
            off: disable the optimizations.")
        set_property(CACHE PNG_POWERPC_VSX PROPERTY STRINGS ${PNG_POWERPC_VSX_POSSIBLE_VALUES})
        list(FIND PNG_POWERPC_VSX_POSSIBLE_VALUES ${PNG_POWERPC_VSX} index)
        if(index EQUAL -1)
            message(FATAL_ERROR "PNG_POWERPC_VSX must be one of [${PNG_POWERPC_VSX_POSSIBLE_VALUES}]")
        elseif(NOT ${PNG_POWERPC_VSX} STREQUAL "off")
            set(POWERPC_SOURCES
                powerpc/powerpc_init.c
                powerpc/filter_vsx_intrinsics.c
            )
            if(${PNG_POWERPC_VSX} STREQUAL "on")
                add_definitions(-DPNG_POWERPC_VSX_OPT=2)
            endif()
        else()
            add_definitions(-DPNG_POWERPC_VSX_OPT=0)
        endif()
    endif()

    # set definitions and sources for intel
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "^i?86" OR CMAKE_SYSTEM_PROCESSOR MATCHES "^x86_64*")
        set(PNG_INTEL_SSE_POSSIBLE_VALUES on off)
        set(PNG_INTEL_SSE "on" CACHE STRING "Enable INTEL_SSE optimizations:
            off: disable the optimizations")
        set_property(CACHE PNG_INTEL_SSE PROPERTY STRINGS ${PNG_INTEL_SSE_POSSIBLE_VALUES})
        list(FIND PNG_INTEL_SSE_POSSIBLE_VALUES ${PNG_INTEL_SSE} index)
        if(index EQUAL -1)
            message(FATAL_ERROR "PNG_INTEL_SSE must be one of [${PNG_INTEL_SSE_POSSIBLE_VALUES}]")
        elseif(NOT ${PNG_INTEL_SSE} STREQUAL "off")
            set(INTEL_SOURCES
                intel/intel_init.c
                intel/filter_sse2_intrinsics.c
            )
            if(${PNG_INTEL_SSE} STREQUAL "on")
                add_definitions(-DPNG_INTEL_SSE_OPT=1)
            endif()
        else()
            add_definitions(-DPNG_INTEL_SSE_OPT=0)
        endif()
    endif()

    # set definitions and sources for MIPS
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "mipsel*" OR CMAKE_SYSTEM_PROCESSOR MATCHES "mips64el*")
        set(PNG_MIPS_MSA_POSSIBLE_VALUES on off)
        set(PNG_MIPS_MSA "on" CACHE STRING "Enable MIPS_MSA optimizations:
            off: disable the optimizations")
        set_property(CACHE PNG_MIPS_MSA PROPERTY STRINGS ${PNG_MIPS_MSA_POSSIBLE_VALUES})
        list(FIND PNG_MIPS_MSA_POSSIBLE_VALUES ${PNG_MIPS_MSA} index)
        if(index EQUAL -1)
            message(FATAL_ERROR "PNG_MIPS_MSA must be one of [${PNG_MIPS_MSA_POSSIBLE_VALUES}]")
        elseif(NOT ${PNG_MIPS_MSA} STREQUAL "off")
            set(MIPS_SOURCES
                mips/mips_init.c
                mips/filter_msa_intrinsics.c
            )
            if(${PNG_MIPS_MSA} STREQUAL "on")
                add_definitions(-DPNG_MIPS_MSA_OPT=2)
            endif()
        else()
            add_definitions(-DPNG_MIPS_MSA_OPT=0)
        endif()
    endif()
else(PNG_HARDWARE_OPTIMIZATIONS)
    # set definitions and sources for arm
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "^arm" OR CMAKE_SYSTEM_PROCESSOR MATCHES "^aarch64")
        add_definitions(-DPNG_ARM_NEON_OPT=0)
    endif()

    # set definitions and sources for powerpc
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "^powerpc*" OR CMAKE_SYSTEM_PROCESSOR MATCHES "^ppc64*")
        add_definitions(-DPNG_POWERPC_VSX_OPT=0)
    endif()

    # set definitions and sources for intel
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "^i?86" OR CMAKE_SYSTEM_PROCESSOR MATCHES "^x86_64*")
        add_definitions(-DPNG_INTEL_SSE_OPT=0)
    endif()

    # set definitions and sources for MIPS
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "mipsel*" OR CMAKE_SYSTEM_PROCESSOR MATCHES "mips64el*")
        add_definitions(-DPNG_MIPS_MSA_OPT=0)
    endif()
endif(PNG_HARDWARE_OPTIMIZATIONS)

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
endif()

set(HEADERS
    png.h
    pngconf.h
    pnglibconf.h
    pngpriv.h
    pngdebug.h
    pnginfo.h
    pngstruct.h
)
set(SOURCES
    png.c
    pngerror.c
    pngget.c
    pngmem.c
    pngpread.c
    pngread.c
    pngrio.c
    pngrtran.c
    pngrutil.c
    pngset.c
    pngtrans.c
    pngwio.c
    pngwrite.c
    pngwtran.c
    pngwutil.c
    ${ARM_SOURCES}
    ${INTEL_SOURCES}
    ${MIPS_SOURCES}
    ${POWERPC_SOURCES}
)
add_library(ext_png ${HEADERS} ${SOURCES})
target_link_libraries(ext_png ext_zlib)
target_include_directories(ext_png
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
set_target_properties(ext_png
  PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "External"
)
if(APPLE)
    # target_compile_options(ext_png
    #   PRIVATE
    #     -Wno-comma
    # )
endif()
if(XCODE OR VS)
    set_xcode_debug(ext_png)
    cocos_mark_code_files("ext_png" GROUPBASE "${CMAKE_CURRENT_SOURCE_DIR}")
endif()