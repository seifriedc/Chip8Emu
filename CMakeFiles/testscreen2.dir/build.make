# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/constantinoflouras/Desktop/GIT/CHIP-8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/constantinoflouras/Desktop/GIT/CHIP-8

# Include any dependencies generated for this target.
include CMakeFiles/testscreen2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testscreen2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testscreen2.dir/flags.make

CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.o: CMakeFiles/testscreen2.dir/flags.make
CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.o: src/tests/screen/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/constantinoflouras/Desktop/GIT/CHIP-8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.o -c /home/constantinoflouras/Desktop/GIT/CHIP-8/src/tests/screen/test.cpp

CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/constantinoflouras/Desktop/GIT/CHIP-8/src/tests/screen/test.cpp > CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.i

CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/constantinoflouras/Desktop/GIT/CHIP-8/src/tests/screen/test.cpp -o CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.s

CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.o.requires:

.PHONY : CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.o.requires

CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.o.provides: CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/testscreen2.dir/build.make CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.o.provides.build
.PHONY : CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.o.provides

CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.o.provides.build: CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.o


CMakeFiles/testscreen2.dir/src/Screen.cpp.o: CMakeFiles/testscreen2.dir/flags.make
CMakeFiles/testscreen2.dir/src/Screen.cpp.o: src/Screen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/constantinoflouras/Desktop/GIT/CHIP-8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/testscreen2.dir/src/Screen.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testscreen2.dir/src/Screen.cpp.o -c /home/constantinoflouras/Desktop/GIT/CHIP-8/src/Screen.cpp

CMakeFiles/testscreen2.dir/src/Screen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testscreen2.dir/src/Screen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/constantinoflouras/Desktop/GIT/CHIP-8/src/Screen.cpp > CMakeFiles/testscreen2.dir/src/Screen.cpp.i

CMakeFiles/testscreen2.dir/src/Screen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testscreen2.dir/src/Screen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/constantinoflouras/Desktop/GIT/CHIP-8/src/Screen.cpp -o CMakeFiles/testscreen2.dir/src/Screen.cpp.s

CMakeFiles/testscreen2.dir/src/Screen.cpp.o.requires:

.PHONY : CMakeFiles/testscreen2.dir/src/Screen.cpp.o.requires

CMakeFiles/testscreen2.dir/src/Screen.cpp.o.provides: CMakeFiles/testscreen2.dir/src/Screen.cpp.o.requires
	$(MAKE) -f CMakeFiles/testscreen2.dir/build.make CMakeFiles/testscreen2.dir/src/Screen.cpp.o.provides.build
.PHONY : CMakeFiles/testscreen2.dir/src/Screen.cpp.o.provides

CMakeFiles/testscreen2.dir/src/Screen.cpp.o.provides.build: CMakeFiles/testscreen2.dir/src/Screen.cpp.o


# Object files for target testscreen2
testscreen2_OBJECTS = \
"CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.o" \
"CMakeFiles/testscreen2.dir/src/Screen.cpp.o"

# External object files for target testscreen2
testscreen2_EXTERNAL_OBJECTS =

testscreen2: CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.o
testscreen2: CMakeFiles/testscreen2.dir/src/Screen.cpp.o
testscreen2: CMakeFiles/testscreen2.dir/build.make
testscreen2: /usr/lib/x86_64-linux-gnu/libSDL2main.a
testscreen2: /usr/lib/x86_64-linux-gnu/libSDL2.so
testscreen2: CMakeFiles/testscreen2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/constantinoflouras/Desktop/GIT/CHIP-8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable testscreen2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testscreen2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testscreen2.dir/build: testscreen2

.PHONY : CMakeFiles/testscreen2.dir/build

CMakeFiles/testscreen2.dir/requires: CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.o.requires
CMakeFiles/testscreen2.dir/requires: CMakeFiles/testscreen2.dir/src/Screen.cpp.o.requires

.PHONY : CMakeFiles/testscreen2.dir/requires

CMakeFiles/testscreen2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testscreen2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testscreen2.dir/clean

CMakeFiles/testscreen2.dir/depend:
	cd /home/constantinoflouras/Desktop/GIT/CHIP-8 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/constantinoflouras/Desktop/GIT/CHIP-8 /home/constantinoflouras/Desktop/GIT/CHIP-8 /home/constantinoflouras/Desktop/GIT/CHIP-8 /home/constantinoflouras/Desktop/GIT/CHIP-8 /home/constantinoflouras/Desktop/GIT/CHIP-8/CMakeFiles/testscreen2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testscreen2.dir/depend

