#include<iostream>

using namespace std;

int bitwiseComplement(int n) {
    if(n == 0)
        return 1;
    int mask = 0;
    int temp = n;
    /*
    In each iteration of the while loop, 
    the function shifts temp one bit to the right (temp >>= 1), 
    and sets the rightmost bit of mask to 1 by shifting mask one bit to the left and OR-ing it with 1 (mask = (mask << 1) | 1).
    After the loop completes, the mask variable will contain a sequence of 1's with the same length as the binary representation of n
    */
    while(temp != 0) {
        temp >>= 1;
        mask = (mask << 1) | 1;
    }
    return (~n) & mask;
}

int main() {
    int n;
    cout<<"Enter the number to find complement: ";
    cin>>n;
    cout<<"The Complement of base 10 of "<<n<<" is : "<<bitwiseComplement(n)<<endl;
    return 0;
}
