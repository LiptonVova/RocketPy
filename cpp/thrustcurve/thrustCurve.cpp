//used to generate nessary parameters for equation modelling thrust levels
//not used during actual sim, run individually the make engine file with new params




#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <TLatex.h>
#include <TImage.h>
#include "TF1.h"
#include "TH2F.h"
#include <TRandom3.h>
#include <TAxis.h>
#include <TH1F.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <cstdlib>
#include <TPad.h>
#include <TFrame.h>
#include <cmath>
#include <TGraph2D.h>
#include <TGraph.h>
#include "TROOT.h"
#include "TSystem.h"
#include "TMath.h"
#include "TFile.h"
#include "TPaveStats.h"
#include <TLegend.h>
#include <TLatex.h>
#include "TAxis.h"
#include "TArrayD.h"

using namespace std;



int read()
{

//rise fall with long fall
float pp0 = 0.035;//rise time
float pp1 = 5;
float pp2 = 1200;//height of lowlevel platue
float pp3 = 0.075;//center

//guassian
float pp4 = 300;//height
float pp5 =0.075;//width
float pp6 = 0.25;//center

TCanvas *c1 = new TCanvas("c1","The FillRandom example",200,50,900,700);

//*******************************************************************************
vector<float> xs;
vector<float> ys;
float x = 0;
float y = 0;

TGraph *gr1 = new TGraph();
for (int i = 0; i < 300; ++i)
{
x = i*0.01;
xs.push_back(x);

y = (pp4*exp(-0.5*pow((x-pp6)/pp5,2)))+(((x-pp3)>0)*(-(pp2)*(exp(-(x-pp3)/pp0)-exp(-(x-pp3)/pp1))));
ys.push_back(y);
gr1->SetPoint(i,x,y);
}


gr1->Draw();


return 0;
}


