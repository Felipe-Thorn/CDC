#CMakeLists file: Top-level
#Requires CMake 3.5 or superior
cmake_minimum_required(VERSION 3.5)

#Name of the project
project(LibsCMake C)

#Verifies the host system and displays the result
if(WIN32)
	message(STATUS "This is a Windows system")
elseif(UNIX)
	message(STATUS "This is a UNIX system")
endif()

#Shows BIN and SRC directorys
message(STATUS "BINARY dir: " ${PROJECT_BINARY_DIR})
message(STATUS "SOURCE dir: " ${PROJECT_SOURCE_DIR})

#Allows the creation of test targets
#Those targets may be defined in other subdirectory
#but these directory need to be included
enable_testing()

#Adds config subdirectory, that must have his own CMakeLists file
#His CMakeLists file will be executed...
add_subdirectory(src/config)

#Adds src subdirectory, that must have his own CMakeLists file
#His CMakeLists file will be executed...
add_subdirectory(src/sources)

#Adds tests subdirectory, that must have his own CMakeLists file
#His CMakeLists file will be executed...
add_subdirectory(src/tests)

#Adds install+examples subdirectory, that must have his own CMakeLists file
#His CMakeLists file will be executed...
add_subdirectory(src/install)

#...and then the execution comes back here
message(STATUS "CMakeLists in top-level dir")

#Rules to run at install time:
#README.md is a file target and it's install destination is specified
#to ${PROJECT_SOURCE_DIR}
INSTALL(FILES README.md DESTINATION ${PROJECT_SOURCE_DIR})

#Rules to run at install time:
#runHello.sh is a program target and it's install destination is specified
#to /usr/local/bin
#In order tu run runSistema.sh, add cd /usr/local/bin/runHello.sh 
#into script stage in .travis.yml
INSTALL(PROGRAMS runSistema.sh DESTINATION bin)

#Rules to run at install time:
#doc/ is a directory target and it's install destination is specified
#to ${PROJECT_SOURCE_DIR}
INSTALL(DIRECTORY doc/ DESTINATION ${PROJECT_SOURCE_DIR})
