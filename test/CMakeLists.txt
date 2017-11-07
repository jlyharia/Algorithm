PROJECT(TEST)
find_package(GTest REQUIRED)
message("-- TEST_SOURCE_DIR " ${TEST_SOURCE_DIR})
include_directories(${TEST_SOURCE_DIR}/src
		${GTEST_INCLUDE_DIRS}/include
		${GTEST_INCLUDE_DIRS}
		)


add_executable(myTest MatrixQuizTest.cpp)


target_link_libraries(myTest
		alg
		${GTEST_BOTH_LIBRARIES}
		)

add_test(NAME testName
		COMMAND -test)
#		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/test.cpp)