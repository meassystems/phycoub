file(GLOB SRCS *.cpp)

add_executable(BorderConditionTests ${SRCS})
target_link_libraries(BorderConditionTests phycoub libgtest libgmock)

add_test(NAME BorderConditionTests COMMAND BorderConditionTests)
