cmake_minimum_required(VERSION 3.17)

project(electroninhomogeneousfields VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(../../QtConfig.cmake)

get_target_property(PHY_COUB_INCLUDE_DIRECTORIES phycoub INCLUDE_DIRECTORIES)
get_target_property(WIDGETS_INCLUDE_DIRECTORIES widgets INCLUDE_DIRECTORIES)

set(SOURCES
     main.cpp
     ElectronInHomogeneousFieldsController.h
     ElectronInHomogeneousFieldsController.cpp
     MainWindow.cpp
     MainWindow.h
     MainWindow.ui
     ScalarControllerAdapters.h
)

add_executable(electroninhomogeneousfields ${SOURCES})
add_dependencies(electroninhomogeneousfields phycoub widgets)

target_include_directories(electroninhomogeneousfields PRIVATE ${PHY_COUB_INCLUDE_DIRECTORIES} ${WIDGETS_INCLUDE_DIRECTORIES})
target_link_libraries(electroninhomogeneousfields widgets phycoub Qt5::Core Qt5::Widgets Qt5::OpenGL ${OPENGL_LIBRARIES})
