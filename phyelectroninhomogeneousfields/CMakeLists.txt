cmake_minimum_required(VERSION 3.17)

project(electroninhomogeneousfields VERSION 1.0)

include(../QtConfig.cmake)
include(../IncludeDirectories.cmake)

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
target_link_libraries(electroninhomogeneousfields phywidgets phycoub Qt5::Core Qt5::Widgets Qt5::OpenGL ${OPENGL_LIBRARIES})
