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

    #return recursiveSubdirectories

    local cmakeFilePath=$1/$cmakeFileName
    recursiveSubdirectories=$(find $1 -type d | grep -v 'CMakeFiles\|\.' | tail -n +2)

    if [ ! -z "$recursiveSubdirectories" ]; then
        for subDirectory in $recursiveSubdirectories
        do
            echo -e "add_subdirectory(${subDirectory#"$1/"})" >> $cmakeFilePath
        done
        echo >> $cmakeFilePath
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

function writeAddLibrary {
    #$1 - folder
    #$2 - library type
    #$3 - subdirectories
    #$4 - sources

    local cmakeFilePath=$1/$cmakeFileName
    local projectName=$(basename $1)

    if [ -z "$3" ]; then
        echo -e "add_library($projectName $2 $4)\n" >> $cmakeFilePath
    else
        echo "add_library($projectName $2 $4" >> $cmakeFilePath
        for subdirectory in $3
        do
            local subDirectoryName=$(basename $subdirectory)
            echo -e "\t $<TARGET_OBJECTS:$subDirectoryName>" >> $cmakeFilePath
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

function writePostBuildCommand {
    #$1 - folder
    #$2 - command

    local cmakeFilePath=$1/$cmakeFileName
    local projectName=$(basename $1)

    echo "add_custom_command(TARGET $projectName 
        POST_BUILD COMMAND \${CMAKE_COMMAND} $2)" >> $cmakeFilePath
    echo >> $cmakeFilePath
}

function createCMakeLists {
    #$1 - folder

    writeHead $1
    writeSources $1
    writeAddLibrary $1 OBJECT "" "\${SOURCES}"

    #writeTargetIncludeDirectories $1
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

    writeSubdirectories $PWD #return recursiveSubdirectories
    writeAddLibrary $PWD STATIC "$recursiveSubdirectories"
    writePostBuildCommand $PWD "-E copy $<TARGET_FILE:$projectName> ."

    #writeTargetIncludeDirectories $PWD
    #writeTargetLinkLibraries $PWD "$recursiveSubdirectories"
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