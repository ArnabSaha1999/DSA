#include<iostream>
#include<vector>

using namespace std;

// Merge two sorted subarrays into a single sorted array
void merge(vector<int> &arr, int start, int mid, int end) {
    int leftArraySize = mid - start + 1; // Calculate the size of the left array
    int rightArraySize = end - mid; // Calculate the size of the right array
    int *leftArray = new int[leftArraySize];
    int *rightArray = new int[rightArraySize];
    // Copy elements to temporary left and right arrays
    for(int i = 0; i < leftArraySize; i++) {
        leftArray[i] = arr[start + i];
    }
    for(int i = 0; i < rightArraySize; i++) {
        rightArray[i] = arr[mid + 1 + i];
    }
    int mainArrayIndex = start;
    int leftArrayIndex = 0, rightArrayIndex = 0;
    // Merge the two subarrays back into the main array in sorted order
    while(leftArrayIndex < leftArraySize && rightArrayIndex < rightArraySize) {
        if(leftArray[leftArrayIndex] < rightArray[rightArrayIndex]) {
            arr[mainArrayIndex++] = leftArray[leftArrayIndex++];
        } else {
            arr[mainArrayIndex++] = rightArray[rightArrayIndex++];
        }
    }
    // Copy any remaining elements from the left array
    while(leftArrayIndex < leftArraySize) {
        arr[mainArrayIndex++] = leftArray[leftArrayIndex++];
    }
    // Copy any remaining elements from the right array
    while(rightArrayIndex < rightArraySize) {
        arr[mainArrayIndex++] = rightArray[rightArrayIndex++];
    }
    // Clean up dynamically allocated memory
    delete[] leftArray;
    delete[] rightArray;
    
}

//Approach 1: Recursive function to perform merge sort
void mergeSort(vector<int> &arr, int start, int end) {
    // Base case: If the array has one or fewer elements, it is already sorted
    if(start >= end) {
        return;
    }
    // Divide the array into two halves
    int mid = start + (end - start) / 2;
    // Recursively sort the left and right halves
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    // Merge the sorted halves
    merge(arr, start, mid, end);
}

// Function to print the elements of an array
void print(vector<int> &arr) {
    for(int a : arr) {
        cout<<a<<" ";
    } cout<<endl;
}

int main() {
    cout<<"Applying Merge Sort"<<endl;
   vector<int> arr = {55 , 99 , 10 , 5 , 0 , 96 , 45 , 66 , 78 , 3};
    // vector<int> arr = {55 , 99 , 10 , 5};
    mergeSort(arr, 0, arr.size() - 1);
    print(arr);
    return 0;
}
