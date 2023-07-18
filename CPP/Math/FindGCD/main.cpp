#include<iostream>

using namespace std;

//Approach 1: Function to find GCD using the Brute Force Approach
int findGCD(int a, int b) {
    int gcd = min(a, b);
    while(gcd > 0) {
        // Check if gcd is a common divisor for both 'a' and 'b'
        if(a % gcd == 0 && b % gcd == 0) {
            break;
        }
        gcd--;
    }
    return gcd;
}

//Approach 2: Function to find GCD using the Euclidean Algorithm
int findGCDUsingEuclidAlgorithm(int a, int b) {
    // Base case: when b becomes 0, a is the GCD
    if(b == 0) {
        return a;
    }
    // Recursively call the function with b and the remainder of a/b
    findGCDUsingEuclidAlgorithm(b, a % b);
}

int main() {
    int a = 24, b = 72;
    cout<<"Using the brute force approach"<<endl;
    cout<<"The GCD of "<<a<<" and "<<b<<" is: "<<findGCD(a, b)<<endl;
    cout<<"Using the Euclid Algorithm"<<endl;
    cout<<"The GCD of "<<a<<" and "<<b<<" is: "<<findGCDUsingEuclidAlgorithm(a, b)<<endl;
}
