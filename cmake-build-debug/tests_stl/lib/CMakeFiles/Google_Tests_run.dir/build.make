# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lmallado/Desktop/ft_containers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lmallado/Desktop/ft_containers/cmake-build-debug

# Include any dependencies generated for this target.
include tests_stl/lib/CMakeFiles/Google_Tests_run.dir/depend.make

# Include the progress variables for this target.
include tests_stl/lib/CMakeFiles/Google_Tests_run.dir/progress.make

# Include the compile flags for this target's objects.
include tests_stl/lib/CMakeFiles/Google_Tests_run.dir/flags.make

tests_stl/lib/CMakeFiles/Google_Tests_run.dir/test.cpp.o: tests_stl/lib/CMakeFiles/Google_Tests_run.dir/flags.make
tests_stl/lib/CMakeFiles/Google_Tests_run.dir/test.cpp.o: ../tests_stl/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lmallado/Desktop/ft_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests_stl/lib/CMakeFiles/Google_Tests_run.dir/test.cpp.o"
	cd /Users/lmallado/Desktop/ft_containers/cmake-build-debug/tests_stl/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Google_Tests_run.dir/test.cpp.o -c /Users/lmallado/Desktop/ft_containers/tests_stl/test.cpp

tests_stl/lib/CMakeFiles/Google_Tests_run.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_Tests_run.dir/test.cpp.i"
	cd /Users/lmallado/Desktop/ft_containers/cmake-build-debug/tests_stl/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lmallado/Desktop/ft_containers/tests_stl/test.cpp > CMakeFiles/Google_Tests_run.dir/test.cpp.i

tests_stl/lib/CMakeFiles/Google_Tests_run.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_Tests_run.dir/test.cpp.s"
	cd /Users/lmallado/Desktop/ft_containers/cmake-build-debug/tests_stl/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lmallado/Desktop/ft_containers/tests_stl/test.cpp -o CMakeFiles/Google_Tests_run.dir/test.cpp.s

tests_stl/lib/CMakeFiles/Google_Tests_run.dir/general_stuff.cpp.o: tests_stl/lib/CMakeFiles/Google_Tests_run.dir/flags.make
tests_stl/lib/CMakeFiles/Google_Tests_run.dir/general_stuff.cpp.o: ../tests_stl/general_stuff.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lmallado/Desktop/ft_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests_stl/lib/CMakeFiles/Google_Tests_run.dir/general_stuff.cpp.o"
	cd /Users/lmallado/Desktop/ft_containers/cmake-build-debug/tests_stl/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Google_Tests_run.dir/general_stuff.cpp.o -c /Users/lmallado/Desktop/ft_containers/tests_stl/general_stuff.cpp

tests_stl/lib/CMakeFiles/Google_Tests_run.dir/general_stuff.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_Tests_run.dir/general_stuff.cpp.i"
	cd /Users/lmallado/Desktop/ft_containers/cmake-build-debug/tests_stl/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lmallado/Desktop/ft_containers/tests_stl/general_stuff.cpp > CMakeFiles/Google_Tests_run.dir/general_stuff.cpp.i

tests_stl/lib/CMakeFiles/Google_Tests_run.dir/general_stuff.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_Tests_run.dir/general_stuff.cpp.s"
	cd /Users/lmallado/Desktop/ft_containers/cmake-build-debug/tests_stl/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lmallado/Desktop/ft_containers/tests_stl/general_stuff.cpp -o CMakeFiles/Google_Tests_run.dir/general_stuff.cpp.s

tests_stl/lib/CMakeFiles/Google_Tests_run.dir/vector_test.cpp.o: tests_stl/lib/CMakeFiles/Google_Tests_run.dir/flags.make
tests_stl/lib/CMakeFiles/Google_Tests_run.dir/vector_test.cpp.o: ../tests_stl/vector_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lmallado/Desktop/ft_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tests_stl/lib/CMakeFiles/Google_Tests_run.dir/vector_test.cpp.o"
	cd /Users/lmallado/Desktop/ft_containers/cmake-build-debug/tests_stl/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Google_Tests_run.dir/vector_test.cpp.o -c /Users/lmallado/Desktop/ft_containers/tests_stl/vector_test.cpp

tests_stl/lib/CMakeFiles/Google_Tests_run.dir/vector_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_Tests_run.dir/vector_test.cpp.i"
	cd /Users/lmallado/Desktop/ft_containers/cmake-build-debug/tests_stl/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lmallado/Desktop/ft_containers/tests_stl/vector_test.cpp > CMakeFiles/Google_Tests_run.dir/vector_test.cpp.i

tests_stl/lib/CMakeFiles/Google_Tests_run.dir/vector_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_Tests_run.dir/vector_test.cpp.s"
	cd /Users/lmallado/Desktop/ft_containers/cmake-build-debug/tests_stl/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lmallado/Desktop/ft_containers/tests_stl/vector_test.cpp -o CMakeFiles/Google_Tests_run.dir/vector_test.cpp.s

tests_stl/lib/CMakeFiles/Google_Tests_run.dir/list_test.cpp.o: tests_stl/lib/CMakeFiles/Google_Tests_run.dir/flags.make
tests_stl/lib/CMakeFiles/Google_Tests_run.dir/list_test.cpp.o: ../tests_stl/list_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lmallado/Desktop/ft_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object tests_stl/lib/CMakeFiles/Google_Tests_run.dir/list_test.cpp.o"
	cd /Users/lmallado/Desktop/ft_containers/cmake-build-debug/tests_stl/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Google_Tests_run.dir/list_test.cpp.o -c /Users/lmallado/Desktop/ft_containers/tests_stl/list_test.cpp

tests_stl/lib/CMakeFiles/Google_Tests_run.dir/list_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_Tests_run.dir/list_test.cpp.i"
	cd /Users/lmallado/Desktop/ft_containers/cmake-build-debug/tests_stl/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lmallado/Desktop/ft_containers/tests_stl/list_test.cpp > CMakeFiles/Google_Tests_run.dir/list_test.cpp.i

tests_stl/lib/CMakeFiles/Google_Tests_run.dir/list_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_Tests_run.dir/list_test.cpp.s"
	cd /Users/lmallado/Desktop/ft_containers/cmake-build-debug/tests_stl/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lmallado/Desktop/ft_containers/tests_stl/list_test.cpp -o CMakeFiles/Google_Tests_run.dir/list_test.cpp.s

# Object files for target Google_Tests_run
Google_Tests_run_OBJECTS = \
"CMakeFiles/Google_Tests_run.dir/test.cpp.o" \
"CMakeFiles/Google_Tests_run.dir/general_stuff.cpp.o" \
"CMakeFiles/Google_Tests_run.dir/vector_test.cpp.o" \
"CMakeFiles/Google_Tests_run.dir/list_test.cpp.o"

# External object files for target Google_Tests_run
Google_Tests_run_EXTERNAL_OBJECTS =

tests_stl/lib/Google_Tests_run: tests_stl/lib/CMakeFiles/Google_Tests_run.dir/test.cpp.o
tests_stl/lib/Google_Tests_run: tests_stl/lib/CMakeFiles/Google_Tests_run.dir/general_stuff.cpp.o
tests_stl/lib/Google_Tests_run: tests_stl/lib/CMakeFiles/Google_Tests_run.dir/vector_test.cpp.o
tests_stl/lib/Google_Tests_run: tests_stl/lib/CMakeFiles/Google_Tests_run.dir/list_test.cpp.o
tests_stl/lib/Google_Tests_run: tests_stl/lib/CMakeFiles/Google_Tests_run.dir/build.make
tests_stl/lib/Google_Tests_run: lib/libgtestd.a
tests_stl/lib/Google_Tests_run: lib/libgtest_maind.a
tests_stl/lib/Google_Tests_run: lib/libgtestd.a
tests_stl/lib/Google_Tests_run: tests_stl/lib/CMakeFiles/Google_Tests_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lmallado/Desktop/ft_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Google_Tests_run"
	cd /Users/lmallado/Desktop/ft_containers/cmake-build-debug/tests_stl/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Google_Tests_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests_stl/lib/CMakeFiles/Google_Tests_run.dir/build: tests_stl/lib/Google_Tests_run

.PHONY : tests_stl/lib/CMakeFiles/Google_Tests_run.dir/build

tests_stl/lib/CMakeFiles/Google_Tests_run.dir/clean:
	cd /Users/lmallado/Desktop/ft_containers/cmake-build-debug/tests_stl/lib && $(CMAKE_COMMAND) -P CMakeFiles/Google_Tests_run.dir/cmake_clean.cmake
.PHONY : tests_stl/lib/CMakeFiles/Google_Tests_run.dir/clean

tests_stl/lib/CMakeFiles/Google_Tests_run.dir/depend:
	cd /Users/lmallado/Desktop/ft_containers/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lmallado/Desktop/ft_containers /Users/lmallado/Desktop/ft_containers/tests_stl /Users/lmallado/Desktop/ft_containers/cmake-build-debug /Users/lmallado/Desktop/ft_containers/cmake-build-debug/tests_stl/lib /Users/lmallado/Desktop/ft_containers/cmake-build-debug/tests_stl/lib/CMakeFiles/Google_Tests_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests_stl/lib/CMakeFiles/Google_Tests_run.dir/depend

