cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

project(logger)

include(cmake/dependencies.cmake)
include(cmake/flags.cmake)

option(RUN_TESTS "Creates and runs unit tests for the project" OFF)

if(RUN_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

add_subdirectory(examples)

include_directories(inc)
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_library(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
