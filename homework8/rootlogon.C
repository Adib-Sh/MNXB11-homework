#include <TSystem.h>
#include <TString.h>
#include <TList.h>
#include <TObjArray.h>
#include <TObjString.h>

void rootlogon() {
    printf("Macro starts...\n");
    gROOT->ProcessLine(".L momentum.cxx+");
    printf("main function is loaded successfully.\n");
    gROOT->ProcessLine(".L write.cxx+");
    gROOT->ProcessLine("writeMomentum()");
    printf("TTree is created.\n");
    gROOT->ProcessLine(".L read.cxx+");
    gROOT->ProcessLine("readMomentum()");
    
    gROOT->ProcessLine("readMomentumZ()");

    printf("Execution of macro is completed.\n");

}