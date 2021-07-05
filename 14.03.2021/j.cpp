#include <bits/stdc++.h>

int main() {
    long long t, m, n, k;
    std::cin >> t;
    std::vector<long long> ans;
    for (auto i = 0; i < t; ++i) {
        long long seen = -1;
        std::cin >> n >> m >> k;
        k--;
        getchar();
        long long count = 0;
        std::string s;
        long long pos;
        std::getline(std::cin, s);
        std::vector<bool> isShort;
        for (auto j = 0; j < s.size(); ++j) {
            if (s[j] == 'S' || s[j] == 'B') {
                if (s[j] == 'S') {
                    isShort.push_back(true);
                } else {
                    isShort.push_back(false);
                }
            }
        }
        for (auto j = 0; j < m; ++j) {
            char c = getchar();
            if (c=='W') {
                std::cin >> pos;
                pos--;
                if (pos<=k || (isShort[pos] == true && seen>=pos)) {
                    count++;
                }
                if (seen<pos) {
                    seen = pos;
                }
            } else {
                seen = n-1;
            }
            c = getchar();
        }
        ans.push_back(count);
    }
    for (auto i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << std::endl;
    }
    return 0;
}