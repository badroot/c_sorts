cmake_minimum_required(VERSION 3.9)
project(c_sort_tests)
set(CMAKE_CXX_STANDARD 11)
set(LIB_DIR lib)
#TURN THIS BACK ON
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")

# UNCOMMENT TO RE-SET-UP GOOGLE TEST
#configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
#execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
#        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
#execute_process(COMMAND "${CMAKE_COMMAND}" --build .
#        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )

add_library(c_sorts SHARED ${LIB_DIR}/c_sorts.c ${LIB_DIR}/c_sorts.h)

add_executable(sort_tests basic_tests.c)

#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

#include_directories("C:\\Users\\Red\\CLionProjects\\c_sorts\\cmake-build-debug\\googletest-src\\googletest\\include" "C:\\Users\\Red\\CLionProjects\\c_sorts\\cmake-build-debug\\googletest-src\\googletest")
#include_directories("lib")

#UNCOMMENT TO RE-SET-UP GOOGLE TEST
#add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
#        "${CMAKE_BINARY_DIR}/googletest-build")

#add_subdirectory("${LIB_DIR}")

#target_link_libraries(sort_tests gtest gtest_main)
target_link_libraries(sort_tests c_sorts)