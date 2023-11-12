#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//Approach 1: Function to merge k sorted arrays using a brute force approach
vector<int> mergeKSortedArraysBruteForce(vector<vector<int>>&kArrays, int k) {
    vector<int> ans;
    // Iterate through each array and element to collect all values
    for(int i = 0; i < kArrays.size(); i++) {
        for(int j = 0; j < kArrays[i].size(); j++) {
            ans.push_back(kArrays[i][j]);
        }
    }
    // Sort the collected values to obtain the final merged array
    sort(ans.begin(), ans.end());
    return ans;
}

// Element class to represent the value, row index, and column index
class Element {
    public:
    int value;
    int rowIndex;
    int colIndex;
    Element(int value, int rowIndex, int colIndex) {
        this->value = value;
        this->rowIndex = rowIndex;
        this->colIndex = colIndex;
    }
};

// CompareElement class for custom comparison in the min-heap
class CompareElement {
    public:
    bool operator() (Element *first, Element *second) {
        return first->value > second->value;
    }
};

//Approach 2: Function to merge k sorted arrays using a min-heap
vector<int> mergeKSortedArraysUsingHeap(vector<vector<int>>&kArrays, int k) {
    vector<int> ans;
    // Create a min-heap using Element objects
    priority_queue<Element*, vector<Element*>, CompareElement> minHeap;
    // Initialize the min-heap with the first element from each array
    for(int i = 0; i < k; i++) {
        Element *newElement = new Element(kArrays[i][0], i, 0);
        minHeap.push(newElement);
    }
    // Continue merging elements until the min-heap is empty
    while(!minHeap.empty()) {
        Element *temp = minHeap.top();
        ans.push_back(temp->value);
        minHeap.pop();
        int rowIndex = temp->rowIndex;
        int colIndex = temp->colIndex;
        // Add the next element from the same array to the min-heap if available
        if(colIndex + 1 < kArrays[rowIndex].size()) {
            Element *newElement = new Element(kArrays[rowIndex][colIndex + 1], rowIndex, colIndex + 1);
            minHeap.push(newElement);
        }
    }
    return ans;
}

// Function to merge two sorted arrays
vector<int> mergeTwoSortedArray(vector<int> &arr1, int m, vector<int> &arr2, int n) {
    vector<int> ans(m + n);
    int i = 0, j = 0, k = 0;
    // Merge the two arrays while maintaining the sorted order
    while(i < m && j < n) {
        if(arr1[i] <= arr2[j]) {
            ans[k++] = arr1[i++];
        } else {
            ans[k++] = arr2[j++];
        }
    }
    // Add any remaining elements from both arrays
    while(i < m) {
        ans[k++] = arr1[i++];
    }
    while(j < n) {
        ans[k++] = arr2[j++];
    }
    return ans;
} 

// Recursively merge k sorted arrays using a divide and conquer approach
vector<int> mergeKSortedArrayHelper(vector<vector<int>> &arrays, int start, int end) {
    // Base case: If there's only one array left to merge, return it
    if(start >= end) {
        return arrays[start];
    }
    // If there are two arrays, merge them using the mergeTwoSortedArrays function
    if(start + 1 == end) {
        return mergeTwoSortedArray(arrays[start], arrays[start].size(), arrays[end], arrays[end].size());
    }
    // Find the middle point for splitting the arrays
    int mid = start + (end - start) / 2;
    // Recursively merge the left and right halves
    vector<int> leftArray = mergeKSortedArrayHelper(arrays, start, mid);
    vector<int> rightArray = mergeKSortedArrayHelper(arrays, mid + 1, end);
    // Merge the two sorted halves
    return mergeTwoSortedArray(leftArray, leftArray.size(), rightArray, rightArray.size());
}

//Approach 3: Merge k sorted arrays using a divide and conquer approach
vector<int> mergeKSortedArraysDivideAndConquer(vector<vector<int>>&kArrays, int k) {
    return mergeKSortedArrayHelper(kArrays, 0, k - 1);
}

// Function to print the elements of an array
void printArr(vector<int> arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}

int main() {
    vector<vector<int>> matrix = {
        {1,5,9},
        {45,90},
        {2,6,78,100,243}
    };
    cout<<"The Input Vector: "<<endl;
    for(vector<int> arr : matrix) {
        printArr(arr);
    }

    cout<<endl<<"Using the Brute Force Approach: "<<endl;
    vector<int> ans = mergeKSortedArraysBruteForce(matrix, matrix.size());
    printArr(ans);

    cout<<endl<<"Using the Min Heap Approach: "<<endl;
    ans = mergeKSortedArraysUsingHeap(matrix, matrix.size());
    printArr(ans);

    cout<<endl<<"Using the Divide And Conquer Approach: "<<endl;
    ans = mergeKSortedArraysDivideAndConquer(matrix, matrix.size());
    printArr(ans);

    return 0;
}
