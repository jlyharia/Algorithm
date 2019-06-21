cmake_minimum_required(VERSION 3.9)

project(Algorithm)
# Enable debug symbols by default
if (CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE Debug)
endif ()

# ============ main ===================
# system check
IF (${CMAKE_SYSTEM_NAME} MATCHES "Darwin") # check apple
    message("-- CMake is running on OS X")
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

message("-- CMAKE_SOURCE_DIR = " ${CMAKE_SOURCE_DIR})

set(HEADER_FILES
        ${HEADER_FILES}
        ${CMAKE_SOURCE_DIR}/src/leetcodeChallenge/ArrayQuiz.hpp
        ${CMAKE_SOURCE_DIR}/src/basic/Utils.hpp
        ${CMAKE_SOURCE_DIR}/src/leetcodeChallenge/LinkedListQuiz.hpp
        ${CMAKE_SOURCE_DIR}/src/leetcodeChallenge/BackTracking.hpp
        ${CMAKE_SOURCE_DIR}/src/leetcodeChallenge/DynamicProgramQuiz.hpp
        ${CMAKE_SOURCE_DIR}/src/leetcodeChallenge/StringQuiz.hpp
        ${CMAKE_SOURCE_DIR}/src/leetcodeChallenge/MathQuiz.hpp
        ${CMAKE_SOURCE_DIR}/src/leetcodeChallenge/GraphQuiz.hpp
        ${CMAKE_SOURCE_DIR}/src/leetcodeChallenge/LRUCache.hpp
        ${CMAKE_SOURCE_DIR}/src/leetcodeChallenge/Sorting.hpp
        ${CMAKE_SOURCE_DIR}/src/leetcodeChallenge/LFUCache.hpp)
# include headers
include_directories(${CMAKE_SOURCE_DIR}/src/Interview
        ${CMAKE_SOURCE_DIR}/src/include
        ${CMAKE_SOURCE_DIR}/src/basic
        ${CMAKE_SOURCE_DIR}/src/leetcodeChallenge)

# include source files
AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/src/Interview SOURCE_FILES)
AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/src/leetcodeChallenge SOURCE_FILES)
AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/src/basic SOURCE_FILES)
message("-- HEADER_FILES: " ${HEADER_FILES})
message("-- SOURCE_FILES: " ${SOURCE_FILES})

# -----------------------------------------------------------------------------
add_library(alg ${SOURCE_FILES} ${HEADER_FILES})

add_subdirectory(src)

enable_testing()
add_subdirectory(test)