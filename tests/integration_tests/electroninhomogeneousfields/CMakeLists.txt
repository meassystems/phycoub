file(GLOB SRCS *.cpp)

add_executable(ElectronInHomogeneousFieldsTests ${SRCS})
target_link_libraries(ElectronInHomogeneousFieldsTests phycoub libgtest libgmock)

add_test(NAME ElectronInHomogeneousFieldsTests COMMAND ElectronInHomogeneousFieldsTests)
