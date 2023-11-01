#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//Approach 1: Function to find the kth largest sum of subarrays using a brute force approach
int getKthLargestSumBruteForce(vector<int> &arr, int k) {
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
    // Sort the sums and return the kth largest sum
	sort(ans.begin(), ans.end());
    // Return the kth largest sum (zero-based index)
	return ans[ans.size() - k];
}

//Approach 2: Function to find the kth largest sum of subarrays using a max heap
int getKthLargestSumMaxHeap(vector<int> &arr, int k) {
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
    // Remove the k - 1 largest sums
	while(--k != 0) {
		maxHeap.pop();
	}
    // Return the kth largest sum
	return maxHeap.top();
}

//Approach 3: Function to find the kth largest sum of subarrays using a min heap
int getKthLargestSumMinHeap(vector<int> &arr, int k) {
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
	while(minHeap.size() != k) {
		minHeap.pop();
	}
    // Return the kth largest sum
	return minHeap.top();
}

//Approach 4: Function to find the kth largest sum of subarrays using an optimized approach
int getKthLargestSumOptimized(vector<int> &arr, int k) {
	int size = arr.size();
    // Check if k is out of range or invalid
	if(k <= 0 || k > (size * (size + 1)) / 2) {
		return -1;
	}
	priority_queue<int, vector<int>, greater<int>> minHeap;
    // Calculate and maintain a max heap with the k largest sums
	for(int i = 0; i < size; i++) {
		int sum = 0;
		for(int j = i; j < size; j++) {
			sum += arr[j];
            // Insert the current sum if the heap size is less than k
			if(minHeap.size() < k) {
				minHeap.push(sum);
			} else if(minHeap.top() < sum) {
                // Replace the smallest sum in the heap with a larger sum
				minHeap.pop();
				minHeap.push(sum);
			}
		}
	}
    // Return the kth largest sum
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
    vector<int> arr = {3,4,2,8,9,1};
    int k = 4;
    printArray(arr);
    cout<<endl<<"The "<<k<<" largest sum of subarray using Brute Force Approach: "<<getKthLargestSumBruteForce(arr, k)<<endl;
    cout<<endl<<"The "<<k<<" largest sum of subarray using Max Heap Approach: "<<getKthLargestSumMaxHeap(arr, k)<<endl;
    cout<<endl<<"The "<<k<<" largest sum of subarray using Min Heap Approach: "<<getKthLargestSumMinHeap(arr, k)<<endl;
    cout<<endl<<"The "<<k<<" largest sum of subarray using Optimized Approach: "<<getKthLargestSumOptimized(arr, k)<<endl;

    return 0;
}
