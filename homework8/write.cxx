#include <iostream>
#include <TRandom.h>
#include <TTree.h>
#include <TFile.h>
#include <TF1.h>
#include "momentum.h"

void writeMomentum() {
    
    // Number of events
    const Int_t nEvent = 1000;

    // Initialize your object e.g. as a pointer
    momentum *event = nullptr;

    // Create your root file here    
    TFile f("tree_file.root", "RECREATE");

    // Create your TTree here
    TTree *tree = new TTree("tree", "momentum tree");

    // And the associated branches underneath
    tree->Branch("event", &event);

    // Now we create our loop for filling the tree with some random data
    Double_t px, py, pz, magnitude;
    Int_t eventID;

    // For loop here
    for (Int_t i{0}; i < nEvent; i++) {
        // Initialize your new object below
        eventID = i;
        px = gRandom->Gaus(0, 0.02);
        py = gRandom->Gaus(0, 0.02);
        pz = gRandom->Gaus(0, 0.02);
        magnitude = std::sqrt(px * px + py * py + pz * pz);

        // Now fill tree
        event = new momentum(eventID, px, py, pz, magnitude);
        tree->Fill();
        // Remember to delete it again otherise you will have memory leak!
        delete event;
    }
    // save the tree/file
    tree->Write();
    tree->AutoSave();
    f.Close();
}