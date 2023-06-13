cmake_minimum_required(VERSION 3.22)

project(declarative_ui)

add_library(declarative_ui src/declarative_ui.cpp)
target_include_directories(declarative_ui PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)