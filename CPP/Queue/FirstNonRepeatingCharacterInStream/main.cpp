#include<iostream>
#include<queue>

using namespace std;

//Approach 1: Function to find the first non-repeating character in a string.
string firstNonRepeatingCharacter(string str) {
    // Queue to store characters in order of appearance.
    queue<char> q;
    // String to store the result.
    string ans = "";
    // Array to count the occurrences of each lowercase letter.
    int count[26] = {0};
    for(char ch : str) {
        // Increment the count for the current character.
        count[ch - 'a']++;
        // Push the current character onto the queue.
        q.push(ch);
        // Remove characters from the front of the queue until a non-repeating character is found.
        while(!q.empty() && count[q.front() - 'a'] > 1) {
            q.pop();
        }
        if(q.empty()) {
            // If the queue is empty, no non-repeating character found, so add '#' to the result.
            ans += '#';
        } else {
            // Otherwise, add the first non-repeating character to the result.
            ans += q.front();
        }
    }
    return ans;
}

int main() {
    string str = "aabc";
    cout<<"The input string: "<<str<<endl;
    cout<<"The answer string: "<<firstNonRepeatingCharacter(str)<<endl;
    return 0;
}

