cmake_minimum_required(VERSION 3.0)

project(OpenCV-GUI)

set (CMAKE_CXX_STANDARD 11)

find_package(OpenCV 4.4.0 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIR})

add_executable(sample01 src/sample01.cpp)
target_link_libraries(sample01 ${OpenCV_LIBS} )