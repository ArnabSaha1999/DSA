#include<iostream>

using namespace std;

// Recursive function to calculate the sum of digits in a number
int addDigit(int num) {
    // Base Case: If the number is less than or equal to 0, return 0.
    // This handles the case for non-positive numbers.
    if(num <= 0) {
        return 0;
    }
    // Recursive Case: Add the last digit (num % 10) to the sum of the remaining digits (num / 10).
    return (num % 10) + addDigit(num / 10);
}

int main() {
    int num;
    cout<<"Enter the number to calculate sum: "<<endl;
    cin>>num;
    cout<<"The sum of digits of number "<<num<<": "<<addDigit(num)<<endl;
    return 0;
}
