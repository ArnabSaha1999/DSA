#include<iostream>
#include<queue>

using namespace std;

//Approach 1: Function to find the index of the first unique character in a string.
int firstUniqChar(string s) {
    // Initialize an array to count the frequency of each character (assuming lowercase English letters).
    int count[26] = {0};
    for(char ch : s) {
        // Increment the count for the corresponding character.
        count[ch - 'a']++;
    }
    for(int i = 0; i < s.length(); i++) {
        if(count[s[i] - 'a'] == 1) {
            // If the character occurs only once, return its index.
            return i;
        }
    }
    return -1;
}

//Approach 2: Function to find the index of the first unique character in a string using a queue.
int firstUniqCharUsingQueue(string s) {
    queue<int> q;
    int ansIndex = 0;
    int count[26] = {0};
    for(int i = 0; i < s.length(); i++) {
        // Increment the count for the corresponding character.
        count[s[i] - 'a']++;
        // Push the index of the character into the queue.
        q.push(i);
        // Remove indices of characters with frequency > 1 from the front of the queue.
        while(!q.empty() && count[s[q.front()] - 'a'] > 1) {
            q.pop();
        }
    }
    // If the queue is empty, return -1; otherwise, return the index of the first unique character.
    return (q.empty()) ? -1 : q.front();
}

int main() {
    string str = "aabb";
    cout<<"The input string: "<<str<<endl;
    cout<<"The index of the first unique character in string: "<<firstUniqChar(str)<<endl;
    cout<<"The index of the first unique character in string using queue: "<<firstUniqCharUsingQueue(str)<<endl;

    str = "aabbbcda";
    cout<<"The input string: "<<str<<endl;
    cout<<"The index of the first unique character in string: "<<firstUniqChar(str)<<endl;
    cout<<"The index of the first unique character in string using queue: "<<firstUniqCharUsingQueue(str)<<endl;

    return 0;
}
