#include <bits/stdc++.h>

int main() {
    long long n;
    std::cin >> n;
    long long a, b, c;
    std::vector<bool> ans;
    for (auto i = 0; i < n; ++i) {
        std::cin >> a >> b >> c;
        if (b >= (a/2+1) && c>=(a/2)) {
            ans.push_back(true);
        } else {
            ans.push_back(false);
        }
    }
    for (auto i = 0; i < ans.size(); ++i) {
        if (ans[i]==true) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}