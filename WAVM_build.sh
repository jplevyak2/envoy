#!/bin/bash
cmake -D WAVM_ENABLE_STATIC_LINKING=YES .
make clean
make -j8
sudo make install
