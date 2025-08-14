#ifndef REVERSER_H
#define REVERSER_H
#include <string>

class Reverser {
private:
    int digitHelper(int value, int acc);
public:
    int reverseDigit(int value);
    std::string reverseString(std::string characters);
};

#endif