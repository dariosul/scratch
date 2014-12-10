set(HEADER_FILES atoi.h)
set(SOURCE_FILES atoi.cpp)

add_library(scratch ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(scratch PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})