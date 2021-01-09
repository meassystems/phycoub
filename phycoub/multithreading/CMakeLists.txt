cmake_minimum_required(VERSION 3.16)

project(multithreading VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
	 ThreadPool.h
	 ThreadPool.cpp
	 SpinLock.h
	 SpinLock.cpp
)

add_library_with_eigen_dependency(multithreading OBJECT ${SOURCES})

