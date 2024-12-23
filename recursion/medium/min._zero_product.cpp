#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

// Function to compute (base^exp) % mod using modular exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) { // If exp is odd
            result = (result * base) % mod;
        }
        base = (base * base) % mod; // Square the base
        exp /= 2; // Divide the exponent by 2
    }
    return result;
}

int minNonZeroProduct(int p) {
    long long maxValue = (1LL << p) - 1; // 2^p - 1
    long long count = (1LL << (p - 1)) - 1; // 2^(p-1) - 1

    // Compute the result using the formula
    long long result = modExp(maxValue - 1, count, MOD);
    result = (result * maxValue) % MOD;

    return result;
}

int main() {
    int p = 3; // Example input
    cout << "Minimum Non-Zero Product: " << minNonZeroProduct(p) << endl;
    return 0;
}
