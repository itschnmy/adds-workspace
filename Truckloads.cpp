#include "Truckloads.h"
#include <iostream>
using namespace std;

int Truckloads::numTrucks(int numCrates, int loadSize) {
    if (numCrates < 2 || numCrates > 10000) {
        cerr << "ERROR!";
    }

    if (loadSize < 1) {
        cerr << "ERROR!";
    }

    if (numCrates <= loadSize) {
        return 1;
    } else {
        int right = numCrates/2;
        int left = numCrates - right;
        return numTrucks(right, loadSize) + numTrucks(left, loadSize);
    }
}