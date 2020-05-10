cmake_minimum_required(VERSION 3.00)

project(heap)

set(SOURCE_FILES main.cc)
set(INCLUDE_DIRS include)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

add_executable(heap ${SOURCE_FILES})

target_include_directories(heap PUBLIC ${INCLUDE_DIRS})