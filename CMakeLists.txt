cmake_minimum_required(VERSION 3.17)

project(PhyCoubAll)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(IncludeDirectories.cmake)

set(CMAKE_PREFIX_PATH /usr/local/Cellar/qt/5.15.2)
include(QtConfig.cmake)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    add_definitions(-DDARWIN -DGL_SILENCE_DEPRECATION)
else()
    add_definitions(-DWIN32)
endif()

enable_testing()

add_subdirectory(phycoub)
add_subdirectory(phyelectroninhomogeneousfields)
add_subdirectory(phywidgets)
