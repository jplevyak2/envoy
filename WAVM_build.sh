#!/bin/bash
cmake -D WAVM_ENABLE_STATIC_LINKING=NO .
make clean
make -j8
sudo make install
cmake -D WAVM_ENABLE_STATIC_LINKING=YES .
make clean
make -j8
sudo make install
