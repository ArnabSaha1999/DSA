#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void findSubsets(vector<int> &nums, vector<int> output, int index, vector<vector<int>> &ans) {
    ans.push_back(output);
    for(int i = index; i < nums.size(); i++) {
        if(i > index && nums[i] == nums[i - 1]) {
            continue;
        }
        output.push_back(nums[i]);
        findSubsets(nums, output, i + 1, ans);
        output.pop_back();
    }
}

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

    // vector<vector<int>> ans_backtracking = subsets(arr);
    // cout<<"The Subsets of the array Backtracking approach: "<<endl<<"{";
    // for (auto &i : ans_backtracking) {
    //     printArray(i);
    // }
    // cout<<"}"<<endl;

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
