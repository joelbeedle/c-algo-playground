# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/joelbeedle/c-data-algo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/joelbeedle/c-data-algo

# Include any dependencies generated for this target.
include tests/CMakeFiles/runTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/runTests.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/runTests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/runTests.dir/flags.make

tests/CMakeFiles/runTests.dir/linked_list_tests.c.o: tests/CMakeFiles/runTests.dir/flags.make
tests/CMakeFiles/runTests.dir/linked_list_tests.c.o: tests/linked_list_tests.c
tests/CMakeFiles/runTests.dir/linked_list_tests.c.o: tests/CMakeFiles/runTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joelbeedle/c-data-algo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/runTests.dir/linked_list_tests.c.o"
	cd /Users/joelbeedle/c-data-algo/tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/runTests.dir/linked_list_tests.c.o -MF CMakeFiles/runTests.dir/linked_list_tests.c.o.d -o CMakeFiles/runTests.dir/linked_list_tests.c.o -c /Users/joelbeedle/c-data-algo/tests/linked_list_tests.c

tests/CMakeFiles/runTests.dir/linked_list_tests.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/runTests.dir/linked_list_tests.c.i"
	cd /Users/joelbeedle/c-data-algo/tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joelbeedle/c-data-algo/tests/linked_list_tests.c > CMakeFiles/runTests.dir/linked_list_tests.c.i

tests/CMakeFiles/runTests.dir/linked_list_tests.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/runTests.dir/linked_list_tests.c.s"
	cd /Users/joelbeedle/c-data-algo/tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joelbeedle/c-data-algo/tests/linked_list_tests.c -o CMakeFiles/runTests.dir/linked_list_tests.c.s

# Object files for target runTests
runTests_OBJECTS = \
"CMakeFiles/runTests.dir/linked_list_tests.c.o"

# External object files for target runTests
runTests_EXTERNAL_OBJECTS =

tests/runTests: tests/CMakeFiles/runTests.dir/linked_list_tests.c.o
tests/runTests: tests/CMakeFiles/runTests.dir/build.make
tests/runTests: /opt/homebrew/lib/libcheck.dylib
tests/runTests: tests/CMakeFiles/runTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/joelbeedle/c-data-algo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable runTests"
	cd /Users/joelbeedle/c-data-algo/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/runTests.dir/build: tests/runTests
.PHONY : tests/CMakeFiles/runTests.dir/build

tests/CMakeFiles/runTests.dir/clean:
	cd /Users/joelbeedle/c-data-algo/tests && $(CMAKE_COMMAND) -P CMakeFiles/runTests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/runTests.dir/clean

tests/CMakeFiles/runTests.dir/depend:
	cd /Users/joelbeedle/c-data-algo && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/joelbeedle/c-data-algo /Users/joelbeedle/c-data-algo/tests /Users/joelbeedle/c-data-algo /Users/joelbeedle/c-data-algo/tests /Users/joelbeedle/c-data-algo/tests/CMakeFiles/runTests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/runTests.dir/depend

