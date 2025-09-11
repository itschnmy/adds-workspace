#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> list;
    int x;

    while (cin >> x) {
        list.push_back(x);
    }
    RecursiveBinarySearch searcher;
    BubbleSort sorter;
    bool result = searcher.search(list, 1);
    if (result) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    list = sorter.sort(list);
    for (int i = 0; i < list.size(); i++) {
        cout << list.at(i) << " ";
    }

    return 0;
}