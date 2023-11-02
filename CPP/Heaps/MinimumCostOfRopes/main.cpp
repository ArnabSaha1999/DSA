#include<iostream>
#include<queue>

using namespace std;

//Approach 1: Function to find the minimum rope cost using a brute force approach
long long minRopeCostBruteForce(long long arr[], long long n) {
    long long totalCost = 0;
    while(n > 1) {
        // Find the two smallest elements in the array
        long long firstSmallestIndex = 0, secondSmallestIndex = 1;
        // Ensure that firstSmallestIndex contains the index of the smaller element
        if(arr[firstSmallestIndex] > arr[secondSmallestIndex]) {
            swap(firstSmallestIndex, secondSmallestIndex);
        }
        for(long long i = 2; i < n; i++) {
            // If the current element is smaller than the current smallest element (firstSmallestIndex),
            // update both firstSmallestIndex and secondSmallestIndex accordingly
            if(arr[i] < arr[firstSmallestIndex]) {
                secondSmallestIndex = firstSmallestIndex;
                firstSmallestIndex = i;
            } else if(arr[i] < arr[secondSmallestIndex]) {
                // If the current element is smaller than the second smallest element but not the smallest,
                // update secondSmallestIndex
                secondSmallestIndex = i;
            }
        }
        // Calculate the cost of merging the two smallest elements
        long long newElement = arr[firstSmallestIndex] + arr[secondSmallestIndex];
        totalCost += newElement;
        // Update the array by replacing the two smallest elements with the newElement
        arr[firstSmallestIndex] = newElement;
        arr[secondSmallestIndex] = arr[n - 1];
        n--;
    }
    // Return the total Rope Cost
    return totalCost;
}

//Approach 2: Function to find the minimum rope cost using an optimized approach with a min heap
long long minRopeCost(long long arr[], long long n) {
    long long totalCost = 0;
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    // Populate the min-heap with the elements from the input array
    for(long i = 0; i < n; i++) {
        minHeap.push(arr[i]);
    }
    // Continue merging the smallest elements until only one element remains in the heap
    while(minHeap.size() > 1) {
        long long firstSmallestElement = minHeap.top();
        minHeap.pop();
        long long secondSmallestElement = minHeap.top();
        minHeap.pop();
        // Calculate the cost of merging the two smallest elements
        long long newElement = firstSmallestElement + secondSmallestElement;
        totalCost += newElement;
        // Insert the merged element back into the min-heap
        minHeap.push(newElement);
    }
    // Return the total Rope Cost
    return totalCost;
}

// Function to print the elements of an array
void printArray(long long arr[], int size) {
    cout<<"The Array Elements: "<<endl;
    for(long long i = 0; i < size; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}

int main() {
    long long arr[] = {4, 2, 7, 6, 9};
    long long size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);

    cout<<endl<<"The Minimum Rope Cost using the Brute Force Approach: "<<minRopeCostBruteForce(arr, size)<<endl;

    long long newArr[] = {4, 2, 7, 6, 9};
    size = sizeof(newArr) / sizeof(newArr[0]);
    cout<<endl<<"The Minimum Rope Cost using the Optimized Min Heap: "<< minRopeCost(newArr, size)<<endl;

    return 0;
}
