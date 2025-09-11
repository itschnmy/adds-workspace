#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "Sort.h"

class QuickSort : public Sort {
private:
    std::vector<int> sortHelper(std::vector<int> list, int start, int end);
public:
    std::vector<int> sort(std::vector<int> list) override;
};

#endif