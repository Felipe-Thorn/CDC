cmake_minimum_required(VERSION 3.0)

#Includes the lib dir so it's files can be used
include_directories(${PROJECT_BINARY_DIR}/../lib)

#Seachs for cmocka named libraries in the lib dir included above
#and stores the result in the CMK_LIB variable 
find_library(CMK_LIB NAMES cmocka PATHS "${PROJECT_BINARY_DIR}/../lib")

#Shows the path to the library
message(STATUS "The library path CMK_LIB is " ${CMK_LIB})

#Adds a executable compiled with a test
add_executable(unit_test cmockatest.c)

#Linking the executable target with it's required Libs
target_link_libraries(teste ${CMK_LIB})

#Adds a test named Test to the target test
add_test(Test unit_test)

#Linking the executable target with it's required Libs
target_link_libraries(unit_test ${MOCKA_LIB})
