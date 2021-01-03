cmake_minimum_required(VERSION 3.17)

project(PhyCoubAll)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    add_definitions(-DDARWIN)
else()
    add_definitions(-DWIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

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