SET(lab0funcs ./lab0/task1.c ./lab0/task2.c ./lab0/task3.c  ./lab0/task4.c  ./lab0/task5.c  ./lab0/task6.c
              ./lab0/task7.c ./lab0/task8.c ./lab0/task9.c ./lab0/task10.c ./lab0/task11.c ./lab0/task12.c)

SET (lab1funcs ./lab1/boolsetsoperations.c ./lab1/orderedsetsoperations.c ./lab1/unorderedsetsoperations.c)

SET (lab3funcs ./algcpp.h ./lab3/set.tpp)

SET (lab6funcs ./lab6/task6.cpp)

SET(lesson060923 ./lesson060923/task1.c)

add_library(alg ${lab0funcs} ${lab1funcs} ${lab3funcs} ${lab6funcs} ${lesson060923})

target_link_libraries(alg m)