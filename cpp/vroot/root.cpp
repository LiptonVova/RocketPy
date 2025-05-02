#include "root.hpp"

using namespace std;


void draw_graph(fvec dfinal, int index1, int index2)
{


 TCanvas *c1 = new TCanvas("c1","The FillRandom example",200,50,900,700);
TCanvas *c2 = new TCanvas("c2","The FillRandom example",200,50,900,700);

c1->cd();
string titlefile = "Payloader D12-7 Rocket Trajectory; Displacement (m); Altitude (m)";
const char* c; 
c = titlefile.c_str();	
TGraph *gr = new TGraph();
gr->SetTitle(c);
TGraph *gr1 = new TGraph();
	gr1->SetMarkerColor(4);
	gr1->SetMarkerStyle(7);
	gr1->SetTitle(c);
TGraph *gr12 = new TGraph();
	gr12->SetMarkerColor(3);
	gr12->SetMarkerStyle(7);
	gr12->SetTitle(c);
TGraph *gr13 = new TGraph();
	gr13->SetMarkerColor(5);
	gr13->SetMarkerStyle(7);
	gr13->SetTitle(c);
titlefile = "Payloader D12-7 Rocket Velocity; Time (s); Velocity (m/s)";
c = titlefile.c_str();
TGraph *gr2 = new TGraph();
	gr2->SetMarkerColor(3);
	gr2->SetMarkerStyle(7);
	gr2->SetTitle(c);

TGraph *gr3 = new TGraph();
	gr3->SetMarkerColor(4);
	gr3->SetMarkerStyle(7);
	gr3->SetTitle(c);
TGraph *gr4 = new TGraph();
	gr4->SetMarkerColor(5);
	gr4->SetMarkerStyle(7);
	gr4->SetTitle(c);
float x, y;

if(index1 > 0)
for (int i = 0; i < index1; ++i)
	{vec temp;	
	temp = dfinal.d.at(i);
	x = temp.x;
	y = temp.y;
	gr1->SetPoint(i,x,y);
		
			
	}

if(index2 > 0)
for (int i = index1; i < index2; ++i)
	{vec temp;	
	temp = dfinal.d.at(i);
	x = temp.x;
	y = temp.y;
	gr12->SetPoint(i,x,y);
		
			
	}


for (int i = index2; i < dfinal.d.size(); ++i)
	{vec temp;	
	temp = dfinal.d.at(i);
	x = temp.x;
	y = temp.y;
	gr13->SetPoint(i,x,y);
		
			
	}
for (int i = 0; i < dfinal.d.size(); ++i)
	{vec temp;	
	temp = dfinal.d.at(i);
	x = temp.x;
	y = temp.y;
	gr->SetPoint(i,x,y);
		
			
	}

gr->Draw();
gr1->Draw("sameP");
gr12->Draw("sameP");
gr13->Draw("sameP");

gr1->GetXaxis()->SetRangeUser(-200,200);
gr1->GetYaxis()->SetRangeUser(0,1000);
gr12->GetXaxis()->SetRangeUser(-200,200);
gr12->GetYaxis()->SetRangeUser(0,1000);
gr13->GetXaxis()->SetRangeUser(-200,200);
gr13->GetYaxis()->SetRangeUser(0,1000);

TLegend *leg = new TLegend(0.1,0.9,0.25,0.8);

leg->AddEntry(gr1,"Thrust","AP");
leg->AddEntry(gr12,"Delay","AP");
leg->AddEntry(gr13,"Recovery","AP");
//leg->AddEntry(fitb,"this one","l");
leg->Draw();




c2->cd();
for (int i = 0; i < dfinal.v.size(); ++i)
	{vec temp;	
	temp = dfinal.v.at(i);
	x = temp.x;
	y = temp.y;
	gr3->SetPoint(i,i*0.01,x);
	gr4->SetPoint(i,i*0.01,y);
	y = mag(temp);
	x = i*0.01;
	gr2->SetPoint(i,x,y);
			
	}


gr2->Draw("AP");
gr3->Draw("sameP");
gr4->Draw("sameP");

TLegend *leg1 = new TLegend(0.75,0.9,0.9,0.8);

leg1->AddEntry(gr2,"Velocity","AP");
leg1->AddEntry(gr3,"X-Velocity","AP");
leg1->AddEntry(gr4,"Y-Velocity","AP");
//leg->AddEntry(fitb,"this one","l");
leg1->Draw();

}
