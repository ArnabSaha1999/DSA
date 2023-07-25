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

void findPowerSet(vector<int>& nums, vector<int>& output, int index, vector<vector<int>>& ans) {
    ans.push_back(output);
    
    for (int i = index; i < nums.size(); ++i) {
        output.push_back(nums[i]);
        findPowerSet(nums, output, i + 1, ans);
        output.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    
    int index = 0;
    
    findPowerSet(nums, output, index, ans);
    return ans;
    
}

int main() {
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans = subsets(arr);
    return 0;
}
