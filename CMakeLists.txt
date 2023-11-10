cmake_minimum_required(VERSION 3.17)

project(PhyCoubAll)

include(PlatformConfig.cmake)

if (DEFINED PLATFORM_WEB)
    set(CMAKE_AR "emar")
    set(CMAKE_STATIC_LIBRARY_SUFFIX ".a")
    set(CMAKE_CXX_CREATE_STATIC_LIBRARY "<CMAKE_AR> rc <TARGET> <OBJECTS>")
else()
    enable_testing()
endif()

add_subdirectory(phycoub)

if(DEFINED QT_PATH)
    set(CMAKE_PREFIX_PATH ${QT_PATH})
    message(STATUS "'QT_PATH' defined with ${CMAKE_PREFIX_PATH} Qt projects will be builded.")
    add_subdirectory(widgets)
    add_subdirectory(examples)
else()
    message(WARNING "QT_PATH not defined. Define it for build Qt projects.")
endif()
