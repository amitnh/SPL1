# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /users/studs/bsc/2020/kapelnik/Desktop/clion-2019.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /users/studs/bsc/2020/kapelnik/Desktop/clion-2019.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /users/studs/bsc/2020/kapelnik/Desktop/SPL1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /users/studs/bsc/2020/kapelnik/Desktop/SPL1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/spl1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/spl1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/spl1.dir/flags.make

CMakeFiles/spl1.dir/src/Main.cpp.o: CMakeFiles/spl1.dir/flags.make
CMakeFiles/spl1.dir/src/Main.cpp.o: ../src/Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2020/kapelnik/Desktop/SPL1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/spl1.dir/src/Main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/spl1.dir/src/Main.cpp.o -c /users/studs/bsc/2020/kapelnik/Desktop/SPL1/src/Main.cpp

CMakeFiles/spl1.dir/src/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spl1.dir/src/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2020/kapelnik/Desktop/SPL1/src/Main.cpp > CMakeFiles/spl1.dir/src/Main.cpp.i

CMakeFiles/spl1.dir/src/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spl1.dir/src/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2020/kapelnik/Desktop/SPL1/src/Main.cpp -o CMakeFiles/spl1.dir/src/Main.cpp.s

CMakeFiles/spl1.dir/src/Action.cpp.o: CMakeFiles/spl1.dir/flags.make
CMakeFiles/spl1.dir/src/Action.cpp.o: ../src/Action.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2020/kapelnik/Desktop/SPL1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/spl1.dir/src/Action.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/spl1.dir/src/Action.cpp.o -c /users/studs/bsc/2020/kapelnik/Desktop/SPL1/src/Action.cpp

CMakeFiles/spl1.dir/src/Action.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spl1.dir/src/Action.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2020/kapelnik/Desktop/SPL1/src/Action.cpp > CMakeFiles/spl1.dir/src/Action.cpp.i

CMakeFiles/spl1.dir/src/Action.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spl1.dir/src/Action.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2020/kapelnik/Desktop/SPL1/src/Action.cpp -o CMakeFiles/spl1.dir/src/Action.cpp.s

CMakeFiles/spl1.dir/src/Session.cpp.o: CMakeFiles/spl1.dir/flags.make
CMakeFiles/spl1.dir/src/Session.cpp.o: ../src/Session.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2020/kapelnik/Desktop/SPL1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/spl1.dir/src/Session.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/spl1.dir/src/Session.cpp.o -c /users/studs/bsc/2020/kapelnik/Desktop/SPL1/src/Session.cpp

CMakeFiles/spl1.dir/src/Session.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spl1.dir/src/Session.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2020/kapelnik/Desktop/SPL1/src/Session.cpp > CMakeFiles/spl1.dir/src/Session.cpp.i

CMakeFiles/spl1.dir/src/Session.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spl1.dir/src/Session.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2020/kapelnik/Desktop/SPL1/src/Session.cpp -o CMakeFiles/spl1.dir/src/Session.cpp.s

CMakeFiles/spl1.dir/src/User.cpp.o: CMakeFiles/spl1.dir/flags.make
CMakeFiles/spl1.dir/src/User.cpp.o: ../src/User.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2020/kapelnik/Desktop/SPL1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/spl1.dir/src/User.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/spl1.dir/src/User.cpp.o -c /users/studs/bsc/2020/kapelnik/Desktop/SPL1/src/User.cpp

CMakeFiles/spl1.dir/src/User.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spl1.dir/src/User.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2020/kapelnik/Desktop/SPL1/src/User.cpp > CMakeFiles/spl1.dir/src/User.cpp.i

CMakeFiles/spl1.dir/src/User.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spl1.dir/src/User.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2020/kapelnik/Desktop/SPL1/src/User.cpp -o CMakeFiles/spl1.dir/src/User.cpp.s

CMakeFiles/spl1.dir/src/Watchable.cpp.o: CMakeFiles/spl1.dir/flags.make
CMakeFiles/spl1.dir/src/Watchable.cpp.o: ../src/Watchable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2020/kapelnik/Desktop/SPL1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/spl1.dir/src/Watchable.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/spl1.dir/src/Watchable.cpp.o -c /users/studs/bsc/2020/kapelnik/Desktop/SPL1/src/Watchable.cpp

CMakeFiles/spl1.dir/src/Watchable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spl1.dir/src/Watchable.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2020/kapelnik/Desktop/SPL1/src/Watchable.cpp > CMakeFiles/spl1.dir/src/Watchable.cpp.i

CMakeFiles/spl1.dir/src/Watchable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spl1.dir/src/Watchable.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2020/kapelnik/Desktop/SPL1/src/Watchable.cpp -o CMakeFiles/spl1.dir/src/Watchable.cpp.s

# Object files for target spl1
spl1_OBJECTS = \
"CMakeFiles/spl1.dir/src/Main.cpp.o" \
"CMakeFiles/spl1.dir/src/Action.cpp.o" \
"CMakeFiles/spl1.dir/src/Session.cpp.o" \
"CMakeFiles/spl1.dir/src/User.cpp.o" \
"CMakeFiles/spl1.dir/src/Watchable.cpp.o"

# External object files for target spl1
spl1_EXTERNAL_OBJECTS =

spl1: CMakeFiles/spl1.dir/src/Main.cpp.o
spl1: CMakeFiles/spl1.dir/src/Action.cpp.o
spl1: CMakeFiles/spl1.dir/src/Session.cpp.o
spl1: CMakeFiles/spl1.dir/src/User.cpp.o
spl1: CMakeFiles/spl1.dir/src/Watchable.cpp.o
spl1: CMakeFiles/spl1.dir/build.make
spl1: CMakeFiles/spl1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/users/studs/bsc/2020/kapelnik/Desktop/SPL1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable spl1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/spl1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/spl1.dir/build: spl1

.PHONY : CMakeFiles/spl1.dir/build

CMakeFiles/spl1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/spl1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/spl1.dir/clean

CMakeFiles/spl1.dir/depend:
	cd /users/studs/bsc/2020/kapelnik/Desktop/SPL1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /users/studs/bsc/2020/kapelnik/Desktop/SPL1 /users/studs/bsc/2020/kapelnik/Desktop/SPL1 /users/studs/bsc/2020/kapelnik/Desktop/SPL1/cmake-build-debug /users/studs/bsc/2020/kapelnik/Desktop/SPL1/cmake-build-debug /users/studs/bsc/2020/kapelnik/Desktop/SPL1/cmake-build-debug/CMakeFiles/spl1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/spl1.dir/depend

