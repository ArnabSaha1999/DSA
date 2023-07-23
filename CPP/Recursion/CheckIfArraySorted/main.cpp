#include<iostream>

using namespace std;

// Recursive function to check if the array is sorted in ascending order
bool isSortedArray(int* arr, int size) {
    // Base Case 1: If the array is empty or has only one element, it is considered sorted.
    if(size == 0 || size == 1) {
        return true;
    }
    // Base Case 2: If the first element is greater than the second element, the array is not sorted.
    if(arr[0] > arr[1]) {
        return false;
    }
    // Recursive Case: Check if the array is sorted for the rest of the elements (excluding the first element).
    // Pass the pointer to the next element (arr + 1) and reduce the size of the array (size - 1) in the recursive call.
    return isSortedArray(arr + 1, size - 1);
}

int main() {
    int size;
    cout<<"Enter the size of the array: "<<endl;
    cin>>size;
    int arr[size];

    cout<<"Enter the array elements: "<<endl;
    for(int i = 0; i < size; i++) {
        cin>>arr[i];
    }

    cout<<"The array elements: "<<endl;
    for(int i = 0; i < size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    if(isSortedArray(arr, size)) {
        cout<<"The array is Sorted"<<endl;
    } else {
        cout<<"The array is not sorted"<<endl;
    }
    
    return 0;

}
