#include<iostream>

using namespace std;

// Recursive function to calculate the power of a number
long long int power(int num, int pow) {
    // Base Case: Any number raised to the power of 1 is the number itself
    if(pow == 1) {
        return num;
    }
    // Base Case: Any number raised to the power of 0 is 1
    if(pow == 0 || num == 1) {
        return 1;
    }
    // Recursive Case: Multiply the number by (num ^ (pow - 1))
    return (num * power(num, pow - 1));
}

int main() {
    int num, pow;
    cout<<"Enter the Number and Exponent to calculate: "<<endl;
    cin>>num>>pow;
    cout<<num<<"^"<<pow<<": "<<power(num, pow)<<endl;
    return 0;
}
