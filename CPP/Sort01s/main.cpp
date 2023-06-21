#include<iostream>
#include<vector>

using namespace std;

// Approach 1: Using Two Pointer approach to sort array of 0s and 1s.
vector<int> sort01s(vector<int> &arr) {
    int left = 0, right = arr.size() - 1;
    while(left < right) { // Continue until the left pointer crosses the right pointer
        while(arr[left] == 0 && left < right) { // Continue until Left pointer points to 1 or Left pointer crosses Right pointer
            left++;
        }
        while(arr[right] == 1 && left < right) { // Continue until Right pointer points to 0 or Right pointer crosses Left pointer
            right--;
        }
        if(left < right) {
            arr[left] = 0;
            arr[right] = 1;
            left++;
            right--;
        }
    }
    return arr;
}

// Approach 2: Using Optimized Two Pointer approach to sort of 0s and 1s.
vector<int> sort01sTwoPointer(vector<int> &arr) {
    int left = 0, right = arr.size() - 1;
    while(left < right) { // Continue until the left pointer crosses the right pointer
        if(arr[left] == 0) {
            left++; // Increment the left pointer if it points to 0
        } else if(arr[right] == 1) {
            right--; // Decrement the right pointer if it points to 1
        } else {
            arr[left] = 0;
            arr[right] = 1; // Swap arr[left] and arr[right] to put 0 at the left and 1 at the right
            left++;
            right--;
        }
    }
    return arr;
}

int main(){ 
    vector<int> arr {0,1,1,1,1,1};
    cout<<"After sorting the Array: "<<endl;
    vector<int> ans = sort01sTwoPointer(arr);
    for(int i : ans) {
        cout<<i<<" ";
    }
    return 0;
}
