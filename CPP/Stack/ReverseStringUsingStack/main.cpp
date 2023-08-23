#include<iostream>
#include<stack>
using namespace std;

// Function to reverse a string using a stack
string reverse(string str) {
    // Create a stack to store characters
    stack<char> st;
    for(int i = 0; i < str.size();i++) {
        // Push each character onto the stack
        st.push(str[i]);
    }
    string ans = ""; // Initialize an empty string to store the reversed string
    while(!st.empty()) {
        // Append the top character of the stack to the result string
        ans.push_back(st.top());
        st.pop(); // Pop the top character from the stack
    }
    return ans;
}

int main() {
    string str = "arnab saha";
    cout<<"The original string: "<<str<<endl;
    cout<<"The reversed string: "<<reverse(str)<<endl;
    
    return 0;
}
