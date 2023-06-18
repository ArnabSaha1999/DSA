#include<iostream>
#include<climits>
#include<string>

using namespace std;

//Approach 1: Using Arithmetic operator and while loop.
int reverseDigit(int num) {
    int sign = (num < 0) ? -1 : 1;
    int tempNum = 0;
    num = abs(num);
    while(num != 0) {
        int remainder = num % 10;
        if((tempNum > (INT_MAX)/10) || (tempNum < (INT_MIN)/10)) 
            return 0;
        tempNum = tempNum * 10 + remainder;
        num /= 10;
    }
    return sign * tempNum;
}

//Approach 2: Using Recursion
//The reverseDigitRecursively function calls the reverseDigitHelper.
int reverseDigitHelper(int num, int tempNum) {
    if(num == 0)
        return tempNum;
    int remainder = num % 10;
    if((tempNum > (INT_MAX)/10) || (tempNum < (INT_MIN)/10))
        return 0;
    tempNum = tempNum * 10 + remainder;
    return reverseDigitHelper(num / 10, tempNum);
}

int reverseDigitRecursively(int num) {
    int sign = (num < 0) ? -1 : 1;
    num = abs(num);
    return sign * reverseDigitHelper(num, 0);
}

//Approach 3: Using String Manipulation
int reverseDigitUsingString(int num) {
    int sign = (num < 0) ? -1 : 1;
    string numString = to_string(num);
    int length = numString.length();
    for(int i = 0; i < length/2; i++) {
        char temp = numString[i];
        numString[i] = numString[length-i-1];
        numString[length-i-1] = temp;
    } try {
        int reversedDigit = stoi(numString);
        return sign * reversedDigit;

    }
    catch (out_of_range& err) {
        return 0;
    }
}

int main(){
    int num;
    cout<<"Enter the number to reverse: ";
    cin>>num;
    cout<<"After reversing the number: "<<reverseDigit(num)<<endl;
    return 0;
}
