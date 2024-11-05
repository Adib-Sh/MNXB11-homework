#ifndef MOMENTUM_H
#define MOMENTUM_H

#include <TObject.h>

class momentum : public TObject {
public:
    // Fill up default constructor
    momentum();
    // Constructor
    momentum(Int_t eventID, Double_t px, Double_t py, Double_t pz, Double_t magnitude);
    // Destructor
    ~momentum(); 

    Double_t GetPx() const {return px;}
    Double_t GetPy() const {return py;}
    Double_t GetPz() const {return pz;}
    Double_t GetEvent() const {return eventID;}
    Double_t GetMagnitude() const {return magnitude;}
    

private:
    Int_t eventID;
    Double_t px ,py ,pz, magnitude;


    ClassDef(momentum, 1);
};

#endif 
