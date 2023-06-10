cmake_minimum_required(VERSION 3.10.0)
project(HWSE-HOSPITAL)
add_library(HWSE-HOSPITAL)
target_include_directories(HWSE-HOSPITAL include)

add_executable(HWSE-HOSPITAL main.c csv.c)


target_include_directories(HWSE-HOSPITAL PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

 Füge beliebige zusätzliche Compiler-Flags hinzu, falls erforderlich
 target_compile_options(HWSE-HOSPITAL PRIVATE -Wall -Wextra)

 
 add_executable(<test_target> test.cpp)
 target_link_libraries(<test_target> PRIVATE Catch2)
 add_test(NAME MyTest COMMAND <test_target>)


