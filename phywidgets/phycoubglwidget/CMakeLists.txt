cmake_minimum_required(VERSION 3.16)

project(phycoubglwidget VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 GLRotationModelAdapter.cpp
	 GLRotationModelAdapter.h
	 ModelViewerGLWidget.cpp
	 ModelViewerGLWidget.h
	 PhyCoubGL.cpp
	 PhyCoubGL.h
	 PhyCoubGlScalarControllerAdapters.h
)

add_library(phycoubglwidget OBJECT ${SOURCES})

