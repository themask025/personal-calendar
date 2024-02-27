cmake_minimum_required(VERSION 3.10)
project(personal-calendar VERSION 0.1.0)

include_directories(common)

add_executable(main main.cpp Time.cpp Date.cpp Event.cpp)


