#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// Check if placing a Queen at the specified position is feasible
bool isPossible(int row, int col, vector<vector<int>> &board, int n) {
    // Check if there is a Queen in the same row
    int c = col - 1;
    while(c >= 0) {
        if(board[row][c--] == 1) {
            return false;
        }
    }
    // Check if there is a Queen in the upper-left diagonal
    int r = row - 1;
    c = col - 1;
    while(r >= 0 && c >= 0) {
        if(board[r--][c--] == 1) {
            return false;
        }
    }
    // Check if there is a Queen in the lower-left diagonal
    r = row + 1;
    c = col - 1;
    while(r < n && c >= 0) {
        if(board[r++][c--] == 1) {
            return false;
        }
    }
    return true;
}

// Backtracking helper function to solve N-Queens problem
void solve(vector<vector<int>> &board, int col, int n, int &count) {
    // Base case: All columns are filled, increment the count
    if(col == n) {
        count++;
        return;
    }
    // Try placing a Queen in each row of the current column
    for(int row = 0; row < n; row++) {
        // Check if it's possible to place a Queen at the current position
        if(isPossible(row, col, board, n)) {
            // Place a Queen
            board[row][col] = 1;
            // Recur for the next column
            solve(board, col + 1, n, count);
            // Backtrack: Reset the current position
            board[row][col] = 0;
        }
    }
}

//Approach 1: Function to calculate the total number of distinct solutions for the N-Queens problem Backtracking approach
int totalNQueens(int n) {
    // Initialize the chessboard
    vector<vector<int>> board(n, vector<int> (n, 0));
    // Initialize count to store the total number of solutions
    int count = 0;
    // Start solving from the first column
    solve(board, 0, n, count);
    return count;
}

// Hashmap to track occupied rows, downward diagonals, and upward diagonals during N-Queens placement
unordered_map<int, bool> mapRow, mapDownDiagonal, mapUpDiagonal;

// Check if placing a Queen at the specified position is feasible using optimized approach
bool isPossible(int row, int col, int n) {
    if(mapRow[row] || mapDownDiagonal[row + col] || mapUpDiagonal[(n - 1) + col - row]) {
        return false;
    }
    return true;
}

// Set values in hash maps when placing a Queen
void setMapValues(int row, int col, int n) {
    // Mark the current row
    mapRow[row] = true;
    // Mark the downward diagonal
    mapDownDiagonal[row + col] = true;
    // Mark the upward diagonal
    mapUpDiagonal[(n - 1) + col - row] = true;
}

// Reset values in hash maps during backtracking
void resetMapValues(int row, int col, int n) {
    // Unmark the current row
    mapRow[row] = false;
    // Unmark the downward diagonal
    mapDownDiagonal[row + col] = false;
    // Unmark the upward diagonal
    mapUpDiagonal[(n - 1) + col - row] = false;
}

// Optimized backtracking helper function
void nQueensHelper(vector<vector<int>> &board, int col, int n, int &count) {
    // Base case: All columns are filled, increment the count
    if(col == n) {
        count++;
        return;
    }
    // Try placing a Queen in each row of the current column
    for(int row = 0; row < n; row++) {
        // Check if it's possible to place a Queen at the current position
        if(isPossible(row, col, n)) {
            // Place a Queen
            board[row][col] = 1;
            // Update hash maps
            setMapValues(row, col, n);
            // Recur for the next column
            nQueensHelper(board, col + 1, n, count);
            // Backtrack: Reset the current position
            board[row][col] = 0;
            // Reset hash maps
            resetMapValues(row, col, n);
        }
    }
}

//Approach 2: Function to calculate the total number of distinct solutions for the N-Queens problem using optimized approac
int totalNQueensOptimized(int n) {
    // Initialize the chessboard
    vector<vector<int>> board(n, vector<int>(n, 0));
    // Initialize count to store the total number of solutions
    int count = 0; 
    // Start solving from the first column
    solve(board, 0, n, count);
    return count;
}

int main() {
    int n = 4;
    cout<<"The Distinct number of solutions of N-Queen Puzzle using Backtracing Approach: "<<totalNQueens(n)<<endl;
    cout<<"The Distinct number of solutions of N-Queen Puzzle using Optimized Backtracing Approach: "<<totalNQueensOptimized(n)<<endl;
    return 0;
}
