#include <bits/stdc++.h>

#define ll long long

int main() {
    ll n, k;
    std::cin >> n >> k;

    if (n & 0) {

    } else {
        std::vector<ll> cnt(n, 0);
        ll cur = 0;
        for (ll i = 0; i < n; i++) {
            cnt[cur]++;
            cur = (cur + k) % n;
        }
        for (ll i = 0; i < n; i++) {
            if (cnt[i] != 1) {
                std::cout << "No\n";
                return 0;
            }
        }
        std::cout << "Yes\n";
    }

    return 0;
}