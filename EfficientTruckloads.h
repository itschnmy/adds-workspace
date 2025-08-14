#ifndef EFFICIENTTRUCKLOADS_H
#define EFFICIENTTRUCKLOADS_H
#include <vector>

class EfficientTruckloads {
private:
    std::vector<std::vector<int>> memo;
public:
    EfficientTruckloads();
    int numTrucks(int numCrates, int loadSize);
};

#endif