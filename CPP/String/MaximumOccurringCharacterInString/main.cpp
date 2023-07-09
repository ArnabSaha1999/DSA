#include<iostream>
#include<string>
#include<map>
#include<unordered_map>

using namespace std;

//Approach 1: Function using unordered_map to find the character with maximum occurrence
char getMaxOccuringCharUnorderedMap(string &str) {
    unordered_map<char, int> mp;
    for(char s : str) {
        mp[s]++;
    }
    int tempCount = mp[str[0]]; // Initialize temporary count to the count of the first character
    char ans = str[0]; // Initialize the answer to the first character
    for(int i = 1; i < str.length(); i++) {
        if(mp[str[i]] > tempCount) {
            tempCount = mp[str[i]]; // Update temporary count if a character has a higher count
            ans = str[i]; // Update the answer to the character with the higher count
        } else if ((mp[str[i]] == tempCount) && ((str[i] < ans))) {
            ans = str[i]; // If two characters have the same count, choose the character with the lower ASCII value
            
        }
    }
    return ans;
}

//Approach 2: Function using map to find the character with maximum occurrence
char getMaxOccuringCharMap(string &str) {
    map<char, int> mp;
    for(char s : str) {
        mp[s]++;
    }
    int tempCount = 0; // Initialize temporary count to 0
    char ans = '\0'; // Initialize the answer to null character
    for(auto m : mp) {
        if(m.second > tempCount) {
            tempCount = m.second; // Update temporary count if a character has a higher count
            ans = m.first; // Update the answer to the character with the higher count
        } 
    }
    return ans;
}

//Approach 3: Optimized function using an array to find the character with maximum occurrence
char getMaxOccuringCharOptimized(string &str) {
    int charCounts[26] = {0}; // Initialize an array to store the count of each character
    for(char s : str) {
        charCounts[s - 'a']++; // Increment the count of the corresponding character in the array
    }
    char ans = '\0'; // Initialize the answer to null character
    int tempCount = 0; // Initialize temporary count to 0
    for(char s : str) {
        if(charCounts[s - 'a'] > tempCount) {
            tempCount = charCounts[s - 'a']; // Update temporary count if a character has a higher count
            ans = s; // Update the answer to the character with the higher count
        } else if((charCounts[s - 'a'] == tempCount) && s < ans) {
            ans = s; // If two characters have the same count, choose the character with the lower ASCII value
        }
    }
    return ans;
}

int main() {
    string str = "testcase";
    cout<<"The input String: "<<str<<endl;

    // cout << "The Maximum occurred Character: " << getMaxOccuringCharUnorderedMap(str) << endl;
    
    // cout << "The Maximum occurred Character: " << getMaxOccuringCharMap(str) << endl;
    
    cout<<"The Maximum occurred Character: "<<getMaxOccuringCharOptimized(str)<<endl;
    
    return 0;
}
