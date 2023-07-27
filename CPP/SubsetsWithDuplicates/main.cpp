#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Backtracking approach to find subsets of 'nums' with duplicates
void solve(vector<int> &nums, vector<int> output, int index, vector<vector<int>> &ans) {
    if(index >= nums.size()) {
        if(find(ans.begin(), ans.end(), output) == ans.end())
        ans.push_back(output);
        return;
    }
    // Exclude the current element and continue exploring other elements in the set
    solve(nums, output, index + 1, ans);
    // Include the current element in the subset and continue exploring other elements
    output.push_back(nums[index]);
    solve(nums, output, index + 1, ans);
}

//Approach 1: Function to find all subsets of 'nums' with duplicates using the backtracking approach
vector<vector<int>> subsetsWithDuplicates(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    sort(nums.begin(), nums.end());
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}

// Backtracking approach to find subsets of 'nums' with duplicates (alternative implementation)
void findSubsets(vector<int> &nums, vector<int> output, int index, vector<vector<int>> &ans) {
    ans.push_back(output);
    for(int i = index; i < nums.size(); i++) {
        // Skip duplicates by checking if the current element is the same as the previous one
        if(i > index && nums[i] == nums[i - 1]) {
            continue;
        }
        output.push_back(nums[i]);
        findSubsets(nums, output, i + 1, ans);
        output.pop_back();
    }
}

//Approach 2: Function to find all subsets of 'nums' with duplicates using the backtracking approach (alternative implementation)
vector<vector<int>> subsetsWithDuplicatesBackTracking(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0; 
    sort(nums.begin(), nums.end());
    findSubsets(nums, output, index, ans);
    return ans;
}

//Approach 3: Function to find the power set using the Bitwise approach 
vector<vector<int>> subsetsWithDuplicatesBitwise(vector<int> &nums) {
    int totalSubsets = 1 << nums.size();
    vector<vector<int>> ans;
    for(int i = 0; i < totalSubsets; i++) {
        vector<int> subsets;
        bool duplicate = false;
        for(int j = 0; j < nums.size(); j++) {
            // If the j-th bit of i is set, add the corresponding element to the subset
            if(i & (1 << j)) {
                subsets.push_back(nums[j]);
            }
        }
        // Check if the subset is not a duplicate and add it to the result
        if(find(ans.begin(), ans.end(), subsets) == ans.end())
            ans.push_back(subsets); // Store the current subset in the power set
    }
    return ans;

}

// Function to print an array
void printArray(vector<int> &arr) {
    cout<<"{";
    for(int i = 0; i < arr.size(); i++) {
        cout<<arr[i];
        if(i != arr.size() - 1) {
            cout<<",";
        }
    }
    
    cout<<"}";
}

int main() {
    vector<int> arr = {1,2,2};

    vector<vector<int>> ans_backtracking = subsetsWithDuplicates(arr);
    cout<<"The Subsets of the array Backtracking approach: "<<endl<<"{";
    for (auto &i : ans_backtracking) {
        printArray(i);
    }
    cout<<"}"<<endl;

    vector<vector<int>> res = subsetsWithDuplicatesBackTracking(arr);
    cout<<"The Subsets of the array Backtracking approach - Alternative: "<<endl<<"{";
    for (auto &i : res) {
        printArray(i);
    }
    cout<<"}"<<endl;

    vector<vector<int>> ans = subsetsWithDuplicatesBitwise(arr);
    cout<<"The Subsets of the array: "<<endl<<"{";
    for(auto &i : ans) {
        printArray(i);
    }
    cout<<"}"<<endl;
    
    return 0;
}
