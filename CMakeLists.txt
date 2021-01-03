cmake_minimum_required(VERSION 3.17)

project(PhyCoubAll)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(PlatformConfig.cmake)

enable_testing()
add_subdirectory(phycoub)

if(DEFINED CMAKE_PREFIX_PATH)
    message(STATUS "'CMAKE_PREFIX_PATH' defined with ${CMAKE_PREFIX_PATH} Qt projects will be builded.")
    add_subdirectory(widgets)
    add_subdirectory(electroninhomogeneousfields)
    add_subdirectory(magnetron)
    add_subdirectory(wilsoncloudchamber)
else()
    message(WARNING "CMAKE_PREFIX_PATH not defined. Define it for build Qt projects.")
endif()