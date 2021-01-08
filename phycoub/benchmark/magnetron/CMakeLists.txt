file(GLOB SRCS *.cpp)

add_executable(MagnetronBenchmark ${SRCS})
target_link_libraries(MagnetronBenchmark phycoub libgtest libgmock libbenchmark)

add_test(NAME MagnetronBenchmark COMMAND MagnetronBenchmark --benchmark_out_format=json --benchmark_out=${PROJECT_SOURCE_DIR}/../benchmark_result.json)
