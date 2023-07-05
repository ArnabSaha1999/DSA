#include<iostream>
#include<vector>

using namespace std;

//Approach 1: Reverses the array iteratively
void reverseArrayIterative(vector<int> &arr, int start, int size) {
    int end = size - 1;
    while(start <= end) {
        swap(arr[start++], arr[end--]);
    }
    return;
}

//Approach 2: Reverses the array recursively
void reverseArrayRecursive(vector<int>&arr, int start, int end) {
    if(start >= end) {
        return;
    }
    swap(arr[start], arr[end]);
    reverseArrayRecursive(arr, start+1, end-1);
}

// Prints the elements of the array
void printArray(vector<int> &arr) {
    for(int i : arr) {
        cout<<i<<" ";
    } cout<<endl;
}

int main() {
    vector<int> arr = {1,4,4,5,6,7,3};
    cout<<"The array before reverse: ";
    printArray(arr);

    reverseArrayIterative(arr, 0, arr.size());
    cout<<"The array after Iterative reverse: ";
    printArray(arr);

    cout<<"The array before reverse: ";
    printArray(arr);

    reverseArrayRecursive(arr, 0, arr.size() - 1);
    cout<<"The array after recursive reverse: ";
    printArray(arr);
    return 0;
}
