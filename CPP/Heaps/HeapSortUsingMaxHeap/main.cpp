#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Function to perform max-heapify operation
void maxHeapify(vector<int> &arr, int size, int index) {
    while(index < size) {
        int leftIndex = index * 2 + 1;
        int rightIndex = index * 2 + 2;
        int largestIndex = index;
        // Check if the left child exists and is greater than the current largest element
        if(leftIndex < size && arr[leftIndex] > arr[largestIndex]) {
            largestIndex = leftIndex;
        }
        // Check if the right child exists and is greater than the current largest element
        if(rightIndex < size && arr[rightIndex] > arr[largestIndex]) {
            largestIndex = rightIndex;
        }
        // If the largest child is not the current element, swap them to maintain the max-heap property
        if(largestIndex != index) {
            swap(arr[index], arr[largestIndex]);
            index = largestIndex;
        } else {
            // Max-heap property is preserved, so exit the loop
            return;
        }
    }
}

//Approach 1: Function to perform Heap Sort with the help of Iterative Max Heapify Function
void heapSort(vector<int> &arr) {
    // Build a max-heap from the input array
    for(int i = arr.size() - 1 / 2; i >= 0; i--) {
        maxHeapify(arr, arr.size(), i);
    }
    // Sort the array by repeatedly extracting the maximum element (root of the max-heap)
    for(int i = arr.size() - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        // Re-heapify the remaining elements to maintain the max-heap property
        maxHeapify(arr, i, 0);
    }
}

//Approach 2: Function to perform Heap Sort using Priority Queue (Max Heap)
void heapSortPriorityQueue(vector<int> &arr) {
    priority_queue<int> maxHeap;
    // Populate a max-heap (priority queue) with the elements from the array
    for(int i : arr) {
        maxHeap.push(i);
    }
    // Extract elements from the max-heap and place them in the array in ascending order
    for(int i = arr.size() - 1; i >= 0; i--) {
        arr[i] = maxHeap.top();
        maxHeap.pop();
    }
}

// Function to print the elements of an array
void printArray(vector<int> &arr) {
    cout<<"The Array Elements: "<<endl;
    for(int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}

int main() {
    vector<int> arr = {34, 43, 54, 21, 44, 35, 71, 55, 29, 93};
    printArray(arr);

    cout<<endl<<"Using Heap Sort Algorithm: "<<endl;
    heapSort(arr);
    printArray(arr);

    arr = {34, 43, 54, 21, 44, 35, 71, 55, 29, 93};
    cout<<endl<<"Using Heap Sort Algorithm using Priority Queue: "<<endl;
    heapSortPriorityQueue(arr);
    printArray(arr);

    return 0;
}
