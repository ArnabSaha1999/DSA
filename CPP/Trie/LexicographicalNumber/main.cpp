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

    // Function to get the lexical order from the Trie
    void getLexicalOrder(TrieNode* root, string &prefix, vector<int> &ans) {
        // Check if the current node represents the end of a word
        if(root->isEndOfWord) {
            // Convert the current prefix string to an integer and add it to the result vector
            ans.push_back(stoi(prefix));
        }
        // Iterate over digits 0 to 9
        for(int i = 0; i < 10; i++) {
            // Get the child node corresponding to the current digit
            TrieNode *childNode = root->children[i + '0'];
            // Check if the child node exists
            if(childNode) {
                // Append the current digit to the prefix string
                prefix.push_back(i + '0');
                // Recursively call the function with the child node
                getLexicalOrder(childNode, prefix, ans);
                // Remove the last digit from the prefix string (backtrack)
                prefix.pop_back();
            }
        }
    }
};

//Approach 1: Function to generate lexical order using Trie
vector<int> lexicalOrderTrieApproach(int n) {
    Trie t;
    // Insert numbers from 1 to n into the Trie
    for(int i = 1; i <= n; i++) {
        t.insert(to_string(i));
    }
    vector<int> ans;
    string prefix = "";
    // Get lexical order from the Trie
    t.getLexicalOrder(t.root, prefix, ans);
    return ans;
}

// helper function to generate lexical order
void generateLexicalOrder(int currNum, int &n, vector<int> &ans) {
    // Base case: If the current number exceeds the given range, return
    if(currNum > n) {
        return;
    }
    // Add the current number to the result vector
    ans.push_back(currNum);
    // Iterate over digits 0 to 9
    for(int i = 0; i < 10; i++) {
        // Recursively generate lexical order
        if((currNum * 10 + i) <= n && (currNum * 10 + i) != 0) {
            generateLexicalOrder(currNum * 10 + i, n, ans);
        }
    }
}

//Approach 2: Function to get lexical order using combination of recursion and iteration approach
vector<int> lexicalOrder(int n) {
    vector<int> ans;
    // Start from 1 to 9 to avoid leading zeros
    for(int i = 1; i < 10; i++) {
        generateLexicalOrder(i, n, ans);
    }
    return ans;
}

int main() {
    int range = 21;
    vector<int> ans = lexicalOrderTrieApproach(range);

    cout<<"The Lexicographical Order using Trie of range: "<<range<<endl;
    for(int a : ans) {
        cout<<a<<" ";
    } cout<<endl;

    cout<<endl<<"The Lexicographical order of range: "<<range<<endl;
    ans = lexicalOrder(range);
    for(int a : ans) {
        cout<<a<<" ";
    } cout<<endl;

    return 0;
}
