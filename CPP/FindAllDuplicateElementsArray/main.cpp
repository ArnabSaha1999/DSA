#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//Approach 1: Using Nested Loop to compare array element with each other.
vector<int> findDuplicatesBruteForce(vector<int>& nums) {
    vector<int> ans;
    for(int i = 0; i < nums.size(); i++) {
        int count = 1;
        for(int j = i+1; j < nums.size(); j++) {
            if(nums[i] == nums[j])
                count++;
        }
        if(count == 2) {
            ans.push_back(nums[i]);
        }
    }
    return ans;
}

//Approach 2: Using Hash map to keep track of the count of the array elements.
vector<int> findDuplicatesHashMap(vector<int> &nums) {
    unordered_map<int, int> count;
    vector<int> ans;
    for(int i = 0; i < nums.size(); i++) {
        count[nums[i]]++;
    }

    for(auto i : count) {
        if(i.second == 2) {
            ans.push_back(i.first);
        }
    }
    return ans;
}

//Approach 3: Using "Negation Marking" or the "Index as a Hash" approach.
/*
it comes with the constraint that the elements in the array must be within a specific range and allows only non-negative values. 
If the range or the non-negative constraint is not guaranteed, this approach may not be applicable.
*/
vector<int> findDuplicatesOptimized(vector<int> &nums) {
    vector<int> duplicates{};
    for(int num : nums) {
        int index = abs(num) - 1;
        if(nums[index] < 0) {
            duplicates.push_back(abs(num));
        } else{
            nums[index] *= -1;
        }
    }
    return duplicates;
}

int main() {
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> ans = findDuplicatesOptimized(nums);
    for(auto i : ans) {
        cout<<i<<" ";
    }
    return 0;
}
