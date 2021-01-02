project(electroninhomogeneousfields VERSION 1.0)

set(SOURCES
     main.cpp
     ElectronInHomogeneousFieldsController.h
     ElectronInHomogeneousFieldsController.cpp
     MainWindow.cpp
     MainWindow.h
     ScalarControllerAdapters.h
)

add_executable(electroninhomogeneousfields ${SOURCES})
target_link_libraries(electroninhomogeneousfields phywidgets)
