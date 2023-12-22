#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
#include<utility>

using namespace std;

//Approach 1: Function to find the shortest transformation sequence length from startWord to endWord
int ladderLength(vector<string> &wordList, string startWord, string endWord) {
    // Create an unordered set for efficient word lookup
    unordered_set<string> s(wordList.begin(), wordList.end());
    // Queue for BFS traversal, storing word and its corresponding steps
    queue<pair<string, int>> bfsQueue;
    bfsQueue.push({startWord, 1});
    // Perform BFS
    while(!bfsQueue.empty()) {
        string word = bfsQueue.front().first;
        int steps = bfsQueue.front().second;
        bfsQueue.pop();
        // Check if the current word is the target (endWord)
        if(word == endWord) {
            return steps;
        }
        // Generate all possible one-letter transformations of the word
        for(int i = 0; i < word.length(); i++) {
            char original = word[i];
            // Iterate over each lowercase letter from 'a' to 'z'
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                // If the transformed word is in the wordList, erase it from the set and enqueue it with the updated steps
                if(s.find(word) != s.end()) {
                    s.erase(word);
                    bfsQueue.push({word, steps + 1});
                }
            }
            // Restore the original character for the next iteration
            word[i] = original;
        }
    }
    // If no transformation sequence is found, return 0
    return 0;
}

int main() {
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    string startWord = "hit", endWord = "cog";
    cout<<"The WordList: "<<endl;
    for(string word: wordList) {
        cout<<word<<" ";
    } cout<<endl;

    cout<<"The Shortest Transformation Sequence of "<<startWord<<" to "<<endWord<<": "<<ladderLength(wordList, startWord, endWord)<<endl;

    return 0;
}
