cmake_minimum_required(VERSION 3.10.0)
project(HWSE-HOSPITAL)
find_package(Catch2 REQUIRED)
include(CTest)
include(Catch)

add_library(HWSE-HOSPITAL src/csv.c)
target_include_directories(HWSE-HOSPITAL PUBLIC include)

add_executable(HWSE-Hospital_test test/main.c)


target_include_directories(HWSE-HOSPITAL PUBLIC include)

 #Füge beliebige zusätzliche Compiler-Flags hinzu, falls erforderlich
 target_compile_options(HWSE-HOSPITAL PRIVATE -Wall -Wextra)
 target_link_libraries(HWSE-Hospital_test HWSE-Hospital)
 add_test(NAME MyTest COMMAND <test_target>)
 catch_discover_tests(HWSE-Hospital_test)


