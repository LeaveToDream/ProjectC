cmake_minimum_required(VERSION 3.7)
project(ProjectC)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        c-src/main.c    c-head/main.h
        c-src/game.c    c-head/game.h
        c-src/board.c   c-head/board.h
        c-src/find.c    c-head/find.h
        c-src/gui.c     c-head/gui.h)

set(SDL2_PATH "D:\\Dev\\SDL2")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${ProjectC_SOURCE_DIR}/c-lib/cmake")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(ProjectC ${SOURCE_FILES})

target_link_libraries(ProjectC ${SDL2_LIBRARY})
