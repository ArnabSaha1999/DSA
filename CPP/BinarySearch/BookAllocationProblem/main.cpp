#include<iostream>
#include<vector>
using namespace std;

// Function to check if a given allocation is a possible solution
bool isPossibleSolution(vector<int> arr, int books, int students, int mid) {
    int studentCount = 1, pageCount = 0;
    for(int i = 0; i < books; i++) { // Iterate through the books
        if(pageCount + arr[i] <= mid) {
            pageCount += arr[i];
        } else {
            // Move to the next student and check if the allocation is valid
            studentCount++;
            if(studentCount > students || arr[i] > mid) {
                // If the number of students exceeds the given limit
                // or a book has more pages than the maximum allowed, return false
                return false;
            }
            // Start a new allocation for the next student
            pageCount = arr[i];
        }
    }
    return true; // All books have been allocated with valid conditions
}

//Approach 1: Using Binary Search Algorithm to find the minimum number of pages allocated to the student with the maximum allocation.
int allocateMinimumPages(vector<int> &arr, int books, int students) {
    if(students > books) {
        return -1; // Not enough books for each student
    }
    int low = 0, high, mid;
    int ans = -1, pageSum = 0;
    for(int i = 0; i < books; i++) {
        pageSum += arr[i]; // Calculate the sum of all book pages
    }

    high = pageSum; // Set the upper bound as the maximum possible allocation
    //Apply Binary Search
    while(low <= high) {
        mid = low + (high - low) / 2;
        // Check if the current mid value represents a possible solution
        if(isPossibleSolution(arr, books, students, mid)) {
            ans = mid; // Update the answer
            high = mid - 1; // Look for smaller allocations
        } else {
            low = mid + 1; // Look for larger allocations
        } 
    }
    return ans; // Return the minimum number of pages allocated to the student with maximum allocation
}

int main() {
    vector<int> arr = {10,20,30,40};
    cout<<"The Minimum possible value of pages allocated to student with maximum pages is : "<<allocateMinimumPages(arr, 4, 2);
    return 0;
}
