#ifndef cpress_INCLUDED
#define cpress_INCLUDED
//g++ macro.cpp GPT.cpp mroot.cpp -Wall -o2 -o test1 `root-config --cflags --glibs` -std=c++0x -pthread



#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <math.h> 
#include <thread>
#include <stdio.h>
#include <iterator>
#include <sys/stat.h>
#include <unistd.h>
#include "loadMesh/lmesh.hpp"
#include <math.h> 




using namespace std;


void set_limits(striset & imesh);

void set_area(striset & imesh);

void set_aproj(striset & imesh, tvec forvec, float mag);

float get_angle(tvec force, tvec normal);

float dotprod(tvec v1, tvec v2);


float find_centerx(striset imesh, float steps);
float find_centery(striset imesh, float steps);
float find_centerz(striset imesh, float steps);

float get_cpress();














#endif
