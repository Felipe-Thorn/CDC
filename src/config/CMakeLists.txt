#CMakeLists file: config
#Requires CMake: 3.5 or superior
cmake_minimum_required(VERSION 3.5)

#Rules to run at install time:
#sistema.cmake is a Script that execute at install time
#Warning: scripts cannot have targets in it
install(SCRIPT sistema.cmake)

#Verifies the actual system and sets variables:
#ID and IS_WINDOWS, or IS_UNIX
if(WIN32)
	SET( IS_WINDOWS \"Windows\")
	SET( ID 1 )

elseif(UNIX)
	SET( IS_UNIX \"Unix\")
	SET( ID 2 )

endif()

#Sets variable: RAM
SET( RAM 8 )

#Command to configure the file sistema.h with the definitions in sistema.h.in.
#sistema.h.in contains some of the variables defined in this file
CONFIGURE_FILE( ${CMAKE_SOURCE_DIR}/src/config/sistema.h.in ${CMAKE_SOURCE_DIR}/src/config/sistema.h )

#Adds the executable sistema
add_executable(sistema sistema.c)

#Sets the output file of the executable
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#Rules to run at install time:
# sistema is an executable, so he must be treated as a RUNTIME target
# This rule specifies bin as the place to install sistema
install(TARGETS sistema RUNTIME DESTINATION bin)
