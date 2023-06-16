cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

project(declarative_ui)

file(GLOB_RECURSE SRC src *.cpp)

add_library(declarative_ui ${SRC})
target_include_directories(declarative_ui PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(declarative_runner main.cpp)
target_include_directories(declarative_runner PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(declarative_runner PRIVATE declarative_ui)


add_subdirectory(test)