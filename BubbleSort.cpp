#include <iostream>
#include "BubbleSort.h"
using namespace std;

vector<int> BubbleSort::sort(vector<int> list) {
    if (list.size() < 2) {
        return list;
    }
    for (int i = list.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (list.at(j) > list.at(j+1)) {
                int num = list.at(j+1);
                list.at(j+1) = list.at(j);
                list.at(j) = num;
            }
        }
    }
    return list;
}