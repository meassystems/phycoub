set(GTEST_NAME gtest_ctest)
include(../ConfigGtest.cmake)

add_subdirectory(integration_tests)
add_subdirectory(unit_tests)