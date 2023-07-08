#include<iostream>
#include<string>

using namespace std;

// Function to reverse a string
void reverseString(string &str) {
    for(int start = 0, end = str.length() - 1; start < end; start++, end--) {
        swap(str[start], str[end]);
    }
}

//Approach 1: Function to check if a string is a palindrome
bool checkPalindrome(string &s) {
    string reversedString = s;
    reverseString(reversedString); // Reversing the string
    int i = 0, j = 0;
    while(i < s.length() && j < s.length()) {
        if(!isalnum(s[i])) { // Skip non-alphanumeric characters in the original string
            i++;
        } else if(!isalnum(reversedString[j])) { // Skip non-alphanumeric characters in the reversed string
            j++;
        } else if(tolower(s[i]) != tolower(reversedString[j])) { // Compare alphanumeric characters ignoring case
            return false;
        } else {
            i++;
            j++;
        }
    }
    return true;
}

//Approach 2: Optimized function to check if a string is a palindrome
bool checkPalindromeOptimized(string s) {
    int start = 0, end = s.length() - 1;
    while(start < end) {
        if(!isalnum(s[start])) { // Skip non-alphanumeric characters at the start
            start++;
        } else if(!isalnum(s[end])) { // Skip non-alphanumeric characters at the end
            end--;
        } else if(tolower(s[start]) != tolower(s[end])){ // Compare alphanumeric characters ignoring case
            return false;
        } else {
            start++;
            end--;
        }
    }
    return true;
}

int main() {
    string str = "N2 i&nJA?a& jnI2n";
    if(checkPalindrome(str)) {
        cout<<"The String "<< str<<" is Palindrome"<<endl;
    } else {
        cout<<"The String "<<str<<" is not Palidrome"<<endl;
    }
    return 0;
}
