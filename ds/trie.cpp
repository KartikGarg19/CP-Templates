#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
public:
    vector<TrieNode*> children;
    bool isEndOfWord;
    TrieNode(){
        children.assign(26, NULL);
        isEndOfWord = false;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root = new TrieNode();
        return ;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        int n = word.length();
        for(int i=0; i<n; i++){
            int id = word[i]-'a';
            if(!curr->children[id]){
                curr->children[id] = new TrieNode();
            }
            curr = curr->children[id];
            if(i == n-1){
                curr->isEndOfWord = true;
            }
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        int n = word.length();
        for(int i=0; i<n; i++){
            int id = word[i]-'a';
            if(!curr->children[id]){
                return false;
            }
            curr = curr->children[id];
            if(i == n-1){
                return curr->isEndOfWord;
            }
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        int n = prefix.length();
        for(int i=0; i<n; i++){
            int id = prefix[i]-'a';
            if(!curr->children[id]){
                return false;
            }
            curr = curr->children[id];
            if(i == n-1){
                if(curr->isEndOfWord) return true;
                for(int j=0; j<26; j++){
                    if(curr->children[j]) return true;
                }
                return false;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */