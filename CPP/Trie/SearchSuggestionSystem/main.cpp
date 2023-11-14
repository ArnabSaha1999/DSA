#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

// TrieNode represents a single node in the trie
class TrieNode {
public:
    // Map to store child nodes
    unordered_map<char, TrieNode*> children;
    // Vector to store top 3 suggestions for the current prefix
    vector<string> suggestions;
    // Flag to indicate if the node represents the end of a word
    bool isEndOfWord;
    TrieNode() {
        // Initialize end of word flag to false
        this->isEndOfWord = false;
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

    // Inserts a word into the Trie and keeps track of top 3 suggestions at each node
    void insert(string &word) {
        TrieNode* currNode = root;
        for(char ch : word) {
            // Create a new node if the child does not exist
            if(currNode->children.find(ch) == currNode->children.end()) {
                currNode->children[ch] = new TrieNode();
            }
            // Move to the next node
            currNode = currNode->children[ch];
            // Update suggestions for the current node
            if(currNode->suggestions.size() < 3) {
                currNode->suggestions.push_back(word);
            }
        }
        // Mark the end of the inserted word
        currNode->isEndOfWord = true;
    }

    // Gets suggestions for a given search word from the Trie
    vector<vector<string>> getSuggestions(string &searchWord) {
        // Vector to store suggestions at each step
        vector<vector<string>> ans;
        TrieNode* currNode = root;
        // Traverse the Trie based on characters in the search word
        for(char ch : searchWord) {
            if(currNode && currNode->children.find(ch) != currNode->children.end()) {
                // Move to the child node corresponding to the current character
                currNode = currNode->children[ch];
                // Push the suggestions for the current node into the result vector
                ans.push_back(currNode->suggestions);
                
            } else {
                // If no matching child node is found, set current node to nullptr
                currNode = nullptr;
                // Push an empty vector to represent no suggestions at this step
                ans.push_back({});
            }
        }
        // Return the final vector of suggestions
        return ans;
    } 
};

//Approach 1: Function to get suggested products for a list of products and a search word
vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    Trie *t = new Trie();
    // Sort products lexicographically
    sort(products.begin(), products.end());
    // Insert sorted products into the Trie
    for(string str : products) {
        t->insert(str);
    }
    // Get suggestions for the search word
    return t->getSuggestions(searchWord);
}

int main() {
    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    string searchedWord = "mouse";

    cout<<"The input Strings: "<<endl;
    for(string str : products) {
        cout<<str<<" ";
    } cout<<endl;

    cout<<endl<<"The Suggestions for searched word: "<<searchedWord<<endl;
    vector<vector<string>> ans = suggestedProducts(products, searchedWord);
    for(vector<string> strs : ans) {
        if(strs.empty()) {
            cout<<"[] ";
        } else {
            for(string str : strs) {
                cout<<str<<" ";
            }
        } cout<<endl;
    }

    products = {"havana"};
    searchedWord = "mouse";

    cout<<endl<<"The input Strings: "<<endl;
    for(string str : products) {
        cout<<str<<" ";
    } cout<<endl;

    cout<<endl<<"The Suggestions for searched word: "<<searchedWord<<endl;
    ans = suggestedProducts(products, searchedWord);
    for(vector<string> strs : ans) {
        if(strs.empty()) {
            cout<<"[] ";
        } else {
            for(string str : strs) {
                cout<<str<<" ";
            }
        } cout<<endl;
    }
  return 0;
}
