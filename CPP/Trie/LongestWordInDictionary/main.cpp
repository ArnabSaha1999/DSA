#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// TrieNode represents a single node in the trie
class TrieNode {
public:
    // Map to store child nodes
    unordered_map<char, TrieNode*> children;
    // Flag to indicate if the node represents the end of a word
    bool isEndOfWord;
    TrieNode() {
        // Initialize end of word flag to false
        isEndOfWord = false;
    }
};

// Trie represents the trie data structure
class Trie {
    // The root node of the trie
    TrieNode *root;
public:
    Trie() {
        // Initialize the Trie with an empty root
        root = new TrieNode();
    }

    // Function to insert a word into the Trie
    void insert(string &str) {
        TrieNode *currNode = root;
        for(char ch : str) {
            // Create a new node if the child does not exist
            if(currNode->children.find(ch) == currNode->children.end()) {
                currNode->children[ch] = new TrieNode();
            }
            // Move to the next node
            currNode = currNode->children[ch];
        }
        // Mark the end of the inserted word
        currNode->isEndOfWord = true;
    }

    // Function to check if a word is buildable from its prefixes
    bool isBuildable(string &str) {
        TrieNode* currNode = root;
        for(char ch : str) {
            // Check if the current character exists and forms a complete word
            if(!currNode->children.count(ch) || !currNode->children[ch]->isEndOfWord) {
                return false;
            }
            // Move to the next node
            currNode = currNode->children[ch];
        }
        return true;
    }
};

//Approach 1: Function to find the longest word that can be built from a list of words
string longestWord(vector<string>& words) {
    Trie *t = new Trie();
    // Insert each word into the Trie
    for(string str : words) {
        t->insert(str);
    }
    string ansWord = "";
    // Iterate through the words to find the longest buildable word
    for(string str : words) {
        // Check if the current word is buildable and longer than the current answer if same length the word with lexicographical order is longest word
        if(t->isBuildable(str) && (str.length() > ansWord.length() || (str.length() == ansWord.length() && str < ansWord))) {
            ansWord = str;
        }
    }
    return ansWord;
}

int main() {
    vector<string> words = {"w","wo","wor","worl","world"};
    cout<<"The Input Words: "<<endl;
    for(string str : words) {
        cout<<str<<" ";
    } cout<<endl;

    cout<<"The Longest Dictionary Word: "<<endl<<longestWord(words)<<endl;

    words = {"w","a","app","world","apply","wor","ap","wo","worl","appl"};
    cout<<endl<<"The Input Words: "<<endl;
    for(string str : words) {
        cout<<str<<" ";
    } cout<<endl;

    cout<<"The Longest Dictionary Word: "<<endl<<longestWord(words)<<endl;

    return 0;
}
