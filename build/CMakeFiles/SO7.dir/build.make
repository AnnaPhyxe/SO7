# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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
CMAKE_SOURCE_DIR = "C:\Users\annab\OneDrive\Skrivebord\Programmering 2023\SO7"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\annab\OneDrive\Skrivebord\Programmering 2023\SO7\build"

# Include any dependencies generated for this target.
include CMakeFiles/SO7.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SO7.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SO7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SO7.dir/flags.make

CMakeFiles/SO7.dir/main.cpp.obj: CMakeFiles/SO7.dir/flags.make
CMakeFiles/SO7.dir/main.cpp.obj: CMakeFiles/SO7.dir/includes_CXX.rsp
CMakeFiles/SO7.dir/main.cpp.obj: C:/Users/annab/OneDrive/Skrivebord/Programmering\ 2023/SO7/main.cpp
CMakeFiles/SO7.dir/main.cpp.obj: CMakeFiles/SO7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\annab\OneDrive\Skrivebord\Programmering 2023\SO7\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SO7.dir/main.cpp.obj"
	C:\Users\annab\scoop\apps\mingw\current\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SO7.dir/main.cpp.obj -MF CMakeFiles\SO7.dir\main.cpp.obj.d -o CMakeFiles\SO7.dir\main.cpp.obj -c "C:\Users\annab\OneDrive\Skrivebord\Programmering 2023\SO7\main.cpp"

CMakeFiles/SO7.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SO7.dir/main.cpp.i"
	C:\Users\annab\scoop\apps\mingw\current\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\annab\OneDrive\Skrivebord\Programmering 2023\SO7\main.cpp" > CMakeFiles\SO7.dir\main.cpp.i

CMakeFiles/SO7.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SO7.dir/main.cpp.s"
	C:\Users\annab\scoop\apps\mingw\current\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\annab\OneDrive\Skrivebord\Programmering 2023\SO7\main.cpp" -o CMakeFiles\SO7.dir\main.cpp.s

CMakeFiles/SO7.dir/Game.cpp.obj: CMakeFiles/SO7.dir/flags.make
CMakeFiles/SO7.dir/Game.cpp.obj: CMakeFiles/SO7.dir/includes_CXX.rsp
CMakeFiles/SO7.dir/Game.cpp.obj: C:/Users/annab/OneDrive/Skrivebord/Programmering\ 2023/SO7/Game.cpp
CMakeFiles/SO7.dir/Game.cpp.obj: CMakeFiles/SO7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\annab\OneDrive\Skrivebord\Programmering 2023\SO7\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SO7.dir/Game.cpp.obj"
	C:\Users\annab\scoop\apps\mingw\current\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SO7.dir/Game.cpp.obj -MF CMakeFiles\SO7.dir\Game.cpp.obj.d -o CMakeFiles\SO7.dir\Game.cpp.obj -c "C:\Users\annab\OneDrive\Skrivebord\Programmering 2023\SO7\Game.cpp"

CMakeFiles/SO7.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SO7.dir/Game.cpp.i"
	C:\Users\annab\scoop\apps\mingw\current\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\annab\OneDrive\Skrivebord\Programmering 2023\SO7\Game.cpp" > CMakeFiles\SO7.dir\Game.cpp.i

CMakeFiles/SO7.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SO7.dir/Game.cpp.s"
	C:\Users\annab\scoop\apps\mingw\current\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\annab\OneDrive\Skrivebord\Programmering 2023\SO7\Game.cpp" -o CMakeFiles\SO7.dir\Game.cpp.s

# Object files for target SO7
SO7_OBJECTS = \
"CMakeFiles/SO7.dir/main.cpp.obj" \
"CMakeFiles/SO7.dir/Game.cpp.obj"

# External object files for target SO7
SO7_EXTERNAL_OBJECTS =

SO7.exe: CMakeFiles/SO7.dir/main.cpp.obj
SO7.exe: CMakeFiles/SO7.dir/Game.cpp.obj
SO7.exe: CMakeFiles/SO7.dir/build.make
SO7.exe: CMakeFiles/SO7.dir/linkLibs.rsp
SO7.exe: CMakeFiles/SO7.dir/objects1.rsp
SO7.exe: CMakeFiles/SO7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\annab\OneDrive\Skrivebord\Programmering 2023\SO7\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable SO7.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SO7.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SO7.dir/build: SO7.exe
.PHONY : CMakeFiles/SO7.dir/build

CMakeFiles/SO7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SO7.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SO7.dir/clean

CMakeFiles/SO7.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\annab\OneDrive\Skrivebord\Programmering 2023\SO7" "C:\Users\annab\OneDrive\Skrivebord\Programmering 2023\SO7" "C:\Users\annab\OneDrive\Skrivebord\Programmering 2023\SO7\build" "C:\Users\annab\OneDrive\Skrivebord\Programmering 2023\SO7\build" "C:\Users\annab\OneDrive\Skrivebord\Programmering 2023\SO7\build\CMakeFiles\SO7.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/SO7.dir/depend

