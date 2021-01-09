cmake_minimum_required(VERSION 3.16)

project(common VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 Constants.h
	 HasId.cpp
	 HasId.h
	 UseLog.cpp
	 UseLog.h
	 Utils.h
)

add_library_with_eigen_dependency(common OBJECT ${SOURCES})

