add_custom_target(DownloadEigen)

set(Eigen3_DIR "${CMAKE_CURRENT_LIST_DIR}/eigen/share/eigen3/cmake")
find_package (Eigen3 NO_MODULE NO_DEFAULT_PATH)
if (NOT TARGET Eigen3::Eigen)
    message(STATUS "Eigen3 not found.")
    include(ExternalProject)
    ExternalProject_Add(
            eigen
            GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
            PREFIX ${CMAKE_CURRENT_BINARY_DIR}/eigen
            CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/eigen
    )
    ExternalProject_Get_Property(eigen install_dir)
    include_directories(${install_dir}/eigen/include)

    add_dependencies(DownloadEigen eigen)
else()
    message(STATUS "Eigen3 found: ${Eigen3_CONFIG}")
endif ()


