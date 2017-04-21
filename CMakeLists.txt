cmake_minimum_required(VERSION 3.7)
project(ProjectC)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        c-src/main.c    c-head/main.h
        c-src/game.c    c-head/game.h
        c-src/board.c   c-head/board.h
        c-head/find.h c-src/find.c)
add_executable(ProjectC ${SOURCE_FILES})
