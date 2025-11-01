#include <memory>
#include <string>

class Trie {
private:
    std::unique_ptr<Trie> children[26]{};
    bool isEnd = false;

    Trie* searchPrefix(std::string prefix) {
        auto node = this;
        for (auto ch: prefix) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                return nullptr;
            }
            node = node->children[ch].get();
        }
        return node;
    }
public:
    Trie() {
        
    }
    
    void insert(std::string word) {
        Trie* node = this;
        if (search(word)) return;
        for (auto ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch].reset(new Trie());
            }
            node = node->children[ch].get();
        }
        node->isEnd = true;
    }
    
    bool search(std::string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }
    
    bool startsWith(std::string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */