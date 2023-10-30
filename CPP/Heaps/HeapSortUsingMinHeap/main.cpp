#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Function to perform min-heapify operation
void minHeapify(vector<int> &arr, int size, int index) {
    while(index < size) {
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;
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

// Function to reverse an array
void reverse(vector<int> &arr, int size) {
    for(int start = 0, end = size - 1; start < end; start++, end--) {
        swap(arr[start], arr[end]);
    }
}

//Approach 1: Function to perform heap sort with the help of iterative Min-Heapify function
void heapSort(vector<int> &arr) {
    // Build a min-heap from the input array
    for(int i = arr.size() - 1 / 2; i >= 0; i--) {
        minHeapify(arr, arr.size(), i);
    }
    // Sort the array by repeatedly extracting the minimum element (root of the min-heap)
    for(int i = arr.size() - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        // Re-heapify the remaining elements to maintain the min-heap property
        minHeapify(arr, i, 0);
    }
    // Reverse the array to obtain the sorted result in ascending order
    reverse(arr, arr.size());
}

//Approach 2: Function to perform heap sort using a min-heap implemented with a priority queue
void heapSortPriorityQueue(vector<int> &arr) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // Populate a min-heap (priority queue) with the elements from the array
    for(int i : arr) {
        minHeap.push(i);
    }
    // Extract elements from the min-heap and place them in the array in ascending order
    for(int i = 0; i < arr.size(); i++) {
        arr[i] = minHeap.top();
        minHeap.pop();
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
