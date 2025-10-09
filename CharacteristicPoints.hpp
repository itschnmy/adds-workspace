#ifndef CHARACTERISTICPOINTS_H
#define CHARACTERISTICPOINTS_H
//Define characteristic points separately from the photovoltaic cell 
//file due to the code's structure purpose

struct CharacteristicPoints {
    double Isc;
    double Imp;
    double Vmp;
    double Voc;
};

#endif