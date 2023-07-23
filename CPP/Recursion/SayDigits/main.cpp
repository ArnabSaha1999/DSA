#include<iostream>

using namespace std;

// Recursive function to convert the digits of a number to words
void sayDigits(int num, string* arr) {
    // Base Case: If the number is 0, there are no digits to convert, return.
    if(num == 0) {
        return;
    }
    // Recursive Case: Convert the digits recursively from the most significant digit to the least significant digit
    sayDigits(num / 10, arr);
    // Print the word representation of the current digit (num % 10) using the arr array.
    cout<<arr[num%10]<<" ";
    return;
}

int main() {
    int num;
    cout<<"Enter the number to print in words: "<<endl;
    cin>>num;
    // Array to store word representations of digits from "zero" to "nine".
    string arr[10] = {
        "zero", "one", "two",
        "three", "four", "five",
        "six", "seven", "eight", "nine"
    };
    
    cout<<"The number "<<num<<" in words: "<<endl;
    sayDigits(num, arr);
    return 0;
}
