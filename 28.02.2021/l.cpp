#include <bits/stdc++.h>

int main() {
    unsigned long long n;
    std::cin >> n;
    std::vector<unsigned long long> C(n / 2 + 1);
    C[0] = 1;
    C[1] = 1;
    unsigned long long mod = 998244353;
    for (unsigned long long i = 2; i <= n / 2; i++) {
        for (unsigned long long k = 0; k < i; k++) {
            C[i] += ((C[k] % mod) * (C[i - 1 - k] % mod)) % mod;
            C[i] %= mod;
        }
    }

    std::cout << C[n / 2] << "\n";


    return 0;
}