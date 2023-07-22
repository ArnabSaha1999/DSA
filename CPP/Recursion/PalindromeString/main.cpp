#include<iostream>
#include<string>

using namespace std;

// Recursive function to check if a string is a palindrome
bool checkPalindrome(string str, int start, int end) {
    if(start >= end) {
        return true; // Base case: empty string or single-character string is a palindrome
    }
    if(str[start] == str[end]) {
        return checkPalindrome(str, ++start, --end); // Recursive case: characters match, move to next pair of characters
    } else {
        return false; // Characters do not match, not a palindrome
    }
}

int main() {
    string str1 = "abbaca";
    string str2 = "bbaabb";

    if(checkPalindrome(str1, 0, str1.length() - 1)) {
        cout<<str1<<" is Palidrome"<<endl;
    } else {
        cout<<str1<<" is not Palidrome"<<endl;
    }

    if(checkPalindrome(str2, 0, str2.length() - 1)) {
        cout<<str2<<" is Palidrome"<<endl;
    } else {
        cout<<str2<<" is not Palidrome"<<endl;
    }
    return 0;

}
