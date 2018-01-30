#CMakeLists file: tests
#Requires CMake 3.5 or superior
cmake_minimum_required(VERSION 3.5)

#Adds a executable compiled with a test
add_executable(test_target main.c cmockatest.c)

#Sets EXECUTABLE_OUTPUT_PATH as the bin subdirectory in build dir
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#Includes the lib dir so it's files can be used
include_directories(${PROJECT_BINARY_DIR}/../lib)

#Seachs for cmocka named libraries in the lib dir included above
#and stores the result in the CMK_LIB variable 
find_library(CMK_LIB NAMES cmocka PATHS "${PROJECT_BINARY_DIR}/../lib")

#Shows the path to the library
message(STATUS "The library path MOCKA_LIB is " ${CMK_LIB})

#Linking the executable target with it's required Libs
target_link_libraries(test_target ${CMK_LIB})

#Adds a test_target named Test to the target test
add_test(Test_Target ${PROJECT_BINARY_DIR}/bin/test_target)

