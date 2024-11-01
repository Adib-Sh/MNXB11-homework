#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TH2.h>
#include <TCanvas.h>
#include "TPad.h"
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


    // plotting px*py:pz 
    TCanvas *c2 = new TCanvas("c2", "Scatter px*py vs pz", 800, 600);
    tree->Draw("px*py:pz", "colz");
    gPad->Modified(); gPad->Update();
    c2->cd(0);
    c2->SaveAs("px*py_vs_pz.png"); // Save scatter plot as an image
}