#include<iostream>
#include<vector>

using namespace std;

//Approach 1: Function to perform bubble sort iteratively
void bubbleSort(vector<int> &arr, int n) {
    for(int i = 0; i < n; i++) {
        bool isSwapped = false;
        //We effectively ignore the elements that have already been sorted in the previous passes by using j < n - i - 1;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                swap(arr[j], arr[j+1]);
                isSwapped = true;
            }
        }
        if(!isSwapped)
            break; // If no swaps were made in the current pass, the array is already sorted
    }
}

//Approach 2: Function to perform bubble sort recursively
void bubbleSortRecursive(vector<int> &arr, int n) {
    // Base case: If there is only one element remaining, return
    if(n == 1)
        return;
    bool isSwapped = false;
    for(int j = 0; j < n - 1; j++) {
        if(arr[j] > arr[j+1]) {
            // Swap elements if they are in the wrong order
            swap(arr[j], arr[j+1]);
            isSwapped = true;
        }
    }
    if(!isSwapped) { // If no swaps were made in the current pass, the array is already sorted
        return;
    }
    bubbleSortRecursive(arr, n-1); // Recursively call bubbleSortRecursive with a reduced size of the array
}

// Function to print the array
void print(vector<int> &arr, int n) {
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}

int main() {
    vector<int> arr = {5,-11,3,8,6,7};
    int size = arr.size();
    cout<<"Iterative way of Bubble Sort"<<endl;
    bubbleSort(arr, size);
    print(arr, size);
    
    vector<int> nums = {61,77,4,9,0,2,45};
    cout<<"Recursive way of Bubble Sort"<<endl;
    bubbleSortRecursive(nums, nums.size());
    print(nums, nums.size());
    return 0;
}
