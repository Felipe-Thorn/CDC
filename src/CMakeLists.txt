#Version requirement
cmake_minimum_required(VERSION 3.5)

#The actual CMakeLists file is the one in src dir
message(STATUS "CMakeLists in src")

#List of source files
set(Source main.c abb.c)

#Adds an executable from src dir
#add_executable(abb ${Fonte})

#Includes the lib dir of the install (TARGETS [...] command
#So it's files can be used
include_directories(${PROJECT_BINARY_DIR}/../lib)

#Seachs for abb named libraries in the lib dir included above
#and stores the result in the variable ABB_LIB
find_library(ABB_LIB NAMES abb PATHS "${PROJECT_BINARY_DIR}/../lib")

#Shows the path to the librarys
message(STATUS "The library path ABB_LIB is " ${ABB_LIB})

#Linking the executable target with it's required Libs
#target_link_libraries(abb ${ABB_LIB})

#Sets EXECUTABLE_OUTPUT_PATH as the bin subdir in build dir
#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#Rules to run at install time:
#hello is an executable, so he must be treated as a RUNTIME target
#This rule specifies bin as the place to install hello
#install(TARGETS abb RUNTIME DESTINATION bin)

#Rules to run at install time:
#Installs the message.cmake SCRIPT
#These simple script is in the same dir.
install(SCRIPT message.cmake)
