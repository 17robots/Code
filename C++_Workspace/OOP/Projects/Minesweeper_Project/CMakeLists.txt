cmake_minimum_required(VERSION 3.8)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
# set(SFML_DIR "/usr/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
include_directories(usr/include/SFML)

add_executable(minesweeper main.cpp)
target_link_libraries(minesweeper ${SFML_LIBRARIES})

