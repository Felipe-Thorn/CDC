#Requires CMake 3.5 or superior
cmake_minimum_required(VERSION 3.5)

#Name of the project
project(HelloCMake C)

#Verifies the host system and displays the result
if(WIN32)
	message(STATUS "This is a Windows system")
elseif(UNIX)
	message(STATUS "This is a UNIX system")
endif()

#ADDs an executable
add_executable(hello helloWorld.c )
