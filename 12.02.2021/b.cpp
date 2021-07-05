#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long n, q, k;
    std::cin >> n >> q >> k;
    std::vector<long long> a(n + 1);
    for (long long i = 0; i < n; i++) {
        std::cin >> a[i + 1];
    }
    long long l, r, res;
    for (long long i = 0; i < q; i++) {
        std::cin >> l >> r;
        res = a[r] - a[l] - 2 * (r - l) + k - 1;
        std::cout << res << "\n";
    }

    return 0;
}