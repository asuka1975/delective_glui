cmake_minimum_required(VERSION 3.22)

project(declarative_test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

enable_testing()
include(GoogleTest)

add_executable(create_test create_test.cpp)
target_include_directories(create_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_link_libraries(create_test GTest::GTest GTest::Main declarative_ui)

gtest_add_tests(TARGET create_test)