# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/madatt/Desktop/star

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/madatt/Desktop/star/releases

# Include any dependencies generated for this target.
include CMakeFiles/Star.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Star.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Star.dir/flags.make

CMakeFiles/Star.dir/main.cpp.o: CMakeFiles/Star.dir/flags.make
CMakeFiles/Star.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/madatt/Desktop/star/releases/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Star.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Star.dir/main.cpp.o -c /home/madatt/Desktop/star/main.cpp

CMakeFiles/Star.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Star.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/madatt/Desktop/star/main.cpp > CMakeFiles/Star.dir/main.cpp.i

CMakeFiles/Star.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Star.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/madatt/Desktop/star/main.cpp -o CMakeFiles/Star.dir/main.cpp.s

CMakeFiles/Star.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Star.dir/main.cpp.o.requires

CMakeFiles/Star.dir/main.cpp.o.provides: CMakeFiles/Star.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Star.dir/build.make CMakeFiles/Star.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Star.dir/main.cpp.o.provides

CMakeFiles/Star.dir/main.cpp.o.provides.build: CMakeFiles/Star.dir/main.cpp.o


CMakeFiles/Star.dir/sources/files_io.cpp.o: CMakeFiles/Star.dir/flags.make
CMakeFiles/Star.dir/sources/files_io.cpp.o: ../sources/files_io.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/madatt/Desktop/star/releases/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Star.dir/sources/files_io.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Star.dir/sources/files_io.cpp.o -c /home/madatt/Desktop/star/sources/files_io.cpp

CMakeFiles/Star.dir/sources/files_io.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Star.dir/sources/files_io.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/madatt/Desktop/star/sources/files_io.cpp > CMakeFiles/Star.dir/sources/files_io.cpp.i

CMakeFiles/Star.dir/sources/files_io.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Star.dir/sources/files_io.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/madatt/Desktop/star/sources/files_io.cpp -o CMakeFiles/Star.dir/sources/files_io.cpp.s

CMakeFiles/Star.dir/sources/files_io.cpp.o.requires:

.PHONY : CMakeFiles/Star.dir/sources/files_io.cpp.o.requires

CMakeFiles/Star.dir/sources/files_io.cpp.o.provides: CMakeFiles/Star.dir/sources/files_io.cpp.o.requires
	$(MAKE) -f CMakeFiles/Star.dir/build.make CMakeFiles/Star.dir/sources/files_io.cpp.o.provides.build
.PHONY : CMakeFiles/Star.dir/sources/files_io.cpp.o.provides

CMakeFiles/Star.dir/sources/files_io.cpp.o.provides.build: CMakeFiles/Star.dir/sources/files_io.cpp.o


# Object files for target Star
Star_OBJECTS = \
"CMakeFiles/Star.dir/main.cpp.o" \
"CMakeFiles/Star.dir/sources/files_io.cpp.o"

# External object files for target Star
Star_EXTERNAL_OBJECTS =

Star: CMakeFiles/Star.dir/main.cpp.o
Star: CMakeFiles/Star.dir/sources/files_io.cpp.o
Star: CMakeFiles/Star.dir/build.make
Star: CMakeFiles/Star.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/madatt/Desktop/star/releases/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Star"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Star.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Star.dir/build: Star

.PHONY : CMakeFiles/Star.dir/build

CMakeFiles/Star.dir/requires: CMakeFiles/Star.dir/main.cpp.o.requires
CMakeFiles/Star.dir/requires: CMakeFiles/Star.dir/sources/files_io.cpp.o.requires

.PHONY : CMakeFiles/Star.dir/requires

CMakeFiles/Star.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Star.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Star.dir/clean

CMakeFiles/Star.dir/depend:
	cd /home/madatt/Desktop/star/releases && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/madatt/Desktop/star /home/madatt/Desktop/star /home/madatt/Desktop/star/releases /home/madatt/Desktop/star/releases /home/madatt/Desktop/star/releases/CMakeFiles/Star.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Star.dir/depend

