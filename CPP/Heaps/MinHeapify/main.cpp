#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Function to perform min-heapify iteratively
void minHeapifyIterarive(vector<int> &arr, int size, int index) {
    while(index < size) {
        int leftIndex = index * 2 + 1;
        int rightIndex = index * 2 + 2;
        int smallestIndex = index;
        // Check if the left child exists and is smaller than the current smallest element
        if(leftIndex < size && arr[leftIndex] < arr[smallestIndex]) {
            smallestIndex = leftIndex;
        }
        // Check if the right child exists and is smaller than the current smallest element
        if(rightIndex < size && arr[rightIndex] < arr[smallestIndex]) {
            smallestIndex = rightIndex;
        }
        // If the smallest child is not the current element, swap them to maintain the min-heap property
        if(smallestIndex != index) {
            swap(arr[index], arr[smallestIndex]);
            index = smallestIndex;
        } else {
            // Min-heap property is preserved, so exit the loop
            return;
        }
    }
}

//Approach 1: Function to build a min heap iteratively
void buildMinHeapIteratively(vector<int> &arr) {
    int size = arr.size();
    // Starting from the last non-leaf node (size - 1) / 2, iterate down to the root (0) of the heap
    // and apply the minHeapifyIterative function at each node to build a min heap
    for(int i = (size - 1) / 2; i >= 0; i--) {
        minHeapifyIterarive(arr, size, i);
    }
}

// Function to perform min-heapify recursively
void minHeapifyRecursive(vector<int> &arr, int size, int index) {
    int leftIndex = index * 2 + 1;
    int rightIndex = index * 2 + 2;
    int smallestIndex = index;
    // Check if the left child exists and is smaller than the current smallest element
    if(leftIndex < size && arr[leftIndex] < arr[smallestIndex]) {
        smallestIndex = leftIndex;
    }
    // Check if the right child exists and is smaller than the current smallest element
    if(rightIndex < size && arr[rightIndex] < arr[smallestIndex]) {
        smallestIndex = rightIndex;
    }
    // If the smallest child is not the current element, swap them to maintain the min-heap property
    if(smallestIndex != index) {
        swap(arr[index], arr[smallestIndex]);
        minHeapifyRecursive(arr, size, smallestIndex);
    } else {
        // Min-heap property is preserved, so return the call stack
        return;
    }
}

//Approach 2: Function to build a min heap recursively
void buildMinHeapRecursively(vector<int> &arr) {
    int size = arr.size();
    // Starting from the last non-leaf node (size - 1) / 2, iterate down to the root (0) of the heap
    // and apply the minHeapifyRecursive function at each node to build a min heap
    for(int i = (size - 1) / 2; i >= 0; i--) {
        minHeapifyRecursive(arr, size, i);
    }
}

//Approach 3: Function to build a min heap using STL Priority Queue (Min Heap)
void minHeapifyPriorityQueue(vector<int> &arr, int size, priority_queue<int, vector<int>, greater<int>> &pq) {
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
    buildMinHeapIteratively(arr);
    cout<<endl<<"Using the Min Heapify Itarative Approach: "<<endl;
    printArr(arr);

    arr = {34, 43, 54, 21, 44, 35, 71, 55, 29, 93};
    buildMinHeapRecursively(arr);
    cout<<endl<<"Using the Min Heapify Recursive Approach: "<<endl;
    printArr(arr);

    arr = {34, 43, 54, 21, 44, 35, 71, 55, 29, 93};
    priority_queue<int, vector<int>, greater<int>> pq;
    minHeapifyPriorityQueue(arr, arr.size(), pq);
    cout<<endl<<"Using the Priority Queue to create Min Heap: "<<endl;
    while(!pq.empty()) {
        cout<<pq.top()<<" ";
        pq.pop();
    } cout<<endl;

    return 0;
}
