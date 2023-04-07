cmake_minimum_required (VERSION 3.8)

project ("diamant")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES src/*.cpp)

find_package(raylib CONFIG)

if(NOT raylib_FOUND)
    include_directories(${CMAKE_SOURCE_DIR}/include/raylib)
    link_directories(lib)
endif()

include_directories(${CMAKE_SOURCE_DIR}/include/raygui)
include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable (${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)