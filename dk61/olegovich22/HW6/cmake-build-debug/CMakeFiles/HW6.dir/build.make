# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.6

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files (x86)\JetBrains\CLion 2016.3.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files (x86)\JetBrains\CLion 2016.3.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CLionProjects\HW6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLionProjects\HW6\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HW6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HW6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HW6.dir/flags.make

CMakeFiles/HW6.dir/main.c.obj: CMakeFiles/HW6.dir/flags.make
CMakeFiles/HW6.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\HW6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/HW6.dir/main.c.obj"
	D:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\HW6.dir\main.c.obj   -c D:\CLionProjects\HW6\main.c

CMakeFiles/HW6.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/HW6.dir/main.c.i"
	D:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\CLionProjects\HW6\main.c > CMakeFiles\HW6.dir\main.c.i

CMakeFiles/HW6.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/HW6.dir/main.c.s"
	D:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\CLionProjects\HW6\main.c -o CMakeFiles\HW6.dir\main.c.s

CMakeFiles/HW6.dir/main.c.obj.requires:

.PHONY : CMakeFiles/HW6.dir/main.c.obj.requires

CMakeFiles/HW6.dir/main.c.obj.provides: CMakeFiles/HW6.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\HW6.dir\build.make CMakeFiles/HW6.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/HW6.dir/main.c.obj.provides

CMakeFiles/HW6.dir/main.c.obj.provides.build: CMakeFiles/HW6.dir/main.c.obj


CMakeFiles/HW6.dir/dk_tool.c.obj: CMakeFiles/HW6.dir/flags.make
CMakeFiles/HW6.dir/dk_tool.c.obj: ../dk_tool.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\HW6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/HW6.dir/dk_tool.c.obj"
	D:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\HW6.dir\dk_tool.c.obj   -c D:\CLionProjects\HW6\dk_tool.c

CMakeFiles/HW6.dir/dk_tool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/HW6.dir/dk_tool.c.i"
	D:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\CLionProjects\HW6\dk_tool.c > CMakeFiles\HW6.dir\dk_tool.c.i

CMakeFiles/HW6.dir/dk_tool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/HW6.dir/dk_tool.c.s"
	D:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\CLionProjects\HW6\dk_tool.c -o CMakeFiles\HW6.dir\dk_tool.c.s

CMakeFiles/HW6.dir/dk_tool.c.obj.requires:

.PHONY : CMakeFiles/HW6.dir/dk_tool.c.obj.requires

CMakeFiles/HW6.dir/dk_tool.c.obj.provides: CMakeFiles/HW6.dir/dk_tool.c.obj.requires
	$(MAKE) -f CMakeFiles\HW6.dir\build.make CMakeFiles/HW6.dir/dk_tool.c.obj.provides.build
.PHONY : CMakeFiles/HW6.dir/dk_tool.c.obj.provides

CMakeFiles/HW6.dir/dk_tool.c.obj.provides.build: CMakeFiles/HW6.dir/dk_tool.c.obj


CMakeFiles/HW6.dir/sortValues.c.obj: CMakeFiles/HW6.dir/flags.make
CMakeFiles/HW6.dir/sortValues.c.obj: ../sortValues.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\HW6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/HW6.dir/sortValues.c.obj"
	D:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\HW6.dir\sortValues.c.obj   -c D:\CLionProjects\HW6\sortValues.c

CMakeFiles/HW6.dir/sortValues.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/HW6.dir/sortValues.c.i"
	D:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\CLionProjects\HW6\sortValues.c > CMakeFiles\HW6.dir\sortValues.c.i

CMakeFiles/HW6.dir/sortValues.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/HW6.dir/sortValues.c.s"
	D:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\CLionProjects\HW6\sortValues.c -o CMakeFiles\HW6.dir\sortValues.c.s

CMakeFiles/HW6.dir/sortValues.c.obj.requires:

.PHONY : CMakeFiles/HW6.dir/sortValues.c.obj.requires

CMakeFiles/HW6.dir/sortValues.c.obj.provides: CMakeFiles/HW6.dir/sortValues.c.obj.requires
	$(MAKE) -f CMakeFiles\HW6.dir\build.make CMakeFiles/HW6.dir/sortValues.c.obj.provides.build
.PHONY : CMakeFiles/HW6.dir/sortValues.c.obj.provides

CMakeFiles/HW6.dir/sortValues.c.obj.provides.build: CMakeFiles/HW6.dir/sortValues.c.obj


CMakeFiles/HW6.dir/sortPointers.c.obj: CMakeFiles/HW6.dir/flags.make
CMakeFiles/HW6.dir/sortPointers.c.obj: ../sortPointers.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\HW6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/HW6.dir/sortPointers.c.obj"
	D:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\HW6.dir\sortPointers.c.obj   -c D:\CLionProjects\HW6\sortPointers.c

CMakeFiles/HW6.dir/sortPointers.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/HW6.dir/sortPointers.c.i"
	D:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\CLionProjects\HW6\sortPointers.c > CMakeFiles\HW6.dir\sortPointers.c.i

CMakeFiles/HW6.dir/sortPointers.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/HW6.dir/sortPointers.c.s"
	D:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\CLionProjects\HW6\sortPointers.c -o CMakeFiles\HW6.dir\sortPointers.c.s

CMakeFiles/HW6.dir/sortPointers.c.obj.requires:

.PHONY : CMakeFiles/HW6.dir/sortPointers.c.obj.requires

CMakeFiles/HW6.dir/sortPointers.c.obj.provides: CMakeFiles/HW6.dir/sortPointers.c.obj.requires
	$(MAKE) -f CMakeFiles\HW6.dir\build.make CMakeFiles/HW6.dir/sortPointers.c.obj.provides.build
.PHONY : CMakeFiles/HW6.dir/sortPointers.c.obj.provides

CMakeFiles/HW6.dir/sortPointers.c.obj.provides.build: CMakeFiles/HW6.dir/sortPointers.c.obj


CMakeFiles/HW6.dir/dk_list.c.obj: CMakeFiles/HW6.dir/flags.make
CMakeFiles/HW6.dir/dk_list.c.obj: ../dk_list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\HW6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/HW6.dir/dk_list.c.obj"
	D:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\HW6.dir\dk_list.c.obj   -c D:\CLionProjects\HW6\dk_list.c

CMakeFiles/HW6.dir/dk_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/HW6.dir/dk_list.c.i"
	D:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\CLionProjects\HW6\dk_list.c > CMakeFiles\HW6.dir\dk_list.c.i

CMakeFiles/HW6.dir/dk_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/HW6.dir/dk_list.c.s"
	D:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\CLionProjects\HW6\dk_list.c -o CMakeFiles\HW6.dir\dk_list.c.s

CMakeFiles/HW6.dir/dk_list.c.obj.requires:

.PHONY : CMakeFiles/HW6.dir/dk_list.c.obj.requires

CMakeFiles/HW6.dir/dk_list.c.obj.provides: CMakeFiles/HW6.dir/dk_list.c.obj.requires
	$(MAKE) -f CMakeFiles\HW6.dir\build.make CMakeFiles/HW6.dir/dk_list.c.obj.provides.build
.PHONY : CMakeFiles/HW6.dir/dk_list.c.obj.provides

CMakeFiles/HW6.dir/dk_list.c.obj.provides.build: CMakeFiles/HW6.dir/dk_list.c.obj


CMakeFiles/HW6.dir/simple_dk_tool.c.obj: CMakeFiles/HW6.dir/flags.make
CMakeFiles/HW6.dir/simple_dk_tool.c.obj: ../simple_dk_tool.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\HW6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/HW6.dir/simple_dk_tool.c.obj"
	D:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\HW6.dir\simple_dk_tool.c.obj   -c D:\CLionProjects\HW6\simple_dk_tool.c

CMakeFiles/HW6.dir/simple_dk_tool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/HW6.dir/simple_dk_tool.c.i"
	D:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\CLionProjects\HW6\simple_dk_tool.c > CMakeFiles\HW6.dir\simple_dk_tool.c.i

CMakeFiles/HW6.dir/simple_dk_tool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/HW6.dir/simple_dk_tool.c.s"
	D:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\CLionProjects\HW6\simple_dk_tool.c -o CMakeFiles\HW6.dir\simple_dk_tool.c.s

CMakeFiles/HW6.dir/simple_dk_tool.c.obj.requires:

.PHONY : CMakeFiles/HW6.dir/simple_dk_tool.c.obj.requires

CMakeFiles/HW6.dir/simple_dk_tool.c.obj.provides: CMakeFiles/HW6.dir/simple_dk_tool.c.obj.requires
	$(MAKE) -f CMakeFiles\HW6.dir\build.make CMakeFiles/HW6.dir/simple_dk_tool.c.obj.provides.build
.PHONY : CMakeFiles/HW6.dir/simple_dk_tool.c.obj.provides

CMakeFiles/HW6.dir/simple_dk_tool.c.obj.provides.build: CMakeFiles/HW6.dir/simple_dk_tool.c.obj


# Object files for target HW6
HW6_OBJECTS = \
"CMakeFiles/HW6.dir/main.c.obj" \
"CMakeFiles/HW6.dir/dk_tool.c.obj" \
"CMakeFiles/HW6.dir/sortValues.c.obj" \
"CMakeFiles/HW6.dir/sortPointers.c.obj" \
"CMakeFiles/HW6.dir/dk_list.c.obj" \
"CMakeFiles/HW6.dir/simple_dk_tool.c.obj"

# External object files for target HW6
HW6_EXTERNAL_OBJECTS =

HW6.exe: CMakeFiles/HW6.dir/main.c.obj
HW6.exe: CMakeFiles/HW6.dir/dk_tool.c.obj
HW6.exe: CMakeFiles/HW6.dir/sortValues.c.obj
HW6.exe: CMakeFiles/HW6.dir/sortPointers.c.obj
HW6.exe: CMakeFiles/HW6.dir/dk_list.c.obj
HW6.exe: CMakeFiles/HW6.dir/simple_dk_tool.c.obj
HW6.exe: CMakeFiles/HW6.dir/build.make
HW6.exe: CMakeFiles/HW6.dir/linklibs.rsp
HW6.exe: CMakeFiles/HW6.dir/objects1.rsp
HW6.exe: CMakeFiles/HW6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CLionProjects\HW6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable HW6.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\HW6.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HW6.dir/build: HW6.exe

.PHONY : CMakeFiles/HW6.dir/build

CMakeFiles/HW6.dir/requires: CMakeFiles/HW6.dir/main.c.obj.requires
CMakeFiles/HW6.dir/requires: CMakeFiles/HW6.dir/dk_tool.c.obj.requires
CMakeFiles/HW6.dir/requires: CMakeFiles/HW6.dir/sortValues.c.obj.requires
CMakeFiles/HW6.dir/requires: CMakeFiles/HW6.dir/sortPointers.c.obj.requires
CMakeFiles/HW6.dir/requires: CMakeFiles/HW6.dir/dk_list.c.obj.requires
CMakeFiles/HW6.dir/requires: CMakeFiles/HW6.dir/simple_dk_tool.c.obj.requires

.PHONY : CMakeFiles/HW6.dir/requires

CMakeFiles/HW6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HW6.dir\cmake_clean.cmake
.PHONY : CMakeFiles/HW6.dir/clean

CMakeFiles/HW6.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLionProjects\HW6 D:\CLionProjects\HW6 D:\CLionProjects\HW6\cmake-build-debug D:\CLionProjects\HW6\cmake-build-debug D:\CLionProjects\HW6\cmake-build-debug\CMakeFiles\HW6.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HW6.dir/depend

