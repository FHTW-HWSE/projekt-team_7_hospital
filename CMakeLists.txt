cmake_minimum_required(VERSION 3.10.0)
project(HWSE_HOSPITAL_PROJECT)
find_package(Catch2 REQUIRED)
include(CTest)
include(Catch)

add_library(HWSE_HOSPITAL src/main.cpp src/functions.cpp)
    

target_include_directories(HWSE_HOSPITAL PUBLIC include)

add_executable(HWSE_Hospital_test
test/main_test.cpp
test/csv_test.cpp 
)
catch_discover_tests(HWSE_Hospital_test)
target_link_libraries(HWSE_Hospital_test HWSE_HOSPITAL)

 #Füge beliebige zusätzliche Compiler-Flags hinzu, falls erforderlich
 target_compile_options(HWSE_HOSPITAL PRIVATE -Wall -Wextra)


