# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\user\Desktop\labs\lab_11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\user\Desktop\labs\lab_11\build

# Include any dependencies generated for this target.
include CMakeFiles/lab_11.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab_11.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab_11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab_11.dir/flags.make

CMakeFiles/lab_11.dir/codegen:
.PHONY : CMakeFiles/lab_11.dir/codegen

CMakeFiles/lab_11.dir/lab_11.cpp.obj: CMakeFiles/lab_11.dir/flags.make
CMakeFiles/lab_11.dir/lab_11.cpp.obj: C:/Users/user/Desktop/labs/lab_11/lab_11.cpp
CMakeFiles/lab_11.dir/lab_11.cpp.obj: CMakeFiles/lab_11.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\user\Desktop\labs\lab_11\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab_11.dir/lab_11.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab_11.dir/lab_11.cpp.obj -MF CMakeFiles\lab_11.dir\lab_11.cpp.obj.d -o CMakeFiles\lab_11.dir\lab_11.cpp.obj -c C:\Users\user\Desktop\labs\lab_11\lab_11.cpp

CMakeFiles/lab_11.dir/lab_11.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab_11.dir/lab_11.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\user\Desktop\labs\lab_11\lab_11.cpp > CMakeFiles\lab_11.dir\lab_11.cpp.i

CMakeFiles/lab_11.dir/lab_11.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab_11.dir/lab_11.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\user\Desktop\labs\lab_11\lab_11.cpp -o CMakeFiles\lab_11.dir\lab_11.cpp.s

# Object files for target lab_11
lab_11_OBJECTS = \
"CMakeFiles/lab_11.dir/lab_11.cpp.obj"

# External object files for target lab_11
lab_11_EXTERNAL_OBJECTS =

lab_11.exe: CMakeFiles/lab_11.dir/lab_11.cpp.obj
lab_11.exe: CMakeFiles/lab_11.dir/build.make
lab_11.exe: CMakeFiles/lab_11.dir/linkLibs.rsp
lab_11.exe: CMakeFiles/lab_11.dir/objects1.rsp
lab_11.exe: CMakeFiles/lab_11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\user\Desktop\labs\lab_11\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab_11.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab_11.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab_11.dir/build: lab_11.exe
.PHONY : CMakeFiles/lab_11.dir/build

CMakeFiles/lab_11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab_11.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab_11.dir/clean

CMakeFiles/lab_11.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\user\Desktop\labs\lab_11 C:\Users\user\Desktop\labs\lab_11 C:\Users\user\Desktop\labs\lab_11\build C:\Users\user\Desktop\labs\lab_11\build C:\Users\user\Desktop\labs\lab_11\build\CMakeFiles\lab_11.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/lab_11.dir/depend

