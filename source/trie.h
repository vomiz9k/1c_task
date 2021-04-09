#include <string>
#include <vector>
#include <unordered_map>


class Trie {
private:
    struct TrieNode {
        std::unordered_map<char, int> next;
        int starting_word_position = -1;
    };
 
    std::vector<TrieNode> data;
 
public:
    Trie();
    void insert(const std::string& str, size_t starting_word_position);
    int get_starting_word_position(const std::string& str);
};