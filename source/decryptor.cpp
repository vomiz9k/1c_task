#include "decryptor.h"
#include <fstream>
#include <deque>
#include <sstream>
#include <iostream>

size_t Decryptor::MAX_KEY_LEN = 5;

Decryptor::Decryptor(const std::string& filename) {
    std::ifstream text(filename);

    std::string word;
    std::deque<std::string> curr_words;

    for (size_t i = 0; i < MAX_KEY_LEN; ++i) {
        if (!(text >> word)) {
            break;
        }
        curr_words.push_back(word);
    }

    size_t curr_starting_word_position = 0;
    while(!curr_words.empty()) {
        std::string inserting_word(curr_words.size(), 0);
        for (size_t i = 0; i < curr_words.size(); ++i) {
            inserting_word[i] = curr_words[i][i];
        }
        trie.insert(inserting_word, curr_starting_word_position);
        ++curr_starting_word_position;
        curr_words.pop_front();
        if (text >> word) {
            curr_words.push_back(word);
        }
    }
}


int Decryptor::decrypt(const std::string& key) {
    return trie.get_starting_word_position(key);
}


