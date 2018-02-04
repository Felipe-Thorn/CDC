#CMakeLists file: install
#Requires CMake: 3.5 or superior
cmake_minimum_required(VERSION 3.5)

#Rules to run at install time:
#<file name> is a file target and it's install destination is specified
#to ${PROJECT_SOURCE_DIR}/src/install/docs. If this destination doesn't
#exists, it shall be created.
INSTALL(FILES README.md DESTINATION ${PROJECT_SOURCE_DIR}/src/install/docs)

#List of source files
set(Source main.c perceptron.c)

#Adds a dynamic library
#Used dynamically. Loaded at Runtime
add_library(perceptron_dynamic SHARED ${Source})

#Sets the output name of the dynamic library as "perceptron"
set_target_properties(perceptron_dynamic PROPERTIES OUTPUT_NAME "perceptron")

#Sets the version and the soversion of the dynamic library
#Where VERSION is the build version and SOVERSION is the API version
set_target_properties(perceptron_dynamic PROPERTIES VERSION 1.2 SOVERSION 1)	

#Adds a static library
#Used to link other targets
add_library(perceptron_static STATIC ${Source})

#Sets the output name of the static library as "perceptron"
#Basically the same as the output name of the dynamic library
#but this one doens't have version or soversion
set_target_properties(perceptron_static PROPERTIES OUTPUT_NAME "perceptron")

#Rules to run at install time
#Installs a code to show the current stage
install(CODE "message(STATUS \"CONFIGURING LIBS\")" )

#Rules to run at install time:
#Both, abb_dynamic and abb_static, are installed at ${CMAKE_INSTALL_PREFIX}/lib
#one as a Lib and the other as an archive. The full path 
#was not informed, so, by the use of the standard path prefix,
#it will be something like /tmp/usr/lib
install(TARGETS perceptron_dynamic perceptron_static
        LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/lib
        ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/lib)
        
#Rules to run at install time:
#abb.h is a file and it's installed in ${PROJECT_SOURCE_DIR}/src/install/docs
#which means a folder in src/install subdir, called docs
install(FILES perceptron.h DESTINATION ${PROJECT_SOURCE_DIR}/lib)
