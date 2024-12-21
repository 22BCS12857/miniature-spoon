#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 50734912;
const long MOD = 1e9 + 7;
long factorial[MAX_N];
long inverseFactorial[MAX_N];

// Quick Modulo Exponentiation Function
long long qmi(long long base, long long exponent, long long modulus) {
    long long res = 1;
    while (exponent != 0) {
        if (exponent & 1) {
            res = res * base % modulus;
        }
        exponent >>= 1;
        base = base * base % modulus;
    }
    return res;
}

// Precompute factorials and modular inverses
void initializeFactorials() {
    factorial[0] = 1;
    inverseFactorial[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        factorial[i] = factorial[i - 1] * i % MOD;
        inverseFactorial[i] = qmi(factorial[i], MOD - 2, MOD);
    }
}

// Compute binomial coefficient using precomputed factorials and inverses
long long comb(int n, int k) {
    if (k > n) return 0;
    return (factorial[n] * inverseFactorial[k] % MOD) * inverseFactorial[n - k] % MOD;
}

// Decompose number into prime factors
vector<int> getPrimeFactors(int x) {
    vector<int> primeFactorCounts;
    for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0) {
            int count = 0;
            while (x % i == 0) {
                ++count;
                x /= i;
            }
            primeFactorCounts.push_back(count);
        }
    }
    if (x > 1) {
        primeFactorCounts.push_back(1);
    }
    return primeFactorCounts;
}

class Solution {
public:
vector<int> waysToFillArray(vector<vector<int>>& queries) {
    initializeFactorials(); // Ensure factorials are precomputed
    vector<int> answer;
    for (auto& q : queries) {
        int n = q[0], k = q[1];
        long long totalWays = 1;

        // Get prime factors of k and calculate ways
        vector<int> primeFactorCounts = getPrimeFactors(k);
        for (int primeFactorCount : primeFactorCounts) {
            totalWays = totalWays * comb(primeFactorCount + n - 1, n - 1) % MOD;
        }
        // Wrap into non-negative range
        totalWays = (totalWays % MOD + MOD) % MOD;
        answer.push_back(totalWays);
    }
    return answer;
}

};

int main() {
    Solution s;

    // Example queries
    vector<vector<int>> queries = {
        {2, 6},
        {5, 1},   
        {73, 660}, 
    };

    vector<int> results = s.waysToFillArray(queries);

    cout << "Results for the queries:" << endl;
    for (size_t i = 0; i < queries.size(); ++i) {
        cout << "Query: n = " << queries[i][0] << ", k = " << queries[i][1]
             << " -> Ways: " << results[i] << endl;
    }

    return 0;
}
