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
CMAKE_SOURCE_DIR = /home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/build

# Include any dependencies generated for this target.
include CMakeFiles/GaugeApp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GaugeApp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GaugeApp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GaugeApp.dir/flags.make

GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp: ../qml.qrc
GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp: CMakeFiles/GaugeApp_autogen.dir/AutoRcc_qml_EWIEGA46WW_Info.json
GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp: ../Gauge.qml
GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp: ../main.qml
GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp: ../img/needle.svg
GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp: ../img/tickmark.svg
GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp: ../img/background.svg
GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp: /home/sevo/Qt/6.7.2/gcc_64/./libexec/rcc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic RCC for qml.qrc"
	/usr/bin/cmake -E cmake_autorcc /home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/build/CMakeFiles/GaugeApp_autogen.dir/AutoRcc_qml_EWIEGA46WW_Info.json Debug

CMakeFiles/GaugeApp.dir/GaugeApp_autogen/mocs_compilation.cpp.o: CMakeFiles/GaugeApp.dir/flags.make
CMakeFiles/GaugeApp.dir/GaugeApp_autogen/mocs_compilation.cpp.o: GaugeApp_autogen/mocs_compilation.cpp
CMakeFiles/GaugeApp.dir/GaugeApp_autogen/mocs_compilation.cpp.o: CMakeFiles/GaugeApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GaugeApp.dir/GaugeApp_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GaugeApp.dir/GaugeApp_autogen/mocs_compilation.cpp.o -MF CMakeFiles/GaugeApp.dir/GaugeApp_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/GaugeApp.dir/GaugeApp_autogen/mocs_compilation.cpp.o -c /home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/build/GaugeApp_autogen/mocs_compilation.cpp

CMakeFiles/GaugeApp.dir/GaugeApp_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GaugeApp.dir/GaugeApp_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/build/GaugeApp_autogen/mocs_compilation.cpp > CMakeFiles/GaugeApp.dir/GaugeApp_autogen/mocs_compilation.cpp.i

CMakeFiles/GaugeApp.dir/GaugeApp_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GaugeApp.dir/GaugeApp_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/build/GaugeApp_autogen/mocs_compilation.cpp -o CMakeFiles/GaugeApp.dir/GaugeApp_autogen/mocs_compilation.cpp.s

CMakeFiles/GaugeApp.dir/main.cpp.o: CMakeFiles/GaugeApp.dir/flags.make
CMakeFiles/GaugeApp.dir/main.cpp.o: ../main.cpp
CMakeFiles/GaugeApp.dir/main.cpp.o: CMakeFiles/GaugeApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/GaugeApp.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GaugeApp.dir/main.cpp.o -MF CMakeFiles/GaugeApp.dir/main.cpp.o.d -o CMakeFiles/GaugeApp.dir/main.cpp.o -c /home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/main.cpp

CMakeFiles/GaugeApp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GaugeApp.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/main.cpp > CMakeFiles/GaugeApp.dir/main.cpp.i

CMakeFiles/GaugeApp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GaugeApp.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/main.cpp -o CMakeFiles/GaugeApp.dir/main.cpp.s

CMakeFiles/GaugeApp.dir/canhandler.cpp.o: CMakeFiles/GaugeApp.dir/flags.make
CMakeFiles/GaugeApp.dir/canhandler.cpp.o: ../canhandler.cpp
CMakeFiles/GaugeApp.dir/canhandler.cpp.o: CMakeFiles/GaugeApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/GaugeApp.dir/canhandler.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GaugeApp.dir/canhandler.cpp.o -MF CMakeFiles/GaugeApp.dir/canhandler.cpp.o.d -o CMakeFiles/GaugeApp.dir/canhandler.cpp.o -c /home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/canhandler.cpp

CMakeFiles/GaugeApp.dir/canhandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GaugeApp.dir/canhandler.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/canhandler.cpp > CMakeFiles/GaugeApp.dir/canhandler.cpp.i

CMakeFiles/GaugeApp.dir/canhandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GaugeApp.dir/canhandler.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/canhandler.cpp -o CMakeFiles/GaugeApp.dir/canhandler.cpp.s

CMakeFiles/GaugeApp.dir/GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp.o: CMakeFiles/GaugeApp.dir/flags.make
CMakeFiles/GaugeApp.dir/GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp.o: GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp
CMakeFiles/GaugeApp.dir/GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp.o: CMakeFiles/GaugeApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/GaugeApp.dir/GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GaugeApp.dir/GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp.o -MF CMakeFiles/GaugeApp.dir/GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp.o.d -o CMakeFiles/GaugeApp.dir/GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp.o -c /home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/build/GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp

CMakeFiles/GaugeApp.dir/GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GaugeApp.dir/GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/build/GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp > CMakeFiles/GaugeApp.dir/GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp.i

CMakeFiles/GaugeApp.dir/GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GaugeApp.dir/GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/build/GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp -o CMakeFiles/GaugeApp.dir/GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp.s

# Object files for target GaugeApp
GaugeApp_OBJECTS = \
"CMakeFiles/GaugeApp.dir/GaugeApp_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/GaugeApp.dir/main.cpp.o" \
"CMakeFiles/GaugeApp.dir/canhandler.cpp.o" \
"CMakeFiles/GaugeApp.dir/GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp.o"

# External object files for target GaugeApp
GaugeApp_EXTERNAL_OBJECTS =

GaugeApp: CMakeFiles/GaugeApp.dir/GaugeApp_autogen/mocs_compilation.cpp.o
GaugeApp: CMakeFiles/GaugeApp.dir/main.cpp.o
GaugeApp: CMakeFiles/GaugeApp.dir/canhandler.cpp.o
GaugeApp: CMakeFiles/GaugeApp.dir/GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp.o
GaugeApp: CMakeFiles/GaugeApp.dir/build.make
GaugeApp: /home/sevo/Qt/6.7.2/gcc_64/lib/libQt6QuickControls2.so.6.7.2
GaugeApp: /home/sevo/Qt/6.7.2/gcc_64/lib/libQt6SerialBus.so.6.7.2
GaugeApp: /home/sevo/Qt/6.7.2/gcc_64/lib/libQt6Quick.so.6.7.2
GaugeApp: /home/sevo/Qt/6.7.2/gcc_64/lib/libQt6QmlModels.so.6.7.2
GaugeApp: /home/sevo/Qt/6.7.2/gcc_64/lib/libQt6Qml.so.6.7.2
GaugeApp: /home/sevo/Qt/6.7.2/gcc_64/lib/libQt6QmlBuiltins.a
GaugeApp: /home/sevo/Qt/6.7.2/gcc_64/lib/libQt6OpenGL.so.6.7.2
GaugeApp: /home/sevo/Qt/6.7.2/gcc_64/lib/libQt6Gui.so.6.7.2
GaugeApp: /usr/lib/x86_64-linux-gnu/libGLX.so
GaugeApp: /usr/lib/x86_64-linux-gnu/libOpenGL.so
GaugeApp: /home/sevo/Qt/6.7.2/gcc_64/lib/libQt6Network.so.6.7.2
GaugeApp: /home/sevo/Qt/6.7.2/gcc_64/lib/libQt6SerialPort.so.6.7.2
GaugeApp: /home/sevo/Qt/6.7.2/gcc_64/lib/libQt6Core.so.6.7.2
GaugeApp: CMakeFiles/GaugeApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable GaugeApp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GaugeApp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GaugeApp.dir/build: GaugeApp
.PHONY : CMakeFiles/GaugeApp.dir/build

CMakeFiles/GaugeApp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GaugeApp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GaugeApp.dir/clean

CMakeFiles/GaugeApp.dir/depend: GaugeApp_autogen/EWIEGA46WW/qrc_qml.cpp
	cd /home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6 /home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6 /home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/build /home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/build /home/sevo/Desktop/Instrument-Cluster/gui/gaugeQt6/build/CMakeFiles/GaugeApp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GaugeApp.dir/depend

