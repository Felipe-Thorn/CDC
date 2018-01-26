#Config - Versão mínima do CMake: 3.0
cmake_minimum_required(VERSION 3.0)

#Regra de instalação
install(SCRIPT sistema.cmake)

# OPTION( VARIABLE "Description" Initial state)
if(WIN32)
	SET( IS_WINDOWS \"Windows\")
	SET( ID 1 )

elseif(UNIX)
	SET( IS_UNIX \"Unix\")
	SET( ID 2 )

endif()

SET( RAM 8 )

CONFIGURE_FILE( ${CMAKE_SOURCE_DIR}/config/sistema.h.in ${CMAKE_SOURCE_DIR}/config/sistema.h )

add_executable(sistema sistema.c)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
