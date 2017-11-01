cmake_minimum_required(VERSION 3.8)

project(Algorithm)
# Enable debug symbols by default
if (CMAKE_BUILD_TYPE STREQUAL "")
	set(CMAKE_BUILD_TYPE Debug)
endif ()

# ============ main ===================
# system check
IF (${CMAKE_SYSTEM_NAME} MATCHES "Darwin") # check apple
	MATH(EXPR bits " ${CMAKE_SIZEOF_VOID_P}*8 ")
	message("-- This environment is ${bits} bits")
endif ()

message("-- Generator is " ${CMAKE_GENERATOR})
message("-- Cmake system Type: " ${CMAKE_SYSTEM_NAME})
message("-- Project binaray dir: " ${PROJECT_BINARY_DIR})

# Compiler Flag
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORTS_CXX17)

if (!COMPILER_SUPPORTS_CXX17 AND !COMPILER_SUPPORTS_CXX0X)
	message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++17 support. Please use a different C++ compiler.")
endif ()

message("-- CMAKE_CXX_COMPILER_ID = " ${CMAKE_CXX_COMPILER_ID})

SET(CMAKE_VERBOSE_MAKEFILE on)  # make debug flag
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall")
message("-- CMAKE_CXX_FLAGS = " ${CMAKE_CXX_FLAGS})

# set paths
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})


add_subdirectory(src)

enable_testing ()
add_subdirectory (test)