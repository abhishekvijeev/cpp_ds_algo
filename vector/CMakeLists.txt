cmake_minimum_required(VERSION 3.00)

project(vector)

set(SOURCE_FILES main.cc)
set(INCLUDE_DIRS include)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

add_executable(vector ${SOURCE_FILES})

target_include_directories(vector PUBLIC ${INCLUDE_DIRS})