#include<iostream>
#include<vector>

using namespace std;

//Approach 1: Brute force approach to find the pivot index.
int findPivotBruteForce(vector<int> &nums) {
    for(int i = 0; i < nums.size(); i++) {
        int leftSum = 0, rightSum = 0;
        // Calculate the sum of elements on the left side of the current index
        for(int j = 0; j < i; i++) {
            leftSum += nums[j];
        }
        // Calculate the sum of elements on the right side of the current index
        for(int k = i+1; k < nums.size(); k++) {
            rightSum += nums[k];
        }
        // Check if the left sum is equal to the right sum
        if(leftSum == rightSum) {
            return i;
        }
    }
    return -1; // No pivot index found
}

//Approach 2: Optimized approach to find the pivot index
int findPivot(vector<int> &nums) {
    int totalSum = 0, leftSum = 0;
    // Calculate the total sum of the array
    for(int num : nums) {
        totalSum += num;
    }
    // Iterate over the array and find the pivot index
    for(int i = 0; i < nums.size(); i++) {
        int rightSum = totalSum - leftSum - nums[i];
        // Check if the left sum is equal to the right sum
        if(rightSum == leftSum) {
            return i;
        }
        // Update the left sum for the next iteration
        leftSum += nums[i];
    }
    return -1; // No pivot index found
}

int main() {
    vector<int> arr = {1,7,3,6,5,6};
    cout<<"The Pivot index of the array is "<<findPivot(arr)<<endl;
    return 0;
}
