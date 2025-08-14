#include "Reverser.h"
#include <iostream>
using namespace std;

int Reverser::digitHelper(int value, int acc) {
    if (value == 0) {
        return acc;
    } else {
        return digitHelper(value/10, acc*10+value%10);
    }
}

int Reverser::reverseDigit(int value) {
    if (value < 0) {
        return -1;
    }
    return digitHelper(value, 0); 
}

string Reverser::reverseString(string characters) {
    if (characters.empty()) {
        cerr << "ERROR!";
        return "";
    }
    
    if (characters.length() == 1) {
        return characters;
    } else {
        return reverseString(characters.substr(1)) + characters[0];
    }
}