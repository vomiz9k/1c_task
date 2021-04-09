#include "trie.h"

Trie::Trie() {
    TrieNode epsillon;
    data.push_back(epsillon);
}

void Trie::insert(const std::string& str, size_t starting_word_position) {
    int curr = 0;

    for (auto c: str) {
        if (data[curr].next.count(c) == 0) {
            TrieNode new_node;
            new_node.starting_word_position = starting_word_position;
            data.push_back(new_node);
            data[curr].next[c] = data.size() - 1;
        }
        curr = data[curr].next[c];
    }
}

int Trie::get_starting_word_position(const std::string& str) {
    int curr = 0;
    for (auto c: str) {
        if (data[curr].next.count(c) == 0) {
            return -1;
        }
        curr = data[curr].next[c];
    }

    return data[curr].starting_word_position;
}