cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(TimeProject VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_library(TimeLib STATIC Time.cpp) 

target_include_directories(TimeLib PUBLIC .)

add_subdirectory(tests)

add_executable(main_app main.cpp) 

target_link_libraries(main_app TimeLib)
