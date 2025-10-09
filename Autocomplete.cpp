#include "Autocomplete.h"
#include <iostream>
using namespace std;

Autocomplete::Autocomplete() {
    root = new TrieNode();
}

void Autocomplete::helper(TrieNode* node, string prefix, vector<string>& results) {
    if (node->isEndOfWord) {
        results.push_back(prefix);
    }

    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            char next = 'a' + i;
            helper(node->children[i], prefix + next, results);
        }
    }
}

void Autocomplete::insert(string word) {
    TrieNode* i = root;
    for (char c : word) {
        int index = c - 'a';
        if (i->children[index] == nullptr) i->children[index] = new TrieNode();
        i = i->children[index];
    }
    i->isEndOfWord = true;
}

vector<string> Autocomplete::getSuggestions(string partialWord) {
    TrieNode* i = root;
    for (char c : partialWord) {
        int index = c - 'a';
        if (i->children[index] == nullptr) return {};
        i = i->children[index];
    }

    vector<string> results;
    helper(i, partialWord, results);
    return results;
}