cmake_minimum_required(VERSION 3.16)
project(discrete_math C CXX)

set(CMAKE_CXX_STANDARD 11)

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

add_executable(lab1_task3_4 ./lab1/main.c)
target_link_libraries(lab1_task3_4 alg)

add_executable(lab3_task7 lab3/task7/main.cpp)
target_link_libraries(lab3_task7 alg)

add_executable(lab3_task8 lab3/task8/main.cpp)
target_link_libraries(lab3_task8 alg)

add_executable(lab4_task3 lab4/task3/main.cpp)
target_link_libraries(lab4_task3 alg)

add_executable(lab4_task6 lab4/task6/main.cpp)
target_link_libraries(lab4_task6 alg)

add_executable(lab5_task1 lab5/task1/main.cpp)
target_link_libraries(lab5_task1 alg)

add_executable(lab5_task6 lab5/task6/main.cpp)
target_link_libraries(lab5_task6 alg)

add_executable(lab5_task8 lab5/task8/main.cpp)
target_link_libraries(lab5_task8 alg)


add_executable(lab5_task13 lab5/task13/main.cpp)
target_link_libraries(lab5_task13 alg)


add_executable(lab6_task5 lab6/task5/main.cpp)
target_link_libraries(lab6_task5 alg)

add_executable(lab6_task6 lab6/task6/test.cpp)
target_link_libraries(lab6_task6 alg)

add_executable(lesson060923_task1 lesson060923/task1.c)
target_link_libraries(lesson060923_task1 alg)

add_executable(lab7_task13 lab7/task13/main.cpp)
target_link_libraries(lab7_task13 alg)

add_executable(lab7_task15 lab7/task15/main.cpp)
target_link_libraries(lab7_task15 alg)

add_executable(lab7_task23 lab7/task23/main.cpp)
target_link_libraries(lab7_task23 alg)

# Zero library