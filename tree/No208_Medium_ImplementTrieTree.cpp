//
// Created by Qiang Chen on 10/09/2017.
//

#include <algorithm>
#include <string>
using namespace std;
struct TrieNode {
    TrieNode* next[26];
    bool isWord;
    TrieNode(bool isWord = false){
        memset(next, 0, sizeof(next));
        this->isWord = isWord;
    }
};
class No208_Medium_ImplementTrieTree {
private:
    TrieNode* root;
    TrieNode* find(string s) {
        TrieNode *temp = root;
        for(int i = 0; i < s.length(); ++i) {
            if(temp->next[s[i] - 'a'] != nullptr) {
                temp = temp->next[s[i] - 'a'];
            } else {
                return nullptr;
            }
        }
        return temp;
    }
public:
    /** Initialize your data structure here. */
    No208_Medium_ImplementTrieTree() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string s) {
        TrieNode* temp = root;
        for(int i = 0; i < s.length(); ++i) {
            if(!temp->next[s[i] - 'a']) {
                temp->next[s[i] - 'a'] = new TrieNode();
            }
            temp = temp->next[s[i]- 'a'];
        }
        temp->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* temp = find(word);
        return temp != nullptr && temp->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
};

