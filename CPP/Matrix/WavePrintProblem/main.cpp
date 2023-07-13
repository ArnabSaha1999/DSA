#include<iostream>
#include<vector>

using namespace std;

// Function to perform wave print of the matrix
vector<int> wavePrint(vector<vector<int>> matrix, int rows, int cols) {
    vector<int> ans(rows * cols); // Vector to store the wave print elements
    int index = 0;  // Index to track the current position in ans vector
    for(int c = 0; c < cols; c++) {
        if(c&1) {
            // Move upwards in odd-indexed columns
            for(int r = rows - 1; r >= 0; r--) {
                ans[index++] = matrix[r][c];
            } 
        } else {
            // Move downwards in even-indexed columns
            for(int r = 0; r < rows; r++) {
                ans[index++] = matrix[r][c];
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {13,34,33},
        {39,54,11},
        {18,22,27}
    };
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> ans = wavePrint(matrix, rows, cols);
    cout<<"Wave print representation of the matrix: "<<endl;
    for(int a : ans) {
        cout<<a<<" ";
    }
    return 0;
}

/*

Initial Matrix:
↓     ↑     ↓
13    34    33
↓     ↑     ↓
39    54    11
↓     ↑     ↓
18    22    27

Wave Print:
13 -> 39 -> 18 -> 22 -> 54 -> 34 -> 33 -> 11 -> 27

*/

