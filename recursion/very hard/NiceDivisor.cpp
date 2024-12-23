#include <iostream>
#include <cmath>
using namespace std;
const int MOD = 1e9 + 7;

int maxNiceDivisors(int primeFactors) {
    if (primeFactors <= 3) return primeFactors;

    long long result = 1;
    
    while (primeFactors > 4) {
        result = (result * 3) % MOD;
        primeFactors -= 3;
    }
    
    return (result * primeFactors) % MOD;
}

int main() {
     cout << maxNiceDivisors(5) <<  endl;  // Output: 6
     cout << maxNiceDivisors(8) <<  endl;  // Output: 18
    return 0;
}
