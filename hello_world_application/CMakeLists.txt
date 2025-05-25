cmake_minimum_required(VERSION 3.10)
project(hello_world)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hello_world hello_world.cpp)
target_link_libraries(hello_world formatter_ex)
target_include_directories(hello_world PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_ex_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_lib
)
