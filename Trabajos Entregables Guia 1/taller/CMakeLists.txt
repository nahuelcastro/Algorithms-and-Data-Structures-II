cmake_minimum_required(VERSION 3.5)
project(solucion)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=gnu++11 -ggdb3 -g")


add_library(gtest STATIC tests/gtest-1.8.1/gtest-all.cc)
add_library(gtest_main STATIC tests/gtest-1.8.1/gtest_main.cc)

foreach(i RANGE 7 14)
    add_executable(ej${i} tests/test_recordatorios.cpp)
endforeach(i)


foreach(i RANGE 7 14)
    target_compile_definitions(ej${i} PUBLIC EJ=${i})
endforeach(i)

foreach(i RANGE 7 14)
    target_link_libraries(ej${i} gtest gtest_main)
endforeach(i)
