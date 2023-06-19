#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

//Approach 1: Using Nested loop to find pairs.
vector<vector<int>> pairSum(vector<int> &arr, int s) {
    vector<vector<int>> ans;
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i+1; j < arr.size(); j++) {
            if(arr[i] + arr[j] == s) {
                ans.push_back({min(arr[i], arr[j]), max(arr[i], arr[j])});
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

//Approach 2: Using HashMap
vector<vector<int>> pairSumHashMap(vector<int> &arr, int s) {
    vector<vector<int>> ans;
    unordered_map<int, int> count; // Hash map to store element frequencies
    for(int i = 0; i < arr.size(); i++) {
        int target = s - arr[i]; // Calculate the complement value
        if(count.find(target) != count.end()) {
            int value = count[target];
            while(value--) { //Check for duplicates value
                ans.push_back({min(target, arr[i]), max(target, arr[i])});
            }
        }
        count[arr[i]]++; // Update the frequency of the current element
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> arr {2,-3,2,3,2};
    int target = 4;
    vector<vector<int>> ans = pairSumHashMap(arr, target);
    cout<<endl<<"The Elements whose Pair Sum equals to "<<target<<endl;
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[0].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
