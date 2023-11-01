#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//Approach 1: Function to find the kth smallest sum of subarrays using a brute force approach
int getKthSmallestSumBruteForce(vector<int> &arr, int k) {
	int size = arr.size();
    // Check if k is out of range or invalid
	if(k <= 0 || k > (size * (size + 1)) / 2) {
		return -1;
	}
	vector<int> ans;
    // Calculate all possible subarray sums
	for(int i = 0; i < size; i++) {
		int sum = 0;
		for(int j = i; j < size; j++) {
			sum += arr[j];
			ans.push_back(sum);
		}
	}
    // Sort the sums and return the kth smallest sum
	sort(ans.begin(), ans.end());
    // Return the Kth Smallest Element
	return ans[k - 1];
}

//Approach 2: Function to find the kth smallest sum of subarrays using a max heap
int getKthSmallestSumMaxHeap(vector<int> &arr, int k) {
	int size = arr.size();
    // Check if k is out of range or invalid
	if(k <= 0 || k > (size * (size + 1)) / 2) {
		return -1;
	}
	priority_queue<int> maxHeap;
    // Calculate and insert all subarray sums into a max heap
	for(int i = 0; i < size; i++) {
		int sum = 0;
		for(int j = i; j < size; j++) {
			sum += arr[j];
			maxHeap.push(sum);
		}
	}
    // Remove the k - 1 smallest sums
	while(maxHeap.size() != k) {
        maxHeap.pop();
    }
    // Return the kth smallest sum
	return maxHeap.top();
}

//Approach 3: Function to find the kth smallest sum of subarrays using a min heap
int getKthSmallestSumMinHeap(vector<int> &arr, int k) {
	int size = arr.size();
    // Check if k is out of range or invalid
	if(k <= 0 || k > (size * (size + 1)) / 2) {
		return -1;
	}
	priority_queue<int, vector<int>, greater<int>> minHeap;
    // Calculate and insert all subarray sums into a min heap
	for(int i = 0; i < size; i++) {
		int sum = 0;
		for(int j = i; j < size; j++) {
			sum += arr[j];
			minHeap.push(sum);
		}
	}
    // Remove elements until the heap size is k
	while(--k != 0) {
		minHeap.pop();
	}
    // Return the kth smallest sum
	return minHeap.top();
}

//Approach 4: Function to find the kth smallest sum of subarrays using an optimized approach
int getKthSmallestSumOptimized(vector<int> &arr, int k) {
	int size = arr.size();
    // Check if k is out of range or invalid
	if(k <= 0 || k > (size * (size + 1)) / 2) {
		return -1;
	}
	priority_queue<int> maxHeap;
    // Calculate and maintain a max heap with the k smallest sums
	for(int i = 0; i < size; i++) {
		int sum = 0;
		for(int j = i; j < size; j++) {
			sum += arr[j];
            // Insert the current sum if the heap size is less than k
			if(maxHeap.size() < k) {
				maxHeap.push(sum);
			} else if(maxHeap.top() > sum) {
                // Replace the largest sum in the heap with a smaller sum
				maxHeap.pop();
				maxHeap.push(sum);
			}
		}
	}
    // Return the kth smallest sum
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
    vector<int> arr = {3,4,2,8,9,1};
    int k = 4;
    printArray(arr);
    cout<<endl<<"The "<<k<<" smallest sum of subarray using Brute Force Approach: "<<getKthSmallestSumBruteForce(arr, k)<<endl;
    cout<<endl<<"The "<<k<<" smallest sum of subarray using Max Heap Approach: "<<getKthSmallestSumMaxHeap(arr, k)<<endl;
    cout<<endl<<"The "<<k<<" smallest sum of subarray using Min Heap Approach: "<<getKthSmallestSumMinHeap(arr, k)<<endl;
    cout<<endl<<"The "<<k<<" smallest sum of subarray using Optimized Approach: "<<getKthSmallestSumOptimized(arr, k)<<endl;

    return 0;
}
