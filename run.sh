#!/usr/bin/bash
 
cd build 
cmake ..
make 
./flux ./test.gflx
