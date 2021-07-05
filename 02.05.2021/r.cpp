#include <bits/stdc++.h>

#define ll long long

int main() {
    ll n, m;
    std::cin >> n >> m;

    std::vector<ll> senders(m);
    for (ll i = 0; i < m; ++i) {
        std::cin >> senders[i];
    }

    ll prev = 0;
    for (ll i = 0; i < m; ++i) {
        ll j;
        for (j = i - 1; j >= 0; --j) {
            if (senders[i] == senders[j])
                break;
        }
        ll res = prev + n - (i + 1 - (j + 1));
        std::cout << res << "\n";
        prev = res;
    }

    return 0;
}