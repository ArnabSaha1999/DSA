#include<iostream>
#include<vector>

using namespace std;

// Function to perform max-heapify iteratively
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

//Approach 1: Function to merge two max heaps represented by vectors a and b
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    vector<int> ans;
    // Copy elements from heap 'a' to the merged heap 'ans'
    for(int i = 0; i < n; i++) {
        ans.push_back(a[i]);
    }
    // Copy elements from heap 'b' to the merged heap 'ans'
    for(int i = 0; i < m; i++) {
        ans.push_back(b[i]);
    }
    int size = ans.size();
    // Perform max-heapify on each node starting from the last non-leaf node
    for(int i = (size - 1) / 2; i >= 0; i--) {
        maxHeapify(ans, size, i);
    }
    return ans;
}

// Function to print the elements of an array
void printArray(vector<int> arr) {
    cout<<"The Array Elements: "<<endl;
    for(int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}

int main() {
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};
    
    printArray(a);
    printArray(b);
    
    cout<<endl<<"The Merged Max Heap: "<<endl;
    vector<int> ans = mergeHeaps(a, b, a.size(), b.size());
    printArray(ans);

    return 0;
}
