cmake_minimum_required(VERSION 4.0)
project(Task1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_C_FLAGS "-Wall -Wextra")

add_executable(task8
        task8/Task8.cpp
        task8/Task8.h
        task8/ArrayList.cpp
        task8/ArrayList.h
        task8/main.cpp
        task8/Team.cpp
)

# Optional: weitere Tasks als separate Programme
add_executable(task7
        task7/Task7.cpp
        task7/Tournament.cpp
        task7/Team.cpp
        task7/main.cpp
)

add_executable(task6
        task6/Task6.cpp
        task6/Tournament.cpp
        task6/Team.cpp
        task6/main.cpp
)

add_executable(task5
        task5/Task5.cpp
        task5/Tournament.cpp
        task5/Team.cpp
        task5/main.cpp
)

add_executable(task3
        task3/Task3.cpp
        task3/Tournament.cpp
        task3/Team.cpp
        task3/main.cpp
)

add_executable(task2 task2/Task2.cpp
        task2/main.cpp)
add_executable(task1 task1/Task1.cpp
        task4/main.cpp
        task1/main.cpp)
