#include<iostream>
#include<unordered_map>

using namespace std;

//Approach 1: Function to compute factorial using iterative approach
long long int factorialIterative(int n) {
    long long int res = 1;
    for(int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

//Approach 2: Function to compute factorial using recursive approach
long long int factorialRecursive(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    return n * factorialRecursive(n - 1);
}

unordered_map<int, long long int> memo;

//Approach 3: Function to compute factorial using memoization approach
long long int factorialMemoization(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    // Check if the result is already calculated and stored in the memoization table
    if(memo.find(n) != memo.end()) {
        return memo[n];
    }
    // Calculate the factorial recursively and store the result in the memoization table
    memo[n] = n * factorialMemoization(n - 1);
    return memo[n];
}

int main() {
    int n;
    cout<<"Enter a number to find factorial: "<<endl;
    cin>>n;
    // Compute and display the factorial using iterative approach
    cout<<"The factorial of "<<n<<" using the iterative way: "<<factorialIterative(n)<<endl;
    // Compute and display the factorial using recursive approach
    cout<<"The factorial of "<<n<<" using the recursive way: "<<factorialRecursive(n)<<endl;
    // Compute and display the factorial using memoization approach
    cout<<"The factorial of "<<n<<" using memoization: "<<factorialMemoization(n)<<endl;
    return 0;
}
