cmake_minimum_required(VERSION 3.00)

project(priority_queue)

set(SOURCE_FILES main.cc)
set(INCLUDE_DIRS include)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

add_executable(priority_queue ${SOURCE_FILES})

target_include_directories(priority_queue PUBLIC ${INCLUDE_DIRS})