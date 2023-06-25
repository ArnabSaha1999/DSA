#include<iostream>
using namespace std;

//Approach 1: Brute force approach to find square root of a number
int sqrtBruteForce(int x) {
    int ans = 0;
    for (long long int i = 1; i <= x; i++) {
        long long int square = i * i;
        if(square == x) {
            return i; // If the square is equal to x, return the current number as the square root
        } else if(square < x) {
            ans = i; // If the square is less than x, update the answer to the current number
        } else {
            break; // If the square exceeds x, break the loop as we can't find an exact square root
        }
    }
    return ans; // Return the last valid square root found
}

//Approach 2: Binary search approach to find square root of a number
int sqrt(int x) {
    long long int low = 0, high = x, mid;
    while(low <= high) {
        mid = low + (high - low) / 2;
        long long int square = mid * mid; // Calculate the square of the middle number
        if(square == x) {
            return mid; // If the square is equal to x, return the middle number as the square root
        } else if(square > x) {
            high = mid - 1; // If the square is greater than x, search in the lower half
        } else {
            low = mid + 1; // If the square is less than x, search in the upper half
        }
    }
    return high; // Return the last valid square root found
}

// Function to find the square root with desired precision
double findPrecision(int x, int precision, int intAns) {
    double factor = 1, ans = intAns;
    for(int i = 0; i < precision; i++) {
        factor = factor / 10; // Update the factor to adjust precision (dividing by 10)
        for(double j = ans; j * j <= x; j = j+factor) {
            ans = j; // Iterate and update the answer to the current number until the square exceeds x
        }
    }
    return ans;
}

int main() {
    int x = 65, precision = 2;
    int intAns = sqrt(x);
    cout<<"The sqauare root of "<<x<<" is : "<< findPrecision(x, precision, intAns)<<endl;
    return 0;
}
