#include<iostream>
#include<stack>

using namespace std;

//Approach 1: Minimum bracket reversal to make string balanced by using stack
int findMinimumCost(string &str) {
    // If the string length is odd, it cannot be balanced
    if(str.length() & 1 != 0) {
        return -1;
    }
    // Stack to keep track of brackets
    stack<char> st;
    for(char ch : str) {
        if(ch == '{') {
            st.push(ch);
        } else {
            // If a closing bracket matches with the top of the stack, pop the opening bracket
            if(!st.empty() && st.top() == '{') {
                st.pop();
            } else {
                // Otherwise, push the closing bracket onto the stack
                st.push(ch);
            }
        }
    }

    int openingBracketCount = 0, closingBracketCount = 0;
    // Count the remaining unbalanced brackets in the stack
    while(!st.empty()) {
        if(st.top() == '{') {
            openingBracketCount++;
        } else {
            closingBracketCount++;
        }
        st.pop();
    }
    // Calculate the minimum number of swaps required to balance the string
    return (openingBracketCount+1) / 2 + (closingBracketCount + 1) / 2;
}

int main() {
    string str = "}{{}}{{{";
    cout<<"The input string: "<<str<<endl;
    cout<<"The minimum reversal required: "<<findMinimumCost(str)<<endl;
    return 0;
}
