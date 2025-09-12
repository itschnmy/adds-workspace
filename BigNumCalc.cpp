#include "BigNumCalc.h"
#include <vector>
using namespace std;

list<int> BigNumCalc::buildBigNum(string numString) {
    list<int> l;
    for (char c : numString) {
        l.push_back(c - '0');
    }
    return l;
}

list<int> BigNumCalc::add(list<int> num1, list<int> num2) {
    list<int> l;
    vector<int> a(num1.begin(), num1.end());
    vector<int> b(num2.begin(), num2.end());
    int store = 0;
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    while (i >= 0 || j >= 0 || store) {
        int d1 = (i >= 0) ? a[i--] : 0;
        int d2 = (j >= 0) ? b[j--] : 0;
        int sum = d1 + d2 + store;
        l.push_front(sum % 10);
        store = sum / 10;
    }
    return l;
}

list<int>  BigNumCalc::sub(list<int> num1, list<int> num2) {
    list<int> l;
    vector<int> a(num1.begin(), num1.end());
    vector<int> b(num2.begin(), num2.end());
    int store = 0;
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    while (i >= 0) {
        int d1 = a[i] - store;
        int d2 = (j >= 0) ? b[j] : 0;
        if (d1 < d2) {
            d1 += 10;
            store = 1;
        } else store = 0;
        l.push_front(d1 - d2);
        i--; 
        j--;
    }
    while (l.size() > 1 && l.front() == 0) l.pop_front();
    return l;
}

list<int> BigNumCalc::mul(list<int> num1, list<int> num2) {
    list<int> l;
    vector<int> a(num1.begin(), num1.end());
    int mul = num2.front();
    int store = 0;
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        int product = a[i] * mul + store;
        l.push_front(product % 10);
        store = product / 10;
    }
    if (store) l.push_front(store);

    return l;
}