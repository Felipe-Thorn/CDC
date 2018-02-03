#SRC - Versão mínima do CMake: 3.0
cmake_minimum_required(VERSION 3.0)

#Name of the project
project(Perceptron C)

#Lista de fontes para a compilação da target executable
set(Source ../main.c)

#Adiciona a target executável a partir dos arquivos desse subdiretório
add_executable	(perceptron_exe ${Source})

#Procura bibliotecas com o nome abb no diretório lib,
# previamente abastecido por install (targets ...),
# e armazenas as bibliotecas encontradas em ABB_LIB.
find_library(PRC_LIB NAMES perceptron PATHS "${PROJECT_SOURCE_DIR}/../../../lib")

#Mostra o caminho da biblioteca.
message(STATUS "Library path PRC_LIB is " ${PRC_LIB})

#Liga a target executável com as bibliotecas que ele
# precisa para executar.
target_link_libraries(main ${PRC_LIB})

#Define o local onde o executável será armazenado
# como ${PROJECT_BINARY_DIR}/bin
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#Rules to run at install time:
# abb is an executable, so he must be treated as a RUNTIME target
# This rule specifies bin as the place to install abb
install(TARGETS perceptron_exe RUNTIME DESTINATION bin)

#In Windows, the founded .dll must be next to the  
# executable, otherwise the executable will not be 
# able to execute.
if(WIN32)
	file(COPY ${PRC_LIB} DESTINATION ${EXECUTABLE_OUTPUT_PATH})
endif(WIN32)

#The required libs of the system are included, in case of
# needing in the target
include (InstallRequiredSystemLibraries)

install (TARGETS perceptron_exe RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/pack)

include (CPack)

