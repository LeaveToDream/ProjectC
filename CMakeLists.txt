cmake_minimum_required(VERSION 3.7)
project(ProjectC)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        c-src/main.c    c-head/main.h
        c-src/game.c    c-head/game.h
        c-src/board.c   c-head/board.h
        c-src/find.c    c-head/find.h
        c-src/gui.c     c-head/gui.h)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${ProjectC_SOURCE_DIR}/c-lib/cmake")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(ProjectC ${SOURCE_FILES})

target_link_libraries(ProjectC ${SDL2_LIBRARY})

#https://brendanwhitfield.wordpress.com/2015/02/26/using-cmake-with-sdl2/
#http://stackoverflow.com/questions/23850472/how-to-use-sdl2-and-sdl-image-with-cmake
#https://github.com/Twinklebear/TwinklebearDev-Lessons/tree/master/cmake