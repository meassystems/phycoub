cmake_minimum_required(VERSION 3.16)

project(particlesources VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 ConeParticleSource.cpp
	 ConeParticleSource.h
	 CylindricalXYParticleSource.cpp
	 CylindricalXYParticleSource.h
	 ParticleSourceBase.cpp
	 ParticleSourceBase.h
	 ParticleSourceIface.h
)

add_library_with_eigen_dependency(particlesources OBJECT ${SOURCES})

