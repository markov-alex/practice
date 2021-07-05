#include <bits/stdc++.h>

int main() {
    std::string x;
    std::cin >> x;
    long long mod = 998244353;
    long long res = 0;
    for (std::string::iterator it = x.begin(); it != x.end(); it++) {
        res = (res * 10 + (*it - '0')) % mod;
    }
    std::cout << res << "\n";
    return 0;
}