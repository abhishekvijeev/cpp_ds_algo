cmake_minimum_required(VERSION 3.0.0)
project(cpp_ds_algo VERSION 0.1.0)

# include(CTest)
# enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(vector)
add_subdirectory(linked_list)

# add_executable(cpp_ds_algo main.cpp)
# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
