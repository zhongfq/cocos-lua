cmake_minimum_required(VERSION 3.10)

add_library(jcore STATIC IMPORTED GLOBAL)

set_target_properties(jcore PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/ios/jcore-noidfa-ios-3.2.9.a"
)

find_library(LIBRESOLV resolv)
target_link_libraries(jcore INTERFACE ${LIBRESOLV})
