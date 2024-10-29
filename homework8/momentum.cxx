#include "momentum.h"
#include <cmath>


ClassImp(momentum)

// Default Constructor
momentum::momentum() : feventID(0), fpx(0), fpy(0), fpz(0) {}

// Constructor
momentum::momentum(Int_t eventID, Double_t px, Double_t py, Double_t pz)
    : feventID(eventID), fpx(px), fpy(py), fpz(pz) {GetMagnitude();};

// Destructor
momentum::~momentum() {}


Double_t momentum::GetMagnitude() const {
    return std::sqrt(fpx * fpx + fpy * fpy + fpz * fpz);
}