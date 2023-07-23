#include<iostream>

using namespace std;

// Recursive function to perform linear search in an array
int linearSearch(int* arr, int index, int size, int target) {
    // Base Case 1: If the array is empty (size = 0), the target element is not found, return -1.
    if(size == 0) {
        return -1;
    }
    // Base Case 2: If the element at the current index matches the target element, return the index.
    if(arr[index] == target) {
        return index;
    }
    // Recursive Case: Continue the linear search in the rest of the array (excluding the current element).
    // Increment the index (index + 1) and reduce the size of the array (size - 1) in the recursive call.
    return linearSearch(arr, index + 1, size - 1, target);
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
    
    int ans = linearSearch(arr, 0, size, target);
    if(ans == -1) {
        cout<<endl<<"The target element "<<target<<" is not present in Array"<<endl;
    } else {
        cout<<endl<<"The target element "<<target<<" is present at index "<<ans<<" in the Array"<<endl;
    }
    
    return 0;
}
