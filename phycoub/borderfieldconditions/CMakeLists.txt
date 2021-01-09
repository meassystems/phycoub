cmake_minimum_required(VERSION 3.16)

project(borderfieldconditions VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 BorderFieldCondition.cpp
	 BorderFieldCondition.h
	 CyclicBoundedField.cpp
	 CyclicBoundedField.h
)

add_library_with_eigen_dependency(borderfieldconditions OBJECT ${SOURCES})

