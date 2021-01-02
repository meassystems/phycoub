file(GLOB SRCS *.cpp)

add_executable(MathematicTests ${SRCS})
target_link_libraries(MathematicTests phycoub libgtest libgmock)

add_test(NAME MathematicTests COMMAND MathematicTests)
