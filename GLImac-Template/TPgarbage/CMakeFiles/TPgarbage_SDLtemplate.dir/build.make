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
CMAKE_SOURCE_DIR = "/home/6im2/sveysset/Documents/OpenGL 3D/GLImac-Template"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/6im2/sveysset/Documents/OpenGL 3D/GLImac-Template"

# Include any dependencies generated for this target.
include TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/depend.make

# Include the progress variables for this target.
include TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/progress.make

# Include the compile flags for this target's objects.
include TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/flags.make

TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/SDLtemplate.cpp.o: TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/flags.make
TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/SDLtemplate.cpp.o: TPgarbage/SDLtemplate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/6im2/sveysset/Documents/OpenGL 3D/GLImac-Template/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/SDLtemplate.cpp.o"
	cd "/home/6im2/sveysset/Documents/OpenGL 3D/GLImac-Template/TPgarbage" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TPgarbage_SDLtemplate.dir/SDLtemplate.cpp.o -c "/home/6im2/sveysset/Documents/OpenGL 3D/GLImac-Template/TPgarbage/SDLtemplate.cpp"

TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/SDLtemplate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TPgarbage_SDLtemplate.dir/SDLtemplate.cpp.i"
	cd "/home/6im2/sveysset/Documents/OpenGL 3D/GLImac-Template/TPgarbage" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/6im2/sveysset/Documents/OpenGL 3D/GLImac-Template/TPgarbage/SDLtemplate.cpp" > CMakeFiles/TPgarbage_SDLtemplate.dir/SDLtemplate.cpp.i

TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/SDLtemplate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TPgarbage_SDLtemplate.dir/SDLtemplate.cpp.s"
	cd "/home/6im2/sveysset/Documents/OpenGL 3D/GLImac-Template/TPgarbage" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/6im2/sveysset/Documents/OpenGL 3D/GLImac-Template/TPgarbage/SDLtemplate.cpp" -o CMakeFiles/TPgarbage_SDLtemplate.dir/SDLtemplate.cpp.s

TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/SDLtemplate.cpp.o.requires:

.PHONY : TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/SDLtemplate.cpp.o.requires

TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/SDLtemplate.cpp.o.provides: TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/SDLtemplate.cpp.o.requires
	$(MAKE) -f TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/build.make TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/SDLtemplate.cpp.o.provides.build
.PHONY : TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/SDLtemplate.cpp.o.provides

TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/SDLtemplate.cpp.o.provides.build: TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/SDLtemplate.cpp.o


# Object files for target TPgarbage_SDLtemplate
TPgarbage_SDLtemplate_OBJECTS = \
"CMakeFiles/TPgarbage_SDLtemplate.dir/SDLtemplate.cpp.o"

# External object files for target TPgarbage_SDLtemplate
TPgarbage_SDLtemplate_EXTERNAL_OBJECTS =

TPgarbage/TPgarbage_SDLtemplate: TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/SDLtemplate.cpp.o
TPgarbage/TPgarbage_SDLtemplate: TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/build.make
TPgarbage/TPgarbage_SDLtemplate: glimac/libglimac.a
TPgarbage/TPgarbage_SDLtemplate: /usr/lib/x86_64-linux-gnu/libSDLmain.a
TPgarbage/TPgarbage_SDLtemplate: /usr/lib/x86_64-linux-gnu/libSDL.so
TPgarbage/TPgarbage_SDLtemplate: /usr/lib/x86_64-linux-gnu/libGL.so.1
TPgarbage/TPgarbage_SDLtemplate: /usr/lib/x86_64-linux-gnu/libGLEW.so
TPgarbage/TPgarbage_SDLtemplate: TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/6im2/sveysset/Documents/OpenGL 3D/GLImac-Template/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TPgarbage_SDLtemplate"
	cd "/home/6im2/sveysset/Documents/OpenGL 3D/GLImac-Template/TPgarbage" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TPgarbage_SDLtemplate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/build: TPgarbage/TPgarbage_SDLtemplate

.PHONY : TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/build

TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/requires: TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/SDLtemplate.cpp.o.requires

.PHONY : TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/requires

TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/clean:
	cd "/home/6im2/sveysset/Documents/OpenGL 3D/GLImac-Template/TPgarbage" && $(CMAKE_COMMAND) -P CMakeFiles/TPgarbage_SDLtemplate.dir/cmake_clean.cmake
.PHONY : TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/clean

TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/depend:
	cd "/home/6im2/sveysset/Documents/OpenGL 3D/GLImac-Template" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/6im2/sveysset/Documents/OpenGL 3D/GLImac-Template" "/home/6im2/sveysset/Documents/OpenGL 3D/GLImac-Template/TPgarbage" "/home/6im2/sveysset/Documents/OpenGL 3D/GLImac-Template" "/home/6im2/sveysset/Documents/OpenGL 3D/GLImac-Template/TPgarbage" "/home/6im2/sveysset/Documents/OpenGL 3D/GLImac-Template/TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : TPgarbage/CMakeFiles/TPgarbage_SDLtemplate.dir/depend

