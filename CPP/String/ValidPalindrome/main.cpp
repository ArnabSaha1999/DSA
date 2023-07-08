#include<iostream>
#include<string>

using namespace std;

// Function to reverse a string
void reverseString(string &str) {
    // Iterate from both ends of the string and swap characters
    for(int start = 0, end = str.length() - 1; start < end; start++, end--) {
        swap(str[start], str[end]);
    }
}

//Approach 1: Function to check if a string is a palindrome
bool checkPalindrome(string &s) {
    string reversedString = s;
    reverseString(reversedString); // Reverse the original string
    int i = 0, j = 0;
    while(i < s.length() && j < s.length()) {
        if(!isalnum(s[i])) {
            i++; // Skip non-alphanumeric characters in the original string
        } else if(!isalnum(reversedString[j])) {
            j++; // Skip non-alphanumeric characters in the reversed string
        } else if(tolower(s[i]) != tolower(reversedString[j])) {
            return false; // Characters don't match, not a palindrome
        } else {
            i++;
            j++; // Move to the next characters
        }
    }
    return true; // All characters match, it's a palindrome
}

//Approach 2: Optimized function to check if a string is a palindrome
bool checkPalindromeOptimized(string s) {
    int start = 0, end = s.length() - 1;
    while(start < end) {
        if(!isalnum(s[start])) {
            start++; // Skip non-alphanumeric characters from the beginning
        } else if(!isalnum(s[end])) {
            end--; // Skip non-alphanumeric characters from the end
        } else if(tolower(s[start]) != tolower(s[end])){
            return false; // Characters don't match, not a palindrome
        } else {
            start++;
            end--; // Move to the next characters
        }
    }
    return true; // All characters match, it's a palindrome
}

int main() {
    string str = "A man, a plan, a canal: Panama";
    if(checkPalindrome(str)) {
        cout<<"The String "<< str<<" is Palindrome"<<endl;
    } else {
        cout<<"The String "<<str<<" is not Palidrome"<<endl;
    }
    return 0;
}
