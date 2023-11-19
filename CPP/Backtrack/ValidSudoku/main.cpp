#include<iostream>
#include<vector>

using namespace std;

// Function to check if placing a value at a specific position is valid in Sudoku
bool isPossible(int row, int col, char value, vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
        // Check if the value is present in the current row, column, or 3x3 subgrid
        if (board[row][i] == value || board[i][col] == value || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value) {
            // If the value is found in the current row, column, and the 3x3 subgrid
            return false;
        }
    }
    // If the value is not found in the row, column, or subgrid, placement is valid
    return true;
}

// Helper function to validate a Sudoku board
bool isValidSudokuHelper(vector<vector<char>> &board) {
    // Iterate through each cell in the board
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            char value = board[row][col];
            // If the cell is non-empty
            if (value != '.') {
                // Temporarily remove the value for validation
                board[row][col] = '.';  
                if (!isPossible(row, col, value, board)) {
                    // If the placement is not valid, the board is not valid
                    return false;
                }
                // Restore the value after validation
                board[row][col] = value;
            }
        }
    }
    // If all placements are valid, the board is valid
    return true;
}

//Approach 1: Function to check if a Sudoku board is valid
bool isValidSudoku(vector<vector<char>> &board) {
    return isValidSudokuHelper(board);
}

int main() {
    vector<vector<char>> board;
    board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','.','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout<<"The Input Sudoku: "<<endl;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout<<board[i][j]<<" ";
        } cout<<endl;
    }

    if(isValidSudoku(board)) {
        cout<<"The Input Board is a Valid Sudoku"<<endl;
    } else {
        cout<<"The Input Board is not a Valid Sudoku"<<endl;
    }

    board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'7','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','.','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout<<endl<<"The Input Sudoku: "<<endl;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout<<board[i][j]<<" ";
        } cout<<endl;
    }

    if(isValidSudoku(board)) {
        cout<<"The Input Board is a Valid Sudoku"<<endl;
    } else {
        cout<<"The Input Board is not a Valid Sudoku"<<endl;
    }

    return 0;
}
