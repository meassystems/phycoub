cmake_minimum_required(VERSION 3.17)

project(magnetron VERSION 1.0)

include(../QtConfig.cmake)
include(../IncludeDirectories.cmake)

set(SOURCES
     main.cpp
     MagnetronController.h
     MagnetronController.cpp
     MainWindow.cpp
     MainWindow.h
     MainWindow.ui
     ScalarControllerAdapters.h
)

add_executable(magnetron ${SOURCES})
target_link_libraries(magnetron widgets phycoub Qt5::Core Qt5::Widgets Qt5::OpenGL ${OPENGL_LIBRARIES})
