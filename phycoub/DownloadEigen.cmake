include(ExternalProject)
ExternalProject_Add(
        eigen
        URL https://gitlab.com/libeigen/eigen/-/archive/3.3.9/eigen-3.3.9.zip
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/eigen
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/eigen
)

ExternalProject_Get_Property(eigen install_dir)
include_directories(${install_dir}/include/eigen3)

macro(add_library_with_eigen_dependency)
    add_library(${ARGV})
    add_dependencies(${ARGV0} eigen)
endmacro(add_library_with_eigen_dependency)
