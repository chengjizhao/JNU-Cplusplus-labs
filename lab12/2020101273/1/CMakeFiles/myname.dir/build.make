# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = "D:\Microsoft VS Code\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Microsoft VS Code\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\86135

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\86135

# Include any dependencies generated for this target.
include CMakeFiles/myname.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/myname.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/myname.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myname.dir/flags.make

CMakeFiles/myname.dir/SRC/myname.cpp.obj: CMakeFiles/myname.dir/flags.make
CMakeFiles/myname.dir/SRC/myname.cpp.obj: SRC/myname.cpp
CMakeFiles/myname.dir/SRC/myname.cpp.obj: CMakeFiles/myname.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\86135\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/myname.dir/SRC/myname.cpp.obj"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myname.dir/SRC/myname.cpp.obj -MF CMakeFiles\myname.dir\SRC\myname.cpp.obj.d -o CMakeFiles\myname.dir\SRC\myname.cpp.obj -c C:\Users\86135\SRC\myname.cpp

CMakeFiles/myname.dir/SRC/myname.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/myname.dir/SRC/myname.cpp.i"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\86135\SRC\myname.cpp > CMakeFiles\myname.dir\SRC\myname.cpp.i

CMakeFiles/myname.dir/SRC/myname.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/myname.dir/SRC/myname.cpp.s"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\86135\SRC\myname.cpp -o CMakeFiles\myname.dir\SRC\myname.cpp.s

# Object files for target myname
myname_OBJECTS = \
"CMakeFiles/myname.dir/SRC/myname.cpp.obj"

# External object files for target myname
myname_EXTERNAL_OBJECTS =

Build/lib/libmyname.a: CMakeFiles/myname.dir/SRC/myname.cpp.obj
Build/lib/libmyname.a: CMakeFiles/myname.dir/build.make
Build/lib/libmyname.a: CMakeFiles/myname.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\86135\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library Build\lib\libmyname.a"
	$(CMAKE_COMMAND) -P CMakeFiles\myname.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\myname.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myname.dir/build: Build/lib/libmyname.a
.PHONY : CMakeFiles/myname.dir/build

CMakeFiles/myname.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\myname.dir\cmake_clean.cmake
.PHONY : CMakeFiles/myname.dir/clean

CMakeFiles/myname.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\86135 C:\Users\86135 C:\Users\86135 C:\Users\86135 C:\Users\86135\CMakeFiles\myname.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/myname.dir/depend

