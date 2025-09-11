#include <iostream>
#include "RecursiveBinarySearch.h"
using namespace std;

bool RecursiveBinarySearch::searchHelper(vector<int> list, int num) {
    if (list.empty()) {
        return false;
    }
    int mid = list.at(list.size()/2);
    if (num == mid) {
        return true;
    }

    if (num > mid) {
        vector<int> new_list;
        for (int i = list.size()/2 + 1; i < list.size(); i++) {
            new_list.push_back(list.at(i));
        }
        return searchHelper(new_list, num);
    }

    if (num < mid) {
        vector<int> new_list;
        for (int i = 0; i < list.size()/2; i++) {
            new_list.push_back(list.at(i));
        }
        return searchHelper(new_list, num);
    }

    return false;
}

bool RecursiveBinarySearch::search(vector<int> list, int num) {
    list = sorter.sort(list);
    return searchHelper(list, num);
}