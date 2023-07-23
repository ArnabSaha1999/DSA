#include<iostream>
#include<unordered_map>

using namespace std;

// Recursive function to calculate the number of distinct ways to climb the stairs
int climbStairs(int nthStair) {
    // Base Case: If the nthStair is less than 0, there are no ways to climb, return 0.
    if(nthStair < 0) {
        return 0;
    }
    // Base Case: If the nthStair is 0 or 1, there is only one way to climb, return 1.
    if(nthStair == 0 || nthStair == 1) {
        return 1;
    }
    // Recursive Case: The number of ways to climb the nthStair is the sum of the ways to climb (nthStair - 1) and (nthStair - 2)
    return climbStairs(nthStair - 1) + climbStairs(nthStair - 2);
}

// Memoization map to store previously calculated ways
unordered_map<int, int> memo;

// Recursive function to calculate the number of distinct ways to climb the stairs with memoization
int climbStairsMemoization(int nthStair) {
    // Base Case: If the nthStair is less than 0, there are no ways to climb, return 0.
    if(nthStair < 0) {
        return 0;
    }
    // Base Case: If the nthStair is 0 or 1, there is only one way to climb, return 1.
    if(nthStair == 0 || nthStair == 1) {
        return 1;
    }
    // Check if the number of ways to climb the nthStair is already calculated and stored in 'memo'
    if(memo.count(nthStair)) {
        return memo[nthStair];
    }
    // If the number of ways to climb the nthStair is not already calculated, calculate it recursively
    memo[nthStair] = climbStairsMemoization(nthStair - 1) + climbStairsMemoization(nthStair - 2);
    // Return the calculated value and store it in 'memo' for future use
    return memo[nthStair];
}

int main() {
    int nthStair;
    cout<<"Enter the Stair to climb: "<<endl;
    cin>>nthStair;
    cout<<"The no. of distinct ways the climb "<<nthStair<<" stair is: "<<climbStairsMemoization(nthStair)<<endl;
    return 0;
}
