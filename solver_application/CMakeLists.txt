cmake_minimum_required(VERSION 3.10)
project(solver)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включение сборки GoogleMock и GoogleTest
set(BUILD_GMOCK ON CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)
set(INSTALL_GTEST ON CACHE BOOL "" FORCE)

add_executable(solver equation.cpp)

target_link_libraries(solver
    formatter_ex
    solver_lib
)

target_include_directories(solver PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_ex_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../solver_lib
)

# Настройка директорий для артефактов сборки
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Установка в локальную директорию
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install CACHE PATH "Installation Directory" FORCE)

install(TARGETS solver
        RUNTIME DESTINATION bin)

# Упаковка
include(InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_NAME "solver")
set(CPACK_PACKAGE_VENDOR "yw0nk Inc.")
set(CPACK_PACKAGE_CONTACT "yw0nk")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Solver Application")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")

# Базовые генераторы
set(CPACK_GENERATOR "ZIP;TGZ")


if(WIN32)
    find_program(WIX_EXECUTABLE candle)
    if(WIX_EXECUTABLE)
        list(APPEND CPACK_GENERATOR WIX)
    else()
        find_program(NSIS_EXECUTABLE makensis)
        if(NSIS_EXECUTABLE)
            list(APPEND CPACK_GENERATOR NSIS)
        endif()
    endif()
endif()

# macOS: DMG
if(APPLE)
    list(APPEND CPACK_GENERATOR DragNDrop)
endif()

# DEB и RPM
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Bogdan")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.27)")
set(CPACK_RPM_PACKAGE_LICENSE "MIT")

include(CPack)