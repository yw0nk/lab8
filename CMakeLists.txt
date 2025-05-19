cmake_minimum_required(VERSION 3.4)
project(lab06)

include(cmake/HunterGate.cmake)

HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.23.251.tar.gz"
    SHA1 "aa0b179b28918ea1c1e0d2c56e4dcbf9e4e957f4"
)

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

add_library(print sources/print.cpp)
target_include_directories(print PUBLIC include)

add_executable(example1 examples/example1.cpp)
target_link_libraries(example1 print)

add_executable(example2 examples/example2.cpp)
target_link_libraries(example2 print)

add_executable(test1 tests/test1.cpp)
target_link_libraries(test1 print GTest::gtest GTest::gtest_main)

add_executable(test_print tests/test_print.cpp)
target_link_libraries(test_print print GTest::gtest GTest::gtest_main)

enable_testing()
add_test(NAME test1 COMMAND test1)
add_test(NAME test_print COMMAND test_print)

add_executable(demo demo/main.cpp)
target_link_libraries(demo print)

install(TARGETS print demo DESTINATION bin)
install(DIRECTORY include/ DESTINATION include)
