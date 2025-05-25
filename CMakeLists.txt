cmake_minimum_required(VERSION 3.22)
project(lab03)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(CODE_COVERAGE "Enable coverage reporting" ON)


if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    message(STATUS "Code coverage enabled")
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
endif()

add_subdirectory(formatter_lib)
add_subdirectory(formatter_ex_lib)
add_subdirectory(solver_lib)
add_subdirectory(banking)
add_subdirectory(tests)
add_subdirectory(hello_world_application)
add_subdirectory(solver_application)

