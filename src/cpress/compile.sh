#!/bin/bash
 
###########################################################
#
#
# 
#
#
###########################################################
 

echo "Starting compilation"
rm getcpress
#macro2
g++ mcpress.cpp cpress.cpp loadMesh/lmesh.cpp -o2 -o getcpress -std=c++20
#macro1

echo "done!"
 

