#!/bin/bash

# Clone duktape and switch to version 2.7.0
git clone git@github.com:svaarala/duktape.git
cd duktape
git checkout tags/v2.7.0
git fetch --all --tags

cd ..

# Configure duktape
python2 duktape/tools/configure.py \
        --rom-support \
        --rom-auto-lightfunc \
        --option-file duktape/config/examples/low_memory.yaml \
        --option-file config.yaml \
        --output-directory duk_src
