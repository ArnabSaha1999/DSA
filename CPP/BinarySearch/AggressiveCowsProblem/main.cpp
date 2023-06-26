#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to check if a given allocation is a possible solution
bool isPossibleSolution(vector<int> &stalls, int aggressiveCows, int mid) {
    int cowCount = 1, lastStall = stalls[0];
    for(int i = 1; i < stalls.size(); i++) { // Iterate through the stalls
        if(stalls[i] - lastStall >= mid) {
            cowCount++; // place aggressive cow here and check if the cow count matches the aggressive cows
            if(cowCount == aggressiveCows) {
                return true; //Return true if all aggressive cows are placed within mid value.
            }
            lastStall = stalls[i]; //Updating the last stall where cow is placed.
        }
    }
    return false; //Not possible to place the aggressive cows within the mid value.
}

//Approach 1: Using Binary Search Algorithm to find the maximum minimum distance of aggressive cows.
int aggressiveCows(vector<int> &stalls, int aggressiveCows) {
    sort(stalls.begin(), stalls.end()); //Sort the stalls
    int low = 0, high = stalls[stalls.size() - 1] - stalls[0], mid, ans = 0; //Set lower and upper bound. Upper is bound difference of first and last stall.
    //Apply Binary Search
    while(low <= high) {
        mid = low + (high - low) / 2;
        // Check if the current mid value represents a possible solution
        if(isPossibleSolution(stalls, aggressiveCows, mid)) {
            ans = mid;
            low = mid + 1; //Look for larger distance.
        } else {
            high = mid - 1; // Look for smaller distance.
        }
    }
    return ans; //Return the ans of maximum minimum distance.
}

int main() {
    vector<int> stalls = {4,2,1,3,6};
    cout<<"The maximum minimum distance is: "<<aggressiveCows(stalls, 2)<<endl;
    return 0;
}
