#include <iostream>
#include <Eigen/Dense>
#include "Helper.hpp"
#include "PhotovoltaicCell.hpp"
#include "PindadoCubasModel.hpp"
#include "SunVector.hpp"
#include "TRIAD.hpp"

int main() {
    using namespace std;
    cout << "=== CubeSat Attitude Determination Test ===\n";

    // Step 1: Define nominal characteristic points (STC)
    CharacteristicPoints cellNominal;
    cellNominal.Isc = 0.6;
    cellNominal.Imp = 0.55;
    cellNominal.Vmp = 2.5;
    cellNominal.Voc = 3.0;

    // Step 2: Define environment coefficients
    EnvironmentCoefficients coeff;
    coeff.a_Isc = 0.0003;
    coeff.a_Imp = 0.0002;
    coeff.a_Vmp = -0.0020;
    coeff.a_Voc = -0.0023;
    coeff.a = 1.2; // ideality factor

    // Step 3: Define PV topology (cells in series/parallel)
    NumSeries num;
    num.ns = 10;
    num.np = 2;

    // Step 4: Instantiate photovoltaic cell
    PhotovoltaicCell pv(cellNominal, 298.15, 1000.0, coeff);

    // Step 5: Compute adjusted characteristic points for current environment
    double T = 303.15; // K
    double G = 900.0;  // W/m2
    CharacteristicPoints adj = pv.getPoints(T, G, num);

    // Step 6: Compute h (shape factor) for Pindado–Cubas model
    double h = Helper::eta(adj);
    PindadoCubasModel model(h);

    // Step 7: Compute I(Vmp)
    double I_Vmp = model.current(adj.Vmp, adj);
    cout << "Estimated current at Vmp: " << I_Vmp << " A" << endl;

    // Step 8: Build sample measured and max currents for 6 panels
    array<double,6> I_measured = {0.85, 0.2, 0.4, 0.1, 0.1, 0.3};
    array<double,6> I_max      = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0};

    // Step 9: Estimate Sun vector from panel currents
    SunVector sunSensor;
    Eigen::Vector3d Sun_body = sunSensor.estimateSunVector(I_measured, I_max);
    cout << "Sun vector (body frame): " << Sun_body.transpose() << endl;

    // Step 10: Define magnetic field + reference Sun vectors (example)
    Eigen::Vector3d B_body(0.2, 0.8, 0.5);
    B_body.normalize();
    Eigen::Vector3d Sun_ref(0.5, 0.3, 0.8);
    Sun_ref.normalize();
    Eigen::Vector3d B_ref(-0.2, 0.9, 0.3);
    B_ref.normalize();

    // Step 11: TRIAD attitude estimation
    Eigen::Matrix3d R = TRIAD::attitude(Sun_body, B_body, Sun_ref, B_ref);

    cout << "Estimated rotation matrix (ECI -> Body):\n" << R << endl;

    // Step 12: Check orthonormality
    cout << "R * R^T = \n" << R * R.transpose() << endl;

    return 0;
}