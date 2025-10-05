#ifndef HELPER_H
#define HELPER_H
#include "CharacteristicPoints.hpp"
#include <cmath>
#include <array>
using namespace std;
//Contain utility functions to calculate small math

class Helper {
public:
    static double ThermalVoltage(double T) {
        //Calculate the thermal voltage for a given temp T
        const double k = 1.380649e-23; //(J/K)
        const double q  = 1.602176634e-19; //(C)
        return (k*T)/q; //(V)
    }
    
    static double eta(CharacteristicPoints& p) {
        //Calculate eta for Pindado-Cubas Model
        double h = p.Isc/p.Imp * p.Isc/(p.Isc-p.Imp) * (p.Voc-p.Vmp)/p.Voc;
        if (h < 1.0) h = 1.0;
        return h;
    }

    static double compareOppositePanels(int posIndex, int negIndex, array<double,6>& I_measured, array<double,6>& I_max) {
        //Compare the produced current on 2 opposite panels to set the direction
        //As the higher current sets the direction (pg. 6, A. Porras-Hermoso et al. (2022))
        double IPos = I_measured[posIndex]/I_max[posIndex];
        double INeg = I_measured[negIndex]/I_max[negIndex];
        if (IPos >= INeg) return IPos;
        else return -INeg;
    }
};

#endif