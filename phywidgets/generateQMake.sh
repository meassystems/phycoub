#/bin/bash

function getHeaderFiles {
    #$1 folder
    #return headerFiles

    headerFiles=$(find $1 -type f | grep '\.h' | grep -v 'build-')
}

function getCppFiles {
    #$1 folder
    #return cppFiles

    cppFiles=$(find $1 -type f | grep '\.cpp' | grep -v 'build-')
}

function getDistFiles {
    #$1 folder
    #return distFiles

    distFiles=$(find $1 -type f | grep '\.gitignore\|\.clang-format\|\.md')
}

function getIncludePaths {
    #$1 folder
    #return includePaths

    includePaths=$(find $1 -type d -maxdepth 1 | grep -v '\.git' | grep -v 'build-' | tail -n +2)
}

function getSubdirs {
    #$1 folder
    #reurn subdirs

    subdirs=$(find $1 -type f | grep '\.pro' | grep -v '\.user' | grep -v 'build-')
}

function getQtModules {
    #return qtModules

    qtModules="gui opengl widgets"
}

function writeSomthingToVariable {
    #$1 folder
    #$2 variablename
    #$3 somthing CMakeLists

    local projectName=$(basename $1)
    local qmakePath=$1/$projectName.qmake

    for somthing in $3
    do
        echo "$2 += ../$projectName/${somthing#"$1/"}" >> $qmakePath
    done
    echo >> $qmakePath
}

function writeWidgetsSpecific {
    #$1 filepath

    echo -e "include(widgets-specific.qmake)\n" >> $1
}

function generateQMake {
    #$1 folder

    local projectName=$(basename $1)
    local qmakePath=$1/$projectName.qmake

    rm -r $qmakePath 2> /dev/null

    writeWidgetsSpecific $qmakePath

    getQtModules #return qtModules
    echo -e "QT += $qtModules\n" >> $qmakePath

    getIncludePaths $1 #return includePaths
    writeSomthingToVariable $1 INCLUDEPATH "$includePaths"

    getHeaderFiles $1 #return headerFiles
    writeSomthingToVariable $1 HEADERS "$headerFiles"

    getCppFiles $1 #return cppFiles
    writeSomthingToVariable $1 SOURCES "$cppFiles"

    getDistFiles $1 #return distFiles
    writeSomthingToVariable $1 DISTFILES "$distFiles"

    getSubdirs $1 #return subdirs
    writeSomthingToVariable $1 SUBDIRS "$subdirs"
}

generateQMake $PWD
