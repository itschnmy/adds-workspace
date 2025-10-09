#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H
#include <string>

struct TrieNode {
    TrieNode* children[2];
    int routerNumber;

    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
        routerNumber = 0;
    }
};

class PrefixMatcher {
private:
    TrieNode* root;
public:
    PrefixMatcher();
    void insert(std::string address, int routerNumber);
    int selectRouter(std::string networkAddress);
};

#endif