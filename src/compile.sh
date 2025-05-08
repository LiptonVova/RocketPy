#!/bin/bash
 
###########################################################
#
#
# M9 sim setup
#
#
###########################################################
 
# compile m9 sim
echo "Starting compilation"
echo "Reminder: Make sure root is sourced"
#rm mtest2

rm rocketSIM1
#macro2
g++ rocketSIM.cpp simcalc/calc.cpp vroot/root.cpp cpress/cpress.cpp cpress/loadMesh/lmesh.cpp -o2 -o rocketSIM1 `root-config --cflags --glibs` -std=c++20 -pthread
#macro1

#g++ muon.cpp gPT/GPT.cpp mROOT/mroot.cpp -o2 -o mugo `root-config --cflags --glibs` -std=c++17 -pthread

echo "done!"
 

