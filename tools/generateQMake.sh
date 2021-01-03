#/bin/bash

function getIncludeDirectories {
    #$1 folder
    #return includeDirectories

    includeDirectories=$(find $1 -type d | grep -v 'CMakeFiles\|\.' | tail -n +2)
}

function writeSomthingToVariable {
    #$1 folder
    #$2 variablename
    #$3 somthing CMakeLists
    #$4 relative path
    #$5 qmake extension

    local projectName=$(basename $1)
    local qmakePath=$1/$projectName.$5

    for somthing in $3
    do
        echo "$2 += $4$projectName/${somthing#"$1/"}" >> $qmakePath
    done
    echo >> $qmakePath
}

function writeWidgetsSpecific {
    #$1 folder
    #$2 qmake extension

    local projectName=$(basename $1)
    local qmakePath=$1/$projectName.$2

    echo -e "LIBS += -L\$\$PWD/../$projectName/ -l$projectName\n" >> $qmakePath
}

function generateQMake {
    #$1 folder

    local projectName=$(basename $1)
    local extension="qmake"
    local qmakePath=$1/$projectName.$extension

    rm -r $qmakePath 2> /dev/null

    getIncludeDirectories $1 #return includeDirectories
    writeSomthingToVariable $1 INCLUDEPATH "$includeDirectories" "../" $extension
    writeWidgetsSpecific $1 $extension
}

function generateQMakeWidgets {
    #$1 folder

    local projectName=$(basename $1)
    local extension="widgets.qmake"
    local qmakePath=$1/$projectName.$extension

    rm -r $qmakePath 2> /dev/null

    getIncludeDirectories $1 #return includeDirectories
    writeSomthingToVariable $1 INCLUDEPATH "$includeDirectories" "../../" $extension
}

generateQMake $PWD
generateQMakeWidgets $PWD