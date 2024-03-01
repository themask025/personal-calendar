cmake_minimum_required(VERSION 3.10)
project(personal-calendar VERSION 0.1.0)

add_executable(main main.cpp Time.cpp Date.cpp Event.cpp Calendar.cpp)
add_executable(testing tests/testing.cpp Time.cpp Date.cpp Event.cpp Calendar.cpp)