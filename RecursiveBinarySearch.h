#ifndef RECURSIVEBINARYSEARCH_H
#define RECURSIVEBINARYSEARCH_H
#include <vector>
#include "QuickSort.h"

class RecursiveBinarySearch {
private:
    QuickSort sorter;
    bool searchHelper(std::vector<int> list, int num);
public:
    bool search(std::vector<int> list, int num);
};

#endif