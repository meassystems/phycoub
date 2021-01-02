cmake_minimum_required(VERSION 3.17)

project(PhyCoubAll)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()
add_subdirectory(phycoub)

add_subdirectory(phywidgets)
add_subdirectory(phyelectroninhomogeneousfields)
add_subdirectory(phymagnetron)
add_subdirectory(phywilsoncloudchamber)
