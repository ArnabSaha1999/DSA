#include<iostream>

using namespace std;

// Recursive function to perform binary search in a sorted array
int binarySearch(int *arr, int start, int end, int target) {
    // Base Case: If the start index becomes greater than the end index, the target element is not found, return -1.
    if(start > end) {
        return -1;
    }
    // Calculate the mid index of the current range
    int mid = start + (end - start) / 2;
    // Base Case: If the element at the mid index matches the target element, return the mid index.
    if(arr[mid] == target) {
        return mid;
    }
    // Recursive Case: If the element at the mid index is greater than the target element,
    // search in the left half of the array (before the mid index).
    // Adjust the upper bound to mid - 1.
    if(arr[mid] > target) {
        return binarySearch(arr, start, mid - 1, target);
    } else {
        // Recursive Case: If the element at the mid index is less than the target element,
        // search in the right half of the array (after the mid index).
        // Adjust the lower bound to mid + 1.
        return binarySearch(arr, mid + 1, end, target);
    }
}

int main() {
    int size, target;
    cout<<"Enter the size of the array: "<<endl;
    cin>>size;
    int arr[size];

    cout<<"Enter the array elements: "<<endl;
    for(int i = 0; i < size; i++) {
        cin>>arr[i];
    }

    cout<<"Enter the target element to search: "<<endl;
    cin>>target;

    cout<<"The array elements: "<<endl;
    for(int i = 0; i < size; i++) {
        cout<<arr[i]<<" ";
    }
    
    int ans = binarySearch(arr, 0, size, target);
    if(ans == -1) {
        cout<<endl<<"The target element "<<target<<" is not present in Array"<<endl;
    } else {
        cout<<endl<<"The target element "<<target<<" is present at index "<<ans<<" in the Array"<<endl;
    }
    
    return 0;
}
