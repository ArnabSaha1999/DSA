#include<iostream>
#include<vector>
using namespace std;

// Function to check if a given allocation of weight is a possible solution
bool isPossibleSolution(vector<int> &weights, int days, int mid) {
    int daysCount = 1, weightCount = 0;
    for(int i = 0; i < weights.size(); i++) { // Iterate through the weights
        if(weightCount + weights[i] <= mid) {
            weightCount += weights[i];
        } else {
            // Move to the next day and check if the allocation is valid
            daysCount++;
            if(daysCount > days || weights[i] > mid) {
                // If the number of days exceeds the given limit
                // or a weight is more than the maximum allowed, return false
                return false;
            }
            // Start a new allocation for the next day.
            weightCount = weights[i];
        }
    }
    return true; // weights have been allocated within the given days
}

//Approach 1: Using Binary Search Algorithm to find the least weight allocated to each day.
int shipWithinDays(vector<int> &weights, int days) {
    int low = 0, high, mid;
    int ans = -1, weightSum = 0;
    for(int weight : weights) {
        weightSum += weight;
    }

    high = weightSum; // Set the upper bound as the maximum possible weight
    //Apply Binary Search
    while(low <= high) {
        mid = low + (high - low) / 2;
        // Check if the current mid value represents a possible solution
        if(isPossibleSolution(weights, days, mid)) {
            ans = mid; // Update the answer
            high = mid - 1; // Look for smaller weights
        } else {
            low = mid + 1; // Look for larger weights
        } 
    }
    return ans; // Return the least weight allocated to each days
}

int main() {
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    cout<<"The least weight capacity to ship all the packages within given days is : "<<shipWithinDays(weights, 5)<<endl;
    return 0;
}
