#ifndef MOMENTUM_H
#define MOMENTUM_H

#include <TObject.h>

class momentum : public TObject {
public:
    // Fill up default constructor
    momentum();
    // Constructor
    momentum(Int_t eventID, double px, double py, double pz);
    // Destructor
    virtual ~momentum(); 

    Double_t GetPx() const { return fpx; }
    Double_t GetPy() const { return fpy; }
    Double_t GetPz() const { return fpz; }
    Double_t GetEvent() const { return feventID; }
    

private:
    Int_t feventID;
    Double_t fpx;
    Double_t fpy;
    Double_t fpz;
    Double_t GetMagnitude() const; 

    ClassDef(momentum, 1);
};

#endif 
