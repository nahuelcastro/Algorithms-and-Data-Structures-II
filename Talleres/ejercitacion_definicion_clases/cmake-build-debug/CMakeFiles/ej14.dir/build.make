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
CMAKE_COMMAND = /snap/clion/113/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/113/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nahuel/Desktop/algo2/Taller/ejercitacion_definicion_clases

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nahuel/Desktop/algo2/Taller/ejercitacion_definicion_clases/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ej14.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ej14.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ej14.dir/flags.make

CMakeFiles/ej14.dir/tests/test_recordatorios.cpp.o: CMakeFiles/ej14.dir/flags.make
CMakeFiles/ej14.dir/tests/test_recordatorios.cpp.o: ../tests/test_recordatorios.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nahuel/Desktop/algo2/Taller/ejercitacion_definicion_clases/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ej14.dir/tests/test_recordatorios.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ej14.dir/tests/test_recordatorios.cpp.o -c /home/nahuel/Desktop/algo2/Taller/ejercitacion_definicion_clases/tests/test_recordatorios.cpp

CMakeFiles/ej14.dir/tests/test_recordatorios.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ej14.dir/tests/test_recordatorios.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nahuel/Desktop/algo2/Taller/ejercitacion_definicion_clases/tests/test_recordatorios.cpp > CMakeFiles/ej14.dir/tests/test_recordatorios.cpp.i

CMakeFiles/ej14.dir/tests/test_recordatorios.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ej14.dir/tests/test_recordatorios.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nahuel/Desktop/algo2/Taller/ejercitacion_definicion_clases/tests/test_recordatorios.cpp -o CMakeFiles/ej14.dir/tests/test_recordatorios.cpp.s

# Object files for target ej14
ej14_OBJECTS = \
"CMakeFiles/ej14.dir/tests/test_recordatorios.cpp.o"

# External object files for target ej14
ej14_EXTERNAL_OBJECTS =

ej14: CMakeFiles/ej14.dir/tests/test_recordatorios.cpp.o
ej14: CMakeFiles/ej14.dir/build.make
ej14: libgtest.a
ej14: libgtest_main.a
ej14: CMakeFiles/ej14.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nahuel/Desktop/algo2/Taller/ejercitacion_definicion_clases/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ej14"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ej14.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ej14.dir/build: ej14

.PHONY : CMakeFiles/ej14.dir/build

CMakeFiles/ej14.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ej14.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ej14.dir/clean

CMakeFiles/ej14.dir/depend:
	cd /home/nahuel/Desktop/algo2/Taller/ejercitacion_definicion_clases/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nahuel/Desktop/algo2/Taller/ejercitacion_definicion_clases /home/nahuel/Desktop/algo2/Taller/ejercitacion_definicion_clases /home/nahuel/Desktop/algo2/Taller/ejercitacion_definicion_clases/cmake-build-debug /home/nahuel/Desktop/algo2/Taller/ejercitacion_definicion_clases/cmake-build-debug /home/nahuel/Desktop/algo2/Taller/ejercitacion_definicion_clases/cmake-build-debug/CMakeFiles/ej14.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ej14.dir/depend

