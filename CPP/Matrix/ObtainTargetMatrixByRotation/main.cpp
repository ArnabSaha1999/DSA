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

//Function to rotate the matrix by creating a temporary matrix
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

//Approach 1: Function to rotate the matrix by creating a temporary matrix
bool findRotation(vector<vector<int>> &matrix, vector<vector<int>> &target) {
    int size = matrix.size();
    // If the input matrix and the target matrix are the same, return true
    if(matrix == target) {
        return true;
    }
    // Try rotating the input matrix 4 times to see if it matches the target matrix
    for(int i = 0; i < 4; i++) {
        rotateImage(matrix);
        if(matrix == target) {
            return true;
        }
    }
    // If after 4 rotations, the target matrix is not found, return false
    return false;
}

//Function to rotate the matrix in-place
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

//Approach 2: Function to rotate the matrix in-place
bool findRotationInPlace(vector<vector<int>> &matrix, vector<vector<int>> &target) {
    int size = matrix.size();
    // If the input matrix and the target matrix are the same, return true
    if(matrix == target) {
        return true;
    }
    // Try rotating the input matrix 4 times to see if it matches the target matrix
    for(int i = 0; i < 4; i++) {
        rotateImageInPlace(matrix);
        if(matrix == target) {
            return true;
        }
    }
    // If after 4 rotations, the target matrix is not found, return false
    return false;
}

//Function to rotate the matrix in-place by using divide and conquer approach.
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

//Approach 3: Function to rotate the matrix in-place by using divide and conquer approach.
bool findRotationDivideAndConquer(vector<vector<int>> &matrix, vector<vector<int>> &target) {
    int size = matrix.size();
    // If the input matrix and the target matrix are the same, return true
    if(matrix == target) {
        return true;
    }
    // Try rotating the input matrix 4 times to see if it matches the target matrix
    for(int i = 0; i < 4; i++) {
        rotateImageDivideAndConquer(matrix);
        if(matrix == target) {
            return true;
        }
    }
    // If after 4 rotations, the target matrix is not found, return false
    return false;
}

int main() {
    vector<vector<int>> matrix1 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
        
    };
    vector<vector<int>> target1 = {
        {7,4,1},
        {8,5,2},
        {9,6,3}
    };
    cout<<"The first input Matrix"<<endl;
    printMatrix(matrix1);
    cout<<"The first Target Matrix"<<endl;
    printMatrix(target1);

    if(findRotation(matrix1, target1)) {
        cout<<"The Target matrix can be obtained by rotating the input Matrix"<<endl;
    } else {
        cout<<"The Target matrix cannot be obtained by rotating the input Matrix"<<endl;
    }

    vector<vector<int>> matrix2 = {
        {0,0,0},
        {0,1,0},
        {1,1,1}
        
    };
    vector<vector<int>> target2 = {
        {1,1,1},
        {0,1,0},
        {0,0,0}
    };

    cout<<"The second input Matrix"<<endl;
    printMatrix(matrix2);
    cout<<"The second Target Matrix"<<endl;
    printMatrix(target2);

    if(findRotationInPlace(matrix2, target2)) {
        cout<<"The Target matrix can be obtained by rotating the input Matrix"<<endl;
    } else {
        cout<<"The Target matrix cannot be obtained by rotating the input Matrix"<<endl;
    }

    vector<vector<int>> matrix3 = {
        {1,1},
        {0,1}
        
    };
    vector<vector<int>> target3 = {
        {1,0},
        {0,1}
    };

    cout<<"The third input Matrix"<<endl;
    printMatrix(matrix3);
    cout<<"The third Target Matrix"<<endl;
    printMatrix(target3);

    if(findRotationInPlace(matrix3, target3)) {
        cout<<"The Target matrix can be obtained by rotating the input Matrix"<<endl;
    } else {
        cout<<"The Target matrix cannot be obtained by rotating the input Matrix"<<endl;
    }

    return 0;
}
