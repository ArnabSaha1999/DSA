#include<iostream>

using namespace std;

void reverseString(string &str, int start, int end) {
    if(start >= end) {
        return;
    }
    swap(str[start], str[end]);
    return reverseString(str, start + 1, end - 1);
}

void reverseString(string &str, int start) {
    if(start >= str.length() - 1 - start) {
        return;
    }
    swap(str[start], str[str.length() - 1 - start]);
    return reverseString(str, ++start);
}

int main() {
    string str = "abcdef";
    cout<<"After reversing the string: ";
    reverseString(str, 0);
    cout<<str<<endl;
    return 0;
}
