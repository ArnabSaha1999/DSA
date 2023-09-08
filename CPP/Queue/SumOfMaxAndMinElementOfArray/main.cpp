#include<iostream>
#include<vector>
#include<deque>
#include<climits>

using namespace std;

//Approach 1: Function to calculate the sum of maximum and minimum elements in subarrays of size 'k' using brute force approach.
long long sumOfMaxAndMinBruteForce(vector<int> arr, int n, int k) {
    // Calculate the number of subarrays.
    int size = n - k + 1;
    long long sum = 0;
    for(int i = 0; i < size; i++) {
        // Initialize the maximum element.
        int maxi = INT_MIN;
        // Initialize the minimum element.
        int mini = INT_MAX;
        // Iterate through the subarray of size 'k' to find the maximum and minimum elements.
        for(int j = i; j < i + k; j++) {
            if(arr[j] > maxi) {
                // Update the maximum element.
                maxi = arr[j];
            }
            if(arr[j] < mini) {
                // Update the minimum element.
                mini = arr[j];
            }
        }
        // Add the sum of maximum and minimum to the result.
        sum += maxi + mini;
    }
    return sum;
}

//Approach 2: Function to calculate the sum of maximum and minimum elements in subarrays of size 'k' using deque-based approach.
long long sumOfMaxAndMin(vector<int> arr, int n, int k) {
    long long sum = 0;
    // Deque to store indices of maximum elements.
    deque<int> maxDeque;
    // Deque to store indices of minimum elements.
    deque<int> minDeque;
    for(int i = 0; i < n; i++) {
        // Remove elements from the front of the deque if they are out of the current window.
        while(!maxDeque.empty() && maxDeque.front() < i - k + 1) {
            maxDeque.pop_front();
        }
        // Remove elements from the front of the deque if they are out of the current window.
        while(!minDeque.empty() && minDeque.front() < i - k + 1) {
            minDeque.pop_front();
        }
        // Remove elements from the back of the deque that are smaller than the current element.
        while(!maxDeque.empty() && arr[maxDeque.back()] < arr[i]) {
            maxDeque.pop_back();
        }
        // Remove elements from the back of the deque that are greater than the current element.
        while(!minDeque.empty() && arr[minDeque.back()] > arr[i]) {
            minDeque.pop_back();
        }
        // Add the current index to the maximum & minimum deque.
        maxDeque.push_back(i);
        minDeque.push_back(i);
        // Add the sum of maximum and minimum to the result when index is equal or greater than k group
        if(i >=  k - 1) {
            sum += arr[maxDeque.front()] + arr[minDeque.front()];
        }
    }
    return sum;
}

int main() {
    vector<int> arr = {2,4,7,3,8,1};
    int k = 4;
    cout<<"The input Array: "<<endl;
    for(int a : arr) {
        cout<<a<<" ";
    } cout<<endl;

    cout<<"The Sum of Maximum and Minimum in "<<k<<" group sub-array using Brute Force approach: "<<sumOfMaxAndMinBruteForce(arr, arr.size(), k)<<endl;
    cout<<"The Sum of Maximum and Minimum in "<<k<<" group sub-array using Queue approach: "<<sumOfMaxAndMin(arr, arr.size(), k)<<endl;

    return 0;
}
