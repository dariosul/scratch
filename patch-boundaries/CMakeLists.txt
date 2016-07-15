cmake_minimum_required(VERSION 2.8)
project(patch)

set(CMAKE_CXX_FLAGS "-std=c++11 -g -Wall -Werror")

# Build library

add_library(libPatch
    src/patch.h src/patch.cpp
)

# Build tests

add_subdirectory(vendor/gtest-1.7.0)
enable_testing()

include_directories(
    ${gtest_SOURCE_DIR}/include
    ${gtest_SOURCE_DIR}
    src
)

set(TEST_SOURCE_FILES
    test/patch_test.cpp
)

add_executable(patch_test ${TEST_SOURCE_FILES})

target_link_libraries(patch_test
    gtest
    gtest_main
    libPatch
)

add_test(test patch_test)
