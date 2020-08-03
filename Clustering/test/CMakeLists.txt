cmake_minimum_required(VERSION 3.9)
project(test)

set(CMAKE_CXX_STANDARD 11)
find_package( OpenCV REQUIRED ) # locate OpenCV in system
include_directories( ${OpenCV_INCLUDE_DIRS} ) # provide library headers

add_executable(test test.cpp)
target_link_libraries( test ${OpenCV_LIBS} )

MESSAGE("OpenCV_LIBS: " ${OpenCV_LIBS} )  #display opencv libs found
