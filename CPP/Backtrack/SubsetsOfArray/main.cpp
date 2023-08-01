#include<iostream>
#include<vector>

using namespace std;

//Function to find the power set using backtracking
void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans) {
    // Base case: If the index is greater than or equal to the size of the input set,
    // we have considered all elements, so we add the current subset to the answer.
    if(index >= nums.size()) {
        ans.push_back(output);
        return ;
    }
    
    // Exclude the current element and continue exploring other elements in the set
    solve(nums, output, index+1, ans);
    
    // Include the current element in the subset and continue exploring other elements
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index+1, ans);
    
}


//Approach 1: Function to find all subsets using backtracking
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
    
}

//Function to find the power set using backtracking
void findSubset(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans) {
    ans.push_back(output); // Add the current subset to the answer
    // Explore elements starting from the given index
    for(int i = index; i < nums.size(); i++) {
        output.push_back(nums[i]); // Include the current element in the subset
        findSubset(nums, output, i + 1, ans); // Continue exploring other elements
        output.pop_back(); // Backtrack: Remove the last added element from the subset
    }
}

//Approach 2: Function to find all subsets using backtracking (Alternative implementation)
vector<vector<int>> subsetBackTracking(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    findSubset(nums, output, index, ans);
    return ans;
}

//Approach 3: Function to find the power set using the Bitwise approach 
vector<vector<int>> subsetsBitwise(vector<int> &nums) {
    int totalSubsets = 1 << nums.size();
    vector<vector<int>> ans;
    for(int i = 0; i < totalSubsets; i++) {
        vector<int> subsets;
        for(int j = 0; j < nums.size(); j++) {
            // If the j-th bit of i is set, add the corresponding element to the subset
            if(i & (1 << j)) {
                subsets.push_back(nums[j]);
            }
        }
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
    vector<int> arr = {1,2,3};

    vector<vector<int>> ans_backtracking = subsets(arr);
    cout<<"The Subsets of the array Backtracking approach: "<<endl<<"{";
    for (auto &i : ans_backtracking) {
        printArray(i);
    }
    cout<<"}"<<endl;

    vector<vector<int>> res = subsetBackTracking(arr);
    cout<<"The Subsets of the array Backtracking approach - Alternative: "<<endl<<"{";
    for (auto &i : res) {
        printArray(i);
    }
    cout<<"}"<<endl;

    vector<vector<int>> ans = subsetsBitwise(arr);
    cout<<"The Subsets of the array: "<<endl<<"{";
    for(auto &i : ans) {
        printArray(i);
    }
    cout<<"}"<<endl;
    
    return 0;
}
