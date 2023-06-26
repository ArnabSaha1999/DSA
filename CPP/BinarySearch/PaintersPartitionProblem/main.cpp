#include<iostream>
#include<vector>
using namespace std;

// Function to check if a given allocation is a possible solution
bool isPossibleSolution(vector<int> &boards, int painters, int mid) {
    int painterCount = 1, boardArea = 0;
    for(int i = 0; i < boards.size(); i++) { // Iterate through the boards
        if(boardArea + boards[i] <= mid) {
            boardArea += boards[i];
        } else {
            painterCount++; // Move to the next painter and check if the allocation is valid
            if(painterCount > painters || boards[i] > mid) {
                // If the number of painters exceeds the given limit
                // or a board has more area than the maximum allowed, return false
                return false;
            }
            // Start a new allocation for the next painter
            boardArea = boards[i];
        }
    }
    return true; // All boards have been allocated with valid conditions
}

//Approach 1: Using Binary Search Algorithm to find the minimum number of boards allocated to the painter with the maximum allocation.
int paintLargestMinArea(vector<int> &boards, int painters) {
    int boardArea = 0;
    for(int board : boards) {
        boardArea += board; // Calculate the area of given board.
    }
    int low = 0, high = boardArea, mid, ans = -1; // Set the upper bound as the maximum possible allocation
    //Apply Binary Search
    while(low <= high) {
        mid = low + (high - low) / 2;
        // Check if the current mid value represents a possible solution
        if(isPossibleSolution(boards, painters, mid)) {
            ans = mid;
            high = mid - 1; // Look for smaller allocations
        } else {
            low = mid + 1; // Look for larger allocations
        }
    }
    return ans; // Return the minimum number of area allocated to the painter with maximum allocation.
}

int main() {
    vector<int> boards = {10,20,30,40};
    cout<<"The Minimum possible area allocated to a painter with maximum area is : "<<paintLargestMinArea(boards, 2)<<endl;
    return 0;
}
