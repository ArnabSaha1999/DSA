#include<iostream>
#include<vector>

using namespace std;

// Partition function for QuickSort
int partition(vector<int> &arr, int start, int end) {
    int pivot = arr[start]; // Select the first element as the pivot
    int count = 0;
    // Count the number of elements smaller than or equal to the pivot
    for(int i = start + 1; i <= end; i++) {
        if(arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    // Swap the pivot with the element at pivotIndex
    swap(arr[start], arr[pivotIndex]);
    int i = start, j = end;
    // Move the pointers inward until they cross each other
    while(i < pivotIndex && j > pivotIndex) {
        //Check if elements left of Pivot is Bigger, in that case swap element to right of pivot.
        while(arr[i] <= pivot) {
            i++;
        }
        //Check if elements right of Pivot is lesser, in that case swap element to left of pivot.
        while(arr[j] > pivot) {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]); // Swap the elements to maintain the partition
        }
    }
    return pivotIndex;
}

//Approach 1: Recursive QuickSort function
void quickSort(vector<int> &arr, int start, int end) {
    if(start >= end)
        return;
    int pivotIndex = partition(arr, start, end);
    // Recursively call QuickSort on the sub-arrays
    quickSort(arr, start, pivotIndex-1);
    quickSort(arr, pivotIndex+1, end);

}

// Function to print the elements of an array
void print(vector<int> arr) {
    for(int a : arr) {
        cout<<a<<" ";
    } cout<<endl;
}

int main() {
    vector<int> arr = {44,2,5,6,2,5,44,11,66,102,-2};
    cout<<"Applying Quick Sort :"<<endl;
    quickSort(arr, 0, arr.size() - 1);
    print(arr);
    return 0;
}
