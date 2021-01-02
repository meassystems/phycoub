file(GLOB SRCS *.cpp)

add_executable(ParticleTests ${SRCS})
target_link_libraries(ParticleTests phycoub libgtest libgmock)

add_test(NAME ParticleTests COMMAND ParticleTests)
