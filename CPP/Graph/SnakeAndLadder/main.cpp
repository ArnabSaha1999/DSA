#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

// Function to get row and column indices for a given value on the board
pair<int, int> getCoordinates(int boardSize, int value) {
    int row = boardSize - 1 - (value - 1) / boardSize;
    int col = (value - 1) % boardSize;
    // Adjust column index based on row and board size to handle snake and ladder pattern
    if(((boardSize & 1) == 1 && (row & 1) == 1) || ((boardSize & 1) == 0 && (row & 1) == 0)) {
        col = boardSize - 1 - col;
    }
    return {row, col};
}

//Approach 1: Function to find the least number of moves to reach the end of the snake and ladder board
int snakeAndLadders(vector<vector<int>> &board) {
    int boardSize = board.size();
    vector<vector<bool>> visited(boardSize, vector<bool> (boardSize, false));
    queue<int> bfsQueue;
    bfsQueue.push(1);
    visited[boardSize - 1][0] = true;
    int moves = 0;
    // Start BFS
    while(!bfsQueue.empty()) {
        int queueSize = bfsQueue.size();
        // Process all nodes at the current level
        while(queueSize--) {
            int num = bfsQueue.front();
            bfsQueue.pop();
            // If reached the last cell, return the number of moves
            if(num == boardSize * boardSize) {
                return moves;
            }
            // Explore next possible moves (1 to 6)
            for(int i = 1; i <= 6; i++) {
                if(num + i > boardSize * boardSize) {
                    break;
                }
                // Get row and column indices for the next position
                pair<int, int> boardCoordinates = getCoordinates(boardSize, num + i);
                int row = boardCoordinates.first;
                int col = boardCoordinates.second;
                // Skip if the cell is already visited
                if(visited[row][col] == true) {
                    continue;
                }
                visited[row][col] = true;
                // Add the next position to the queue based on whether it's a ladder or snake
                if(board[row][col] == -1) {
                    bfsQueue.push(num + i);
                } else {
                    bfsQueue.push(board[row][col]);
                }
            }
        }
        // Move to the next level
        moves++;
    }
    // If it's not possible to reach the end
    return -1;
}

int main() {
    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1},
    };
    cout<<"The Input Snake and Ladder board: "<<endl;
    for(auto arr: board) {
        for(int a: arr) {
            cout<<a<<" ";
        } cout<<endl;
    }
    cout<<"The Least Number of Moves required to move "<<board.size() * board.size()<<": "<<snakeAndLadders(board)<<endl;

    board = {
        {-1, -1},
        {-1, 3}
    };
    cout<<endl<<"The Input Snake and Ladder board: "<<endl;
    for(auto arr: board) {
        for(int a: arr) {
            cout<<a<<" ";
        } cout<<endl;
    }
    cout<<"The Least Number of Moves required to move "<<board.size() * board.size()<<": "<<snakeAndLadders(board)<<endl;

    return 0;
}
