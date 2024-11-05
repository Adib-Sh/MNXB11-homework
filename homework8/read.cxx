#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TH2.h>
#include <TCanvas.h>
#include "TPad.h"
#include <TStyle.h>
#include "momentum.h"


void readMomentum() {
    // initialize your object
    momentum *event = nullptr;

    // open your file
    TFile *file = new TFile("tree_file.root", "READ");

    // get your tree
    TTree *tree = (TTree*)file->Get("tree");

    // remember to set the branch address 
    tree->SetBranchAddress("event", &event);

    // plotting px:py
    TH2F *h2 = new TH2F("h2", "Momentum px,py", 100, -0.10, 0.10, 100, -0.10, 0.10);
    Int_t N = tree->GetEntries();

    for (Int_t i = 0; i < N; i++) {
        tree->GetEntry(i);
        h2->Fill(event->GetPx(), event->GetPy());
    }

    TCanvas *c1 = new TCanvas("c1", "Momentum px vs py", 800, 600);
    h2->Draw("COLZ"); 
    c1->SaveAs("px_py_momentum.png"); // Save

    //Cleanup
    delete h2;
    delete c1;
    delete event;
    delete tree;
    file->Close();

}

void readMomentumZ() {
    // open your file
    TFile *file = new TFile("tree_file.root", "READ");

    // get your tree
    TTree *tree = (TTree*)file->Get("tree");

    

    // Scatter plot of px * py vs pz with the condition magnitude <10
    TCanvas *c1 = new TCanvas("c1", "Scatter px*py vs pz", 800, 600);
    gStyle->SetMarkerStyle(20);  
    gStyle->SetMarkerColor(kBlue);
    gStyle->SetMarkerSize(1.5);
    tree->Draw("px*py:pz", "magnitude < 10", "SCATTER");
    c1->SetGrid();
    c1->Update(); 
    c1->cd(0);
    c1->SaveAs("px*py_vs_pz.png"); // Save

    // Cleanup
    delete c1;
    delete tree;
    file->Close();
    delete file;
}