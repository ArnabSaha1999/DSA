#include<iostream>
#include<vector>

using namespace std;

//Approach 1: Check if the array is sorted and rotated
bool checkSortedRotated(vector<int> &arr) {
    int size = arr.size(), count = 0;
    // Iterate through the array to check for decreasing pairs
    for(int i = 1; i < size; i++) {
        if(arr[i-1] > arr[i]) {
            count++;
        }
    }
    // Check the last element with the first element for another decreasing pair
    if(arr[size-1] > arr[0]) {
        count++;
    }
    // If there is at most one decreasing pair, the array is sorted and rotated
    return count <= 1;
}

//Approach 2: Check if the array is sorted and rotated within a single loop & modulus operator.
bool isSortedRotated(vector<int> &arr) {
    int size = arr.size(), count = 0;
    // Iterate through the array to check for decreasing pairs
    for(int i = 0; i < size; i++) {
        if(arr[i] > arr[(i+1) % size]) {
            count++;
        }
        // If more than one decreasing pair is found, the array is not sorted and rotated
        if(count > 1) {
            return false;
        }
    }
    // If there is at most one decreasing pair, the array is sorted and rotated
    return true;
}

// Prints the elements of the array
void printArray(vector<int> &arr) {
    for(int i : arr) {
        cout<<i<<" ";
    } cout<<endl;
}

int main() {
    vector<int> arr = {8,9,1,3,4,7};
    printArray(arr);
    if(checkSortedRotated(arr)) {
        cout<<"The above array is Sorted & Rotated"<<endl;
    } else {
        cout<<"The above array is not Sorted & Rotated"<<endl;
    }
}
