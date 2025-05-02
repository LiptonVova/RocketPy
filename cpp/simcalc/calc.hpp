#ifndef calc_INCLUDED
#define calc_INCLUDED
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
#include "/home/vova_rybin/RocketPy/cpp/cpress/cpress.hpp"



using namespace std;

//used for converting string to const char
template <typename T> string tostr(const T& t) { 
   ostringstream os; 
   os<<t; 
   return os.str();
}

//basic 2d vector
struct vec
{
 float x, y;
};


//various characteristics of rocket at any given point in time
//position vector; velocity vector; sum force vector; and scalor mass
struct prock
{
vec d;
vec v;
vec Ft;
float m;
};


//an object holding all the forces considered on the rocket
struct frock
{
vec fd;
vec fw;
vec ft;
vec fg;
};

//data arrays/vectors holds all displament and velocity data
struct fvec
{vector<vec> v;
 vector<vec> d;
};


//sets some intial values for velocity mass and displacmnent
void initialize(prock & rp, frock & rf, string filename);

//calculates and sums all forces considered
void calc_forces(prock & rp, frock & rf, float tstep);

//calculates based on forces kinematics of rocket
void calc_kinematics(prock & rp, float tstep);

//log data
void log_data(prock rp, fvec & dfinal);

//setters
void set_thrust(float temp);
void set_stmass(float temp);
void set_dragCd(float temp);
void set_Xarea(float temp);
void set_wind(float temp);

//import thrust curve
void use_thrustCurve(string filename);

float get_btime();
float mag(vec v1);

//deploy chute, reverses and changes value of drag coefficient
void deploy_Chute();




#endif
