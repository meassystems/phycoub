cmake_minimum_required(VERSION 3.16)

project(particlesources VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 ConeParticleSource.h
	 CylindricalXYParticleSource.cpp
	 CylindricalXYParticleSource.h
	 ParticleSourceIface.h
)

add_library(particlesources OBJECT ${SOURCES})

