file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(unit_tests ${SRCS})

TARGET_LINK_LIBRARIES(unit_tests
        phycoub
        libgtest
        libgmock
        )

add_test(NAME unit_tests COMMAND unit_tests)
