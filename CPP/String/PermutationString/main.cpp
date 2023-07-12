#include<iostream>
#include<string>

using namespace std;

// Function to check if two count arrays are equal
bool checkEqual(int count1[26], int count2[26]) {
    for(int i = 0; i < 26; i++) {
        if(count1[i] != count2[i]) {
            return false;
        }
    }
    return true;
}

//Approach 1: Function to check if permutation of s1 exists in s2 using sliding window approach
bool checkInclusion(string &s1, string &s2) {
    int count1[26] = {0};
    // Calculate character counts of s1
    for(char s : s1) {
        count1[s - 'a']++;
    }
    // Initialize window
    int i = 0, windowSize = s1.length();
    int count2[26] = {0};
    // Initialize the count array for the initial window
    while(i < windowSize && i < s2.length()) {
        count2[s2[i] - 'a']++;
        i++;
    }

    if(checkEqual(count1, count2)) {
        return true;
    }
    // Slide the window and update the count array
    while(i < s2.length()) {
        count2[s2[i] - 'a']++;
        count2[s2[i - windowSize] - 'a']--;

        if(checkEqual(count1, count2)) {
            return true;
        }
        i++;
    }
    return false;
}

//Approach 2: Function to check if permutation of s1 exists in s2 using two-pointer approach
bool checkInclusionTwoPointers(string &s1, string &s2) {
    int count[26] = {0};
    // Calculate character counts of s1
    for(char s : s1) {
        count[s - 'a']++;
    }
    // Initialize window
    int left = 0, right = 0;
    
    while(right < s2.length()) {
        // Decrement count for current character
        count[s2[right] - 'a']--;
        // Shrink the window if its size exceeds s1's length
        if(right - left >= s1.length()) {
            count[s2[left] - 'a']++;
            left++;
        }
        // Check if counts match
        if(right - left + 1 == s1.length()) {
            bool match = true;
            for(int i = 0; i < 26; i++) {
                if(count[i] != 0) {
                    match = false;
                    break;
                }
            }
            if(match) {
                return true;
            }
        }
        right++;
    }
    return false;
}

int main() {
    string s1 = "ab";
    string s2 = "eiddfbaiiiooo";

    cout<<"Using checkInclusion function:"<<endl;
    if(checkInclusion(s1, s2)) {
        cout<<"Permutation of s1 exists in s2."<<endl;
    } else {
        cout<<"Permutation of s1 does not exist in s2."<<endl;
    }
    
    cout<<"Using checkInclusionTwoPointers function:"<<endl;
    if(checkInclusionTwoPointers(s1, s2)) {
        cout<<"Permutation of s1 exists in s2."<<endl;
    } else {
        cout<<"Permutation of s1 does not exist in s2."<<endl;
    }

    return 0;
}
