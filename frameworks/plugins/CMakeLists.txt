cmake_minimum_required(VERSION 3.6)

set(PLUGINS_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

set(PLUGINS_HEADER
)

set(PLUGINS_SRC
)

list(APPEND PLUGINS_SRC ${PLUGINS_HEADER})

add_library(plugins ${PLUGINS_SRC})

target_link_libraries(plugins
    PRIVATE
    xgame
    PRIVATE
    cocos2d
)

target_include_directories(plugins
    PUBLIC ${PLUGINS_ROOT}
)