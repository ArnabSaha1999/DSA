#include<iostream>
#include<vector>

using namespace std;

// Function to convert a matrix into spiral representation
vector<int> spiralPrint(vector<vector<int>> matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    int maxElements = rows * cols;
    vector<int> ans(maxElements, 0);
    int index = 0, count = 0;
    int startRow = 0, startCol = 0, endRow = rows - 1, endCol = cols - 1;
    while(startRow <= endRow && startCol <= endCol){
        // Traverse the top row from left to right
        for(int c = startCol; c <= endCol; c++) {
            ans[index++] = matrix[startRow][c];
            count++;
        }
        startRow++;
        // Traverse the right column from top to bottom
        for(int r = startRow; r <= endRow; r++) {
            ans[index++] = matrix[r][endCol];
            count++;
        }
        endCol--;
        // Check if there are more rows to traverse
        // If there are rows present, Traverse the bottom row from right to left
        for(int c = endCol; (startRow <= endRow) && c >= startCol; c--) {
            ans[index++] = matrix[endRow][c];
            count++;
        }
        endRow--;
        // Check if there are more columns to traverse
        // If there are cols present, Traverse the left column from bottom to top
        for(int r = endRow; (startCol <= endCol) && r >= startRow; r--) {
            ans[index++] = matrix[r][startCol];
            count++;
        }
        startCol++;
    }
    return ans;
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
        {13,34,33,43},
        {39,54,11,17},
        {18,22,27,29},
        {19,23,88,10}
        
    };
    printMatrix(matrix);
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> ans = spiralPrint(matrix);
    cout<<"Spiral print representation of the matrix: "<<endl;
    for(int a : ans) {
        cout<<a<<" ";
    }
    return 0;
}

/*

Initial Matrix
13 → 34 → 33 → 43
                ↓
39 → 54 → 11   17
↑          ↓    ↓
18   22 ← 27   29
↑               ↓
19 ← 23 ← 88 ← 10

Output: 13 → 34 → 33 → 43 → 17 → 29 → 10 → 88 → 23 → 19 → 18 → 39 → 54 → 11 → 27 → 22

*/
