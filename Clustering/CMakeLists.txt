cmake_minimum_required(VERSION 3.9)
project(clustering)

set(CMAKE_CXX_STANDARD 11)
find_package( OpenCV REQUIRED ) # locate OpenCV in system
include_directories( ${OpenCV_INCLUDE_DIRS} ) # provide library headers

add_executable(clustering main.cpp)
target_link_libraries( clustering ${OpenCV_LIBS} /usr/lib/x86_64-linux-gnu/libopencv_highgui.so) # link OpenCV libraries , hightgui.so not found by cmake so this hack

add_executable(test test.cpp)
target_link_libraries( test ${OpenCV_LIBS} )

MESSAGE("OpenCV_LIBS: " ${OpenCV_LIBS} )  #display opencv libs found