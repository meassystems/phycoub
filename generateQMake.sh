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

    local projectName=$(basename $1)
    local qmakePath=$1/$projectName.qmake

    for somthing in $3
    do
        echo "$2 += ../$projectName/${somthing#"$1/"}" >> $qmakePath
    done
    echo >> $qmakePath
}

function writeWidgetsSpecific {
    #$1 folder

    local projectName=$(basename $1)
    local qmakePath=$1/$projectName.qmake

    echo -e "LIBS += -L\$\$PWD/../$projectName/ -l$projectName\n" >> $qmakePath
}

function generateQMake {
    #$1 folder

    local projectName=$(basename $1)
    local qmakePath=$1/$projectName.qmake

    rm -r $qmakePath 2> /dev/null

    getIncludeDirectories $1 #return includeDirectories
    writeSomthingToVariable $1 INCLUDEPATH "$includeDirectories"
    writeWidgetsSpecific $1
}

generateQMake $PWD