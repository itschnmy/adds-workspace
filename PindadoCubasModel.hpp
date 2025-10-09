#ifndef PINDADOCUBASMODEL_H
#define PINDADOCUBASMODEL_H
#include <cmath>
#include "PhotovoltaicCell.hpp"
using namespace std;
//Calculate the current I via the Pindado-Cubas Model, which is the
//equation 24 in  S.Pindado, J.Cubas/RenewableEnergy103(2017)729e738.
//The value of eta is estimated by the Deihimi estimation, 
//which also can be found in the same paper (eq. 23)

class PindadoCubasModel {
private:
    double h;
public:
    PindadoCubasModel(double h) : h(h) {}

    void setEta(double eta) {
        h = eta;
    }

    double getEta() {
        return h;
    }

    double current(double V, CharacteristicPoints& p) {
        if (V <= 0) return p.Isc;
        else if (V <= p.Vmp) {
            return p.Isc * (1 - (1 - p.Imp/p.Isc) * pow(V/p.Vmp, p.Imp/(p.Isc - p.Imp)));
        } else {
            return p.Imp * p.Vmp/V * (1 - pow((V-p.Vmp)/(p.Voc-p.Vmp),h));
        }
    }

};

#endif