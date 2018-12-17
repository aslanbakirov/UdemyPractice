cmake_minimum_required(VERSION 3.12)
project(UdemyTDD)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

set(GTEST_LIBRARY /usr/include/gtest)
set(GTEST_MAIN_LIBRARY /usr/include/gtest)
set(GTEST_INCLUDE_DIRS /usr/include/gtest)


include_directories(${GTEST_LIBRARY})
include_directories(${GTEST_MAIN_LIBRARY})
find_package(GTest REQUIRED)
find_package(GMock REQUIRED)
include_directories(${GMOCK_INCLUDE_DIRS})
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(tdd test/MathTest.cpp)
target_link_libraries(tdd gtest rt pthread)

add_subdirectory(src)
add_subdirectory(program)