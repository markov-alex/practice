#include <bits/stdc++.h>

unsigned long long factmod(unsigned long long n, unsigned long long p) {
    unsigned long long res = 1;
    while (n > 1) {
        res = (res * ((n / p) % 2 ? p - 1 : 1)) % p;
        for (unsigned long long i = 2; i <= n % p; ++i) {
            res = (res * i) % p;
        }
        n /= p;
    }

    return res % p;
}

int main() {
    long long n;
    std::cin >> n;
    if (n >= 13) {
        std::cout << 0 << "\n";
        return 0;
    } 
    if (n == 12) {
        std::cout << 527656359 << "\n";
        return 0;
    }

    unsigned long long mod = 998244353;

    unsigned long long fact = 1;

    for (long long i = 1; i <= n; i++) {
        fact *= i;
    }
    unsigned long long res = factmod(fact, mod);
    std::cout << res << "\n";   
    
    return 0;
}