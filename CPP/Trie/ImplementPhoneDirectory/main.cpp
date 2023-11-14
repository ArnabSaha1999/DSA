#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// TrieNode represents a node in the Trie
class TrieNode {
public:
    // Map to store child node
    unordered_map<char, TrieNode*> children;
    // Flag indicating whether the node represents the end of a word
    bool isEndOfWord;
    // Value of the node
    char value;

    TrieNode(char ch) {
        this->isEndOfWord = false;
        this->value = ch;
    }
};

// Trie class for handling Trie operations
class Trie {
    // Root node of the Trie
    TrieNode *root;
public:
    // Initialize Trie with a dummy root node
    Trie() {
        root = new TrieNode('\0');
    }

    // Insert a word into the trie
    void insert(string word) {
        // Start from the root
        TrieNode* currNode = root;
        for(char ch : word) {
            if(currNode->children.find(ch) == currNode->children.end()) {
                // Create a new node if the child does not exist
                currNode->children[ch] = new TrieNode(ch);
            }
            // Move to the next node
            currNode = currNode->children[ch];
        }
        // Mark the end of the word
        currNode->isEndOfWord = true;
    }

    // Recursively print suggestions starting from the given node
    void printSuggestions(TrieNode* root, vector<string> &ans, string prefix) {
        // If the current node is the end of a word, add it to suggestions
        if(root->isEndOfWord) {
            ans.push_back(prefix);
        }
        TrieNode* currNode = root;
        // Iterate over the children nodes of the current node
        for(char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode* childNode = currNode->children[ch];
            // If a child node exists, explore it by appending its value to the prefix
            if(childNode) {
                prefix += childNode->value;
                printSuggestions(childNode, ans, prefix);
                // Backtrack: remove the last character to explore other possibilities
                prefix.pop_back();
            }
        }
    }

    // Get suggestions for a given query string
    vector<vector<string>> getSuggestions(string queryStr) {
        TrieNode *currNode = root;
        string prefix = "";
        vector<vector<string>> ans;
        // Traverse the Trie based on the characters in the query string
        for (char ch : queryStr) {
            prefix.push_back(ch);
            TrieNode* childNode = currNode->children[ch];
            // If no child node is found for the current character, break and add "No Suggestions Found"
            if(!childNode) {
                ans.push_back({"No Suggestions Found"});
                break;
            }
            vector<string> temp;
            // Recursively print suggestions starting from the child node
            printSuggestions(childNode, temp, prefix);
            ans.push_back(temp);
            // Move to the next node for the next character
            currNode = childNode;
        }
        return ans;
    }
};

//Approach 1: Function to get suggestions from a phone directory using Trie
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr) {
    // Create a new Trie instance
    Trie *t = new Trie();
    // Insert each contact from the list into the Trie
    for(string str : contactList) {
        t->insert(str);
    }
    // Get suggestions for the query string from the Trie
    return t->getSuggestions(queryStr);
}

int main() {
    vector<string> contactList = {"cod", "coding", "codding", "code", "coly"};
    string queryStr = "coding";
    
    cout<<"The input Strings: "<<endl;
    for(string str : contactList) {
        cout<<str<<" ";
    } cout<<endl;

    cout<<endl<<"The Suggestions for query: "<<queryStr<<endl;
    vector<vector<string>> ans = phoneDirectory(contactList, queryStr);
    for(vector<string> strs : ans) {
        for(string str : strs) {
            cout<<str<<" ";
        } cout<<endl;
    }

    return 0;
}
