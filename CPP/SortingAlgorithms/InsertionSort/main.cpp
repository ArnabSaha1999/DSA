#include <iostream>
#include <vector>

using namespace std;

//Approach 1: Function to perform iterative insertion sort
void insertionSort(vector<int> &arr) {
    for(int i = 1; i < arr.size(); i++) {
        int temp = arr[i];
        int j = i - 1;
        // Shift elements to the right until the correct position for the key is found
        while(j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j--]; // Shift element to the right
        }
        arr[j+1] = temp; // Insert the key into the correct position
    }
}

//Approach 2: Function to perform recursive insertion sort
void insertionSortRecursive(vector<int> &arr, int index = 1) {
    if(index == arr.size()) {
        return; // Base case: All elements have been processed
    }

    int temp = arr[index];
    int j = index - 1;
    // Shift elements to the right until the correct position for the key is found
    while(j >= 0 && arr[j] > temp) {
        arr[j+1] = arr[j--]; // Shift element to the right
    }
    arr[j+1] = temp; // Insert the key into the correct position
    // Recursively call the function for the next element
    insertionSortRecursive(arr, index+1);
}

// Function to print the elements of the array
void print(vector<int> &arr) {
    for(int a : arr) {
        cout<<a<<" ";
    } cout<<endl;
}

int main() {
    vector<int> arr1 = {5,2,3,1};
    cout<<"Insertion Sort Iterative Way"<<endl;
    insertionSort(arr1);
    print(arr1);

    vector<int> arr2 = {3,3,3,5,2,66,1,33,4};
    cout<<"Insertion Sort Recursive Way"<<endl;
    insertionSortRecursive(arr2);
    print(arr2);
    return 0;
}
