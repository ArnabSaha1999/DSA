#include<iostream>
#include<vector>

using namespace std;

//Approach 1: Check if a number is prime using brute force
bool isPrime(int n) {
    for(int i = 2; i < n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

//Approach 2: Check if a number is prime using optimized Brute Force approach
bool isPrimeOptimized(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

// Count the prime numbers up to n using optimized brute force approach
int countPrimes(int n) {
    if(n <= 1) {
        return 0;
    }
    int count = 0;
    cout<<"The Prime numbers: "<<endl;
    for(int i = 2; i < n; i++) {
        if(isPrimeOptimized(i)) {
            count++;
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return count;
}

// Count the prime numbers up to n using Sieve of Eratosthenes
bool countPrimesSieveOfEratosthenes(int n) {
    if(n <= 1) {
        return 0;
    }
    int count = 0;
    vector<bool> isPrime(n, true);
    // Apply Sieve of Eratosthenes algorithm
    for(int i = 2; i < n; i++) {
        if(isPrime[i]) {
            count++;
            cout<<i<<" ";
            // Mark all multiples of i as non-prime
            for(int j = 2 * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }

    }
    cout<<endl;
    return count;
}

int main() {
    int numbers;
    cout<<"Enter the numbers to find the Primes: "<<endl;
    cin>>numbers;
    cout<<"The count: "<<countPrimes(numbers)<<endl;
    cout<<"Using Sieve of Eratosthenes:"<<endl;
    cout<<"The count: "<<countPrimesSieveOfEratosthenes(numbers)<<endl;
    return 0;
}
