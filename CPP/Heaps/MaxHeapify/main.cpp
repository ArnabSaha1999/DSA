#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Function to perform max-heapify iteratively
void maxHeapifyIterative(vector<int> &arr, int size, int index) {
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

//Approach 1: Function to build a max heap iteratively
void buildMaxHeapItartively(vector<int> &arr) {
    int size = arr.size();
    // Starting from the last non-leaf node (size - 1) / 2, iterate down to the root (0) of the heap
    // and apply the maxHeapifyIterative function at each node to build a max heap
    for(int i = (size - 1) / 2; i >= 0; i--) {
        maxHeapifyIterative(arr, size, i);
    }
}

// Function to perform max-heapify recursively
void maxHeapifyRecursive(vector<int> &arr, int size, int index) {
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
        maxHeapifyRecursive(arr, size, largestIndex);
    } else {
        // Max-heap property is preserved, so return the call stack
        return;
    }
}

//Approach 2: Function to build a max heap recursively
void buildMaxHeapRecursively(vector<int> &arr) {
    int size = arr.size();
    // Starting from the last non-leaf node (size - 1) / 2, iterate down to the root (0) of the heap
    // and apply the maxHeapifyRecurstive function at each node to build a max heap
    for(int i = (size - 1) / 2; i >= 0; i--) {
        maxHeapifyIterative(arr, size, i);
    }
}

//Approach 3: Function to build a max heap using STL Priority Queue (Max Heap)
void maxHeapifyPriorityQueue(vector<int> &arr, int size, priority_queue<int> &pq) {
    for(int i = 0; i < size; i++) {
        pq.push(arr[i]);
    }
}

// Function to print the elements of an array
void printArr(vector<int> arr) {
    cout<<"The Array Elements: "<<endl;
    for(int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}

int main() {
    vector<int> arr = {34, 43, 54, 21, 44, 35, 71, 55, 29, 93};
    printArr(arr);
    buildMaxHeapItartively(arr);
    cout<<endl<<"Using the Max Heapify Itarative Approach: "<<endl;
    printArr(arr);

    arr = {34, 43, 54, 21, 44, 35, 71, 55, 29, 93};
    buildMaxHeapRecursively(arr);
    cout<<endl<<"Using the Max Heapify Recursive Approach: "<<endl;
    printArr(arr);

    arr = {34, 43, 54, 21, 44, 35, 71, 55, 29, 93};
    priority_queue<int> pq;
    maxHeapifyPriorityQueue(arr, arr.size(), pq);
    cout<<endl<<"Using the Priority Queue to create Max Heap: "<<endl;
    while(!pq.empty()) {
        cout<<pq.top()<<" ";
        pq.pop();
    } cout<<endl;

    return 0;
}
