cmake_minimum_required(VERSION 3.16)

project(particle VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 ContainOneParticleGroup.cpp
	 ContainOneParticleGroup.h
	 ContainParticleGroupIface.h
	 ContainParticleGroupList.cpp
	 ContainParticleGroupList.h
	 Particle.cpp
	 Particle.h
	 ParticleGroup.cpp
	 ParticleGroup.h
	 ParticleGroupList.cpp
	 ParticleGroupList.h
	 ParticleOptions.h
	 ParticleOptionsCatalog.cpp
	 ParticleOptionsCatalog.h
)

add_library_with_eigen_dependency(particle OBJECT ${SOURCES})

