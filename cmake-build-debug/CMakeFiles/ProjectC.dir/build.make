# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\John-i5m\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\171.4073.41\bin\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\John-i5m\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\171.4073.41\bin\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\John-i5m\Documents\GitHub\ProjectC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\John-i5m\Documents\GitHub\ProjectC\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ProjectC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ProjectC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProjectC.dir/flags.make

CMakeFiles/ProjectC.dir/c-src/main.c.obj: CMakeFiles/ProjectC.dir/flags.make
CMakeFiles/ProjectC.dir/c-src/main.c.obj: CMakeFiles/ProjectC.dir/includes_C.rsp
CMakeFiles/ProjectC.dir/c-src/main.c.obj: ../c-src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\John-i5m\Documents\GitHub\ProjectC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ProjectC.dir/c-src/main.c.obj"
	C:\Dev\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ProjectC.dir\c-src\main.c.obj   -c C:\Users\John-i5m\Documents\GitHub\ProjectC\c-src\main.c

CMakeFiles/ProjectC.dir/c-src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjectC.dir/c-src/main.c.i"
	C:\Dev\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\John-i5m\Documents\GitHub\ProjectC\c-src\main.c > CMakeFiles\ProjectC.dir\c-src\main.c.i

CMakeFiles/ProjectC.dir/c-src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjectC.dir/c-src/main.c.s"
	C:\Dev\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\John-i5m\Documents\GitHub\ProjectC\c-src\main.c -o CMakeFiles\ProjectC.dir\c-src\main.c.s

CMakeFiles/ProjectC.dir/c-src/main.c.obj.requires:

.PHONY : CMakeFiles/ProjectC.dir/c-src/main.c.obj.requires

CMakeFiles/ProjectC.dir/c-src/main.c.obj.provides: CMakeFiles/ProjectC.dir/c-src/main.c.obj.requires
	$(MAKE) -f CMakeFiles\ProjectC.dir\build.make CMakeFiles/ProjectC.dir/c-src/main.c.obj.provides.build
.PHONY : CMakeFiles/ProjectC.dir/c-src/main.c.obj.provides

CMakeFiles/ProjectC.dir/c-src/main.c.obj.provides.build: CMakeFiles/ProjectC.dir/c-src/main.c.obj


CMakeFiles/ProjectC.dir/c-src/game.c.obj: CMakeFiles/ProjectC.dir/flags.make
CMakeFiles/ProjectC.dir/c-src/game.c.obj: CMakeFiles/ProjectC.dir/includes_C.rsp
CMakeFiles/ProjectC.dir/c-src/game.c.obj: ../c-src/game.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\John-i5m\Documents\GitHub\ProjectC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ProjectC.dir/c-src/game.c.obj"
	C:\Dev\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ProjectC.dir\c-src\game.c.obj   -c C:\Users\John-i5m\Documents\GitHub\ProjectC\c-src\game.c

CMakeFiles/ProjectC.dir/c-src/game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjectC.dir/c-src/game.c.i"
	C:\Dev\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\John-i5m\Documents\GitHub\ProjectC\c-src\game.c > CMakeFiles\ProjectC.dir\c-src\game.c.i

CMakeFiles/ProjectC.dir/c-src/game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjectC.dir/c-src/game.c.s"
	C:\Dev\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\John-i5m\Documents\GitHub\ProjectC\c-src\game.c -o CMakeFiles\ProjectC.dir\c-src\game.c.s

CMakeFiles/ProjectC.dir/c-src/game.c.obj.requires:

.PHONY : CMakeFiles/ProjectC.dir/c-src/game.c.obj.requires

CMakeFiles/ProjectC.dir/c-src/game.c.obj.provides: CMakeFiles/ProjectC.dir/c-src/game.c.obj.requires
	$(MAKE) -f CMakeFiles\ProjectC.dir\build.make CMakeFiles/ProjectC.dir/c-src/game.c.obj.provides.build
.PHONY : CMakeFiles/ProjectC.dir/c-src/game.c.obj.provides

CMakeFiles/ProjectC.dir/c-src/game.c.obj.provides.build: CMakeFiles/ProjectC.dir/c-src/game.c.obj


CMakeFiles/ProjectC.dir/c-src/board.c.obj: CMakeFiles/ProjectC.dir/flags.make
CMakeFiles/ProjectC.dir/c-src/board.c.obj: CMakeFiles/ProjectC.dir/includes_C.rsp
CMakeFiles/ProjectC.dir/c-src/board.c.obj: ../c-src/board.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\John-i5m\Documents\GitHub\ProjectC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ProjectC.dir/c-src/board.c.obj"
	C:\Dev\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ProjectC.dir\c-src\board.c.obj   -c C:\Users\John-i5m\Documents\GitHub\ProjectC\c-src\board.c

CMakeFiles/ProjectC.dir/c-src/board.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjectC.dir/c-src/board.c.i"
	C:\Dev\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\John-i5m\Documents\GitHub\ProjectC\c-src\board.c > CMakeFiles\ProjectC.dir\c-src\board.c.i

CMakeFiles/ProjectC.dir/c-src/board.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjectC.dir/c-src/board.c.s"
	C:\Dev\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\John-i5m\Documents\GitHub\ProjectC\c-src\board.c -o CMakeFiles\ProjectC.dir\c-src\board.c.s

CMakeFiles/ProjectC.dir/c-src/board.c.obj.requires:

.PHONY : CMakeFiles/ProjectC.dir/c-src/board.c.obj.requires

CMakeFiles/ProjectC.dir/c-src/board.c.obj.provides: CMakeFiles/ProjectC.dir/c-src/board.c.obj.requires
	$(MAKE) -f CMakeFiles\ProjectC.dir\build.make CMakeFiles/ProjectC.dir/c-src/board.c.obj.provides.build
.PHONY : CMakeFiles/ProjectC.dir/c-src/board.c.obj.provides

CMakeFiles/ProjectC.dir/c-src/board.c.obj.provides.build: CMakeFiles/ProjectC.dir/c-src/board.c.obj


CMakeFiles/ProjectC.dir/c-src/find.c.obj: CMakeFiles/ProjectC.dir/flags.make
CMakeFiles/ProjectC.dir/c-src/find.c.obj: CMakeFiles/ProjectC.dir/includes_C.rsp
CMakeFiles/ProjectC.dir/c-src/find.c.obj: ../c-src/find.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\John-i5m\Documents\GitHub\ProjectC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ProjectC.dir/c-src/find.c.obj"
	C:\Dev\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ProjectC.dir\c-src\find.c.obj   -c C:\Users\John-i5m\Documents\GitHub\ProjectC\c-src\find.c

CMakeFiles/ProjectC.dir/c-src/find.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjectC.dir/c-src/find.c.i"
	C:\Dev\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\John-i5m\Documents\GitHub\ProjectC\c-src\find.c > CMakeFiles\ProjectC.dir\c-src\find.c.i

CMakeFiles/ProjectC.dir/c-src/find.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjectC.dir/c-src/find.c.s"
	C:\Dev\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\John-i5m\Documents\GitHub\ProjectC\c-src\find.c -o CMakeFiles\ProjectC.dir\c-src\find.c.s

CMakeFiles/ProjectC.dir/c-src/find.c.obj.requires:

.PHONY : CMakeFiles/ProjectC.dir/c-src/find.c.obj.requires

CMakeFiles/ProjectC.dir/c-src/find.c.obj.provides: CMakeFiles/ProjectC.dir/c-src/find.c.obj.requires
	$(MAKE) -f CMakeFiles\ProjectC.dir\build.make CMakeFiles/ProjectC.dir/c-src/find.c.obj.provides.build
.PHONY : CMakeFiles/ProjectC.dir/c-src/find.c.obj.provides

CMakeFiles/ProjectC.dir/c-src/find.c.obj.provides.build: CMakeFiles/ProjectC.dir/c-src/find.c.obj


CMakeFiles/ProjectC.dir/c-src/gui.c.obj: CMakeFiles/ProjectC.dir/flags.make
CMakeFiles/ProjectC.dir/c-src/gui.c.obj: CMakeFiles/ProjectC.dir/includes_C.rsp
CMakeFiles/ProjectC.dir/c-src/gui.c.obj: ../c-src/gui.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\John-i5m\Documents\GitHub\ProjectC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ProjectC.dir/c-src/gui.c.obj"
	C:\Dev\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ProjectC.dir\c-src\gui.c.obj   -c C:\Users\John-i5m\Documents\GitHub\ProjectC\c-src\gui.c

CMakeFiles/ProjectC.dir/c-src/gui.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjectC.dir/c-src/gui.c.i"
	C:\Dev\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\John-i5m\Documents\GitHub\ProjectC\c-src\gui.c > CMakeFiles\ProjectC.dir\c-src\gui.c.i

CMakeFiles/ProjectC.dir/c-src/gui.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjectC.dir/c-src/gui.c.s"
	C:\Dev\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\John-i5m\Documents\GitHub\ProjectC\c-src\gui.c -o CMakeFiles\ProjectC.dir\c-src\gui.c.s

CMakeFiles/ProjectC.dir/c-src/gui.c.obj.requires:

.PHONY : CMakeFiles/ProjectC.dir/c-src/gui.c.obj.requires

CMakeFiles/ProjectC.dir/c-src/gui.c.obj.provides: CMakeFiles/ProjectC.dir/c-src/gui.c.obj.requires
	$(MAKE) -f CMakeFiles\ProjectC.dir\build.make CMakeFiles/ProjectC.dir/c-src/gui.c.obj.provides.build
.PHONY : CMakeFiles/ProjectC.dir/c-src/gui.c.obj.provides

CMakeFiles/ProjectC.dir/c-src/gui.c.obj.provides.build: CMakeFiles/ProjectC.dir/c-src/gui.c.obj


CMakeFiles/ProjectC.dir/c-src/getLine.c.obj: CMakeFiles/ProjectC.dir/flags.make
CMakeFiles/ProjectC.dir/c-src/getLine.c.obj: CMakeFiles/ProjectC.dir/includes_C.rsp
CMakeFiles/ProjectC.dir/c-src/getLine.c.obj: ../c-src/getLine.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\John-i5m\Documents\GitHub\ProjectC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/ProjectC.dir/c-src/getLine.c.obj"
	C:\Dev\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ProjectC.dir\c-src\getLine.c.obj   -c C:\Users\John-i5m\Documents\GitHub\ProjectC\c-src\getLine.c

CMakeFiles/ProjectC.dir/c-src/getLine.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjectC.dir/c-src/getLine.c.i"
	C:\Dev\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\John-i5m\Documents\GitHub\ProjectC\c-src\getLine.c > CMakeFiles\ProjectC.dir\c-src\getLine.c.i

CMakeFiles/ProjectC.dir/c-src/getLine.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjectC.dir/c-src/getLine.c.s"
	C:\Dev\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\John-i5m\Documents\GitHub\ProjectC\c-src\getLine.c -o CMakeFiles\ProjectC.dir\c-src\getLine.c.s

CMakeFiles/ProjectC.dir/c-src/getLine.c.obj.requires:

.PHONY : CMakeFiles/ProjectC.dir/c-src/getLine.c.obj.requires

CMakeFiles/ProjectC.dir/c-src/getLine.c.obj.provides: CMakeFiles/ProjectC.dir/c-src/getLine.c.obj.requires
	$(MAKE) -f CMakeFiles\ProjectC.dir\build.make CMakeFiles/ProjectC.dir/c-src/getLine.c.obj.provides.build
.PHONY : CMakeFiles/ProjectC.dir/c-src/getLine.c.obj.provides

CMakeFiles/ProjectC.dir/c-src/getLine.c.obj.provides.build: CMakeFiles/ProjectC.dir/c-src/getLine.c.obj


# Object files for target ProjectC
ProjectC_OBJECTS = \
"CMakeFiles/ProjectC.dir/c-src/main.c.obj" \
"CMakeFiles/ProjectC.dir/c-src/game.c.obj" \
"CMakeFiles/ProjectC.dir/c-src/board.c.obj" \
"CMakeFiles/ProjectC.dir/c-src/find.c.obj" \
"CMakeFiles/ProjectC.dir/c-src/gui.c.obj" \
"CMakeFiles/ProjectC.dir/c-src/getLine.c.obj"

# External object files for target ProjectC
ProjectC_EXTERNAL_OBJECTS =

ProjectC.exe: CMakeFiles/ProjectC.dir/c-src/main.c.obj
ProjectC.exe: CMakeFiles/ProjectC.dir/c-src/game.c.obj
ProjectC.exe: CMakeFiles/ProjectC.dir/c-src/board.c.obj
ProjectC.exe: CMakeFiles/ProjectC.dir/c-src/find.c.obj
ProjectC.exe: CMakeFiles/ProjectC.dir/c-src/gui.c.obj
ProjectC.exe: CMakeFiles/ProjectC.dir/c-src/getLine.c.obj
ProjectC.exe: CMakeFiles/ProjectC.dir/build.make
ProjectC.exe: C:/Dev/MinGW/lib/libSDL2main.a
ProjectC.exe: C:/Dev/MinGW/lib/libSDL2.dll.a
ProjectC.exe: C:/Dev/MinGW/lib/libSDL2_image.dll.a
ProjectC.exe: CMakeFiles/ProjectC.dir/linklibs.rsp
ProjectC.exe: CMakeFiles/ProjectC.dir/objects1.rsp
ProjectC.exe: CMakeFiles/ProjectC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\John-i5m\Documents\GitHub\ProjectC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable ProjectC.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ProjectC.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProjectC.dir/build: ProjectC.exe

.PHONY : CMakeFiles/ProjectC.dir/build

CMakeFiles/ProjectC.dir/requires: CMakeFiles/ProjectC.dir/c-src/main.c.obj.requires
CMakeFiles/ProjectC.dir/requires: CMakeFiles/ProjectC.dir/c-src/game.c.obj.requires
CMakeFiles/ProjectC.dir/requires: CMakeFiles/ProjectC.dir/c-src/board.c.obj.requires
CMakeFiles/ProjectC.dir/requires: CMakeFiles/ProjectC.dir/c-src/find.c.obj.requires
CMakeFiles/ProjectC.dir/requires: CMakeFiles/ProjectC.dir/c-src/gui.c.obj.requires
CMakeFiles/ProjectC.dir/requires: CMakeFiles/ProjectC.dir/c-src/getLine.c.obj.requires

.PHONY : CMakeFiles/ProjectC.dir/requires

CMakeFiles/ProjectC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ProjectC.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ProjectC.dir/clean

CMakeFiles/ProjectC.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\John-i5m\Documents\GitHub\ProjectC C:\Users\John-i5m\Documents\GitHub\ProjectC C:\Users\John-i5m\Documents\GitHub\ProjectC\cmake-build-debug C:\Users\John-i5m\Documents\GitHub\ProjectC\cmake-build-debug C:\Users\John-i5m\Documents\GitHub\ProjectC\cmake-build-debug\CMakeFiles\ProjectC.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProjectC.dir/depend

