#include<iostream>

using namespace std;

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout<<arr[i]<<" ";
    }
}
// Approach 1: Using a temporary variable inside the swapAlternative function
void swapAlternative(int arr[], int size) {
    for(int i = 0; i < size - 1; i+=2) {
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
    printArray(arr, size);
}

// Approach 2: Using XOR operation for swapping elements
void swapAlternativeXOR(int arr[], int size) {
    for(int i = 0; i < size-1; i+=2) {
        arr[i] ^= arr[i+1];
        arr[i+1] ^= arr[i];
        arr[i] ^= arr[i+1];
    }
    printArray(arr, size);
}

int main() {
    int even[6] = {1,2,3,4,5,6};
    int odd[5] = {1,2,3,4,5};
    cout<<"The arrays is :"<<endl;
    printArray(odd, 5);
    cout<<endl<<"After swapping alternative elements: "<<endl;
    swapAlternativeXOR(odd, 5);
    cout<<endl;
    return 0;
}
