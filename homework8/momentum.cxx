#include "momentum.h"
#include <cmath>


ClassImp(momentum)

// Default Constructor
momentum::momentum() : eventID(0), px(0), py(0), pz(0), magnitude(0) {}

// Constructor
momentum::momentum(Int_t eventID, Double_t px, Double_t py, Double_t pz, Double_t magnitude)
    : eventID(eventID), px(px), py(py), pz(pz), magnitude(magnitude) {};

// Destructor
momentum::~momentum() {}
