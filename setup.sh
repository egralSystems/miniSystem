#!/bin/bash

# Clone duktape and switch to version 2.7.0
git submodule init && git submodule update && \
cd duktape && \
git checkout tags/v2.7.0 && \
git fetch --all --tags && \

cd ..

# Configure duktape
[ ! -d ./duk_src ] && python2 duktape/tools/configure.py \
        --rom-support \
        --rom-auto-lightfunc \
        --option-file duktape/config/examples/low_memory.yaml \
        --option-file config.yaml \
        --output-directory duk_src
