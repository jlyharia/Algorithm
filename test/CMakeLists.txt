PROJECT(TEST)

# -------
MACRO(ADD_TEST_CASE TESTCASE_NAME)
	add_executable(${TESTCASE_NAME} ${TESTCASE_NAME}.cpp)
	target_link_libraries(${TESTCASE_NAME} alg ${GTEST_BOTH_LIBRARIES})

ENDMACRO()
# -------
find_package(GTest REQUIRED)
message("-- TEST_SOURCE_DIR " ${TEST_SOURCE_DIR})
include_directories(${TEST_SOURCE_DIR}/src
		${GTEST_INCLUDE_DIRS}/include
		${GTEST_INCLUDE_DIRS}
		)


ADD_TEST_CASE(MatrixQuizTest)
ADD_TEST_CASE(ArrayQuizTest)
ADD_TEST_CASE(BacktrackingQuizTest)
ADD_TEST_CASE(DynamicQuizTest)
ADD_TEST_CASE(StringQuizTest)
ADD_TEST_CASE(TreeQuizTest)
ADD_TEST_CASE(DepthFirstSearchTest)

add_test(NAME testName
		COMMAND -test)
#		WORKcING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/test.cpp)