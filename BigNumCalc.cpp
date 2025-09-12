#include "BigNumCalc.h"
using namespace std;

list<int> BigNumCalc::buildBigNum(string numString) {
    list<int> l;
    for (char c : numString) {
        l.push_back(c - '0');
    }
    return l;
}

void BigNumCalc::removeLeadingZeros(list<int>& num) {
    while (num.size() > 1 && num.front() == 0) {
        num.pop_front();
    }
}

list<int> BigNumCalc::add(list<int> num1, list<int> num2) {
    list<int> l;
    auto i1 = num1.rbegin();
    auto i2 = num2.rbegin();
    int store = 0;

    while (i1 != num1.rend() || i2 != num2.rend() || store != 0) {
        int d1 = (i1 != num1.rend()) ? *i1++ : 0;
        int d2 = (i2 != num2.rend()) ? *i2++ : 0;

        int sum = d1 + d2 + store;
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

    while (i1 != num1.rend()) {
        int d1 = *i1++;
        int d2 = (i2 != num2.rend()) ? *i2++ : 0;

        int digit = d1 - store;
        store = 0;

        if (digit < d2) {
            digit += 10;
            store = 1;
        }

        l.push_front(digit - d2);
    }
    
    removeLeadingZeros(l);
    return l;
}

list<int> BigNumCalc::mul(list<int> num1, list<int> num2) {
    if (num2.empty()) return {0};
    int mul = num2.front();
    if (mul == 0) return {0};

    list<int> l;
    auto it1 = num1.rbegin();
    int store = 0;

    while (it1 != num1.rend() || store != 0) {
        int d1 = (it1 != num1.rend()) ? *it1++ : 0;
        
        int product = (d1 * mul) + store;
        l.push_front(product % 10);
        store = product / 10;
    }
    
    removeLeadingZeros(l);
    return l;
}