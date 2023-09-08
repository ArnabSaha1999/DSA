#include<iostream>
#include<vector>
#include<deque>

using namespace std;

//Approach 1: Function to find the maximum element in each sliding window of size 'k' using brute force approach.
vector<int> maxSlidingWindowBruteForce(vector<int> &nums, int k) {
    // Calculate the number of sliding windows.
    int size = nums.size() - k + 1;
    vector<int> ans(size);
    for(int i = 0; i < size; i++) {
        // Initialize the maximum element with the first element in the window.
        int maxVal = nums[i];
        // Iterate through the elements within the current sliding window to find the maximum.
        for(int j = i + 1; j < i + k; j++) {
            // Update the maximum element if a larger element is found.
            maxVal = max(maxVal, nums[j]);
        }
        // Store the maximum element for the current window in the result vector.
        ans[i] = maxVal;
    }
    return ans;
}

//Approach 2: Function to find the maximum element in each sliding window of size 'k' using deque-based approach.
vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    // Deque to store indices of maximum elements.
    deque<int> maxDeque;
    vector<int> ans;
    for(int i = 0; i < nums.size(); i++) {
        // Remove elements from the front of the deque that are out of the current window.
        while(!maxDeque.empty() && maxDeque.front() < i - k + 1) {
            maxDeque.pop_front();
        }
        // Remove elements from the back of the deque that are smaller than the current element.
        while(!maxDeque.empty() && nums[maxDeque.back()] < nums[i]) {
            maxDeque.pop_back();
        }
        // Add the current index to the deque.
        maxDeque.push_back(i);
        // Once the window size reaches 'k', find and store the maximum element
        if(i >= k - 1) {
            // Add the maximum element for the current window to the result vector.
            ans.push_back(nums[maxDeque.front()]);
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    cout<<"The input Array: "<<endl;
    for(int n : nums) {
        cout<<n<<" ";
    } cout<<endl;

    cout<<"The Maximum element in "<<k<<" window using brute force approach: "<<endl;
    vector<int> ans = maxSlidingWindowBruteForce(nums, k);
    for(int a : ans) {
        cout<<a<<" ";
    } cout<<endl;

    cout<<"The Maximum element in "<<k<<" window using Dequeue approach: "<<endl;
    ans = maxSlidingWindow(nums, k);
    for(int a : ans) {
        cout<<a<<" ";
    } cout<<endl;

    return 0;
}
