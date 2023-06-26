#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to check if a certain time is a possible solution
bool isPossibleSolution(vector<int> &rank, int targetDishes, int mid) {
    int cookedDishes = 0, time = 0;
    for(int i = 0; i < rank.size(); i++) {
        time = rank[i];
        int multiplier = 2;
        while(time <= mid) { //Check if the time taken is less or equal to mid or not.
            cookedDishes++;
            if(cookedDishes == targetDishes) { //if number of dishes cooked is equal to target dishes then found a possible solution.
                return true;
            }
            time += rank[i] * multiplier; // Increase the cooking time for the current rank
            multiplier++; // Increment the multiplier for subsequent dishes
        }
    }
    return false;
}

//Approach 1: Using Binary Search Algorithm to find the minimum time required to cook the pratas.
int minCookTime(vector<int> &rank, int targetDishes)
{
    sort(rank.begin(), rank.end());
    int low = 0, mid, ans = -1;
    // Calculate the maximum possible time by multiplying the maximum rank by the sum of the target dishes
    // The maximum possible time ensures that each dish can be cooked individually for the maximum rank
    int high = ((targetDishes * (targetDishes + 1)) / 2) * rank[rank.size() - 1];
    // Binary search to find the minimum cooking time
    while(low <= high) {
        mid = low + (high - low) / 2;
        if(isPossibleSolution(rank, targetDishes, mid)) {
            ans = mid;
            high = mid - 1; // Look for smaller time
        } else {
            low = mid + 1; // Look for larger time
        }
    }
    // Return the minimum cooking time found
    return ans;
}

int main() {
    vector<int> rank = {8,3,4,5,1,3};
    cout<<"The minimum time to cook the dishes is : "<<minCookTime(rank, 15)<<endl;
    return 0;
}
