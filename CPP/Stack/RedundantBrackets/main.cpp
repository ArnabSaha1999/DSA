#include<iostream>
#include<stack>

using namespace std;

//Approach 1: Find redundant brackets using stack
bool findRedundantBrackets(string &str) {
    stack<char> st;
    for(char ch : str) {
        // Push opening brackets or operators onto the stack
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        } else if(ch == ')') { 
            bool isRedundant = true;
            // Check for operators between opening and closing brackets
            while(!st.empty() && st.top() != '(') {
                if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/') {
                    isRedundant = false;
                }
                st.pop();
            }
            st.pop();
            // Found redundant brackets
            if(isRedundant) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string str = "(a+b+(a*b))";
    string str1 = "(a+c*b)+(c))";
    cout<<"The input string: "<<str<<endl;
    bool ans = findRedundantBrackets(str);
    if(ans) {
        cout<<"There is Redundant Brackets"<<endl;
    } else {
        cout<<"There is no Redundant Brackets"<<endl;
    }

    cout<<"The input string: "<<str1<<endl;
    ans = findRedundantBrackets(str1);
    if(ans) {
        cout<<"There is Redundant Bracket"<<endl;
    } else {
        cout<<"There is no Redundant Bracket"<<endl;
    }
    return 0;
}
