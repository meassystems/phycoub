cmake_minimum_required(VERSION 3.16)

project(phycoub VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(../IncludeDirectories.cmake)

add_subdirectory(examples)
add_subdirectory(lifetimecontrollers)
add_subdirectory(phyobjects)
add_subdirectory(phyobjects/particlefigurematrix)
add_subdirectory(phyobjects/intercommunications)
add_subdirectory(phyobjects/fieldcreators)
add_subdirectory(particlesources)
add_subdirectory(borderfieldconditions)
add_subdirectory(calculationmodels)
add_subdirectory(shapes)
add_subdirectory(borderevents)
add_subdirectory(borderconditions)
add_subdirectory(common)
add_subdirectory(interworkingfunctions)
add_subdirectory(phymeasurement)
add_subdirectory(errors)
add_subdirectory(mathematic)
add_subdirectory(fieldfunctions)
add_subdirectory(particle)
add_subdirectory(logging)

add_library(phycoub STATIC
	 $<TARGET_OBJECTS:examples>
	 $<TARGET_OBJECTS:lifetimecontrollers>
	 $<TARGET_OBJECTS:phyobjects>
	 $<TARGET_OBJECTS:particlefigurematrix>
	 $<TARGET_OBJECTS:intercommunications>
	 $<TARGET_OBJECTS:fieldcreators>
	 $<TARGET_OBJECTS:particlesources>
	 $<TARGET_OBJECTS:borderfieldconditions>
	 $<TARGET_OBJECTS:calculationmodels>
	 $<TARGET_OBJECTS:shapes>
	 $<TARGET_OBJECTS:borderevents>
	 $<TARGET_OBJECTS:borderconditions>
	 $<TARGET_OBJECTS:common>
	 $<TARGET_OBJECTS:interworkingfunctions>
	 $<TARGET_OBJECTS:phymeasurement>
	 $<TARGET_OBJECTS:errors>
	 $<TARGET_OBJECTS:mathematic>
	 $<TARGET_OBJECTS:fieldfunctions>
	 $<TARGET_OBJECTS:particle>
	 $<TARGET_OBJECTS:logging>
)

add_custom_command(TARGET phycoub
        POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:phycoub> .)

include(Tests.cmake)
