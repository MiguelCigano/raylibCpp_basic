# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jmiguel-nitro/Documents/cpp/fireC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jmiguel-nitro/Documents/cpp/fireC/build/debug

# Include any dependencies generated for this target.
include CMakeFiles/fireC.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/fireC.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/fireC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fireC.dir/flags.make

CMakeFiles/fireC.dir/main.cpp.o: CMakeFiles/fireC.dir/flags.make
CMakeFiles/fireC.dir/main.cpp.o: ../../main.cpp
CMakeFiles/fireC.dir/main.cpp.o: CMakeFiles/fireC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jmiguel-nitro/Documents/cpp/fireC/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fireC.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/fireC.dir/main.cpp.o -MF CMakeFiles/fireC.dir/main.cpp.o.d -o CMakeFiles/fireC.dir/main.cpp.o -c /home/jmiguel-nitro/Documents/cpp/fireC/main.cpp

CMakeFiles/fireC.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fireC.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jmiguel-nitro/Documents/cpp/fireC/main.cpp > CMakeFiles/fireC.dir/main.cpp.i

CMakeFiles/fireC.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fireC.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jmiguel-nitro/Documents/cpp/fireC/main.cpp -o CMakeFiles/fireC.dir/main.cpp.s

# Object files for target fireC
fireC_OBJECTS = \
"CMakeFiles/fireC.dir/main.cpp.o"

# External object files for target fireC
fireC_EXTERNAL_OBJECTS =

fireC: CMakeFiles/fireC.dir/main.cpp.o
fireC: CMakeFiles/fireC.dir/build.make
fireC: CMakeFiles/fireC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jmiguel-nitro/Documents/cpp/fireC/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fireC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fireC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fireC.dir/build: fireC
.PHONY : CMakeFiles/fireC.dir/build

CMakeFiles/fireC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fireC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fireC.dir/clean

CMakeFiles/fireC.dir/depend:
	cd /home/jmiguel-nitro/Documents/cpp/fireC/build/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jmiguel-nitro/Documents/cpp/fireC /home/jmiguel-nitro/Documents/cpp/fireC /home/jmiguel-nitro/Documents/cpp/fireC/build/debug /home/jmiguel-nitro/Documents/cpp/fireC/build/debug /home/jmiguel-nitro/Documents/cpp/fireC/build/debug/CMakeFiles/fireC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fireC.dir/depend

