#include<iostream>
#include<vector>
#include<climits>

using namespace std;

//Function to calculate the sum of each rows.
int largestRowSum(vector<vector<int>> matrix, int row, int col) {
    int rowIndex = 0;
    int maxi = INT_MIN;
    // Iterate over each row
    for(int r = 0; r < row; r++) {
        int sum = 0;
        // Iterate over each column in the current row
        for(int c = 0; c < col; c++) {
            sum += matrix[r][c]; // Add the element to the sum
        }
        cout<<"The sum of "<<r<<" row is: "<<sum<<endl;
        if(sum > maxi) { // Check if the previous row sum is small or bigger. 
            maxi = sum;
            rowIndex = r;
        }
    }
    return rowIndex;
}

int main() {
    vector<vector<int>> matrix = {
        {13,34,33},
        {39,54,11},
        {18,22,27}
    };
    int row = matrix.size(); // Get the number of rows
    int col = matrix[0].size(); // Get the number of columns assuming all rows have the same number of columns
    cout<<"The Largest row sum is at row index: "<<largestRowSum(matrix, row, col); // Call the rowSum function
    return 0;
}
