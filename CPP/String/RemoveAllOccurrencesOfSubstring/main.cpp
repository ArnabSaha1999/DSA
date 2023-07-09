#include<iostream>
#include<string>

using namespace std;

//Approach 1: Function to remove all occurrences of a substring from a given string
string removeOccurrences(string &str, string &part) {
    // Iterate until either the string is empty or the substring is not found anymore
    while(str.length() != 0 && (str.find(part) < str.length())) {
        // Erase the substring from the string at the found position
        str.erase(str.find(part), part.length());
    }
    // Return the modified string with all occurrences of the substring removed
    return str;
}

int main() {
    string str = "daabcbaabcbc";
    string part = "abc";
    cout<<"The string: "<<str<<" & The substring: "<<part<<endl;
    cout<<"The string after removing the substring: "<<removeOccurrences(str, part);
    return 0;
}
