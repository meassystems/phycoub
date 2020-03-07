#!/bin/bash

cmakeFileName="CMakeLists.txt"

function writeSources {
    #$1 - folder

    local cmakeFilePath=$1/$cmakeFileName

    local files=$(ls -p $1 | grep -v / | grep '\.h\|\.cpp' )
    if [ ! -z "$files" ]; then
        echo "set(SOURCES " >> $cmakeFilePath
        for cxxFile in $files
        do
            echo -e "\t $cxxFile" >> $cmakeFilePath
        done
        echo -e ")\n" >> $cmakeFilePath
    fi
}

function writeSubdirectories {
    #$1 - folder

    # return subdirectories

    local cmakeFilePath=$1/$cmakeFileName

    subdirectories=$(ls -F $1 | grep \/$ | grep -v CMakeFiles)
    if [ ! -z "$subdirectories" ]; then
        for subDirectory in $subdirectories
        do
            local subDirectoryName=$(basename $subDirectory)
            echo "add_subdirectory( $subDirectoryName )" >> $cmakeFilePath
        done
        echo "" >> $cmakeFilePath
    fi 
}

function writeIncludeDirectories {
    #$1 - folder

    local cmakeFilePath=$1/$cmakeFileName
    local projectName=$(basename $1)
    local recursiveSubdirectories=$(find $1 -type d | grep -v 'CMakeFiles\|\.' | tail -n +2)

    if [ ! -z "$recursiveSubdirectories" ]; then
        echo "include_directories(" >> $cmakeFilePath
        for subDirectory in $recursiveSubdirectories
        do
            echo -e "\t ${subDirectory#"$1/"}" >> $cmakeFilePath
        done
        echo -e ")\n" >> $cmakeFilePath
    fi
}

function writeTargetIncludeDirectories {
    #$1 - folder

    local cmakeFilePath=$1/$cmakeFileName
    local projectName=$(basename $1)
    local recursiveSubdirectories=$(find $1 -type d | grep -v 'CMakeFiles\|\.' | tail -n +2)

    if [ ! -z "$recursiveSubdirectories" ]; then
        echo "target_include_directories($projectName PUBLIC" >> $cmakeFilePath
        for subDirectory in $recursiveSubdirectories
        do
            echo -e "\t ${subDirectory#"$1/"}" >> $cmakeFilePath
        done
        echo -e ")\n" >> $cmakeFilePath
    fi
}

function writeTargetLinkLibraries {
    #$1 - folder
    #$2 - subdirectories

    local cmakeFilePath=$1/$cmakeFileName
    local projectName=$(basename $1)

    if [ ! -z "$2" ]; then
        echo -e "target_link_libraries($projectName LINK_PUBLIC" >> $cmakeFilePath
        for subDirectory in $2
        do
            local subDirectoryName=$(basename $subDirectory)
            echo -e "\t $subDirectoryName" >> $cmakeFilePath
        done
        echo -e ")\n" >> $cmakeFilePath
    fi
}

function writeHead {
    #$1 - folder

    local cmakeFilePath=$1/$cmakeFileName
    local projectName=$(basename $1)

    echo -e "cmake_minimum_required(VERSION 3.16)\n" >> $cmakeFilePath
    echo -e "project($projectName VERSION 1.0)\n" >> $cmakeFilePath

    echo "set(CMAKE_CXX_STANDARD 17)" >> $cmakeFilePath
    echo -e "set(CMAKE_CXX_STANDARD_REQUIRED True)\n" >> $cmakeFilePath
}

function writeBody {
    #$1 - folder

    writeSources $1
    writeSubdirectories $1 # return subsubDirectories
}

function writeTail {
    #$1 - folder
    #$2 - subtargets

    local cmakeFilePath=$1/$cmakeFileName
    local projectName=$(basename $1)

    echo -e "add_library($projectName STATIC \${SOURCES})\n" >> $cmakeFilePath
}

function createCMakeLists {
    #$1 - folder

    writeHead $1
    writeBody $1 # return subdirectories
    writeTail $1

    writeTargetIncludeDirectories $1
    writeTargetLinkLibraries $1 "$subdirectories"
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

    local allFiles=$(ls -p $1 | grep -v /)
    if [ $2 -eq 0 ] || [[ ! $allFiles == *"$cmakeFileName"* ]]; then
        rm -r $1/$cmakeFileName 2> /dev/null
        createCMakeLists $1
    fi
}

function generateMainCmake {
    projectName=$(basename $PWD)

    rm -r $cmakeFileName 2> /dev/null

    writeHead $PWD
    writeIncludeDirectories $PWD

    writeSubdirectories $PWD # return subdirectories

    local stubForSharedLibrary="empty_stub.cpp"
    touch $stubForSharedLibrary 2> /dev/null
    echo -e "add_library($projectName SHARED $stubForSharedLibrary)\n" >> $cmakeFileName

    writeTargetIncludeDirectories $PWD
    writeTargetLinkLibraries $PWD "$subdirectories"
}

function generateCmakeDefaults {
    #$1 - not skip if already exists

    generateDeep ${PWD} $1
    if [ $1 -eq 0 ]; then
        generateMainCmake
    fi
}

[ $# -gt 0 ] && [ $1 = "hard" ]
generateCmakeDefaults $?