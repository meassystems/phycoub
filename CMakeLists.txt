cmake_minimum_required(VERSION 3.17)

project(PhyCoubAll)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(phycoub)

enable_testing()

add_subdirectory(phyelectroninhomogeneousfields)
add_subdirectory(phywidgets)
