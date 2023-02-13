SET(lab0funcs ./lab0/task1.c ./lab0/task2.c ./lab0/task3.c  ./lab0/task4.c  ./lab0/task5.c  ./lab0/task6.c
              ./lab0/task7.c ./lab0/task8.c ./lab0/task9.c ./lab0/task10.c ./lab0/task11.c ./lab0/task12.c)

SET (lab1funcs ./lab1/boolsetsoperations.c ./lab1/orderedsetsoperations.c ./lab1/unorderedsetsoperations.c)

add_library(alg alg.h ${lab0funcs} ${lab1funcs})

target_link_libraries(alg m)