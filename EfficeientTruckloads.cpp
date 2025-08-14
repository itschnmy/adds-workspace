#include "EfficientTruckloads.h"
#include <iostream>
using namespace std;

EfficientTruckloads::EfficientTruckloads() {
    memo.assign(11, std::vector<int>(11, -1));
}

int EfficientTruckloads::numTrucks(int numCrates, int loadSize) {
    if (numCrates < 2 || numCrates > 10000) {
        cerr << "ERROR!";
        return -1;
    }

    if (loadSize < 1) {
        cerr << "ERROR!";
        return -1;
    }

    if (memo[numCrates][loadSize] != -1) {
        return memo[numCrates][loadSize];
    }

    if (numCrates <= loadSize) {
        return 1;
    } else {
        int right = numCrates/2;
        int left = numCrates - right;
        memo[numCrates][loadSize] = numTrucks(right, loadSize) + numTrucks(left, loadSize);
        return memo[numCrates][loadSize];
    }
}

