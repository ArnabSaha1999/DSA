#include<iostream>
#include<vector>

using namespace std;

//Approach 1: Moves zeros to the end of the vector while maintaining the order of non-zero elements
void moveZeros(vector<int> &nums, int size) {
    int slow = 0, fast = slow + 1;
    // Iterate through the vector
    while(fast <= size - 1) {
        if(nums[slow] != 0) {
            slow++;
            fast++;
        }
        else if(nums[fast] == 0) {
            fast++;
        } else {
            swap(nums[slow++], nums[fast++]);
        }
    }
}

//Approach 2: Optimized version to move zeros to the end of the vector while maintaining the order of non-zero elements
void moveZerosOptimized(vector<int> &nums, int size) {
    int slow = 0;
    // Iterate through the vector
    for(int fast = 0; fast < size; fast++) {
        if(nums[fast] != 0 && slow != fast) {
            if(slow != fast) {
                nums[slow] = nums[fast];
            }
            slow++;
        }
    }
    // Fill the remaining positions with zeros
    while(slow < size) {
        nums[slow++] = 0;
    }
}

// Prints the elements of the array
void printArray(vector<int> &arr) {
    for(int i : arr) {
        cout<<i<<" ";
    } cout<<endl;
}

int main() {
    vector<int> nums = {1,0,3,4,0,3,88,0};
    cout<<"The vector before moving 0s: ";
    printArray(nums);

    moveZerosOptimized(nums, nums.size());
    cout<<"The Vector after moving 0s: ";
    printArray(nums);
    return 0;
}
