cmake_minimum_required(VERSION 2.6)
 
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 

# Create build targets for testing.
enable_testing()

set(files
    helper.h 
    helper.cpp 
    )

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests test.cpp ${files})

target_link_libraries(runTests GTest::Main pthread stdc++fs)
