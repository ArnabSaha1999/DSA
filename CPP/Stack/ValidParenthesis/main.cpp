#include<iostream>
#include<stack>
#include<unordered_map>

using namespace std;

//Approach 1: Function to check balanced parentheses using a stack-based approach
bool isValidParenthesisStack(string expression) {
    // If the expression is empty or has only one character, it's not valid
    if(expression.length() == 0 || expression.length() == 1) {
        return false;
    }
    stack<char> st;
    for(char ch : expression) {
        // Push opening brackets onto the stack
        if(ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else if(!st.empty() && (st.top() == '(' && ch == ')' || st.top() == '{' && ch == '}' || st.top() == '[' && ch == ']')) {
            st.pop(); // Pop matching closing brackets from the stack
        } else {
            return false; // If none of the above cases, it's not valid
        }
    }
    // If the stack is empty, all brackets are matched
    return st.empty();
}

//Approach 2: Function to check balanced parentheses using a hash map-based approach
bool isValidParenthesisHashMap(string expression) {
    // If the expression is empty or has only one character, it's not valid
    if(expression.length() == 0 || expression.length() == 1) {
        return false;
    }
    // Define the mapping of opening to closing brackets
    unordered_map<char, char> bracketPair = {
        {'(', ')'},
        {'{', '}'},
        {'[', ']'}
    };
    stack<char> st;

    for(char ch : expression) {
        // Push opening brackets onto the stack
        if(bracketPair.count(ch)) {
            st.push(ch);
        } else if(!st.empty() && ch == bracketPair[st.top()]) {
            st.pop(); // Pop matching closing brackets from the stack
        } else {
            // If none of the above cases, it's not valid
            return false;
        }
    }
    // If the stack is empty, all brackets are matched
    return st.empty();
}

int main() {
    string expression = "[({}{}())]";
    // Check validity using stack-based approach
    bool ans = isValidParenthesisStack(expression);
    if(ans) {
        cout<<"The expression "<<expression<<" is Valid"<<endl;
    } else {
        cout<<"The expression "<<expression<<" is not Valid"<<endl;
    }
    // Check validity using hash map-based approach
    ans = isValidParenthesisHashMap(expression);
    if(ans) {
        cout<<"The expression "<<expression<<" is Valid"<<endl;
    } else {
        cout<<"The expression "<<expression<<" is not Valid"<<endl;
    }

    return 0;
}
