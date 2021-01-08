# Enable ExternalProject CMake module
include(ExternalProject)

# Download and install GoogleTest
ExternalProject_Add(
        eigen
        GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/eigen
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/eigen
)

ExternalProject_Get_Property(eigen install_dir)
include_directories(${install_dir}/include/eigen3)
