#! /bin/bash

cd imgui
make $@
cd ..
make $@
cd examples
make $@
cd ..
