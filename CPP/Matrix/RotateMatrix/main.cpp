#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Function to print the matrix.
void printMatrix(vector<vector<int>> matrix) {
    for(int r = 0; r < matrix.size(); r++) {
        for(int c = 0; c < matrix[0].size(); c++) {
            cout<<matrix[r][c]<<" ";
        } cout<<endl;
    }
}

//Approach 1: Function to rotate the matrix by creating a temporary matrix
void rotateImage(vector<vector<int>> &matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    vector<vector<int>> temp;
    // Iterate over columns
    for(int c = 0; c < cols; c++) {
        vector<int> arr;
        // Iterate over rows in reverse order
        for(int r = rows - 1; r>=0; r--) {
            arr.push_back(matrix[r][c]);
        } 
        // Store the reversed column in the temporary matrix
        temp.push_back(arr);
    }
    // Assign the temporary matrix back to the original matrix
    matrix = temp;
}

//Approach 2: Function to rotate the matrix in-place
void rotateImageInPlace(vector<vector<int>> &matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    // Transpose the matrix
    for(int row = 0; row < rows; row++) {
        for(int col = row + 1; col < cols; col++) {
            swap(matrix[row][col], matrix[col][row]);
        }
    }
    // Reverse each row
    for(int row = 0; row < rows; row++) {
        reverse(matrix[row].begin(), matrix[row].end());
    }
}

//Approach 3: Function to rotate the matrix in-place by using divide and conquer approach.
void rotateImageDivideAndConquer(vector<vector<int>> &matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    //Perform on layers of the matrix (Outer Layer to Inner Layer)
    for(int start = 0, end = rows - 1; start < end; start++, end--) {
        for(int i = start; i < end; i++) {
            //Save the Top element.
            int top = matrix[start][i];
            //Move elements from Left to Top side (↑ Left to Top →)
            matrix[start][i] = matrix[end - i + start][start];
            //Move elements from Buttom to Left side(← Buttom to Left ↑)
            matrix[end - i + start][start] = matrix[end][end - i + start];
            //Move elements from Right to Buttom (↓ Right to Buttom ←)
            matrix[end][end - i + start] = matrix[i][end];
            //Move elements from Top to Right (→ Top to Right ↓)
            matrix[i][end] = top;

        }
    }
}

int main() {
    vector<vector<int>> matrix1 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
        
    };
    vector<vector<int>> matrix2 = {
        {11,14,17,18,19},
        {12,33,23,19,21},
        {65,78,99,98,54},
        {31,32,88,91,67},
        {66,75,55,78,89}
        
    };

    vector<vector<int>> matrix3 = {
        {13,14,23,33},
        {39,44,51,57},
        {58,62,67,79},
        {89,93,98,99}
        
    };
  
    cout<<"Printing the first matrix:"<<endl;
    printMatrix(matrix1);
    cout<<"Applying Function to rotate the matrix by creating a temporary matrix: "<<endl;
    rotateImage(matrix1);
    printMatrix(matrix1);

    cout<<"Printing the second matrix:"<<endl;
    printMatrix(matrix2);
    cout<<"Applying Function to rotate the matrix in-place: "<<endl;
    rotateImageInPlace(matrix2);
    printMatrix(matrix2);

    cout<<"Printing the third matrix:"<<endl;
    printMatrix(matrix3);
    cout<<"Applying Function to rotate the matrix in-place by using divide and conquer approach: "<<endl;
    rotateImageDivideAndConquer(matrix3);
    printMatrix(matrix3);

    return 0;
}
