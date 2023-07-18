#include<iostream>

using namespace std;

//Approach 1: Function to find LCM using the Brute Force Approach
int findLCM(int a, int b) {
    int lcm = max(a, b);
    while(true) {
        // Check if lcm is a common multiple for both 'a' and 'b'
        if(lcm % a == 0 && lcm % b == 0) {
            break;
        }
        lcm++;
    }
    return lcm;
}

// Function to find GCD using the Euclidean Algorithm
int findGCDUsingEuclidAlgorithm(int a, int b) {
    if(b == 0) {
        return a; // Base case: when b becomes 0, a is the GCD
    }
    // Recursively call the function with b and the remainder of a/b
    findGCDUsingEuclidAlgorithm(b, a % b);
}

//Approach 2: Function to find LCM using GCD with the help of Euclid Algorithm
int findLCMUsingGCD(int a, int b) {
    // Find the GCD of 'a' and 'b' using the Euclidean Algorithm
    int gcd = findGCDUsingEuclidAlgorithm(a, b);
    // Calculate the LCM using the formula: LCM(a, b) = (a * b) / GCD(a, b)
    return (a * b) / gcd;
}

int main() {
    int a = 2, b = 3;
    cout<<"Using the brute force approach"<<endl;
    cout<<"The LCM of "<<a<<" and "<<b<<" is: "<<findLCM(a, b)<<endl;
    cout<<"Using the Euclid algorithm"<<endl;
    cout<<"The LCM of "<<a<<" and "<<b<<" is: "<<findLCMUsingGCD(a, b)<<endl;
    return 0;
}
