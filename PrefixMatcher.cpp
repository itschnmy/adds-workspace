#include "PrefixMatcher.h"
#include <iostream>
using namespace std;

PrefixMatcher::PrefixMatcher() {
    root = new TrieNode();
}

void PrefixMatcher::insert(string address, int routerNumber) {
    TrieNode* i = root;
    for (char bit : address) {
        int index = bit - '0';
        if (i->children[index] == nullptr) i->children[index] = new TrieNode();
        i = i->children[index];
    }
    i->routerNumber = routerNumber;
}

int PrefixMatcher::selectRouter(string networkAddress) {
    TrieNode* i = root;
    int match = 0;
    for (char bit : networkAddress) {
        int index = bit - '0';
        if (i->children[index] == nullptr) break;
        i = i->children[index];
        if (i->routerNumber != 0) match = i->routerNumber;
    }
    return match;
}