cmake_minimum_required(VERSION 3.00)

project(linked_list)

set(SOURCE_FILES main.cc)
set(INCLUDE_DIRS include)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

add_executable(linked_list ${SOURCE_FILES})

target_include_directories(linked_list PUBLIC ${INCLUDE_DIRS})