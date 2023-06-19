#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

//Approach 1: Using Nested loops to find the pairs.
vector<vector<int>> tripletSum(vector<int> &arr, int n, int target) {
    set<vector<int>> uniqueCombination; //Set to store unique combinations
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) { 
                if(arr[i] + arr[j] + arr[k] == target) { // Found a triplet with the target sum
                    vector<int> temp = {arr[i], arr[j], arr[k]}; // Create a triplet
                    sort(temp.begin(), temp.end()); // Sort the triplet in ascending order, so no duplicates gets inserted
                    uniqueCombination.insert(temp); // Insert the sorted triplet into the set
                }
            }
        }
    }
    vector<vector<int>> ans(uniqueCombination.begin(), uniqueCombination.end()); // Convert the set to a vector
    return ans;
}

//Approach 2: Using Two Pointer Approach to find the pairs in optimized way.
vector<vector<int>> tripletSumOptimized(vector<int> &arr, int n, int target) {
    set<vector<int>>uniqueCombination; // Set to store unique combinations
    sort(arr.begin(), arr.end()); // Sort the array in ascending order
    for(int i = 0; i < n-2; i++) {
        int left = i+1, right = n-1; // Pointers for two-pointer approach
        while(left < right) {
            int currentSum = arr[i] + arr[left] + arr[right]; // Calculate the current sum
            if(currentSum == target) { // Found a triplet with the target sum
                vector<int> temp = {arr[i], arr[left], arr[right]};
                uniqueCombination.insert(temp); // Insert the triplet into the set
                left++; // Move the left pointer to the right to search for the next combination
                right--; // Move the right pointer to the left to search for the next combination
            } else if(currentSum < target) {
                left++; // Increment the left pointer to increase the sum
            } else{
                right--; // Decrement the right pointer to decrease the sum
            }
        }
    }
    vector<vector<int>> ans(uniqueCombination.begin(), uniqueCombination.end()); // Convert the set to a vector
    return ans;
}
int main() {
    vector<int> arr {10, 5, 5, 5, 2};
    int target = 12;
    vector<vector<int>> ans = tripletSumOptimized(arr,arr.size(), target);
    cout<<endl<<"The Elements whose Pair Sum equals to "<<target<<endl;
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[0].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
