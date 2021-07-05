#include <bits/stdc++.h>

#define ull unsigned long long

const ull MOD = static_cast<ull>(std::pow(10, 9)) + 7;

ull mod_bin_pow(ull a, ull n) {
    ull res = 1;
    while (n) {
        if (n & 1) {
            res = (res % MOD * a % MOD) % MOD;
            --n;
        } else {
            a = (a % MOD * a % MOD) % MOD;
            n >>= 1;
        }
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int q;
    std::cin >> q;

    for (int it = 0; it < q; it++) {
        ull i1, i2, j1, j2;
        std::cin >> i1 >> i2 >> j1 >> j2;
        ull first = (mod_bin_pow(2, i1) % MOD * (mod_bin_pow(2, i2 - i1 + 1) % MOD - 1) % MOD) % MOD;
        ull second = (mod_bin_pow(3, j1) % MOD * ((mod_bin_pow(3, j2 - j1 + 1) % MOD - 1) % MOD * mod_bin_pow(2, MOD - 2) % MOD) % MOD) % MOD;
        
        std::cout << (first * second) % MOD << "\n";
    }

    return 0;
}