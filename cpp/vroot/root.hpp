#ifndef ROOT_INCLUDED
#define ROOT_INCLUDED

#include "TF1.h"
#include <TAxis.h>
#include <TH1F.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph2D.h>
#include <TGraph.h>
#include "TF1.h"
#include "TH2F.h"
#include "TROOT.h"
#include "TSystem.h"
#include "TFile.h"
#include "TApplication.h"
#include <TLatex.h>
#include <TImage.h>
#include <TRandom3.h>
#include <TMultiGraph.h>
#include <TLegend.h>
#include <TPad.h>
#include <TFrame.h>
#include "TH3.h"
#include "TNtuple.h"

#include <TRandom3.h>
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
#include "/home/vova_rybin/RocketPy/cpp/simcalc/calc.hpp"

using namespace std;

void draw_graph(fvec dfinal, int index1, int index2);

#endif
