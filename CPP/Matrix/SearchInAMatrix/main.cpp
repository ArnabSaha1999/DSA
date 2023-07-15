#include<iostream>
#include<vector>

using namespace std;

//Approach 1: Function to search for a target using the linear search approach
bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int rows = matrix.size(), cols = matrix[0].size();
    // Iterate through each element in the matrix
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            // Check if the current element is equal to the target
            if(matrix[row][col] == target) {
                return true;
            }
        }
    }
    return false;
}

//Approach 2: Function to search for a target using the binary search approach
bool searchMatrixBinarySearch(vector<vector<int>> &matrix, int target) {
    int rows = matrix.size(), cols = matrix[0].size(), start = 0, end = (rows * cols) - 1, mid;
    // Perform binary search on the matrix
    while(start <= end) {
        mid = start + (end - start) / 2; // Calculate the mid index
        if(matrix[mid/cols][mid%cols] == target) { // Calculate the row and column indices corresponding to the mid index
            return true; // Check if the element at the mid index is equal to the target
        } else if(matrix[mid/cols][mid%cols] < target) { // If the element is less than the target, move to the right half of the search space
            start = mid + 1;
        } else { // If the element is greater than the target, move to the left half of the search space
            end = mid - 1;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {13,14,23,33},
        {39,44,51,57},
        {58,62,67,79},
        {89,93,98,99}
        
    };
    int target = 98;
    cout<<"Using the Linear search approach"<<endl;
    if(searchMatrix(matrix, target)) {
        cout<<"The target "<<target<<" is present in the matrix"<<endl;
    } else {
        cout<<"The target "<<target<<" is not present in the matrix"<<endl;
    }

    cout<<"Using the Binary search approach"<<endl;
    if(searchMatrixBinarySearch(matrix, target)) {
        cout<<"The target "<<target<<" is present in the matrix"<<endl;
    } else {
        cout<<"The target "<<target<<" is not present in the matrix"<<endl;
    }
    return 0;
}
