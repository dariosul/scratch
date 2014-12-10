set(TEST_FILES catch.hpp test_atoi.cpp)

add_executable(test ${TEST_FILES})

target_link_libraries(test LINK_PUBLIC scratch)