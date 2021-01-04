cmake_minimum_required(VERSION 3.16)

project(errors VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 ErrorCode.h
	 ErrorDescription.cpp
	 ErrorDescription.h
	 ProgrammingException.h
	 MathExceptions.h
)

add_library(errors OBJECT ${SOURCES})

