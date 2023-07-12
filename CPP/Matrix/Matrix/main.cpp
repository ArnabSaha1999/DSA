#include<iostream>
#include<utility>
#define ROWS 3
#define COLS 3

using namespace std;

// Function to print the matrix in row-wise representation
void printRowWiseMatrix(int matrix[ROWS][COLS]) {
    cout<<"The row-wise representation of the Matrix: "<<endl;
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            cout<<matrix[r][c]<<" ";
        } cout<<endl;
    }
}

// Function to print the matrix in column-wise representation
void printColumnMatrix(int matrix[ROWS][COLS]) {
    cout<<"The column-wise representation of the Matrix: "<<endl;
    for(int c = 0; c < COLS; c++) {
        for(int r = 0; r < ROWS; r++) {
            cout<<matrix[r][c]<<" ";
        } cout<<endl;
    }
}

// Function to perform linear search on a matrix and return the position of the target element
pair<int, int> linearSearch(int matrix[ROWS][COLS], int target) {
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            if(target == matrix[r][c]) {
                return make_pair(r, c);
            }
        }
    }
    return make_pair(-1, -1);
}

// Function to input a matrix and print it in row-wise and column-wise representations
void matrix() {
    int matrix[ROWS][COLS];
    cout<<"Enter you matrix elements: "<<endl;
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            cin>>matrix[r][c];
        }
    }
    // Print the matrix in row-wise and column-wise representations
    printRowWiseMatrix(matrix);
    printColumnMatrix(matrix);
}

// Function to input a matrix of user-defined size and print it in row-wise and column-wise representations
void userInputMatrix() {
    int row, col;
    cout<<"Enter row value: ";
    cin>>row;
    cout<<"Enter column value: ";
    cin>>col;
    int matrix[row][col];
    cout<<"Enter you matrix elements: "<<endl;
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            cin>>matrix[r][c];
        }
    }
    cout<<"The row-wise representation of the Matrix: "<<endl;
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            cout<<matrix[r][c]<<" ";
        } cout<<endl;
    }

    cout<<"The column-wise representation of the Matrix: "<<endl;
    for(int c = 0; c < col; c++) {
        for(int r = 0; r < row; r++) {
            cout<<matrix[r][c]<<" ";
        } cout<<endl;
    }
}


int main() {
    int matrix[ROWS][COLS] = {
        {13,34,33},
        {39,54,11},
        {18,22,27}
    };

    int target = 54;
    printRowWiseMatrix(matrix);
    printColumnMatrix(matrix);
    
    pair<int, int> ansPair = linearSearch(matrix, target);
    if(ansPair.first == -1 && ansPair.second == -1) {
        cout<<"The target "<<target<<" is not present in the matrix"<<endl;
    } else {
        cout<<"The target "<<target<<" is present at row: "<<ansPair.first<<", col: "<<ansPair.second<<endl;
    }

    // matrix();
    // userInputMatrix();

    return 0;
}
