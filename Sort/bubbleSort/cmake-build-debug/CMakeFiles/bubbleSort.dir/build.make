# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "D:\IDE\clion\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\IDE\clion\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\IDE\DataStructure\bubbleSort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\IDE\DataStructure\bubbleSort\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/bubbleSort.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/bubbleSort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bubbleSort.dir/flags.make

CMakeFiles/bubbleSort.dir/main.cpp.obj: CMakeFiles/bubbleSort.dir/flags.make
CMakeFiles/bubbleSort.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\IDE\DataStructure\bubbleSort\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bubbleSort.dir/main.cpp.obj"
	D:\code\CodeBlocks\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\bubbleSort.dir\main.cpp.obj -c D:\IDE\DataStructure\bubbleSort\main.cpp

CMakeFiles/bubbleSort.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bubbleSort.dir/main.cpp.i"
	D:\code\CodeBlocks\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\IDE\DataStructure\bubbleSort\main.cpp > CMakeFiles\bubbleSort.dir\main.cpp.i

CMakeFiles/bubbleSort.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bubbleSort.dir/main.cpp.s"
	D:\code\CodeBlocks\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\IDE\DataStructure\bubbleSort\main.cpp -o CMakeFiles\bubbleSort.dir\main.cpp.s

# Object files for target bubbleSort
bubbleSort_OBJECTS = \
"CMakeFiles/bubbleSort.dir/main.cpp.obj"

# External object files for target bubbleSort
bubbleSort_EXTERNAL_OBJECTS =

bubbleSort.exe: CMakeFiles/bubbleSort.dir/main.cpp.obj
bubbleSort.exe: CMakeFiles/bubbleSort.dir/build.make
bubbleSort.exe: CMakeFiles/bubbleSort.dir/linklibs.rsp
bubbleSort.exe: CMakeFiles/bubbleSort.dir/objects1.rsp
bubbleSort.exe: CMakeFiles/bubbleSort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\IDE\DataStructure\bubbleSort\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bubbleSort.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\bubbleSort.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bubbleSort.dir/build: bubbleSort.exe
.PHONY : CMakeFiles/bubbleSort.dir/build

CMakeFiles/bubbleSort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\bubbleSort.dir\cmake_clean.cmake
.PHONY : CMakeFiles/bubbleSort.dir/clean

CMakeFiles/bubbleSort.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\IDE\DataStructure\bubbleSort D:\IDE\DataStructure\bubbleSort D:\IDE\DataStructure\bubbleSort\cmake-build-debug D:\IDE\DataStructure\bubbleSort\cmake-build-debug D:\IDE\DataStructure\bubbleSort\cmake-build-debug\CMakeFiles\bubbleSort.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bubbleSort.dir/depend

