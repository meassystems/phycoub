find_package(Threads REQUIRED)

# Enable ExternalProject CMake module
include(ExternalProject)

# Download and install GoogleTest
ExternalProject_Add(
        gtest
        URL https://github.com/google/googletest/archive/master.zip
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
        CMAKE_ARGS -Dgtest_force_shared_crt=ON
        # Disable install step
        INSTALL_COMMAND ""
)

# Get GTest source and binary directories from CMake project
ExternalProject_Get_Property(gtest source_dir binary_dir)

include(../ConfigGtest.cmake)

add_subdirectory(integration_tests)
add_subdirectory(unit_tests)