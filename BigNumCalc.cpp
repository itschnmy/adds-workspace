#include "BigNumCalc.h"
#include <iostream>
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
    auto i1 = num1.rbegin();
    auto i2 = num2.rbegin();
    int store = 0;
    while(i1 != num1.rend() || i2 != num2.rend() || store) {
        int n1 = *i1++;
        int n2 = *i2++;
        if (i1 == num1.rend()) { n1 = 0; }
        else if (i2 == num2.rend()) { n2 = 0; }
        int sum = n1 + n2 + store;
        l.push_front(sum % 10);
        store = sum / 10;
    }
    return l;
}

list<int>  BigNumCalc::sub(list<int> num1, list<int> num2) {
    list<int> l;
    auto i1 = num1.rbegin();
    auto i2 = num2.rbegin();
    int store = 0;
    while(i1 != num1.rend()) {
        int n1 = *i1 - store;
        int n2 = *i2;
        if (i2 == num2.rend()) {
            n2 = 0;
        }
        if (n1 < n2) {
            n1 += 10;
            store = 1;
        } else {
            store = 0;
        }
        int sub = n1 - n2;
        l.push_front(sub);
        ++i1;
        if (i2 != num2.rend()) {++i2;}
    }
    return l;
}

list<int> BigNumCalc::mul(list<int> num1, list<int> num2) {
    list<int> l;
    int mul = num2.front();
    int store = 0;
    for (auto i = num1.rbegin(); i != num1.rend(); ++i) {
        int product = *i * mul + store;
        l.push_front(product % 10);
        store = product / 10;
    }
    if (store) {l.push_front(store);}

    return l;
}