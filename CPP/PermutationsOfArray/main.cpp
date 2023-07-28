#include<iostream>
#include<vector>

using namespace std;

// Function to find all permutations of the array using backtracking
void findPermutations(vector<int> &nums, int index, vector<vector<int>> &ans) {
    // If the index is equal to or greater than the size of the array,
    // it means we have considered all elements, so we add the current permutation to the answer.
    if(index >= nums.size()) {
        ans.push_back(nums);
        return;
    }
    // Try all possible elements at the current index and continue finding permutations
    for(int i = index; i < nums.size(); i++) {
        // Swap the elements at index and i to generate a new permutation
        swap(nums[index], nums[i]);
        // Recursively find permutations for the next index
        findPermutations(nums, index + 1, ans);
        // Backtrack by swapping the elements back to the original order
        swap(nums[index], nums[i]);
    }
}

//Approach 1: Function to find all permutations of the array using Backtracking
vector<vector<int>> permutation(vector<int> &nums) {
    vector<vector<int>> ans;
    int index = 0;
    findPermutations(nums, index, ans);
    return ans;
}

//Function to print array elements.
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
    vector<int> nums = {1,2,3};
    cout<<"The permutations of the array: "<<endl;
    vector<vector<int>> ans = permutation(nums);
    for(auto &i : ans) {
        printArray(i);
    } cout<<endl;
    return 0;
}
