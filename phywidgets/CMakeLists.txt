cmake_minimum_required(VERSION 3.16)

project(phywidgets VERSION 1.0)

include(../QtConfig.cmake)
include(../IncludeDirectories.cmake)

add_subdirectory(phyparticleoptionscontroller)
add_subdirectory(phycoubglwidget)
add_subdirectory(phydirectioncontroller)
add_subdirectory(phydirectiongl)
add_subdirectory(phycommon)
add_subdirectory(physcalarcontroller)
add_subdirectory(phyhomogeneousdirectfieldcontroller)
add_subdirectory(phyremoveparticle)
add_subdirectory(phyviewparticletable)
add_subdirectory(phyaddparticle)
add_subdirectory(phycoubcontroller)

add_library(phywidgets STATIC 
	 $<TARGET_OBJECTS:phyparticleoptionscontroller>
	 $<TARGET_OBJECTS:phycoubglwidget>
	 $<TARGET_OBJECTS:phydirectioncontroller>
	 $<TARGET_OBJECTS:phydirectiongl>
	 $<TARGET_OBJECTS:phycommon>
	 $<TARGET_OBJECTS:physcalarcontroller>
	 $<TARGET_OBJECTS:phyhomogeneousdirectfieldcontroller>
	 $<TARGET_OBJECTS:phyremoveparticle>
	 $<TARGET_OBJECTS:phyviewparticletable>
	 $<TARGET_OBJECTS:phyaddparticle>
	 $<TARGET_OBJECTS:phycoubcontroller>
)

target_link_libraries(phywidgets phycoub Qt5::Core Qt5::Widgets Qt5::OpenGL ${OPENGL_LIBRARIES})