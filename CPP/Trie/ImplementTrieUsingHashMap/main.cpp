#include<iostream>
#include<unordered_map>

using namespace std;

// TrieNode represents a single node in the trie
class TrieNode {
public:
    // Map to store child nodes for each character
    unordered_map<char, TrieNode*> children;
    // Flag indicating if this node marks the end of a word
    bool isEndOfWord;
    // Initialize end of word flag to false
    TrieNode() {
        isEndOfWord = false;
    }
};

// Trie represents the trie data structure
class Trie {
    // The root node of the trie
    TrieNode* root;
public:

    Trie() {
        // Initialize the trie with an empty root node
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(string word) {
        // Start from the root
        TrieNode* currNode = root;
        for(char c : word) {
            if(currNode->children.find(c) == currNode->children.end()) {
                // Create a new node if the child does not exist
                currNode->children[c] = new TrieNode();
            }
            // Move to the next node
            currNode = currNode->children[c];
        }
        // Mark the end of the word
        currNode->isEndOfWord = true;
    }

    // Search for a word in the trie
    bool search(string word) {
        TrieNode* currNode = root;
        for(char c : word) {
            // If the child node does not exist, the word is not in the trie
            if(currNode->children.find(c) == currNode->children.end()) {
                return false;
            }
            // Move to the next node
            currNode = currNode->children[c];
        }
        // Check if the last node marks the end of a word
        return currNode->isEndOfWord;
    }

    // Check if there is any word in the trie that starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode *currNode = root;
        for(char c : prefix) {
             // If the child node does not exist, no word starts with the given prefix
            if(currNode->children.find(c) == currNode->children.end()) {
                return false;
            }
            // Move to the next node
            currNode = currNode->children[c];
        }
        // The trie contains at least one word that starts with the given prefix
        return true;
    }

    // Remove a word from the trie
    bool remove(string word) {
        // Call the helper function to perform the removal
        return removeHelper(root, word, 0);
    }

private:
    // Helper function for removing a word from the trie
    bool removeHelper(TrieNode *root, string word, int index) {
        // Base case: reached the end of the word
        if (index == word.length()) {
            // If the last node marks the end of a word, reset the flag and return true
            if (root->isEndOfWord) {
                root->isEndOfWord = false;
                return true;
            }
            // Word not found
            return false;
        }

        char c = word[index];
        // If the child node does not exist, the word is not in the trie
        if (root->children.find(c) == root->children.end()) {
            return false;
        }
        // Recursively remove the word from the children of the current node
        bool removeChild = removeHelper(root->children[c], word, index + 1);
        // If the child is successfully removed and the current node is not the end of a word
        if (removeChild && !root->isEndOfWord) {
            if(root->children[c]->children.empty()) {
                // Delete the child node
                delete root->children[c];
                // Remove the child node from the map
                root->children.erase(c);
                return true;
            }
        }
        // Return the result of the removal operation
        return removeChild;
    }
};

int main() {
    Trie t;
    t.insert("apple");
    t.insert("app");
    t.insert("application");
    t.insert("applet");
    t.insert("cat");
    t.insert("dog");
    
    cout<<"Searching apple: "<<(t.search("apple") ? "True" : "False")<<endl;
    cout<<"Searching app: "<<(t.search("app") ? "True" : "False")<<endl;
    cout<<"Searching application: "<<(t.search("application") ? "True" : "False")<<endl;
    cout<<"Searching applet: "<<(t.search("applet") ? "True" : "False")<<endl;
    cout<<"Searching cat: "<<(t.search("cat") ? "True" : "False")<<endl;
    cout<<"Searching dog: "<<(t.search("dog") ? "True" : "False")<<endl;

    cout<<"Removing apple: "<<(t.remove("apple") ? "True" : "False")<<endl;

    cout<<"Searching apple: "<<(t.search("apple") ? "True" : "False")<<endl;
    cout<<"Searching app: "<<(t.search("app") ? "True" : "False")<<endl;
    cout<<"Searching application: "<<(t.search("application") ? "True" : "False")<<endl;
    cout<<"Searching applet: "<<(t.search("applet") ? "True" : "False")<<endl;
    cout<<"Searching cat: "<<(t.search("cat") ? "True" : "False")<<endl;
    cout<<"Searching dog: "<<(t.search("dog") ? "True" : "False")<<endl;

    cout<<"Removing dog: "<<(t.remove("dog") ? "True" : "False")<<endl;

    cout<<"Searching dog: "<<(t.search("dog") ? "True" : "False")<<endl;

    cout<<"Prefix Search dog: "<<(t.startsWith("dog") ? "True" : "False")<<endl;
    cout<<"Prefix Search applet: "<<(t.startsWith("applet") ? "True" : "False")<<endl;

    cout<<"Remove apple: "<<(t.remove("apple") ? "True" : "False")<<endl;

    return 0;
}
