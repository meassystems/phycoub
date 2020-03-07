#!/bin/bash

cmakeFileName="CMakeLists.txt"

function writeHead {
    #$1 - folder

    cmakeFilePath=$1/$cmakeFileName
    projectName=$(basename $1)

    echo -e "cmake_minimum_required(3.16)\n" >> $cmakeFilePath
    echo -e "project($projectName VERSION 1.0)\n" >> $cmakeFilePath

    echo "set(CMAKE_CXX_STANDARD 17)" >> $cmakeFilePath
    echo -e "set(CMAKE_CXX_STANDARD_REQUIRED True)\n" >> $cmakeFilePath
}

function writeBody {
    #$1 - folder

    cmakeFilePath=$1/$cmakeFileName

    echo "set(SOURCES " >> $cmakeFilePath

    files=$(ls -p $1 | grep -v / | grep '.h\|.cpp' )
    for cxxFile in $files
    do
        echo -e "\t $cxxFile" >> $cmakeFilePath
    done
    echo -e ")\n" >> $cmakeFilePath
}

function writeTail {
    #$1 - folder

    cmakeFilePath=$1/$cmakeFileName
    projectName=$(basename $1)

    echo "add_library($projectName STATIC \${SOURCES})" >> $cmakeFilePath 
}

function createCMakeLists {
    #$1 - folder

    writeHead $1
    writeBody $1
    writeTail $1
}

function generateDeep {
    #$1 - folder
    #$2 - not skeep if already exists

    for entry in "$1"/*
    do
        if [ -d $entry ]; then
            generateDeep $entry $2
        fi
    done

    allFiles=$(ls -p $1 | grep -v /)
    if [ $2 -eq 0 ] || [[ ! $allFiles == *"$cmakeFileName"* ]]; then
        rm -r $1/$cmakeFileName
        createCMakeLists $1
    fi
}

function generateCmakeDefaults {
    #$1 - not skip if already exists

    for entry in "$1"/*
    do
        generateDeep ${PWD} $1
    done
}

[ $# -gt 0 ] && [ $1 = "hard" ]
generateCmakeDefaults $?