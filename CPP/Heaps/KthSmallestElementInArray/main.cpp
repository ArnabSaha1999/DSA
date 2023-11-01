#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//Approach 1: Function to find the kth smallest element in the array using a brute force approach
int kthSmallestElementBruteForce(vector<int> arr, int k) {
    int size = arr.size();
    // Check if k is out of range or invalid
    if(k <= 0 || k > size) {
        return -1;
    }
    // Sort the array in ascending order and return the kth smallest element
    sort(arr.begin(), arr.end());
    // Return the Kth Smallest Element
    return arr[k - 1];
}

//Approach 2: Function to find the kth smallest element in the array using a max heap
int kthSmallestElementMaxHeap(vector<int> &arr, int k) {
    int size = arr.size();
    // Check if k is out of range or invalid
    if(k <= 0 || k > size) {
        return -1;
    }
    // Create a max heap (priority queue) and insert elements
    priority_queue<int> maxHeap;
    for(int i : arr) {
        maxHeap.push(i);
    }
    // Remove elements from the max heap until the kth smallest element is found
    while(k != maxHeap.size()) {
        maxHeap.pop();
    }
    // Return the kth smallest element
    return maxHeap.top();
}

//Approach 3: Function to find the kth smallest element in the array using a min heap
int kthSmallestElementMinHeap(vector<int> &arr, int k) {
    int size = arr.size();
    // Check if k is out of range or invalid
    if(k <= 0 || k > size) {
        return -1;
    }
    // Create a min heap (priority queue) and insert elements
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i : arr) {
        minHeap.push(i);
    }
    // Remove elements from the min heap until the kth smallest element is found
    while(--k != 0) {
        minHeap.pop();
    }
    // Return the kth smallest element
    return minHeap.top();
}

//Approach 4: Function to find the kth smallest element in the array using a max heap (Optimized Approach)
int kthSmallestElementOptimized(vector<int> &arr, int k) {
    int size = arr.size();
    // Check if the value of k is out of range or invalid
    if(k <= 0 || k > size) {
        return -1;
    }
    // Create a max heap to maintain the k smallest elements
    priority_queue<int> maxHeap;
    // Insert the first k elements into the max heap
    for(int i = 0; i < k; i++) {
        maxHeap.push(arr[i]);
    }
    // Iterate through the remaining elements in the array
    for(int i = k; i < arr.size(); i++) {
        // If the current element is smaller than the current maximum in the heap
        if(arr[i] < maxHeap.top()) {
            // Replace the current maximum with the smaller element
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }
    // The top element of the max heap is the kth smallest element
    return maxHeap.top();
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
    cout<<endl<<"The "<<k<<" smallest element using Brute Force Approach: "<<kthSmallestElementBruteForce(arr, k)<<endl;
    cout<<endl<<"The "<<k<<" smallest element using Max Heap Approach: "<<kthSmallestElementMaxHeap(arr, k)<<endl;
    cout<<endl<<"The "<<k<<" smallest element using Min Heap Approach: "<<kthSmallestElementMinHeap(arr, k)<<endl;
    cout<<endl<<"The "<<k<<" smallest element using the Optimized Approach: "<<kthSmallestElementOptimized(arr, k)<<endl;

    return 0;
}
