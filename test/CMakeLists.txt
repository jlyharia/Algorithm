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
#add_executable(MatrixQuizTest MatrixQuizTest.cpp)
#target_link_libraries(MatrixQuizTest alg ${GTEST_BOTH_LIBRARIES})
ADD_TEST_CASE(ArrayQuizTest)
#add_executable(ArrayQuizTest ArrayQuizTest.cpp)
#target_link_libraries(ArrayQuizTest alg ${GTEST_BOTH_LIBRARIES})

add_test(NAME testName
		COMMAND -test)
#		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/test.cpp)