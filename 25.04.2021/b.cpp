#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
    ll n;
    ll m;
    cin >> n >> m;
    vector<ll> digits;
    ll a;
    for (auto i = 0; i < m; ++i) {
        cin >> a;
        digits.push_back(a);
    }
    vector<ll> good_digits;
    for (auto i = 0; i < 10; ++i) {
        bool flag = false;
        for (auto j = 0; j < m; ++j) {
            if (digits[j] == i) {
                flag = true;
            }
        }
        if (!flag) {
            good_digits.push_back(i);
        }
    }

    sort(good_digits.begin(), good_digits.end());
    ll base = good_digits.size();
    vector<ll> ans;
    while (n) {
        ans.push_back(n % base);
        n = n/base;
    }
    for (ll i = ans.size()-1; i >=0; --i) {
        cout << good_digits[ans[i]];
    }
    return 0;
}