# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_SOURCE_DIR = /home/user/Development/rinobot/codigos/projetos/FeatureDetector/Clustering

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/Development/rinobot/codigos/projetos/FeatureDetector/Clustering/build

# Include any dependencies generated for this target.
include CMakeFiles/clustering.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/clustering.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/clustering.dir/flags.make

CMakeFiles/clustering.dir/main.cpp.o: CMakeFiles/clustering.dir/flags.make
CMakeFiles/clustering.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/Development/rinobot/codigos/projetos/FeatureDetector/Clustering/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/clustering.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clustering.dir/main.cpp.o -c /home/user/Development/rinobot/codigos/projetos/FeatureDetector/Clustering/main.cpp

CMakeFiles/clustering.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clustering.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Development/rinobot/codigos/projetos/FeatureDetector/Clustering/main.cpp > CMakeFiles/clustering.dir/main.cpp.i

CMakeFiles/clustering.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clustering.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Development/rinobot/codigos/projetos/FeatureDetector/Clustering/main.cpp -o CMakeFiles/clustering.dir/main.cpp.s

# Object files for target clustering
clustering_OBJECTS = \
"CMakeFiles/clustering.dir/main.cpp.o"

# External object files for target clustering
clustering_EXTERNAL_OBJECTS =

clustering: CMakeFiles/clustering.dir/main.cpp.o
clustering: CMakeFiles/clustering.dir/build.make
clustering: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_face.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_text.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so
clustering: /usr/lib/x86_64-linux-gnu/libopencv_video.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.3.2.0
clustering: /usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2.0
clustering: CMakeFiles/clustering.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/Development/rinobot/codigos/projetos/FeatureDetector/Clustering/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable clustering"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/clustering.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/clustering.dir/build: clustering

.PHONY : CMakeFiles/clustering.dir/build

CMakeFiles/clustering.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/clustering.dir/cmake_clean.cmake
.PHONY : CMakeFiles/clustering.dir/clean

CMakeFiles/clustering.dir/depend:
	cd /home/user/Development/rinobot/codigos/projetos/FeatureDetector/Clustering/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/Development/rinobot/codigos/projetos/FeatureDetector/Clustering /home/user/Development/rinobot/codigos/projetos/FeatureDetector/Clustering /home/user/Development/rinobot/codigos/projetos/FeatureDetector/Clustering/build /home/user/Development/rinobot/codigos/projetos/FeatureDetector/Clustering/build /home/user/Development/rinobot/codigos/projetos/FeatureDetector/Clustering/build/CMakeFiles/clustering.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/clustering.dir/depend

