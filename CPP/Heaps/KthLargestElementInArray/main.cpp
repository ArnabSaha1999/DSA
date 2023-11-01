#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//Approach 1: Function to find the kth largest element in an array using a brute force approach
int findKthLargestElementBruteForce(vector<int> arr, int k) {
    int size = arr.size();
    // Check if k is out of range or invalid
    if(k <= 0 || k > size) {
        return -1;
    }
    // Sort the array in ascending order
    sort(arr.begin(), arr.end());
    // Return the kth largest element (zero-based index)
    return arr[size - k];
}

//Approach 2: Function to find the kth largest element in an array using a max heap
int findKthLargestElementMaxHeap(vector<int> &arr, int k) {
    int size = arr.size();
    // Check if k is out of range or invalid
    if(k <= 0 || k > size) {
        return -1;
    }
    priority_queue<int> maxHeap;
    // Populate a max heap with array elements
    for(int i : arr) {
        maxHeap.push(i);
    }
    // Remove the k - 1 largest elements
    while(--k != 0) {
        maxHeap.pop();
    }
    // Return the kth largest element
    return maxHeap.top();
}

//Approach 3: Function to find the kth largest element in an array using a min heap
int findKthLargestElementMinHeap(vector<int> &arr, int k) {
    int size = arr.size();
    // Check if k is out of range or invalid
    if(k <= 0 || k > size) {
        return -1;
    }
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // Populate a min heap with array elements
    for(int i : arr) {
        minHeap.push(i);
    }
    // Remove elements until the heap size is k
    while(minHeap.size() != k) {
        minHeap.pop();
    }
    // Return the kth largest element
    return minHeap.top();
}

//Approach 4: Function to find the kth largest element in an array using a min heap (Optimized Approach)
int findKthLargestElementOptimized(vector<int> &arr, int k) {
    int size = arr.size();
    // Check if the value of k is out of range or invalid
    if(k <= 0 || k > size) {
        return -1;
    }
    // Create a min heap to maintain the k largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i = 0; i < k; i++) {
        minHeap.push(arr[i]);
    }
    // Insert the first k elements into the min heap
    for(int i = k; i < arr.size(); i++) {
        // If the current element is greater than the current minimum in the heap
        if(arr[i] > minHeap.top()) {
            // Replace the current minimum with the larger element
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }
    // The top element of the min heap is the kth largest element
    return minHeap.top();
}

// Function to print the elements of an array
void printArray(vector<int> arr) {
    cout<<"The Array Elements: "<<endl;
    for(int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}

int main() {
    vector<int> arr = {3,2,1,5,6,4};
    int k = 3;
    printArray(arr);
    cout<<endl<<"The "<<k<<" largest element using Brute Force Approach: "<<findKthLargestElementBruteForce(arr, k)<<endl;
    cout<<endl<<"The "<<k<<" largest element using Max Heap Approach: "<<findKthLargestElementMaxHeap(arr, k)<<endl;
    cout<<endl<<"The "<<k<<" largest element using Min Heap Approach: "<<findKthLargestElementMinHeap(arr, k)<<endl;
    cout<<endl<<"The "<<k<<" largest element using Optimized Approach: "<<findKthLargestElementOptimized(arr, k)<<endl;

    return 0;
}
