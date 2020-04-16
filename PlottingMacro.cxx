#include <TFile.h>
#include <TCanvas.h>
#include <TH1.h>
#include <string.h>

/*
TH1F* getHist(TFile file, string histName){
  TH1F *hist = (TH1F*) file -> Get(histName);
  hist -> Scale(1./hist->Integral());
  return hist;
}
*/
  

void PlottingMacro() {
  // I tried to automate things to avoid all of the repetition, but it's too time-consuming
  // to troubleshoot at this point. Hopefully I'll figure it out for future assignments.

  /*
  char* filepaths[2] = {"./test3/hist-ZPrime750.root", "./test3/hist-ZPrime2500.root"};
  char* objects[4] = {"lep", "el", "mu", "jet"};
  char* kinematics[3] = {"pt", "eta", "phi"};
  TH1F* histograms[filepaths.size()][objects.size()*kinematics.size()];

  for(int i=0; i<filepaths.size(); i++){
    int l=0; // Index for inserting histograms
    TFile *file = TFile::Open(filepaths[i], "READ");
    for(int j=0; j<objects.size(); j++){
      for(int k=0; k<kinematics.size(); k++){
	histograms[i][l] = getHist(file, std::string::format("h_{}_{}", objects[j], kinematics[k]));
      }
    }
  }
  */
	
  
  TFile *f750 = TFile::Open("./final/hist-ZPrime750.root", "READ");
  
  TH1F *h_ZP750_lep_pt = (TH1F*) f750 -> Get("h_lep_pt");
  TH1F *h_ZP750_lep_eta = (TH1F*) f750 -> Get("h_lep_eta");
  TH1F *h_ZP750_lep_phi = (TH1F*) f750 -> Get("h_lep_phi");
  
  TH1F *h_ZP750_jet_pt = (TH1F*) f750 -> Get("h_jet_pt");
  TH1F *h_ZP750_jet_eta = (TH1F*) f750 -> Get("h_jet_eta");
  TH1F *h_ZP750_jet_phi = (TH1F*) f750 -> Get("h_jet_phi");

  TH1F *h_ZP750_el_pt = (TH1F*) f750 -> Get("h_el_pt");
  TH1F *h_ZP750_el_eta = (TH1F*) f750 -> Get("h_el_eta");
  TH1F *h_ZP750_el_phi = (TH1F*) f750 -> Get("h_el_phi");

  TH1F *h_ZP750_mu_pt = (TH1F*) f750 -> Get("h_mu_pt");
  TH1F *h_ZP750_mu_eta = (TH1F*) f750 -> Get("h_mu_eta");
  TH1F *h_ZP750_mu_phi = (TH1F*) f750 -> Get("h_mu_phi");

  TH1F *h_ZP750_met = (TH1F*) f750 -> Get("h_met");
  TH1F *h_ZP750_met_phi = (TH1F*) f750 -> Get("h_met_phi");


  
  TFile *f2500 = TFile::Open("./final/hist-ZPrime2500.root", "READ");
  
  TH1F *h_ZP2500_lep_pt = (TH1F*) f2500 -> Get("h_lep_pt");
  TH1F *h_ZP2500_lep_eta = (TH1F*) f2500 -> Get("h_lep_eta");
  TH1F *h_ZP2500_lep_phi = (TH1F*) f2500 -> Get("h_lep_phi");
  
  TH1F *h_ZP2500_jet_pt = (TH1F*) f2500 -> Get("h_jet_pt");
  TH1F *h_ZP2500_jet_eta = (TH1F*) f2500 -> Get("h_jet_eta");
  TH1F *h_ZP2500_jet_phi = (TH1F*) f2500 -> Get("h_jet_phi");

  TH1F *h_ZP2500_el_pt = (TH1F*) f2500 -> Get("h_el_pt");
  TH1F *h_ZP2500_el_eta = (TH1F*) f2500 -> Get("h_el_eta");
  TH1F *h_ZP2500_el_phi = (TH1F*) f2500 -> Get("h_el_phi");

  TH1F *h_ZP2500_mu_pt = (TH1F*) f2500 -> Get("h_mu_pt");
  TH1F *h_ZP2500_mu_eta = (TH1F*) f2500 -> Get("h_mu_eta");
  TH1F *h_ZP2500_mu_phi = (TH1F*) f2500 -> Get("h_mu_phi");

  TH1F *h_ZP2500_met = (TH1F*) f2500 -> Get("h_met");
  TH1F *h_ZP2500_met_phi = (TH1F*) f2500 -> Get("h_met_phi");

  

  TFile *fttbar = TFile::Open("./final/hist-ttbar_lep.root", "READ");

  TH1F *h_ttbar_lep_pt = (TH1F*) fttbar -> Get("h_lep_pt");
  TH1F *h_ttbar_lep_eta = (TH1F*) fttbar -> Get("h_lep_eta");
  TH1F *h_ttbar_lep_phi = (TH1F*) fttbar -> Get("h_lep_phi");
  
  TH1F *h_ttbar_jet_pt = (TH1F*) fttbar -> Get("h_jet_pt");
  TH1F *h_ttbar_jet_eta = (TH1F*) fttbar -> Get("h_jet_eta");
  TH1F *h_ttbar_jet_phi = (TH1F*) fttbar -> Get("h_jet_phi");

  TH1F *h_ttbar_el_pt = (TH1F*) fttbar -> Get("h_el_pt");
  TH1F *h_ttbar_el_eta = (TH1F*) fttbar -> Get("h_el_eta");
  TH1F *h_ttbar_el_phi = (TH1F*) fttbar -> Get("h_el_phi");

  TH1F *h_ttbar_mu_pt = (TH1F*) fttbar -> Get("h_mu_pt");
  TH1F *h_ttbar_mu_eta = (TH1F*) fttbar -> Get("h_mu_eta");
  TH1F *h_ttbar_mu_phi = (TH1F*) fttbar -> Get("h_mu_phi");

  TH1F *h_ttbar_met = (TH1F*) fttbar -> Get("h_met");
  TH1F *h_ttbar_met_phi = (TH1F*) fttbar -> Get("h_met_phi");


  h_ZP750_lep_eta -> Scale(1./h_ZP750_lep_eta->Integral());
  h_ZP750_lep_phi -> Scale(1./h_ZP750_lep_phi->Integral());
  h_ZP750_lep_pt -> Scale(1./h_ZP750_lep_pt->Integral());
  h_ZP750_jet_eta -> Scale(1./h_ZP750_jet_eta->Integral());
  h_ZP750_jet_phi -> Scale(1./h_ZP750_jet_phi->Integral());
  h_ZP750_jet_pt -> Scale(1./h_ZP750_jet_pt->Integral());
  h_ZP750_el_eta -> Scale(1./h_ZP750_el_eta->Integral());
  h_ZP750_el_phi -> Scale(1./h_ZP750_el_phi->Integral());
  h_ZP750_el_pt -> Scale(1./h_ZP750_el_pt->Integral());
  h_ZP750_mu_eta -> Scale(1./h_ZP750_mu_eta->Integral());
  h_ZP750_mu_phi -> Scale(1./h_ZP750_mu_phi->Integral());
  h_ZP750_mu_pt -> Scale(1./h_ZP750_mu_pt->Integral());
  h_ZP750_met -> Scale(1./h_ZP750_met->Integral());
  h_ZP750_met_phi -> Scale(1./h_ZP750_met_phi->Integral());

  
  h_ZP2500_lep_eta -> Scale(1./h_ZP2500_lep_eta->Integral());
  h_ZP2500_lep_phi -> Scale(1./h_ZP2500_lep_phi->Integral());
  h_ZP2500_lep_pt -> Scale(1./h_ZP2500_lep_pt->Integral());
  h_ZP2500_jet_eta -> Scale(1./h_ZP2500_jet_eta->Integral());
  h_ZP2500_jet_phi -> Scale(1./h_ZP2500_jet_phi->Integral());
  h_ZP2500_jet_pt -> Scale(1./h_ZP2500_jet_pt->Integral());
  h_ZP2500_el_eta -> Scale(1./h_ZP2500_el_eta->Integral());
  h_ZP2500_el_phi -> Scale(1./h_ZP2500_el_phi->Integral());
  h_ZP2500_el_pt -> Scale(1./h_ZP2500_el_pt->Integral());
  h_ZP2500_mu_eta -> Scale(1./h_ZP2500_mu_eta->Integral());
  h_ZP2500_mu_phi -> Scale(1./h_ZP2500_mu_phi->Integral());
  h_ZP2500_mu_pt -> Scale(1./h_ZP2500_mu_pt->Integral());
  h_ZP2500_met -> Scale(1./h_ZP2500_met->Integral());
  h_ZP2500_met_phi -> Scale(1./h_ZP2500_met_phi->Integral());
  

  h_ttbar_lep_eta -> Scale(1./h_ttbar_lep_eta->Integral());
  h_ttbar_lep_phi -> Scale(1./h_ttbar_lep_phi->Integral());
  h_ttbar_lep_pt -> Scale(1./h_ttbar_lep_pt->Integral());
  h_ttbar_jet_eta -> Scale(1./h_ttbar_jet_eta->Integral());
  h_ttbar_jet_phi -> Scale(1./h_ttbar_jet_phi->Integral());
  h_ttbar_jet_pt -> Scale(1./h_ttbar_jet_pt->Integral());
  h_ttbar_el_eta -> Scale(1./h_ttbar_el_eta->Integral());
  h_ttbar_el_phi -> Scale(1./h_ttbar_el_phi->Integral());
  h_ttbar_el_pt -> Scale(1./h_ttbar_el_pt->Integral());
  h_ttbar_mu_eta -> Scale(1./h_ttbar_mu_eta->Integral());
  h_ttbar_mu_phi -> Scale(1./h_ttbar_mu_phi->Integral());
  h_ttbar_mu_pt -> Scale(1./h_ttbar_mu_pt->Integral());
  h_ttbar_met -> Scale(1./h_ttbar_met->Integral());
  h_ttbar_met_phi -> Scale(1./h_ttbar_met_phi->Integral());

  
  h_ZP2500_lep_eta -> SetLineColor(kRed);
  h_ZP2500_lep_phi -> SetLineColor(kRed);
  h_ZP2500_lep_pt -> SetLineColor(kRed);
  h_ZP2500_jet_eta -> SetLineColor(kRed);
  h_ZP2500_jet_phi -> SetLineColor(kRed);
  h_ZP2500_jet_pt -> SetLineColor(kRed);
  h_ZP2500_el_eta -> SetLineColor(kRed);
  h_ZP2500_el_phi -> SetLineColor(kRed);
  h_ZP2500_el_pt -> SetLineColor(kRed);
  h_ZP2500_mu_eta -> SetLineColor(kRed);
  h_ZP2500_mu_phi -> SetLineColor(kRed);
  h_ZP2500_mu_pt -> SetLineColor(kRed);
  h_ZP2500_met -> SetLineColor(kRed);
  h_ZP2500_met_phi -> SetLineColor(kRed);
  
  
  h_ttbar_lep_eta -> SetLineColor(kGray);
  h_ttbar_lep_phi -> SetLineColor(kGray);
  h_ttbar_lep_pt -> SetLineColor(kGray);
  h_ttbar_jet_eta -> SetLineColor(kGray);
  h_ttbar_jet_phi -> SetLineColor(kGray);
  h_ttbar_jet_pt -> SetLineColor(kGray);
  h_ttbar_el_eta -> SetLineColor(kGray);
  h_ttbar_el_phi -> SetLineColor(kGray);
  h_ttbar_el_pt -> SetLineColor(kGray);
  h_ttbar_mu_eta -> SetLineColor(kGray);
  h_ttbar_mu_phi -> SetLineColor(kGray);
  h_ttbar_mu_pt -> SetLineColor(kGray);
  h_ttbar_met -> SetLineColor(kGray);
  h_ttbar_met_phi -> SetLineColor(kGray);

  


  TCanvas *c_lep_eta = new TCanvas("c_lep_eta", "", 600, 600);
  c_lep_eta -> cd();
  h_ZP750_lep_eta  -> Draw("hist");
  h_ZP2500_lep_eta -> Draw("histsame");
  h_ttbar_lep_eta -> Draw("histsame");
  c_lep_eta -> Print("output.pdf(");

  TCanvas *c_lep_phi = new TCanvas("c_lep_phi", "", 600, 600);
  c_lep_phi -> cd();
  h_ZP750_lep_phi  -> Draw("hist");
  h_ZP2500_lep_phi -> Draw("histsame");
  h_ttbar_lep_phi -> Draw("histsame");
  c_lep_phi -> Print("output.pdf");

  TCanvas *c_lep_pt = new TCanvas("c_lep_pt", "", 600, 600);
  c_lep_pt -> cd();
  h_ZP750_lep_pt  -> Draw("hist");
  h_ZP2500_lep_pt -> Draw("histsame");
  h_ttbar_lep_pt -> Draw("histsame");
  c_lep_pt -> Print("output.pdf");

  TCanvas *c_jet_eta = new TCanvas("c_jet_eta", "", 600, 600);
  c_jet_eta -> cd();
  h_ZP750_jet_eta  -> Draw("hist");
  h_ZP2500_jet_eta -> Draw("histsame");
  h_ttbar_jet_eta -> Draw("histsame");
  c_jet_eta -> Print("output.pdf");
  
  TCanvas *c_jet_phi = new TCanvas("c_jet_phi", "", 600, 600);
  c_jet_phi -> cd();
  h_ZP750_jet_phi  -> Draw("hist");
  h_ZP2500_jet_phi -> Draw("histsame");
  h_ttbar_jet_phi -> Draw("histsame");
  c_jet_phi -> Print("output.pdf");
  
  TCanvas *c_jet_pt = new TCanvas("c_jet_pt", "", 600, 600);
  c_jet_pt -> cd();
  h_ZP750_jet_pt  -> Draw("hist");
  h_ZP2500_jet_pt -> Draw("histsame");
  h_ttbar_jet_pt -> Draw("histsame");
  c_jet_pt -> Print("output.pdf");
  
  TCanvas *c_el_eta = new TCanvas("c_el_eta", "", 600, 600);
  c_el_eta -> cd();
  h_ZP750_el_eta  -> Draw("hist");
  h_ZP2500_el_eta -> Draw("histsame");
  h_ttbar_el_eta -> Draw("histsame");
  c_el_eta -> Print("output.pdf");
  
  TCanvas *c_el_phi = new TCanvas("c_el_phi", "", 600, 600);
  c_el_phi -> cd();
  h_ZP750_el_phi  -> Draw("hist");
  h_ZP2500_el_phi -> Draw("histsame");
  h_ttbar_el_phi -> Draw("histsame");
  c_el_phi -> Print("output.pdf");
  
  TCanvas *c_el_pt = new TCanvas("c_el_pt", "", 600, 600);
  c_el_pt -> cd();
  h_ZP750_el_pt  -> Draw("hist");
  h_ZP2500_el_pt -> Draw("histsame");
  h_ttbar_el_pt -> Draw("histsame");
  c_el_pt -> Print("output.pdf");
  
  TCanvas *c_mu_eta = new TCanvas("c_mu_eta", "", 600, 600);
  c_mu_eta -> cd();
  h_ZP750_mu_eta  -> Draw("hist");
  h_ZP2500_mu_eta -> Draw("histsame");
  h_ttbar_mu_eta -> Draw("histsame");
  c_mu_eta -> Print("output.pdf");
  
  TCanvas *c_mu_phi = new TCanvas("c_mu_phi", "", 600, 600);
  c_mu_phi -> cd();
  h_ZP750_mu_phi  -> Draw("hist");
  h_ZP2500_mu_phi -> Draw("histsame");
  h_ttbar_mu_phi -> Draw("histsame");
  c_mu_phi -> Print("output.pdf");
  
  TCanvas *c_mu_pt = new TCanvas("c_mu_pt", "", 600, 600);
  c_mu_pt -> cd();
  h_ZP750_mu_pt  -> Draw("hist");
  h_ZP2500_mu_pt -> Draw("histsame");
  h_ttbar_mu_pt -> Draw("histsame");
  c_mu_pt -> Print("output.pdf");  

  TCanvas *c_met = new TCanvas("c_met", "", 600, 600);
  c_met -> cd();
  h_ZP750_met  -> Draw("hist");
  h_ZP2500_met -> Draw("histsame");
  h_ttbar_met -> Draw("histsame");
  c_met -> Print("output.pdf");  
  c_met -> cd();
  
  TCanvas *c_met_phi = new TCanvas("c_met_phi", "", 600, 600);
  c_met_phi -> cd();
  h_ZP750_met_phi  -> Draw("hist");
  h_ZP2500_met_phi -> Draw("histsame");
  h_ttbar_met_phi -> Draw("histsame");
  c_met_phi -> Print("output.pdf)");  

  
}
