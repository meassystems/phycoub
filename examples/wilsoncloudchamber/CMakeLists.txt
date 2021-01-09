cmake_minimum_required(VERSION 3.17)

project(wilsoncloudchamber VERSION 1.0)

include(../../QtConfig.cmake)

get_target_property(PHY_COUB_INCLUDE_DIRECTORIES phycoub INCLUDE_DIRECTORIES)
get_target_property(WIDGETS_INCLUDE_DIRECTORIES widgets INCLUDE_DIRECTORIES)

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
add_dependencies(wilsoncloudchamber phycoub widgets)

target_include_directories(wilsoncloudchamber PRIVATE ${PHY_COUB_INCLUDE_DIRECTORIES} ${WIDGETS_INCLUDE_DIRECTORIES})
target_link_libraries(wilsoncloudchamber widgets phycoub Qt5::Core Qt5::Widgets Qt5::OpenGL ${OPENGL_LIBRARIES})
