# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = "K:\CLion 2018.2.6\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "K:\CLion 2018.2.6\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\553\dynamic-memory-kai-zhang-jiawei-wang\dynamicmemory\String

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\553\dynamic-memory-kai-zhang-jiawei-wang\dynamicmemory\String\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/String.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/String.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/String.dir/flags.make

CMakeFiles/String.dir/main.cc.obj: CMakeFiles/String.dir/flags.make
CMakeFiles/String.dir/main.cc.obj: CMakeFiles/String.dir/includes_CXX.rsp
CMakeFiles/String.dir/main.cc.obj: ../main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\553\dynamic-memory-kai-zhang-jiawei-wang\dynamicmemory\String\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/String.dir/main.cc.obj"
	K:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\String.dir\main.cc.obj -c E:\553\dynamic-memory-kai-zhang-jiawei-wang\dynamicmemory\String\main.cc

CMakeFiles/String.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/String.dir/main.cc.i"
	K:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\553\dynamic-memory-kai-zhang-jiawei-wang\dynamicmemory\String\main.cc > CMakeFiles\String.dir\main.cc.i

CMakeFiles/String.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/String.dir/main.cc.s"
	K:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\553\dynamic-memory-kai-zhang-jiawei-wang\dynamicmemory\String\main.cc -o CMakeFiles\String.dir\main.cc.s

CMakeFiles/String.dir/String.cc.obj: CMakeFiles/String.dir/flags.make
CMakeFiles/String.dir/String.cc.obj: CMakeFiles/String.dir/includes_CXX.rsp
CMakeFiles/String.dir/String.cc.obj: ../String.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\553\dynamic-memory-kai-zhang-jiawei-wang\dynamicmemory\String\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/String.dir/String.cc.obj"
	K:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\String.dir\String.cc.obj -c E:\553\dynamic-memory-kai-zhang-jiawei-wang\dynamicmemory\String\String.cc

CMakeFiles/String.dir/String.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/String.dir/String.cc.i"
	K:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\553\dynamic-memory-kai-zhang-jiawei-wang\dynamicmemory\String\String.cc > CMakeFiles\String.dir\String.cc.i

CMakeFiles/String.dir/String.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/String.dir/String.cc.s"
	K:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\553\dynamic-memory-kai-zhang-jiawei-wang\dynamicmemory\String\String.cc -o CMakeFiles\String.dir\String.cc.s

# Object files for target String
String_OBJECTS = \
"CMakeFiles/String.dir/main.cc.obj" \
"CMakeFiles/String.dir/String.cc.obj"

# External object files for target String
String_EXTERNAL_OBJECTS =

String.exe: CMakeFiles/String.dir/main.cc.obj
String.exe: CMakeFiles/String.dir/String.cc.obj
String.exe: CMakeFiles/String.dir/build.make
String.exe: CMakeFiles/String.dir/linklibs.rsp
String.exe: CMakeFiles/String.dir/objects1.rsp
String.exe: CMakeFiles/String.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\553\dynamic-memory-kai-zhang-jiawei-wang\dynamicmemory\String\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable String.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\String.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/String.dir/build: String.exe

.PHONY : CMakeFiles/String.dir/build

CMakeFiles/String.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\String.dir\cmake_clean.cmake
.PHONY : CMakeFiles/String.dir/clean

CMakeFiles/String.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\553\dynamic-memory-kai-zhang-jiawei-wang\dynamicmemory\String E:\553\dynamic-memory-kai-zhang-jiawei-wang\dynamicmemory\String E:\553\dynamic-memory-kai-zhang-jiawei-wang\dynamicmemory\String\cmake-build-debug E:\553\dynamic-memory-kai-zhang-jiawei-wang\dynamicmemory\String\cmake-build-debug E:\553\dynamic-memory-kai-zhang-jiawei-wang\dynamicmemory\String\cmake-build-debug\CMakeFiles\String.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/String.dir/depend

