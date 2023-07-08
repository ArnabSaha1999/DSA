#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

//Approach 1: Function to reverse the string iteratively
void reverseStringIteratively(string &str) {
    for(int start = 0, end = str.length() - 1; start < end; start++, end--) {
        swap(str[start], str[end]);
    }
}

//Approach 2: Function to reverse the string recursively
void reverseStringRecursively(string &str, int start, int end) {
    if(start < end) {
        swap(str[start], str[end]);
        reverseStringRecursively(str, start + 1, end - 1);
    }
}

//Approach 3: Function to reverse the string using iterators
void reverseStringUsingIterators(string &str) {
    reverse(str.begin(), str.end());
}

//Approach 4: Function to reverse the string using reverse iterators
void reverseStringUsingReverseIterators(string &str) {
    str = string(str.rbegin(), str.rend());
}

int main() {
    string str = "arnab";
    cout<<"Before String reversal: ";
    cout<<str<<endl;

    cout<<"After reversing String iteratively: ";
    reverseStringIteratively(str);
    cout<<str<<endl;

    cout<<"After reversing String recursively: ";
    reverseStringRecursively(str, 0, str.length() - 1);
    cout<<str<<endl;

    cout<<"After reversing String Using iterators: ";
    reverseStringUsingIterators(str);
    cout<<str<<endl;

    cout<<"After reversing String using reverse iterators: ";
    reverseStringUsingReverseIterators(str);
    cout<<str<<endl;
    
    return 0;
}
