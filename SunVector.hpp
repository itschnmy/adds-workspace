#ifndef SUNVECTOR_H
#define SUNVECTOR_H
#include <Eigen/Dense>
#include <cmath>
#include <array>
#include "Helper.hpp"
using namespace std;
//Determine the sun vector based on equation 29.
//The angles are not calculated as equation 27.
//Instead, the ratio I/Imax derived from that equation 
//was used to determine which panel on each axis has 
//higher produced current. The explicit function for this feature
//was written in Helper.hpp 

class SunVector {
private:
    array<double,6> I_measured;
    array<double,6> I_max;
public:
    SunVector() {
        I_measured.fill(0.0);
        I_max.fill(1.0);
    }

    void setI_measured(array<double,6>& values) {
        I_measured = values;
    }

    void setI_max(array<double,6>& max) {
        I_max = max;
    }

    Eigen::Vector3d estimateSunVector(array<double,6> I_measured, array<double,6> I_max) {
        //determine the vector
        double Sx = Helper::compareOppositePanels(0, 3, I_measured, I_max); //0 & 3 are indices of X & -X in the array
        double Sy = Helper::compareOppositePanels(1, 4, I_measured, I_max); //Similarly
        double Sz = Helper::compareOppositePanels(2, 5, I_measured, I_max);
        Eigen::Vector3d S(Sx, Sy, Sz);
        return S.normalized();
    }

};

#endif