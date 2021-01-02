file(GLOB SRCS *.cpp)

add_executable(WilsonCloudChamberTests ${SRCS})
target_link_libraries(WilsonCloudChamberTests phycoub libgtest libgmock)

add_test(NAME WilsonCloudChamberTests COMMAND WilsonCloudChamberTests)
