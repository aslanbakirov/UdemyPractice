cmake_minimum_required(VERSION 3.12)
project(UdemyHPC)

set(CMAKE_CXX_STANDARD 14)

#add_executable(UdemyHPC pthread_example.cpp)
#target_link_libraries(UdemyHPC rt pthread)

add_executable(concurrency concurrency-example.cpp)
target_link_libraries(concurrency rt pthread)

add_executable(promise promise_example.cpp)
target_link_libraries(promise rt pthread)