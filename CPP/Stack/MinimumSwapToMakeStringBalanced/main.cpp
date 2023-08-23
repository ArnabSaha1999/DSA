#include<iostream>
#include<stack>

using namespace std;

//Approach 1: Function to calculate the minimum number of swaps needed to balance the string using stack
int minimumSwaps(string str) {
    // If the string length is odd, it cannot be balanced
    if(str.size() & 1 != 0) {
        return -1;
    }
    // Stack to keep track of brackets
    stack<char> st;
    int swap = 0;
    // Iterate through each character in the string
    for(char ch : str) {
        if(ch == '[') {
            // Push opening bracket onto the stack
            st.push(ch);
        } else if(!st.empty() && st.top() == '[') {
            // If a closing bracket matches with the top of the stack, pop the opening bracket
            st.pop();
        } else {
            // Otherwise, push the closing bracket onto the stack
            st.push(ch);
            // Increment the swap count
            swap++;
        }
    }
    // Calculate and return the minimum number of swaps needed
    return (swap + 1) / 2;
}

int main() {
    string str = "]]][[[";
    cout<<"The input string: "<<str<<endl;
    cout<<"The minimum swaps to make string balance: "<<minimumSwaps(str)<<endl;
    return 0;
}
