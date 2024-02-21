cmake_minimum_required(VERSION 3.27)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        kmp.cpp
        kmp.h
        exc.cpp
        exc.h
        arr.cpp
        arr.h
        test.cpp
)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link the project with what we want to test and the GTest and pthread library
target_link_libraries(untitled ${GTEST_LIBRARIES} pthread)
