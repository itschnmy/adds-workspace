#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H
#include <vector>
#include <string>

struct TrieNode {
    bool isEndOfWord;
    std::vector<TrieNode*> children;
    TrieNode() {
        isEndOfWord = false;
        children = std::vector<TrieNode*>(26, nullptr);
    }
};


class Autocomplete {
private:
    TrieNode* root;
    void helper(TrieNode* node, std::string prefix, std::vector<std::string>& results);
public:
    Autocomplete();
    std::vector<std::string> getSuggestions(std::string partialWord);
    void insert(std::string word);
};

#endif