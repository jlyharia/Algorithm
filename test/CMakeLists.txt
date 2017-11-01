PROJECT(Test)
find_package(GTest REQUIRED)

include_directories(${TEST_SOURCE_DIR}/src
		${GTEST_INCLUDE_DIRS}
		)


add_executable(Test test.cpp)

target_link_libraries(Test
		alg
		${GTEST_BOTH_LIBRARIES}
		)

add_test(NAME MyTest
		COMMAND -test
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/test.cpp)