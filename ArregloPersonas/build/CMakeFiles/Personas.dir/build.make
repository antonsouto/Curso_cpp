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
CMAKE_SOURCE_DIR = /home/anton/Desktop/Proyecto/Pruebas/ArregloPersonas

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anton/Desktop/Proyecto/Pruebas/ArregloPersonas/build

# Include any dependencies generated for this target.
include CMakeFiles/Personas.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Personas.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Personas.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Personas.dir/flags.make

CMakeFiles/Personas.dir/main.cpp.o: CMakeFiles/Personas.dir/flags.make
CMakeFiles/Personas.dir/main.cpp.o: ../main.cpp
CMakeFiles/Personas.dir/main.cpp.o: CMakeFiles/Personas.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anton/Desktop/Proyecto/Pruebas/ArregloPersonas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Personas.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Personas.dir/main.cpp.o -MF CMakeFiles/Personas.dir/main.cpp.o.d -o CMakeFiles/Personas.dir/main.cpp.o -c /home/anton/Desktop/Proyecto/Pruebas/ArregloPersonas/main.cpp

CMakeFiles/Personas.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Personas.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton/Desktop/Proyecto/Pruebas/ArregloPersonas/main.cpp > CMakeFiles/Personas.dir/main.cpp.i

CMakeFiles/Personas.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Personas.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton/Desktop/Proyecto/Pruebas/ArregloPersonas/main.cpp -o CMakeFiles/Personas.dir/main.cpp.s

# Object files for target Personas
Personas_OBJECTS = \
"CMakeFiles/Personas.dir/main.cpp.o"

# External object files for target Personas
Personas_EXTERNAL_OBJECTS =

Personas: CMakeFiles/Personas.dir/main.cpp.o
Personas: CMakeFiles/Personas.dir/build.make
Personas: CMakeFiles/Personas.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anton/Desktop/Proyecto/Pruebas/ArregloPersonas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Personas"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Personas.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Personas.dir/build: Personas
.PHONY : CMakeFiles/Personas.dir/build

CMakeFiles/Personas.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Personas.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Personas.dir/clean

CMakeFiles/Personas.dir/depend:
	cd /home/anton/Desktop/Proyecto/Pruebas/ArregloPersonas/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anton/Desktop/Proyecto/Pruebas/ArregloPersonas /home/anton/Desktop/Proyecto/Pruebas/ArregloPersonas /home/anton/Desktop/Proyecto/Pruebas/ArregloPersonas/build /home/anton/Desktop/Proyecto/Pruebas/ArregloPersonas/build /home/anton/Desktop/Proyecto/Pruebas/ArregloPersonas/build/CMakeFiles/Personas.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Personas.dir/depend

