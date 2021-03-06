#include <string>
#include "trie.h"

class Decryptor {
    Trie trie;
    static size_t MAX_KEY_LEN;
public:
    Decryptor(const std::string& filename);
    int decrypt(const std::string& key);
};
