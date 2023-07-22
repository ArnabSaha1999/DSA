#include<iostream>
#include<unordered_map>
using namespace std;

// Recursive function to calculate the factorial of a number
long long int factorial(int num) {
    // Base Case: Factorial of 0 and 1 is 1
    if(num == 0 || num == 1) {
        return 1;
    }
    // Recursive Case: Multiply the number by factorial of (num - 1)
    return num * factorial(num - 1);
}

unordered_map<int, int> memo;

// Recursive function to calculate the factorial of a number with memoization
long long int factorialMemoization(int num) {
    // Base Case: Factorial of 0 and 1 is 1
    if(num == 0 || num == 1) {
        return 1;
    }
    // Check if the factorial of 'num' is already calculated and stored in 'memo'
    if(memo.count(num)) {
        return memo[num];
    }
    // If the factorial is not already calculated, calculate it recursively
    memo[num] = num * factorial(num - 1);
    return memo[num]; // Return the calculated value and store it in 'memo' for future use
}
int main() {
    int num;
    cout<<"Enter the number to calculate Factorial: "<<endl;
    cin>>num;
    cout<<"The Factorial of "<<num<<": "<<factorialMemoization(num)<<endl;
    return 0;
}
