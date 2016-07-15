#!/bin/sh

./build.sh

if [ $? -ne 0 ]; then
    echo "Build failed, not running tests."
    exit 1
fi

./.build/patch_test
