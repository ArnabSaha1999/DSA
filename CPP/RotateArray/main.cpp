#include<iostream>
#include<vector>

using namespace std;

//Approach 1: Function to rotate the array using temporary array
void rotate(vector<int> &nums, int k) {
    int size = nums.size();
    vector<int> temp(size); // Temporary array to store rotated elements
    for(int i = 0, j = size - 1; i <= j; i++, j--) {
        if(i != j){
            temp[(i + k) % size] = nums[i]; // Rotate elements from the beginning
            temp[(j + k) % size] = nums[j]; // Rotate elements from the end
        } else {
            temp[(i + k) % size] = nums[i]; // Handle middle element (if exists)
        }
    }
    nums = temp; // Copy the rotated elements back to the original array
}

//Function to reverse a portion of the array in-place
void reverseArray(vector<int> &nums, int start, int size) {
    int end = size - 1;
    while(start <= end) {
        swap(nums[start++], nums[end--]); // Swap elements to reverse the array portion
    }
    return;
}

//Approach 2: Optimized function to rotate the array in-place
void rotateOptimized(vector<int> &nums, int k) {
    int size = nums.size();
    // Normalize k to be within the range of array size
    k %= size;
    // Step 1: Reverse the entire array
    reverseArray(nums, 0, size);
    // Step 2: Reverse the first k elements
    reverseArray(nums, 0, k);
    // Step 3: Reverse the remaining elements
    reverseArray(nums, k, size);
}

// Prints the elements of the array
void printArray(vector<int> &arr) {
    for(int i : arr) {
        cout<<i<<" ";
    } cout<<endl;
}

int main() {
    vector<int> nums = {1,1,3,4,9,10,12};
    int k = 4;
    cout<<"The array before Rotating: ";
    printArray(nums);
    cout<<"The array after Rotating from index "<<k<<": ";
    rotateOptimized(nums, k);
    printArray(nums);
    return 0;
}
