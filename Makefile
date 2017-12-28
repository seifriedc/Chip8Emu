# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/local/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/constantinoflouras/Desktop/GIT/CHIP-8/CMakeFiles /home/constantinoflouras/Desktop/GIT/CHIP-8/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/constantinoflouras/Desktop/GIT/CHIP-8/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named testscreen2

# Build rule for target.
testscreen2: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 testscreen2
.PHONY : testscreen2

# fast build rule for target.
testscreen2/fast:
	$(MAKE) -f CMakeFiles/testscreen2.dir/build.make CMakeFiles/testscreen2.dir/build
.PHONY : testscreen2/fast

#=============================================================================
# Target rules for targets named testscreen1

# Build rule for target.
testscreen1: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 testscreen1
.PHONY : testscreen1

# fast build rule for target.
testscreen1/fast:
	$(MAKE) -f CMakeFiles/testscreen1.dir/build.make CMakeFiles/testscreen1.dir/build
.PHONY : testscreen1/fast

#=============================================================================
# Target rules for targets named chip8dis

# Build rule for target.
chip8dis: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 chip8dis
.PHONY : chip8dis

# fast build rule for target.
chip8dis/fast:
	$(MAKE) -f CMakeFiles/chip8dis.dir/build.make CMakeFiles/chip8dis.dir/build
.PHONY : chip8dis/fast

#=============================================================================
# Target rules for targets named chip8emu

# Build rule for target.
chip8emu: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 chip8emu
.PHONY : chip8emu

# fast build rule for target.
chip8emu/fast:
	$(MAKE) -f CMakeFiles/chip8emu.dir/build.make CMakeFiles/chip8emu.dir/build
.PHONY : chip8emu/fast

src/CHIP8Cpu.o: src/CHIP8Cpu.cpp.o

.PHONY : src/CHIP8Cpu.o

# target to build an object file
src/CHIP8Cpu.cpp.o:
	$(MAKE) -f CMakeFiles/chip8emu.dir/build.make CMakeFiles/chip8emu.dir/src/CHIP8Cpu.cpp.o
.PHONY : src/CHIP8Cpu.cpp.o

src/CHIP8Cpu.i: src/CHIP8Cpu.cpp.i

.PHONY : src/CHIP8Cpu.i

# target to preprocess a source file
src/CHIP8Cpu.cpp.i:
	$(MAKE) -f CMakeFiles/chip8emu.dir/build.make CMakeFiles/chip8emu.dir/src/CHIP8Cpu.cpp.i
.PHONY : src/CHIP8Cpu.cpp.i

src/CHIP8Cpu.s: src/CHIP8Cpu.cpp.s

.PHONY : src/CHIP8Cpu.s

# target to generate assembly for a file
src/CHIP8Cpu.cpp.s:
	$(MAKE) -f CMakeFiles/chip8emu.dir/build.make CMakeFiles/chip8emu.dir/src/CHIP8Cpu.cpp.s
.PHONY : src/CHIP8Cpu.cpp.s

src/CHIP8Emu.o: src/CHIP8Emu.cpp.o

.PHONY : src/CHIP8Emu.o

# target to build an object file
src/CHIP8Emu.cpp.o:
	$(MAKE) -f CMakeFiles/chip8emu.dir/build.make CMakeFiles/chip8emu.dir/src/CHIP8Emu.cpp.o
.PHONY : src/CHIP8Emu.cpp.o

src/CHIP8Emu.i: src/CHIP8Emu.cpp.i

.PHONY : src/CHIP8Emu.i

# target to preprocess a source file
src/CHIP8Emu.cpp.i:
	$(MAKE) -f CMakeFiles/chip8emu.dir/build.make CMakeFiles/chip8emu.dir/src/CHIP8Emu.cpp.i
.PHONY : src/CHIP8Emu.cpp.i

src/CHIP8Emu.s: src/CHIP8Emu.cpp.s

.PHONY : src/CHIP8Emu.s

# target to generate assembly for a file
src/CHIP8Emu.cpp.s:
	$(MAKE) -f CMakeFiles/chip8emu.dir/build.make CMakeFiles/chip8emu.dir/src/CHIP8Emu.cpp.s
.PHONY : src/CHIP8Emu.cpp.s

src/Screen.o: src/Screen.cpp.o

.PHONY : src/Screen.o

# target to build an object file
src/Screen.cpp.o:
	$(MAKE) -f CMakeFiles/testscreen2.dir/build.make CMakeFiles/testscreen2.dir/src/Screen.cpp.o
	$(MAKE) -f CMakeFiles/testscreen1.dir/build.make CMakeFiles/testscreen1.dir/src/Screen.cpp.o
	$(MAKE) -f CMakeFiles/chip8emu.dir/build.make CMakeFiles/chip8emu.dir/src/Screen.cpp.o
.PHONY : src/Screen.cpp.o

src/Screen.i: src/Screen.cpp.i

.PHONY : src/Screen.i

# target to preprocess a source file
src/Screen.cpp.i:
	$(MAKE) -f CMakeFiles/testscreen2.dir/build.make CMakeFiles/testscreen2.dir/src/Screen.cpp.i
	$(MAKE) -f CMakeFiles/testscreen1.dir/build.make CMakeFiles/testscreen1.dir/src/Screen.cpp.i
	$(MAKE) -f CMakeFiles/chip8emu.dir/build.make CMakeFiles/chip8emu.dir/src/Screen.cpp.i
.PHONY : src/Screen.cpp.i

src/Screen.s: src/Screen.cpp.s

.PHONY : src/Screen.s

# target to generate assembly for a file
src/Screen.cpp.s:
	$(MAKE) -f CMakeFiles/testscreen2.dir/build.make CMakeFiles/testscreen2.dir/src/Screen.cpp.s
	$(MAKE) -f CMakeFiles/testscreen1.dir/build.make CMakeFiles/testscreen1.dir/src/Screen.cpp.s
	$(MAKE) -f CMakeFiles/chip8emu.dir/build.make CMakeFiles/chip8emu.dir/src/Screen.cpp.s
.PHONY : src/Screen.cpp.s

src/chip8dis/CHIP8Dis.o: src/chip8dis/CHIP8Dis.c.o

.PHONY : src/chip8dis/CHIP8Dis.o

# target to build an object file
src/chip8dis/CHIP8Dis.c.o:
	$(MAKE) -f CMakeFiles/chip8dis.dir/build.make CMakeFiles/chip8dis.dir/src/chip8dis/CHIP8Dis.c.o
.PHONY : src/chip8dis/CHIP8Dis.c.o

src/chip8dis/CHIP8Dis.i: src/chip8dis/CHIP8Dis.c.i

.PHONY : src/chip8dis/CHIP8Dis.i

# target to preprocess a source file
src/chip8dis/CHIP8Dis.c.i:
	$(MAKE) -f CMakeFiles/chip8dis.dir/build.make CMakeFiles/chip8dis.dir/src/chip8dis/CHIP8Dis.c.i
.PHONY : src/chip8dis/CHIP8Dis.c.i

src/chip8dis/CHIP8Dis.s: src/chip8dis/CHIP8Dis.c.s

.PHONY : src/chip8dis/CHIP8Dis.s

# target to generate assembly for a file
src/chip8dis/CHIP8Dis.c.s:
	$(MAKE) -f CMakeFiles/chip8dis.dir/build.make CMakeFiles/chip8dis.dir/src/chip8dis/CHIP8Dis.c.s
.PHONY : src/chip8dis/CHIP8Dis.c.s

src/tests/screen/screen_testing.o: src/tests/screen/screen_testing.cpp.o

.PHONY : src/tests/screen/screen_testing.o

# target to build an object file
src/tests/screen/screen_testing.cpp.o:
	$(MAKE) -f CMakeFiles/testscreen1.dir/build.make CMakeFiles/testscreen1.dir/src/tests/screen/screen_testing.cpp.o
.PHONY : src/tests/screen/screen_testing.cpp.o

src/tests/screen/screen_testing.i: src/tests/screen/screen_testing.cpp.i

.PHONY : src/tests/screen/screen_testing.i

# target to preprocess a source file
src/tests/screen/screen_testing.cpp.i:
	$(MAKE) -f CMakeFiles/testscreen1.dir/build.make CMakeFiles/testscreen1.dir/src/tests/screen/screen_testing.cpp.i
.PHONY : src/tests/screen/screen_testing.cpp.i

src/tests/screen/screen_testing.s: src/tests/screen/screen_testing.cpp.s

.PHONY : src/tests/screen/screen_testing.s

# target to generate assembly for a file
src/tests/screen/screen_testing.cpp.s:
	$(MAKE) -f CMakeFiles/testscreen1.dir/build.make CMakeFiles/testscreen1.dir/src/tests/screen/screen_testing.cpp.s
.PHONY : src/tests/screen/screen_testing.cpp.s

src/tests/screen/test.o: src/tests/screen/test.cpp.o

.PHONY : src/tests/screen/test.o

# target to build an object file
src/tests/screen/test.cpp.o:
	$(MAKE) -f CMakeFiles/testscreen2.dir/build.make CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.o
.PHONY : src/tests/screen/test.cpp.o

src/tests/screen/test.i: src/tests/screen/test.cpp.i

.PHONY : src/tests/screen/test.i

# target to preprocess a source file
src/tests/screen/test.cpp.i:
	$(MAKE) -f CMakeFiles/testscreen2.dir/build.make CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.i
.PHONY : src/tests/screen/test.cpp.i

src/tests/screen/test.s: src/tests/screen/test.cpp.s

.PHONY : src/tests/screen/test.s

# target to generate assembly for a file
src/tests/screen/test.cpp.s:
	$(MAKE) -f CMakeFiles/testscreen2.dir/build.make CMakeFiles/testscreen2.dir/src/tests/screen/test.cpp.s
.PHONY : src/tests/screen/test.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... testscreen2"
	@echo "... testscreen1"
	@echo "... chip8dis"
	@echo "... chip8emu"
	@echo "... src/CHIP8Cpu.o"
	@echo "... src/CHIP8Cpu.i"
	@echo "... src/CHIP8Cpu.s"
	@echo "... src/CHIP8Emu.o"
	@echo "... src/CHIP8Emu.i"
	@echo "... src/CHIP8Emu.s"
	@echo "... src/Screen.o"
	@echo "... src/Screen.i"
	@echo "... src/Screen.s"
	@echo "... src/chip8dis/CHIP8Dis.o"
	@echo "... src/chip8dis/CHIP8Dis.i"
	@echo "... src/chip8dis/CHIP8Dis.s"
	@echo "... src/tests/screen/screen_testing.o"
	@echo "... src/tests/screen/screen_testing.i"
	@echo "... src/tests/screen/screen_testing.s"
	@echo "... src/tests/screen/test.o"
	@echo "... src/tests/screen/test.i"
	@echo "... src/tests/screen/test.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

