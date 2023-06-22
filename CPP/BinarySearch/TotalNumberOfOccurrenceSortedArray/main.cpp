#include<iostream>
#include<vector>

using namespace std;

//Approach 1: Find the first and last occurrence of the target element using Linear Seerch.
int totalOccurrenceBruteForce(vector<int> &arr, int n, int target) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            count++;
        }
    }
    return count;
}

//Approach 2: Find the first and last occurrence of the target element using Binary Search.
int totalOccurrence(vector<int> &arr, int n, int target) {
    int first = -1, last = -1;
    
    // Binary search to find the first occurrence
    int low = 0, high = n-1, mid;
    while(low <= high) {
        //mid = (low + high) / 2 can cause problem when low + high can exceed the limit of int
        mid = low + (high - low) / 2;
        if(arr[mid] == target) {
            first = mid;
            high = mid - 1;
        } else if(arr[mid] > target){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // Binary search to find the last occurrence
    low = 0, high = n-1;
    while(low <= high) {
        mid = low + (high - low) /2;
        if(arr[mid] == target) {
            last = mid;
            low = mid + 1;
        } else if(arr[mid] > target) {
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }

    return (last - first) + 1; //Calculates the total number of occurrence using first and last index.
}

int main() {
    vector<int> arr = {0, 2, 2, 2, 3, 7};
    int target = 2;
    int ans = totalOccurrence(arr, arr.size(), target);
    if(ans == 0){
        cout<<"The element "<<target<<" is not present in the Array"<<endl;
    } else{
        cout<<"The total number of occurrence of "<<target<<" is "<<ans<<endl;
    }
    return 0;
}
