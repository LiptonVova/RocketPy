#ifndef lmesh_INCLUDED
#define lmesh_INCLUDED
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



#include <cstring>




using namespace std;

//quaternion stuff
struct quaternion
{
  float x, y, z, w;
};




//ijk vector
struct tvec
{
  float i, j, k;
};

//3 vertices and 1 facet
struct stri
{
tvec vert1;
tvec vert2;
tvec vert3;
tvec facet;
float area;
float aproj;
};

//vector of vertices and facets
struct striset
{
vector< stri> mesh;

float i_limH;
float i_limL;
float j_limH;
float j_limL;
float k_limH;
float k_limL;

};


void print_triangle(stri temp, int i);

//project loader
void load_mesh(striset & imesh, string cadfile);

//bool cadpath(vector< vector <vector <double> > > Gpaths);
float get_tri_area(tvec v1, tvec v2, tvec v3);

//Generated points between reflected points for animation purposes
void Tanimate(vector< vector <vector <double> > > & AFpath);

//math functions
void cyltocart(double & r, double & theta, double & z);
vector<double> normalize(vector<double> v1);

#endif
