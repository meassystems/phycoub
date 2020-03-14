cmake_minimum_required(VERSION 3.16)

project(common VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 Constants.h
	 ContainParticleGroupIface.h
	 ContainParticleGroupList.cpp
	 ContainParticleGroupList.h
	 HasId.cpp
	 HasId.h
	 UseLog.cpp
	 UseLog.h
	 Utils.h
)

add_library(common OBJECT ${SOURCES})

