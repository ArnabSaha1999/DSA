#include<iostream>
#include<string>
#include<vector>

using namespace std;

//Approach 1: Function to compress the characters in the given vector
int compress(vector<char> &chars) {
    int slow = 0, ansIndex = 0;
    while(slow < chars.size()) {
        int fast = slow + 1; // Index to move through the characters in the group
        // Move the fast pointer until the character changes or the end of the vector is reached
        while(fast < chars.size() && chars[slow] == chars[fast]) {
            fast++;
        }
        // Write the character at slow index to the compressed vector
        chars[ansIndex++] = chars[slow];
        int count = fast - slow; // Count of consecutive occurrences of the character
        if(count > 1) {
            // Convert the count to a string
            string countString = to_string(count);
            // Write the count digits as characters to the compressed vector
            for(char cs : countString) {
                chars[ansIndex++] = cs;
            }
        }
        slow = fast; // Move slow to the next group of characters
    }
    return ansIndex; // Return the length of the compressed vector
}

//Approach 2: Modified version of the compress function with optimized loop condition
int compressModified(vector<char> &chars) {
    int slow = 0, ansIndex = 0;
    for(int fast = slow + 1; fast <= chars.size(); fast++) {
        if(fast == chars.size() || chars[fast] != chars[slow]) {
            // Write the character at slow index to the compressed vector
            chars[ansIndex++] = chars[slow];
            int count = fast - slow;
            if(count > 1) {
                // Convert the count to a string
                string countString = to_string(count);
                // Write the count digits as characters to the compressed vector
                for(char cs : countString) {
                    chars[ansIndex++] = cs; 
                }
            }
            slow = fast; // Move slow to the next group of characters
        }
    }
    return ansIndex; // Return the length of the compressed vector
}

int main() {
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    cout<<"The new length of the compressed array: "<<compressModified(chars)<<endl;
}
