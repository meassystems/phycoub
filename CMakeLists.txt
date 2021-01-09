cmake_minimum_required(VERSION 3.17)

project(PhyCoubAll)

include(PlatformConfig.cmake)

enable_testing()
add_subdirectory(phycoub)

if(DEFINED QT_PATH)
    set(CMAKE_PREFIX_PATH ${QT_PATH})
    message(STATUS "'QT_PATH' defined with ${CMAKE_PREFIX_PATH} Qt projects will be builded.")
    add_subdirectory(widgets)
    add_subdirectory(examples)
else()
    message(WARNING "QT_PATH not defined. Define it for build Qt projects.")
endif()
