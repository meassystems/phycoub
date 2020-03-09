cmake_minimum_required(VERSION 3.16)

project(src VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 main.cpp
)

add_library(src OBJECT ${SOURCES})

