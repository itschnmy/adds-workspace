#include <iostream>
#include "QuickSort.h"
using namespace std;

vector<int> QuickSort::sort(vector<int> list) {
    int start = 0;
    int end = list.size() - 1;
    list = sortHelper(list, start, end);
    return list;
}

vector<int> QuickSort::sortHelper(vector<int> list, int start, int end) {
    if (start >= end) {
        return list;
    }

    int length = end - start + 1;

    int pivot_index;
    if (length >= 3) {
        pivot_index = start + 2;
    } else {
        pivot_index = start + (length - 1) / 2; 
    }

    int pivot_value = list.at(pivot_index);
    int tmp = list.at(end);
    list.at(end) = pivot_value;
    list.at(pivot_index) = tmp;

    int store_index = start;
    for (int i = start; i < end; i++) {
        if (list.at(i) <= pivot_value) {
            int temp = list.at(i);
            list.at(i) = list.at(store_index);
            list.at(store_index) = temp;
            store_index++;
        }
    }

    int temp2 = list.at(store_index);
    list.at(store_index) = list.at(end);
    list.at(end) = temp2;

    list = sortHelper(list, start, store_index - 1);
    list = sortHelper(list, store_index + 1, end);

    return list;
}