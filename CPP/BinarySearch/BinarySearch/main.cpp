#include<iostream>
using namespace std;

//Approach 1: Using Iteration method
int binarySearch(int *arr, int size, int target) {
    int low = 0, high = size - 1, mid = 0;
    while(low <= high) {
        //mid = (low + high) / 2 can cause problem when low + high can exceed the limit of int
        mid = low + (high - low) / 2;
        if(arr[mid] == target) {
            return mid;
        } else if(arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

//Approach 2: Using Recursive method
int binarySearchRecursive(int *arr, int target, int low, int high) {
    if(low > high) {
        return -1;
    }
    //mid = (low + high) / 2 can cause problem when low + high can exceed the limit of int
    int mid = low + (high - low) / 2;
    if(arr[mid] == target) {
        return mid;
    }
    if(arr[mid] > target) {
        return binarySearchRecursive(arr, target, low, mid-1);
    }
    return binarySearchRecursive(arr, target, mid+1, high);
}

int main(){
    int arr[] = {0, 2, 4, 7, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 9;
    int ans = binarySearch(arr, size, target);
    // int ans = binarySearchRecursive(arr, target, 0, size-1);
    if(ans == -1) {
        cout<<"The "<<target<<" Element is not present in the Array."<<endl;
    } else
        cout<<"The "<<target<<" Element is present at the "<<ans<<" Index of the Array."<<endl;
}
