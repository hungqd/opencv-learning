cmake_minimum_required(VERSION 3.0)

project(OpenCV-Basic)

set (CMAKE_CXX_STANDARD 11)

find_package(OpenCV 4.4.0 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIR})

add_executable(01.sample01 src/sample01.cpp)
target_link_libraries(01.sample01 ${OpenCV_LIBS} )

add_executable(01.sample02 src/sample02.cpp)
target_link_libraries(01.sample02 ${OpenCV_LIBS} )

add_executable(01.sample03 src/sample03.cpp)
target_link_libraries(01.sample03 ${OpenCV_LIBS} )

add_executable(01.sample04 src/sample04.cpp)
target_link_libraries(01.sample04 ${OpenCV_LIBS} )

add_executable(01.sample05 src/sample05.cpp)
target_link_libraries(01.sample05 ${OpenCV_LIBS} )

macro(print_all_variables)
    message(STATUS "print_all_variables------------------------------------------{")
    get_cmake_property(_variableNames VARIABLES)
    foreach (_variableName ${_variableNames})
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
    message(STATUS "print_all_variables------------------------------------------}")
endmacro()

print_all_variables()