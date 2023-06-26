#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to check if a certain height is a possible solution
bool isPossibleSolution(vector<long long int> &trees, int size ,int wood, int mid) {
    long long int woodCount = 0;
    for(int i = 0; i < size; i++) {
        // Check if the tree height is greater than or equal to the current height (mid)
        if(trees[i] >= mid) {
            // Calculate the amount of wood that can be obtained from the tree
            woodCount += trees[i] - mid;
            // If the wood count is greater than or equal to the required wood, return true
            if(woodCount >= wood) {
                return true;
            }
        }
    }
    return false; // If the required wood cannot be obtained at the given height, return false
}

//Approach 1: Using Binary Search Algorithm to find the maximum height of the sawblade
long long int maximumHeight(vector<long long int> &trees, long long int size ,int wood) {
    // Sorting the tree heights in ascending order
    sort(trees.begin(), trees.end());
    long long int low = 0, high = trees[size - 1] - trees[0], mid, ans = 0;
    // Applying binary search to find the maximum height
    while(low <= high) {
        mid = low + (high - low) / 2;
        // Check if the current mid height is a possible solution
        if(isPossibleSolution(trees, size, wood, mid)) {
            ans = mid;
            low = mid + 1; // Look for larger height
        } else {
            high = mid - 1; // Look for smaller height
        }
    }
    return ans; // Return the maximum height found
}

int main() {
    vector<long long int> trees = {26, 4, 42, 40, 46};
    cout<<maximumHeight(trees,trees.size() ,20);
    return 0;
}

//Separate main function, so that the code works on the Spoj platform.
// int main() {
//     long long int size, requiredWood;
//     cin>>size>>requiredWood;
//     // Creating a vector to store tree heights
//     vector<long long int> trees (size, 0);
//     for(long long int i = 0;i < size; i++)
//         cin>>trees[i];
//     // Finding the maximum height and outputting the result
//     cout<<maximumHeight(trees, size, requiredWood);
// }
