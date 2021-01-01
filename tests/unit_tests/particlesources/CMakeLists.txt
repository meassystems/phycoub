file(GLOB SRCS *.cpp)

add_executable(ParticleSourceTests ${SRCS})
target_link_libraries(ParticleSourceTests phycoub libgtest libgmock)

add_test(NAME ParticleSourceTests COMMAND ParticleSourceTests)
