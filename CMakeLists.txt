cmake_minimum_required(VERSION 3.9)
#option(test "Build all tests." OFF)
project(c_sort_tests)
set(CMAKE_CXX_STANDARD 11)
set(LIB_DIR lib)
#set(gtest_SOURCE_DIR cmake-build-debug/googletest-src/googletest)
#set(gtest_PROJ_FIR cmake-build-debug/googletest-src)
#TURN THIS BACK ON
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")

# UNCOMMENT TO RE-SET-UP GOOGLE TEST
#configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
#execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
#        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
#execute_process(COMMAND "${CMAKE_COMMAND}" --build .
#        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )

add_library(c_sorts SHARED ${LIB_DIR}/c_sorts.c ${LIB_DIR}/c_sorts.h)

add_executable(solo_tests basic_tests.c)
add_executable(perf HW5_CS288.c)
add_executable(runUnitTests testing.cpp)



#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

#include_directories("C:\\Users\\Red\\CLionProjects\\c_sorts\\cmake-build-debug\\googletest-src\\googletest\\include" "C:\\Users\\Red\\CLionProjects\\c_sorts\\cmake-build-debug\\googletest-src\\googletest")
#include_directories("lib")

#UNCOMMENT TO RE-SET-UP GOOGLE TEST
#add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
#        "${CMAKE_BINARY_DIR}/googletest-build")

#add_subdirectory("${LIB_DIR}")

#target_link_libraries(sort_tests gtest gtest_main)
target_link_libraries(solo_tests c_sorts)
target_link_libraries(perf c_sorts)
target_link_libraries(runUnitTests c_sorts)
##if (test)
#    add_subdirectory("${gtest_PROJ_DIR}")
#    enable_testing()
#    include_directories("${gtest_SOURCE_DIR}/include" "${gtest_SOURCE_DIR}")
#
#    add_executable(runUnitTests testing.cpp)
#    target_link_libraries(runUnitTests gtest gtest_main)
#    target_link_libraries(runUnitTests c_sorts)
#
##endif ()