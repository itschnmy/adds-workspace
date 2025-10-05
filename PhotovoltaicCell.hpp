#ifndef PHOTOVOLTAICCELL_H
#define PHOTOVOLTAICCELL_H
#include <cmath>
#include "Helper.hpp"
#include "CharacteristicPoints.hpp"
using namespace std;
//Recieve parameters then calculate and return the characteristic points of 
//the solar panel with the environment factors, irradiance and temperature, 
//being taken into account. The formulas are from equations 17-21 in
//A. Porras-Hermoso et al. (2022)

struct EnvironmentCoefficients {
    double a_Isc;
    double a_Voc;
    double a_Imp;
    double a_Vmp;
    double a;
};

struct NumSeries {
    int ns;
    int np;
};

class PhotovoltaicCell {
private:
    CharacteristicPoints points;
    EnvironmentCoefficients c;
    double T0; //(K)
    double G0; //(W/m^2)
public:
    PhotovoltaicCell(CharacteristicPoints& points, 
        double T0, double G0, EnvironmentCoefficients& c)
        : points(points), T0(T0), G0(G0), c(c) {}   

    CharacteristicPoints getPoints(double T, double G, NumSeries n) {
        //Calculate the characteristic points with T & G
        CharacteristicPoints p;
        double VT = Helper::ThermalVoltage(T);

        p.Isc = G/G0 * n.np * (points.Isc + c.a_Isc * (T-T0));
        p.Imp = G/G0 * n.np * (points.Imp + c.a_Imp * (T-T0));
        p.Vmp = n.ns * (points.Vmp + c.a_Vmp * (T-T0) + c.a * VT * log(G/G0));
        p.Voc = n.ns * (points.Voc + c.a_Voc * (T-T0) + c.a * VT * log(G/G0));

        return p;
    }
};

#endif