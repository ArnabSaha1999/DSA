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

//Approach 3: Function to search for a target using the Divide and Conquer approach
bool searchMatrixDivideAndConquer(vector<vector<int>> &matrix, int target) {
    int rows = matrix.size(), cols = matrix[0].size();
    int row = 0, col = cols - 1; // Start from the top-right corner of the matrix
    while(row < rows && col >= 0) {
        int element = matrix[row][col]; // Get the element at the current position
        if(element == target) {
            return true; // Target found, return true
        } else if(element < target) { // If the element is less than the target, move down to the next row
            row++;
        } else { // If the element is greater than the target, move left to the previous column
            col--;
        }
    }
    return false;

}

void printMatrix(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    cout<<"The row-wise representation of the Matrix: "<<endl;
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            cout<<matrix[r][c]<<" ";
        } cout<<endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10,13,14,17, 24},
        {18,21,23,26, 30}
    };
    int target = 9;
    printMatrix(matrix);
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

    cout<<"Using the Divide and Conquer approach"<<endl;
    if(searchMatrixDivideAndConquer(matrix, target)) {
        cout<<"The target "<<target<<" is present in the matrix"<<endl;
    } else {
        cout<<"The target "<<target<<" is not present in the matrix"<<endl;
    }

    return 0;
}
