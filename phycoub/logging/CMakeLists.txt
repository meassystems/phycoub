cmake_minimum_required(VERSION 3.16)

project(logging VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
	 Log.cpp
	 Log.h
	 LogLevel.h
	 LogObserver.h
	 StdErrLogObserver.cpp
	 StdErrLogObserver.h
)

add_library_with_eigen_dependency(logging OBJECT ${SOURCES})

