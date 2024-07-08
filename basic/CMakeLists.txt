# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# Añadir el directorio de componentes
list(APPEND EXTRA_COMPONENT_DIRS "components/arduino")
list(APPEND EXTRA_COMPONENT_DIRS "components/stdintf")
list(APPEND EXTRA_COMPONENT_DIRS "components/app")
list(APPEND EXTRA_COMPONENT_DIRS "components/wrapper")
project(basic)

message(STATUS "Component directories: ${EXTRA_COMPONENT_DIRS}")