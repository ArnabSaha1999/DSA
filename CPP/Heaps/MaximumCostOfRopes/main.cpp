#include<iostream>
#include<queue>

using namespace std;

//Approach 1: Function to find the maximum rope cost using a brute force approach
long long maxRopeCostBruteForce(long long arr[], long long n) {
    long long totalCost = 0;
    while(n > 1) {
        // Find the two largest elements in the array
        long long firstLargestIndex = 0, secondLargestIndex = 1;
        // Ensure that firstLargestIndex contains the index of the larger element
        if(arr[firstLargestIndex] < arr[secondLargestIndex]) {
            swap(firstLargestIndex, secondLargestIndex);
        }
        for(long long i = 2; i < n; i++) {
            // If the current element is larger than the current largest element (firstLargestIndex),
            // update both firstLargestIndex and secondLargestIndex accordingly
            if(arr[i] > arr[firstLargestIndex]) {
                secondLargestIndex = firstLargestIndex;
                firstLargestIndex = i;
            } else if(arr[i] > arr[secondLargestIndex]) {
                // If the current element is larger than the second largest element but not the largest,
                // update secondLargestIndex
                secondLargestIndex = i;
            }
        }
        // Calculate the cost of merging the two largest elements
        long long newElement = arr[firstLargestIndex] + arr[secondLargestIndex];
        totalCost += newElement;
        // Update the array by replacing the two largest elements with the newElement
        arr[firstLargestIndex] = newElement;
        arr[secondLargestIndex] = arr[n - 1];
        n--;
    }
    // Return the total Rope Cost
    return totalCost;
}

//Approach 2: Function to find the maximum rope cost using an optimized approach with a max heap
long long maxRopeCost(long long arr[], long long n) {
    long long totalCost = 0;
    priority_queue<long long> maxHeap;
    // Populate the max-heap with the elements from the input array
    for(long i = 0; i < n; i++) {
        maxHeap.push(arr[i]);
    }
    // Continue merging the largest elements until only one element remains in the heap
    while(maxHeap.size() > 1) {
        long long firstLargestElement = maxHeap.top();
        maxHeap.pop();
        long long secondLargestElement = maxHeap.top();
        maxHeap.pop();
        // Calculate the cost of merging the two largest elements
        long long newElement = firstLargestElement + secondLargestElement;
        totalCost += newElement;
        // Insert the merged element back into the max-heap
        maxHeap.push(newElement);
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
    long long arr[] = {4, 3, 2, 6};
    long long size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);

    cout<<endl<<"The Minimum Rope Cost using the Brute Force Approach: "<<maxRopeCostBruteForce(arr, size)<<endl;

    long long newArr[] = {4, 3, 2, 6};
    size = sizeof(newArr) / sizeof(newArr[0]);
    cout<<endl<<"The Minimum Rope Cost using the Optimized Min Heap: "<< maxRopeCost(newArr, size)<<endl;

    return 0;
}
