# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/student/Desktop/HWSE_HOSPITAL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/Desktop/HWSE_HOSPITAL

# Include any dependencies generated for this target.
include CMakeFiles/HWSE_HOSPITAL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HWSE_HOSPITAL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HWSE_HOSPITAL.dir/flags.make

CMakeFiles/HWSE_HOSPITAL.dir/src/main.c.o: CMakeFiles/HWSE_HOSPITAL.dir/flags.make
CMakeFiles/HWSE_HOSPITAL.dir/src/main.c.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/HWSE_HOSPITAL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/HWSE_HOSPITAL.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/HWSE_HOSPITAL.dir/src/main.c.o -c /home/student/Desktop/HWSE_HOSPITAL/src/main.c

CMakeFiles/HWSE_HOSPITAL.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/HWSE_HOSPITAL.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/student/Desktop/HWSE_HOSPITAL/src/main.c > CMakeFiles/HWSE_HOSPITAL.dir/src/main.c.i

CMakeFiles/HWSE_HOSPITAL.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/HWSE_HOSPITAL.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/student/Desktop/HWSE_HOSPITAL/src/main.c -o CMakeFiles/HWSE_HOSPITAL.dir/src/main.c.s

CMakeFiles/HWSE_HOSPITAL.dir/src/functions.c.o: CMakeFiles/HWSE_HOSPITAL.dir/flags.make
CMakeFiles/HWSE_HOSPITAL.dir/src/functions.c.o: src/functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/HWSE_HOSPITAL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/HWSE_HOSPITAL.dir/src/functions.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/HWSE_HOSPITAL.dir/src/functions.c.o -c /home/student/Desktop/HWSE_HOSPITAL/src/functions.c

CMakeFiles/HWSE_HOSPITAL.dir/src/functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/HWSE_HOSPITAL.dir/src/functions.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/student/Desktop/HWSE_HOSPITAL/src/functions.c > CMakeFiles/HWSE_HOSPITAL.dir/src/functions.c.i

CMakeFiles/HWSE_HOSPITAL.dir/src/functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/HWSE_HOSPITAL.dir/src/functions.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/student/Desktop/HWSE_HOSPITAL/src/functions.c -o CMakeFiles/HWSE_HOSPITAL.dir/src/functions.c.s

# Object files for target HWSE_HOSPITAL
HWSE_HOSPITAL_OBJECTS = \
"CMakeFiles/HWSE_HOSPITAL.dir/src/main.c.o" \
"CMakeFiles/HWSE_HOSPITAL.dir/src/functions.c.o"

# External object files for target HWSE_HOSPITAL
HWSE_HOSPITAL_EXTERNAL_OBJECTS =

libHWSE_HOSPITAL.a: CMakeFiles/HWSE_HOSPITAL.dir/src/main.c.o
libHWSE_HOSPITAL.a: CMakeFiles/HWSE_HOSPITAL.dir/src/functions.c.o
libHWSE_HOSPITAL.a: CMakeFiles/HWSE_HOSPITAL.dir/build.make
libHWSE_HOSPITAL.a: CMakeFiles/HWSE_HOSPITAL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/student/Desktop/HWSE_HOSPITAL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libHWSE_HOSPITAL.a"
	$(CMAKE_COMMAND) -P CMakeFiles/HWSE_HOSPITAL.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HWSE_HOSPITAL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HWSE_HOSPITAL.dir/build: libHWSE_HOSPITAL.a

.PHONY : CMakeFiles/HWSE_HOSPITAL.dir/build

CMakeFiles/HWSE_HOSPITAL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HWSE_HOSPITAL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HWSE_HOSPITAL.dir/clean

CMakeFiles/HWSE_HOSPITAL.dir/depend:
	cd /home/student/Desktop/HWSE_HOSPITAL && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/Desktop/HWSE_HOSPITAL /home/student/Desktop/HWSE_HOSPITAL /home/student/Desktop/HWSE_HOSPITAL /home/student/Desktop/HWSE_HOSPITAL /home/student/Desktop/HWSE_HOSPITAL/CMakeFiles/HWSE_HOSPITAL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HWSE_HOSPITAL.dir/depend

