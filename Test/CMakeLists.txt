find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE_FILES test_Run.cpp Chrono_test.cpp)
add_executable(test_Run ${SOURCE_FILES})
target_link_libraries(test_Run ${GTEST_BOTH_LIBRARIES} core)