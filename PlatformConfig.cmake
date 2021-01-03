if(NOT DEFINED CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    add_definitions(-DDARWIN)
else()
    add_definitions(-DWIN32)
endif()