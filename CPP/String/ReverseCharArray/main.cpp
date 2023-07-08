#include<iostream>
#include<vector>

using namespace std;

//Approach 1: Function to reverse the vector iteratively
void reverseIteratively(vector<char> &arr) {
    for(int start = 0, end = arr.size() - 1; start < end; start++, end--) {
        swap(arr[start], arr[end]);
    }
}

//Approach 2: Function to reverse the vector recursively
void reverseRecursively(vector<char> &arr, int start, int end) {
    // Base case: if the start index becomes greater than or equal to the end index, we stop recursion
    if(start < end) {
        // Swap the characters at the start and end indices
        swap(arr[start], arr[end]);
        // Recursively call the function with updated start and end indices
        reverseRecursively(arr, start + 1, end - 1);
    }
}

// Function to print the elements of the vector
void printArray(vector<char> &arr) {
    for(char a : arr) {
        cout<<a;
    } cout<<endl;
}

int main() {
    vector<char> arr = {'a','r','n','a','b'};
    cout<<"Printing String before reversal: ";
    printArray(arr);

    cout<<"Printing String after iterative reversal: ";
    reverseIteratively(arr);
    printArray(arr);

    cout<<"Printing String after recursive reversal: ";
    reverseRecursively(arr, 0, arr.size() - 1);
    printArray(arr);
    return 0;
}
