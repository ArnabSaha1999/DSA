#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>

using namespace std;

//Approach 1: Brute Force Approach
vector<int> arrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m) {
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr1[i] == arr2[j]) {
                ans.push_back(arr1[i]);
                arr2[j] = INT_MIN;
                break;
            }
        }
    }
    return ans;
}

//Approach 2: Two-Pointer Approach
vector<int> arrayIntersectionOptimized(vector<int> &arr1, int n, vector<int> &arr2, int m) {
    vector<int> ans;
    int i = 0, j = 0;
    while(i < n & j < m) {
        if(arr1[i] == arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
            j++;
        } else if(arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }
    return ans;
}

//Approach 3: Hash Map Approach
vector<int> arrayIntersectionHashMap(vector<int> &arr1, int n, vector<int> &arr2, int m) {
    unordered_map<int, int> count;
    vector<int> ans;
    for(int i : arr1) {
        count[i]++;
    }

    for(int i : arr2) {
        if(count[i] > 0) {
            ans.push_back(i);
            count[i]--;
        }
    }
    return ans;
}

int main() {
    vector<int> arr1 {1,2,2,2,3,4}, arr2 {2,2,3,3};
    vector<int> ans = arrayIntersectionOptimized(arr1, arr1.size(), arr2, arr2.size());
    for(int i : ans) {
        cout<<i<<" ";
    }
}
