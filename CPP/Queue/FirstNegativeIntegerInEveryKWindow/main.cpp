#include<iostream>
#include<vector>
#include<deque>

using namespace std;

//Approach 1: Function to find the first negative element in each k-sized window using a brute force approach
vector<int> firstNegativeBruteForce(vector<int> arr, int n, int k) {
    int size = n - k + 1;
    // Initialize the result vector with zeros
    vector<int> ans(size, 0);
    // Loop through all possible k-sized windows
    for(int i = 0; i < size; i++) {
        // Initialize a flag to check if a negative element is found
        bool isNegative = false;
        // Check each element within the current window
        for(int j = i; j < i + k; j++) {
            if(arr[j] < 0) {
                // If a negative element is found, store it in the result vector
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

//Approach 2: Function to find the first negative element in each k-sized window using a deque
vector<int> firstNegative(vector<int> arr, int n, int k) {
    deque<int> negativeindices;
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        // Remove indices that are no longer in the current window
        if(!negativeindices.empty() && negativeindices.front() < i - k + 1) {
            negativeindices.pop_front();
        }
        // If the current element is negative, add its index to the deque
        if(arr[i] < 0) {
            negativeindices.push_back(i);
        }
        // Once the window size reaches 'k', find and store the first negative element
        if(i >= k - 1) {
            if(!negativeindices.empty()) {
                ans.push_back(arr[negativeindices.front()]);
            } else {
                ans.push_back(0);
            }
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {-3, 4, 7, -4, 1, -2, 4};
    int k = 3;

    cout<<"The input array: "<<endl;
    for(int a : arr) {
        cout<<a<<" ";
    } cout<<endl;

    cout<<"The array of the first negative element in "<<k<<" size window using Brute Force: "<<endl;
    vector<int> ans = firstNegativeBruteForce(arr, arr.size(), k);
    for(int a : ans) {
        cout<<a<<" ";
    } cout<<endl;

    cout<<"The array of the first negative element in "<<k<<" size window using Deque: "<<endl;
    ans = firstNegativeBruteForce(arr, arr.size(), k);
    for(int a : ans) {
        cout<<a<<" ";
    } cout<<endl;

    return 0;
}
