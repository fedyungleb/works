# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\User\CLionProjects\Tasks\Sorting Algorithms"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\User\CLionProjects\Tasks\Sorting Algorithms\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Task2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Task2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task2.dir/flags.make

CMakeFiles/Task2.dir/main.cpp.obj: CMakeFiles/Task2.dir/flags.make
CMakeFiles/Task2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\User\CLionProjects\Tasks\Sorting Algorithms\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Task2.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Task2.dir\main.cpp.obj -c "C:\Users\User\CLionProjects\Tasks\Sorting Algorithms\main.cpp"

CMakeFiles/Task2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task2.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\CLionProjects\Tasks\Sorting Algorithms\main.cpp" > CMakeFiles\Task2.dir\main.cpp.i

CMakeFiles/Task2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task2.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\CLionProjects\Tasks\Sorting Algorithms\main.cpp" -o CMakeFiles\Task2.dir\main.cpp.s

# Object files for target Task2
Task2_OBJECTS = \
"CMakeFiles/Task2.dir/main.cpp.obj"

# External object files for target Task2
Task2_EXTERNAL_OBJECTS =

Task2.exe: CMakeFiles/Task2.dir/main.cpp.obj
Task2.exe: CMakeFiles/Task2.dir/build.make
Task2.exe: CMakeFiles/Task2.dir/linklibs.rsp
Task2.exe: CMakeFiles/Task2.dir/objects1.rsp
Task2.exe: CMakeFiles/Task2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\User\CLionProjects\Tasks\Sorting Algorithms\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Task2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Task2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task2.dir/build: Task2.exe

.PHONY : CMakeFiles/Task2.dir/build

CMakeFiles/Task2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Task2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Task2.dir/clean

CMakeFiles/Task2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\User\CLionProjects\Tasks\Sorting Algorithms" "C:\Users\User\CLionProjects\Tasks\Sorting Algorithms" "C:\Users\User\CLionProjects\Tasks\Sorting Algorithms\cmake-build-debug" "C:\Users\User\CLionProjects\Tasks\Sorting Algorithms\cmake-build-debug" "C:\Users\User\CLionProjects\Tasks\Sorting Algorithms\cmake-build-debug\CMakeFiles\Task2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Task2.dir/depend

