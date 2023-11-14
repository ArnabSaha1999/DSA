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
    // The original word associated with this node
    string word;
    TrieNode() {
        // Initialize end of word flag to false
        isEndOfWord = false;
        // Initialize empty word
        word = "";
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
        // Add the original word at the end of the word
        currNode->word = str;
    }

    // Function to get the shortest prefix of a word present in the Trie
    string getWord(string &str) {
        TrieNode* currNode = root;
        for(char ch : str) {
            // Break if the character is not present in the Trie
            if(!currNode->children.count(ch)) {
                break;
            }
            currNode = currNode->children[ch];
            // Return the word if the end of a word is reached
            if(currNode->isEndOfWord) {
                return currNode->word;
            }
        }
        // If no shorter prefix is found, return the original word
        return str;
    }
};

//Approach 1: Function to replace words in a sentence with their shortest prefixes
string replaceWords(vector<string>& dictionary, string sentence) {
    Trie *t = new Trie();
    for(string str : dictionary) {
        t->insert(str);
    }
    vector<string> words;
    string word = "";
    // Split the sentence into words
    for(char ch : sentence) {
        if(ch == ' ') {
            // Add the completed word to the list
            words.push_back(word);
            // Reset the word for the next iteration
            word = "";
        } else {
            // Append characters to form the current word
            word.push_back(ch);
        }
    }
    // Push the last word
    words.push_back(word);

    string ansSentence = "";
    // Replace words with their shortest prefixes
    for(string str : words) {
        // Get the shortest prefix from the Trie for the current word
        ansSentence += t->getWord(str) + " ";
    }
    // Remove the trailing space and return the result
    ansSentence.pop_back();

    return ansSentence;
}

int main() {
    vector<string> dictionary = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";

    cout<<"The Input String: "<<sentence<<endl;
    cout<<endl<<"The Dictionary Words to replace words from Sentence: "<<endl;
    for(string str : dictionary) {
        cout<<str<<" ";
    } cout<<endl;

    cout<<endl<<"The Sentence after replacing words: "<<endl<<replaceWords(dictionary, sentence)<<endl;

    dictionary = {"a","b","c"};
    sentence = "aadsfasf absbs bbab cadsfafs";

    cout<<endl<<"The Input String: "<<sentence<<endl;
    cout<<endl<<"The Dictionary Words to replace words from Sentence: "<<endl;
    for(string str : dictionary) {
        cout<<str<<" ";
    } cout<<endl;

    cout<<endl<<"The Sentence after replacing words: "<<endl<<replaceWords(dictionary, sentence)<<endl;

  return 0;
}
