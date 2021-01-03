find_package(Threads REQUIRED)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

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

# Create a libgtest target to be used as a dependency by test programs
add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)

set(LIBGTEST_PATH ${binary_dir}/lib/libgtest.a)
if(DEFINED WIN32)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(LIBGTEST_PATH ${binary_dir}/lib/Debug/gtestd.lib)
    else()
        set(LIBGTEST_PATH ${binary_dir}/lib/Release/gtest.lib)
    endif()
endif()

# Set libgtest properties
set_target_properties(libgtest PROPERTIES
        "IMPORTED_LOCATION" "${LIBGTEST_PATH}"
        "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
        )

# Create a libgmock target to be used as a dependency by test programs
add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)

set(LIBMOCK_PATH ${binary_dir}/lib/libgmock.a)
if(DEFINED WIN32)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(LIBMOCK_PATH ${binary_dir}/lib/Debug/gmockd.lib)
    else()
        set(LIBMOCK_PATH ${binary_dir}/lib/Release/gmock.lib)
    endif()
endif()

# Set libgmock properties
set_target_properties(libgmock PROPERTIES
        "IMPORTED_LOCATION" "${LIBMOCK_PATH}"
        "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
        )

# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
include_directories("${source_dir}/googletest/include"
        "${source_dir}/googlemock/include")

add_subdirectory(integration_tests)
add_subdirectory(unit_tests)