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
        this->isEndOfWord = false;
    }
};

// Trie represents the trie data structure
class Trie {
public:
    // The root node of the trie
    TrieNode *root;
    Trie() {
        // Initialize the Trie with an empty root
        root = new TrieNode();
    }

    // Function to insert a word into the Trie
    void insert(string str) {
        TrieNode* currNode = root;
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

    // Function to check if a given string matches the CamelCase pattern
    bool isCamelCase(string &str) {
        TrieNode *currNode = root;
        for(char ch : str) {
            // Move through the Trie for each character in the input string
            if(currNode->children.count(ch) ) {
                currNode = currNode->children[ch];
            } else if(islower(ch)) {
                // Continue if the character is lowercase
                continue;
            } else {
                // Return false if the character is uppercase and not present in the Trie
                return false;
            }
        }
        // Return true if the entire string is successfully matched in the Trie
        return currNode->isEndOfWord;
    }
};

//Approach 1: Function to perform CamelCase matching for a list of queries with a given pattern
vector<bool> camelMatch(vector<string>& queries, string pattern) {
    Trie *t = new Trie();
    vector<bool> ans;
    // Insert the pattern into the Trie
    t->insert(pattern);
    // Check CamelCase matching for each query
    for(string str : queries) {
        ans.push_back(t->isCamelCase(str));
    }
    return ans;
}

int main() {
    vector<string> queries = {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
    string pattern = "FB";

    cout<<"The input Strings: "<<endl;
    for(string str : queries) {
        cout<<str<<" ";
    } cout<<endl;

    cout<<endl<<"The CamelCase Match for Patten: "<<pattern<<endl;
    vector<bool> ans = camelMatch(queries, pattern);
    for(bool a : ans) {
        if(a) {
            cout<<"True ";
        } else {
            cout<<"False ";
        } 
    } cout<<endl;

    queries = {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
    pattern = "FoBaT";

    cout<<endl<<"The input Strings: "<<endl;
    for(string str : queries) {
        cout<<str<<" ";
    } cout<<endl;

    cout<<endl<<"The CamelCase Match for Patten: "<<pattern<<endl;
    ans = camelMatch(queries, pattern);
    for(bool a : ans) {
        if(a) {
            cout<<"True ";
        } else {
            cout<<"False ";
        } 
    } cout<<endl;

  return 0;
}
