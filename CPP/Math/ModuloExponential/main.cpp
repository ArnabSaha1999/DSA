#include <iostream>

using namespace std;

//Approach 1: Brute Force (Naive) Approach
int powerModBruteForce(int x, int n, int m) {
    long long result = 1;
    for (int i = 0; i < n; ++i) {
        result = (result * x) % m;
    }
    return static_cast<int>(result);
}

//Approach 2: Exponentiation by Squaring Approach
int powerModExponentiationBySquaring(int x, int n, int m) {
    long long result = 1;
    long long base = x;

    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * base) % m;
        }
        base = (base * base) % m;
        n /= 2;
    }

    return static_cast<int>(result);
}

int main() {
    int x = 5;
    int n = 3;
    int m = 1000000007;

    cout<<"Input values: x = "<<x<<", n = "<<n<<", m = "<<m<<endl;

    // Brute Force Approach
    int result1 = powerModBruteForce(x, n, m);
    cout<<"Brute Force Result: "<<result1<<endl;

    // Exponentiation by Squaring Approach
    int result2 = powerModExponentiationBySquaring(x, n, m);
    cout<<"Exponentiation by Squaring Result: "<<result2<<endl;
    return 0;
}
