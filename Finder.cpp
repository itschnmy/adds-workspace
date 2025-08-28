#include "Finder.h"
using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {

    vector<int> result(s2.size(), -1);
    size_t start = 0;

    for(size_t i = 1; i <= s2.size(); i++) {
        size_t found = s1.find(s2.c_str(), start, i);
        if (found != string::npos) {
            result[i - 1] = static_cast<int>(found);
            start = found;
        } else {
           break;
        }
    }

    return result;
}
   