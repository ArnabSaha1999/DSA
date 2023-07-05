#include<iostream>
#include<vector>

using namespace std;

//Approach 1: Reverses the array iteratively
void reverseArrayIterative(vector<int> &arr, int targetIndex) {
    for(int start = targetIndex+1, end = arr.size() - 1; start <= end; start++, end--) {
        swap(arr[start], arr[end]);
    }
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
    int targetIndex = 3;
    cout<<"The array before reverse: ";
    printArray(arr);

    reverseArrayIterative(arr, 3);
    cout<<"Applying Iterative reverse after index "<<targetIndex<<": ";
    printArray(arr);

    cout<<"The array before reverse: ";
    printArray(arr);

    reverseArrayRecursive(arr, targetIndex + 1, arr.size() - 1);
    cout<<"The array after recursive reverse after index: "<<targetIndex<<": ";
    printArray(arr);
    return 0;
}
