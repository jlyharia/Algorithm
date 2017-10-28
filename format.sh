#!/usr/bin/env bash
BASEDIR=$(dirname $0)
# echo $BASEDIR
file=`find $BASEDIR -not -path "*/build/*" -name "*.cpp" -o -name "*.hpp" -o -name "*.h"`
# echo $file

clang-format -style=file -i $file
