cmake_minimum_required(VERSION 4.0)
project(Task1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_C_FLAGS "-Wall -Wextra")

add_executable(Task1 main.cpp
        task3/Team.cpp
        task3/Tournament.cpp
        task5/Tournament.cpp
        task6/Task6.cpp
        task3/Task3.cpp
        task5/Task5.cpp
        task2/Task2.cpp
        task1/Task1.cpp
        task1/Task1.h
        task2/Task2.h
        task3/Tournament.h
        task3/Team.h
        task3/Task3.h
        task4/Task4.cpp
        task4/Task4.h
        task5/Task5.h
        task5/Team.cpp
        task5/Team.h
        task5/Tournament.h
        task6/Tournament.h
        task6/Tournament.cpp
        task6/Team.cpp
        task6/Task6.h
        task6/Team.h
        task7/Tournament.cpp
        task7/Task7.h
        task7/Task7.cpp
        task7/Team.cpp)
