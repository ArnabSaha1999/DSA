#include<iostream>
#include<vector>

using namespace std;

//Approach 1: Using Linear Search to find the pivot/Smallest element.
int findPivotLinearSearch(vector<int> &arr) {
    int ans = arr[0];
    for(int i = 0; i < arr.size() - 1; i++) {
        if(arr[i] > arr[i+1]) {
            ans = arr[i+1];
        }
    }
    return ans;
}

//Approach 2: Using Binary Search to find the pivot/smallest element.
int findPivotBinarySearch(vector<int> &arr) {
    int low = 0, high = arr.size() - 1, mid;
    while(low < high) {
        mid = low + (high - low) / 2;
        if(arr[mid] > arr[high]) { //If middle element is bigger than high element means pivot lies in the right of the array.
            low = mid+1;
        } else{ //If middle element is smaller than low element means pivot lies in the left or the middle itself is the pivot.
            high = mid;
        }
    
    }
    return arr[low];
}

int main() {
    vector<int> arr = {3,4,5,1,2};
    cout<<"The Pivot element is :"<<findPivotBinarySearch(arr)<<endl;
    return 0;
}
