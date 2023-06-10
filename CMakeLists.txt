add_library(HWSE-Hospital)
target_include_directories(HWSE-Hospital include)

add_executable(main.c /csv.c /csv.h)


target_link_libraries(fizzbuzz_test fizzbuzz)

catch_discover_tests(fizzbuzz_test)