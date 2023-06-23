#include<iostream>
#include<vector>
using namespace std;

//Approach 1: Find the peak index in a mountain array using Linear Search
int findPeakIndexMountainArrayBruteForce(vector<int> &arr) {
    int ans = 0; // Initialize the answer as the first index
    for(int i = 0; i < arr.size(); i++) {
        if(arr[ans] < arr[i]) {
            ans = i; // Update the answer if a larger element is found
        }
    }
    return ans; // Return the peak index
}

//Approach 2: Find the peak index in a mountain array using Binary Search
int findPeakIndexMountainArray(vector<int> &arr) {
    int low = 0, high = arr.size() - 1, mid;
    while(low <= high) {
        mid = low + (high - low) / 2;
        if(arr[mid] < arr[mid + 1]) {
            low = mid + 1; // Peak is on the right side, update the lower bound
        } else if(arr[mid] < arr[mid - 1]){
            high = mid - 1; // Peak is on the left side, update the upper bound
        } else {
            return mid; // Peak index found, return the middle index
        }
    }
    return mid; // Return the middle index as the peak index (should never reach this point)
}

int main() {
    vector<int> arr = {0,7,2,1,0,-1};
    cout<<"The Peak index is "<<findPeakIndexMountainArray(arr)<<endl;
    return 0;
    
}
