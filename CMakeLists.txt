cmake_minimum_required(VERSION 3.17)

project(PhyCoubAll)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()
add_subdirectory(phycoub)

if(DEFINED CMAKE_PREFIX_PATH)
    message("[!]'CMAKE_PREFIX_PATH' defined with ${CMAKE_PREFIX_PATH} Qt projects will be builded.")
    add_subdirectory(phywidgets)
    add_subdirectory(phyelectroninhomogeneousfields)
    add_subdirectory(phymagnetron)
    add_subdirectory(phywilsoncloudchamber)
else()
    message("[!] CMAKE_PREFIX_PATH not defined. Define it for build Qt projects.")
endif()