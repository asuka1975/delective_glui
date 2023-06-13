cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

project(declarative_ui)

add_library(declarative_ui src/declarative_ui.cpp)
target_include_directories(declarative_ui PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)