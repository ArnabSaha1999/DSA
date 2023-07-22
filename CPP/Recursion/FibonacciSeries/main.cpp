#include<iostream>
#include<unordered_map>

using namespace std;

// Recursive function to calculate the nth Fibonacci number
int fibonacciSeries(int sequence) {
    if(sequence <= 1) {
        return sequence; // Base case: 0 for sequence = 0, 1 for sequence = 1
    }
    // Recursive case: Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)
    return fibonacciSeries(sequence - 1) + fibonacciSeries(sequence - 2);
}

// Memoization using an unordered_map to store calculated Fibonacci values
unordered_map<int, int> memo;

// Recursive function to calculate the nth Fibonacci number with memoization
int fibonacciSeriesMemoization(int sequence) {
    if(sequence <= 1) {
        return sequence; // Base case: 0 for sequence = 0, 1 for sequence = 1
    }
    // Check if the Fibonacci value for the given 'sequence' is already calculated and stored in 'memo'
    if(memo.count(sequence)) {
        return memo[sequence]; // Return the cached value
    }
    // If the Fibonacci value is not already calculated, calculate it recursively
    memo[sequence] = fibonacciSeriesMemoization(sequence - 1) + fibonacciSeriesMemoization(sequence - 2);
    return memo[sequence];
}

int main() {
    int sequence;
    cout<<"Enter the range of Sequence";
    cin>>sequence;
    cout<<"The "<<sequence<<" term of Fibonacci Series: "<<fibonacciSeriesMemoization(sequence)<<endl;
    return 0;
}
