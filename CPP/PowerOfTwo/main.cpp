#include <iostream>
#include <climits>

using namespace std;

// Approach 1: Using for loop.
bool isPowerOfTwoLoop(int n)
{
    if (n <= 0)
        return false;
    int ans = 1;
    for (int i = 0; i <= 30; i++)
    {
        if (ans == n)
            return true;
        if (ans < (INT_MAX / 2))
        {
            ans *= 2;
        }
    }
    return false;
}

/* 
Use the bitwise AND operator (&) to check if n and n-1 have any common set bits (bits that are set to 1 in both numbers). 
If they don't have any common set bits, then n must be a power of 2. 
This is because powers of 2 have only one bit set to 1, and subtracting 1 from a power of 2 flips that bit to 0 and sets all lower-order bits to 1.
*/
bool isPowerOfTwoBitwise(int n)
{
    return (n > 0 && (n & (n - 1) == 0));
}

int main()
{
    int num;
    cout << "Enter the number to check : ";
    cin >> num;
    if (isPowerOfTwoBitwise(num))
        cout << "Yes " << num << " is a power of 2" << endl;
    else
        cout << "No " << num << " is not a power of 2" << endl;
    return 0;
}
