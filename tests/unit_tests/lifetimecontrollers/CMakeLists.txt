file(GLOB SRCS *.cpp)

add_executable(LifeTimeControllerTests ${SRCS})
target_link_libraries(LifeTimeControllerTests phycoub libgtest libgmock)

add_test(NAME LifeTimeControllerTests COMMAND LifeTimeControllerTests)
