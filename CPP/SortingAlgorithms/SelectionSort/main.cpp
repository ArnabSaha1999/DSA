#include <iostream>
#include<vector>

using namespace std;

//Approach 1: Selection Sort - Iterative Approach
void selectionSort(vector<int> &arr) {
    for(int i = 0; i < arr.size() - 1; i++) {
        int arrayMinIndex = i;
        // Find the minimum element in the unsorted part of the array
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[arrayMinIndex] > arr[j]) {
                arrayMinIndex = j;
            }
        }
        // Swap the minimum element with the first element of the unsorted part
        swap(arr[i], arr[arrayMinIndex]);
    }
}

//Approach 2: Selection Sort - Recursive Approach
void selectionSortRecursive(vector<int> &arr, int index = 0) {
    // Base case: If the index reaches the last element, return
    if(index == arr.size() - 1) {
        return;
    }

    int arrayMinIndex = index;
    // Find the minimum element in the unsorted part of the array
    for(int j = index + 1; j < arr.size(); j++) {
        if(arr[arrayMinIndex] > arr[j]) {
            arrayMinIndex = j;
        }
    }
    // Swap the minimum element with the first element of the unsorted part
    swap(arr[index], arr[arrayMinIndex]);
    // Recursively call the function with the next index
    selectionSortRecursive(arr, index+1);
} 

// Function to print the elements of the array
void print(vector<int> &arr) {
    for(int a:arr) {
        cout<<a<<" ";
    } cout<<endl;
}

int main() {
    vector<int> arr1 = {2,3,88,0,-1,33,66};
    cout<<"Selection Sort Iterative Way"<<endl;
    selectionSort(arr1);
    print(arr1);

    vector<int> arr2 = {-2, 99, 4, 2, 1, 8, 12};
    cout<<"Selection Sort Recursive Way"<<endl;
    selectionSortRecursive(arr2);
    print(arr2);
    return 0;
}
