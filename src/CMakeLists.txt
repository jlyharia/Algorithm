# -----------------------------------------------------------------------------
# include headers
include_directories(Interview include basic leetcodeChallenge)

# include source files
AUX_SOURCE_DIRECTORY(Interview SOURCE_FILES)
AUX_SOURCE_DIRECTORY(leetcodeChallenge SOURCE_FILES)
AUX_SOURCE_DIRECTORY(basic SOURCE_FILES)

set(HEADER_FILES
		${HEADER_FILES}
		include/LeetCodeHeaders.hpp
		include/SingleLinkedList.hpp
		include/SortAlgorithm.hpp
		include/Tree.hpp
		include/UndirectedGraphNode.hpp)

# include main file
#set(SOURCE_FILES
#		${SOURCE_FILES}
#		LeetCode.cpp)

message("-- HEADER_FILES: " ${HEADER_FILES})
message("-- SOURCE_FILES: " ${SOURCE_FILES})

# -----------------------------------------------------------------------------
add_library(alg ${SOURCE_FILES} ${HEADER_FILES})
add_executable(leetcode LeetCode.cpp)
target_link_libraries(leetcode alg)