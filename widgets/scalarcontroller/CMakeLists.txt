cmake_minimum_required(VERSION 3.16)

project(scalarcontroller VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 PhyBoolPhyCoubControllerSubscriber.cpp
	 PhyBoolPhyCoubControllerSubscriber.h
	 PhyScalarBoolControllerWidget.cpp
	 PhyScalarBoolControllerWidget.h
	 PhyScalarControllerWidgetBase.h
	 PhyScalarDoubleControllerWidget.cpp
	 PhyScalarDoubleControllerWidget.h
	 PhyScalarPhyCoubControllerSubscriber.h
	 PhyScalarULongControllerWidget.cpp
	 PhyScalarULongControllerWidget.h
	 PhyScalarVectorControllerWidget.cpp
	 PhyScalarVectorControllerWidget.h
	 PhyVectorPhyCoubControllerSubscriber.cpp
	 PhyVectorPhyCoubControllerSubscriber.h
)

add_library(scalarcontroller OBJECT ${SOURCES})

