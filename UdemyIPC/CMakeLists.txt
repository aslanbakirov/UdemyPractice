cmake_minimum_required(VERSION 3.12)
project(UdemyIPC C)

set(CMAKE_C_STANDARD 99)

#add_executable(server server.c)
#add_executable(client client.c)
add_executable(queue-sender msgqueue-sender.c)
add_executable(queue-receiver msgqueue-receiver.c)

target_link_libraries(queue-sender rt)
target_link_libraries(queue-receiver rt)

add_executable(shm_writer shm_writer.c shm_impl.c)
add_executable(shm_reader shm_reader.c shm_impl.c)

target_link_libraries(shm_writer rt)
target_link_libraries(shm_reader rt)



