# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\code\c++_code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\code\c++_code\build

# Include any dependencies generated for this target.
include CMakeFiles/lab13_1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab13_1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab13_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab13_1.dir/flags.make

CMakeFiles/lab13_1.dir/lab13/lab13-1.cpp.obj: CMakeFiles/lab13_1.dir/flags.make
CMakeFiles/lab13_1.dir/lab13/lab13-1.cpp.obj: D:/code/c++_code/lab13/lab13-1.cpp
CMakeFiles/lab13_1.dir/lab13/lab13-1.cpp.obj: CMakeFiles/lab13_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\code\c++_code\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab13_1.dir/lab13/lab13-1.cpp.obj"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab13_1.dir/lab13/lab13-1.cpp.obj -MF CMakeFiles\lab13_1.dir\lab13\lab13-1.cpp.obj.d -o CMakeFiles\lab13_1.dir\lab13\lab13-1.cpp.obj -c D:\code\c++_code\lab13\lab13-1.cpp

CMakeFiles/lab13_1.dir/lab13/lab13-1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab13_1.dir/lab13/lab13-1.cpp.i"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\c++_code\lab13\lab13-1.cpp > CMakeFiles\lab13_1.dir\lab13\lab13-1.cpp.i

CMakeFiles/lab13_1.dir/lab13/lab13-1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab13_1.dir/lab13/lab13-1.cpp.s"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\c++_code\lab13\lab13-1.cpp -o CMakeFiles\lab13_1.dir\lab13\lab13-1.cpp.s

# Object files for target lab13_1
lab13_1_OBJECTS = \
"CMakeFiles/lab13_1.dir/lab13/lab13-1.cpp.obj"

# External object files for target lab13_1
lab13_1_EXTERNAL_OBJECTS =

lab13_1.exe: CMakeFiles/lab13_1.dir/lab13/lab13-1.cpp.obj
lab13_1.exe: CMakeFiles/lab13_1.dir/build.make
lab13_1.exe: CMakeFiles/lab13_1.dir/linkLibs.rsp
lab13_1.exe: CMakeFiles/lab13_1.dir/objects1.rsp
lab13_1.exe: CMakeFiles/lab13_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\code\c++_code\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab13_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab13_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab13_1.dir/build: lab13_1.exe
.PHONY : CMakeFiles/lab13_1.dir/build

CMakeFiles/lab13_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab13_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab13_1.dir/clean

CMakeFiles/lab13_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\code\c++_code D:\code\c++_code D:\code\c++_code\build D:\code\c++_code\build D:\code\c++_code\build\CMakeFiles\lab13_1.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/lab13_1.dir/depend

