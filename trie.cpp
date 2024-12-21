#include <iostream>
#include <unordered_map>

using namespace std;

// assuming may not all be lowercase alphabetic 

class Node {
    public:
        unordered_map<char,Node*> children;
        bool isWord;
        Node() : isWord(false) {};
};

class Trie {
    public:
    Node* head = new Node;
    void addWord(string word){
        Node* curr = head;
        for (int i = 0; i < word.length(); i++){
            char c = word.at(i);
            if (curr->children.find(c) == curr->children.end()){
                curr->children[c] = new Node();
            }
            curr = curr->children[c];
        }
        curr->isWord = true;
    }
    bool startsWith(string word){
        Node* str = checkWord(word);
        return str != nullptr;
    }
    bool includesWord(string word){
        Node* str = checkWord(word);
        return str != nullptr && str->isWord == true;
    }
    Node* checkWord(string word){
        Node* curr = head;
        for (int i = 0; i < word.length(); i++){
            char c = word.at(i);
            if (curr->children.find(c) != curr->children.end()){
                curr = curr->children[c];
            } else {
                return nullptr;
            }
        }
        return curr;
    }
};

int main(void){

    Trie trie;

    // Add words to the Trie
    trie.addWord("hello");
    trie.addWord("world");
    trie.addWord("hell");

    // Test cases
    cout << boolalpha; // Print "true" or "false" for boolean values // remember this
    cout << "Includes 'hello': " << trie.includesWord("hello") << endl; // true
    cout << "Includes 'hell': " << trie.includesWord("hell") << endl;   // true
    cout << "Includes 'world': " << trie.includesWord("world") << endl; // true
    cout << "Includes 'wor': " << trie.includesWord("wor") << endl;     // false
    cout << "Starts with 'hel': " << trie.startsWith("hel") << endl;    // true
    cout << "Starts with 'wor': " << trie.startsWith("wor") << endl;    // true
    cout << "Starts with 'worlz': " << trie.startsWith("worlz") << endl; // false

    return 0;
}