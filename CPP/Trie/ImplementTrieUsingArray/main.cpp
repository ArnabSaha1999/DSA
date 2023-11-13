#include<iostream>

using namespace std;

// TrieNode represents a single node in the trie
class TrieNode {
public:
    // The character value of the node
    char value;
    // Array to store children nodes for each lowercase letter
    TrieNode *children[26];
    // Flag indicating if this node marks the end of a word
    bool isEndOfWord;
    
    TrieNode(char value) {
        // Initialize end of word flag to false
        isEndOfWord = false;
        // Set the character value for the node
        this->value = value;
        // Initialize the children array to nullptr for each lowercase letter
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
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
        // Start from the root
        TrieNode *currNode = root;
        for(char c : word) {
            // Calculate the index for the character in the children array
            int index = c - 'a';
            if(!currNode->children[index]) {
                // Create a new node if the child does not exist
                currNode->children[index] = new TrieNode(c);
            }
            // Move to the next node
            currNode = currNode->children[index];
        }
        // Mark the end of the word
        currNode->isEndOfWord = true;
    }
    
    // Search for a word in the trie
    bool search(string word) {
        // Start from the root
        TrieNode *currNode = root;
        for(char c : word) {
            // Calculate the index for the character in the children array
            int index = c - 'a';
            if(!currNode->children[index]) {
                // If the child node does not exist, the word is not in the trie
                return false;
            }
            // Move to the next node
            currNode = currNode->children[index];
        }
        // Check if the last node marks the end of a word
        return currNode->isEndOfWord;
    }
    
    // Check if there is any word in the trie that starts with the given prefix
    bool startsWith(string prefix) {
        // Start from the root
        TrieNode *currNode = root;
        for(char c : prefix) {
            // Calculate the index for the character in the children array
            int index = c - 'a';
            if(!currNode->children[index]) {
                // If the child node does not exist, no word starts with the given prefix
                return false;
            }
            // Move to the next node
            currNode = currNode->children[index];
        }
        // The trie contains at least one word that starts with the given prefix
        return true;
    }

    // Remove a word from the trie
    bool remove(string word) {
        // Call the helper function to perform the removal
        return removeHelper(word, root, 0);
    }

private:
    // Check if a node has no children
    bool isChildEmpty(TrieNode *currNode) {
        for(int i = 0; i < 26; i++) {
            if(currNode->children[i]) {
                // If any child exists, the node is not empty
                return false;
            } 
        }
        // The node is empty if no child exists
        return true;
    }

    // Helper function for removing a word from the trie
    bool removeHelper(string word, TrieNode *root, int index) {
        // Base case: reached the end of the word
        if(index == word.length()) {
            if(root->isEndOfWord) {
                // If the last node marks the end of a word, reset the flag and return true
                root->isEndOfWord = false;
                return true;
            }
            // The word is not in the trie
            return false;
        }
        char c = word[index];
        // If the child node does not exist, the word is not in the trie
        if(!root->children[c - 'a']) {
            return false;
        }
        // Recursively remove the word from the children of the current node
        bool removeChild = removeHelper(word, root->children[c - 'a'], index + 1);
        // If the child is successfully removed and the current node is not the end of a word
        if(removeChild && !root->isEndOfWord) {
            if(isChildEmpty(root->children[c - 'a'])) {
                // Delete the child node
                delete root->children[c - 'a'];
                // Set the child pointer to nullptr
                root->children[c - 'a'] = nullptr;
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
