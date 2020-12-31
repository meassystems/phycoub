file(GLOB SRCS *.cpp)

add_executable(BorderConditionTest ${SRCS})
target_link_libraries(BorderConditionTest phycoub libgtest libgmock)

add_test(NAME BorderConditionTest COMMAND BorderConditionTest)
