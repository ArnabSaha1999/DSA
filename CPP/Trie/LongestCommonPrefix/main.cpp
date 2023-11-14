#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//Approach 1: Function to find the longest common prefix using the character-by-character comparison approach
string longestCommonPrefix(vector<string>& strs) {
    string ans = "";
    // Check each character position in the first string
    for(int i = 0; i < strs[0].size(); i++) {
        char ch = strs[0][i];
        bool isMatched = true;
        // Compare the current character with the same position in other strings
        for(int j = 1; j < strs.size(); j++) {
            // If the string is shorter than the current position or the character is different, break
            if(strs[j].size() < i || strs[j][i] != ch) {
                isMatched = false;
                break;
            }
        }
        // If all strings matched at the current position, add the character to the common prefix
        if(isMatched) {
            ans.push_back(ch);
        } else {
            // Break the loop if there is a mismatch
            break;
        }
    }
    return ans;
}

// TrieNode represents a single node in the trie
class TrieNode {
public:
    // Map to store child nodes for each character
    unordered_map<char, TrieNode*> children;
    // Flag indicating if this node marks the end of a word
    bool isEndOfWord;
    // The character value of the node
    char value;
    TrieNode(char ch) {
        // Initialize end of word flag to false
        this->isEndOfWord = false;
        // Set the character value for the node
        this->value = ch;
    }
};

// Trie represents the trie data structure
class Trie {
    // The root node of the trie
    TrieNode *root;
public:
    Trie() {
        // Initialize the trie with an empty root node
        root = new TrieNode('\0');
    }

    // Insert a word into the trie
    void insert(string word) {
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

    // Find the longest common prefix using the trie approach
    string longestCommonPrefix(vector<string> &strs) {
        string ans = "";
        TrieNode *currNode = root;
        // Traverse the trie until a node has more than one child or is the end of a word
        while(currNode && currNode->children.size() == 1) {
            char ch = currNode->children.begin()->first;
            // If the current node is the end of a word, break the loop
            if (currNode->isEndOfWord) {
                break; 
            }
            // Add the character to the common prefix
            ans.push_back(ch);
            // Move to the next node
            currNode = currNode->children.begin()->second;
        }
        
        return ans;
    }
};

//Approach 2: Function to find the longest common prefix using the Trie approach
string longestCommonPrefixTrieApproach(vector<string>& strs) {
    Trie *t = new Trie();
    string ans = "";
    // Insert each string into the trie
    for(string str : strs) {
        if(str == "") {
            // If an empty string is present, the common prefix is empty
            return "";
        }
        t->insert(str);
    }
    // Find the longest common prefix using the trie approach
    return t->longestCommonPrefix(strs);
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout<<"The input Strings: "<<endl;
    for(string str : strs) {
        cout<<str<<" ";
    } cout<<endl;
    cout<<"The Longest Common Prefix is: "<<longestCommonPrefix(strs)<<endl;
    cout<<"The Longest Common Prefix Using Trie is: "<<longestCommonPrefixTrieApproach(strs)<<endl;

    return 0;    
}
