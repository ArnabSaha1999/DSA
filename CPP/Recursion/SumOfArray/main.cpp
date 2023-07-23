#include<iostream>

using namespace std;

// Recursive function to calculate the sum of elements in an array
int sumOfArray(int* arr, int size) {
    // Base Case 1: If the array is empty (size = 0), the sum is 0.
    if(size == 0) {
        return 0;
    }
    // Base Case 2: If the array has only one element, the sum is that element.
    if(size == 1) {
        return arr[0];
    }
    // Recursive Case: The sum of the array is the sum of the first element (arr[0])
    // and the sum of the rest of the elements (arr + 1) in the array (excluding the first element).
    // Reduce the size of the array (size - 1) in the recursive call.
    return arr[0] + sumOfArray(arr + 1, size - 1);
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

    cout<<endl<<"The Sum of Array: "<<sumOfArray(arr, size)<<endl;

    return 0;
}
