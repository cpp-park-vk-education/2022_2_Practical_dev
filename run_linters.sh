#!/bin/bash


#!/bin/bash
set -o pipefail

function check_log() {
    LOG=$( { ${1}; } 2>&1 )
    STATUS=$?
    echo "$LOG"
    if echo "$LOG" | grep -q -E "${2}"
    then
        exit 1
    fi

    if [ $STATUS -ne 0 ]
    then
        exit $STATUS
    fi
}

echo -e "\nRun linters"

echo -e "\nRUN cpplint.py"
check_log "cpplint --extensions=cpp,hpp --recursive ./src/*" "Can't open for reading"

echo - e "\nRUN cppcheck"
check_log "cppcheck src --std=c++14 --enable=all --inconclusive --error-exitcode=1 -I src/internal/*/include --suppress=missingIncludeSystem --suppress=unusedFunction --suppress=functionStatic" "\(information\)"

echo -e "SUCCESS"
