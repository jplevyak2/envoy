#!/bin/bash
cmake -DWAVME_ENABLE_STGATIC_LINKING=OFF .
make -j8
sudo make install
cmake -DWAVM_ENABLE_STATIC_LINKING=ON ...
make -j8
sudo make install
