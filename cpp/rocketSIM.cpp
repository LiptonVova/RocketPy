#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <math.h> 
#include "TApplication.h"
#include "simcalc/calc.hpp"
#include "vroot/root.hpp"
#include <thread>

//g++ rocketSIM.cpp calc.cpp -Wall -o2 -o test1 `root-config --cflags --glibs` -std=c++0x -pthread

using namespace std;



int main(int argc, char **argv)
{

//get_cpress(); 
 
fvec dfinal;
prock rp1;
frock rf1;
float tstep = 0.01;
float btime;
float delay = 7.0;


//initialize
initialize(rp1, rf1,"spec/Frenzy_J.txt");
use_thrustCurve("spec/L935.txt");
btime = get_btime();
int ind = 0;





//--------------thrust----------------//
for(int i = 0; i < (btime/tstep); ++i)
{
calc_forces(rp1, rf1, (ind*tstep));
calc_kinematics(rp1, tstep);
log_data(rp1, dfinal);
++ind;

}
int index1 = ind;




//----------------delay----------------//
set_thrust(0.0);
set_stmass(0.0);

for(int i = 0; i < (delay/tstep); ++i)
{
calc_forces(rp1, rf1, 0);
calc_kinematics(rp1, tstep);
log_data(rp1, dfinal);
++ind;
}
int index2 = ind;




//---------recovery---------------------//

deploy_Chute();

while(rp1.d.y > 0)
{
calc_forces(rp1, rf1, 0);
calc_kinematics(rp1, tstep);
log_data(rp1, dfinal);
}


printf("\n\ndata size dfinal: %ld\nDrawing Data...ctrl-c to quit\n", dfinal.v.size());

if(dfinal.v.size() > 0)
{
	TApplication theApp("App", &argc, argv);
	draw_graph(dfinal, index1, index2);
	theApp.Run();
}



//end
}
