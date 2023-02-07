cmake_minimum_required(VERSION 3.16)
project(programming_and_algorithmization_basics C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(./libs/alg)

add_executable(lab0_task1 ./lab0/task1/main.c)
target_link_libraries(lab0_task1 alg)

add_executable(lab0_task2 ./lab0/task2/main.c)
target_link_libraries(lab0_task2 alg)

add_executable(lab0_task3 ./lab0/task3/main.c)
target_link_libraries(lab0_task3 alg)

add_executable(lab0_task4 ./lab0/task4/main.c)
target_link_libraries(lab0_task4 alg)

add_executable(lab0_task5 ./lab0/task5/main.c)
target_link_libraries(lab0_task5 alg)

add_executable(lab0_task6 ./lab0/task6/main.c)
target_link_libraries(lab0_task6 alg)

add_executable(lab0_task7 ./lab0/task7/main.c)
target_link_libraries(lab0_task7 alg)

add_executable(lab0_task8 ./lab0/task8/main.c)
target_link_libraries(lab0_task8 alg)

add_executable(lab0_task9 ./lab0/task9/main.c)
target_link_libraries(lab0_task9 alg)

add_executable(lab0_task10 ./lab0/task10/main.c)
target_link_libraries(lab0_task10 alg)

add_executable(lab0_task11 ./lab0/task11/main.c)
target_link_libraries(lab0_task11 alg)

add_executable(lab0_task12 ./lab0/task12/main.c)
target_link_libraries(lab0_task12 alg)

# Zero library