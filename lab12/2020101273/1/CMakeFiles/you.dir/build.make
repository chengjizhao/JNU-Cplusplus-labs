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
include CMakeFiles/you.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/you.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/you.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/you.dir/flags.make

CMakeFiles/you.dir/main.cpp.obj: CMakeFiles/you.dir/flags.make
CMakeFiles/you.dir/main.cpp.obj: CMakeFiles/you.dir/includes_CXX.rsp
CMakeFiles/you.dir/main.cpp.obj: main.cpp
CMakeFiles/you.dir/main.cpp.obj: CMakeFiles/you.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\86135\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/you.dir/main.cpp.obj"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/you.dir/main.cpp.obj -MF CMakeFiles\you.dir\main.cpp.obj.d -o CMakeFiles\you.dir\main.cpp.obj -c C:\Users\86135\main.cpp

CMakeFiles/you.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/you.dir/main.cpp.i"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\86135\main.cpp > CMakeFiles\you.dir\main.cpp.i

CMakeFiles/you.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/you.dir/main.cpp.s"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\86135\main.cpp -o CMakeFiles\you.dir\main.cpp.s

# Object files for target you
you_OBJECTS = \
"CMakeFiles/you.dir/main.cpp.obj"

# External object files for target you
you_EXTERNAL_OBJECTS =

you.exe: CMakeFiles/you.dir/main.cpp.obj
you.exe: CMakeFiles/you.dir/build.make
you.exe: Build/lib/libmyname.a
you.exe: CMakeFiles/you.dir/linkLibs.rsp
you.exe: CMakeFiles/you.dir/objects1.rsp
you.exe: CMakeFiles/you.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\86135\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable you.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\you.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/you.dir/build: you.exe
.PHONY : CMakeFiles/you.dir/build

CMakeFiles/you.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\you.dir\cmake_clean.cmake
.PHONY : CMakeFiles/you.dir/clean

CMakeFiles/you.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\86135 C:\Users\86135 C:\Users\86135 C:\Users\86135 C:\Users\86135\CMakeFiles\you.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/you.dir/depend

