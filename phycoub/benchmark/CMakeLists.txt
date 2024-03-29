find_package(Threads REQUIRED)

# Enable ExternalProject CMake module
include(ExternalProject)

# Download and install GoogleTest
ExternalProject_Add(
        benchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG main
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/google-benchmark
        CMAKE_ARGS -DBENCHMARK_DOWNLOAD_DEPENDENCIES=OFF -DGOOGLETEST_PATH=${PROJECT_SOURCE_DIR}/gtest/src/gtest -DCMAKE_BUILD_TYPE=Release
        DEPENDS gtest
        # Disable install step
        INSTALL_COMMAND ""
)

ExternalProject_Get_Property(benchmark source_dir binary_dir)

# Create a libgtest target to be used as a dependency by test programs
add_library(libbenchmark IMPORTED STATIC)
add_dependencies(libbenchmark benchmark)

set(LIBBENCHMARK_PATH ${binary_dir}/src/libbenchmark.a)
if(DEFINED WIN32)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(LIBBENCHMARK_PATH ${binary_dir}/src/Debug/benchmarkd.lib)
    else()
        set(LIBBENCHMARK_PATH ${binary_dir}/src/Release/benchmark.lib)
    endif()
endif()

# Set libgmock properties
set_target_properties(libbenchmark PROPERTIES
        "IMPORTED_LOCATION" "${LIBBENCHMARK_PATH}"
        "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
        )

# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
include_directories("${source_dir}/include")

add_subdirectory(magnetron)