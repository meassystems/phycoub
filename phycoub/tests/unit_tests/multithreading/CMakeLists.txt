file(GLOB SRCS *.cpp)

add_executable(MultithreadingTests ${SRCS})
target_link_libraries(MultithreadingTests phycoub libgtest libgmock)

add_test(NAME MultithreadingTests COMMAND MathematicTests)
