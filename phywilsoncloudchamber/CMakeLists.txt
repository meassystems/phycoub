cmake_minimum_required(VERSION 3.17)

project(wilsoncloudchamber VERSION 1.0)

include(../QtConfig.cmake)
include(../IncludeDirectories.cmake)

set(SOURCES
     main.cpp
     WilsonCloudChamberController.h
     WilsonCloudChamberController.cpp
     WidgetConfigurationUtils.h
     WidgetConfigurationUtils.cpp
     MainWindow.cpp
     MainWindow.h
     MainWindow.ui
     ScalarControllerAdapters.h
)

add_executable(wilsoncloudchamber ${SOURCES})
target_link_libraries(wilsoncloudchamber phywidgets phycoub Qt5::Core Qt5::Widgets Qt5::OpenGL ${OPENGL_LIBRARIES})
