cmake_minimum_required(VERSION 3.16)

project(widgets VERSION 1.0)

include(../QtConfig.cmake)
include(../IncludeDirectories.cmake)

add_subdirectory(particleoptionscontroller)
add_subdirectory(trajectory)
add_subdirectory(coubglwidget)
add_subdirectory(directioncontroller)
add_subdirectory(directiongl)
add_subdirectory(common)
add_subdirectory(scalarcontroller)
add_subdirectory(homogeneousdirectfieldcontroller)
add_subdirectory(removeparticle)
add_subdirectory(viewparticletable)
add_subdirectory(addparticle)
add_subdirectory(coubcontroller)

add_library(widgets STATIC 
	 $<TARGET_OBJECTS:particleoptionscontroller>
	 $<TARGET_OBJECTS:coubglwidget>
	 $<TARGET_OBJECTS:directioncontroller>
	 $<TARGET_OBJECTS:directiongl>
	 $<TARGET_OBJECTS:common_w>
	 $<TARGET_OBJECTS:scalarcontroller>
	 $<TARGET_OBJECTS:homogeneousdirectfieldcontroller>
	 $<TARGET_OBJECTS:removeparticle>
	 $<TARGET_OBJECTS:viewparticletable>
	 $<TARGET_OBJECTS:addparticle>
	 $<TARGET_OBJECTS:coubcontroller>
	 $<TARGET_OBJECTS:trajectory>
)

target_link_libraries(widgets phycoub Qt5::Core Qt5::Widgets Qt5::OpenGL ${OPENGL_LIBRARIES})