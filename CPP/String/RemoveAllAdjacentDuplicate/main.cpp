#include<iostream>
#include<string>
#include<stack>

using namespace std;

//Approach 1: Function to remove adjacent duplicates from the string by erasing them
string removeDuplicates(string &str) {
    int i = 0;
    while(i < str.length() - 1) {
        if(str[i] == str[i + 1]) {
            str.erase(i, 2); // Erase the adjacent duplicates
            if(i != 0) {
                i--; // Decrement i to check for new adjacent duplicates
            }
        } else {
            i++; // Move to the next character
        }
    }
    return str;
}

//Approach 2: Function to remove adjacent duplicates from the string using a stack
string removeDuplicatesUsingStack(string &str) {
    stack<char> st;
    for(char s : str) {
        if(!st.empty() && st.top() == s) {
            st.pop(); // Remove the duplicate character from the stack
        } else {
            st.push(s); // Push non-duplicate character onto the stack
        }
    }
    string result;
    while(!st.empty()) {
        result = st.top() + result; // Construct the result string in reverse order
        st.pop();
    }
    return result;
}

int main() {
    string str = "abbaca";
    cout<<"The string: "<<str<<endl;
    // cout<<"After removing the adjacent duplicates: "<<removeDuplicates(str);
    cout<<"After removing the adjacent duplicates: "<<removeDuplicatesUsingStack(str);
    return 0;
}
