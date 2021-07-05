#include <bits/stdc++.h>
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        long long n, m, k;
        long long num = 0;
        std::set<std::pair<char, char> > start_end;
        std::cin >> n >> m >> k;
        std::string a, b;
        std::cin >> a >> b;
        for (long long i = 0; i + k - 1 < n; i++)
            start_end.insert(std::make_pair(a[i], a[i + k - 1]));
        for (auto s_e : start_end) {
            char s = s_e.first, e = s_e.second;
            long long num_ends = 0;
            if (s != e) {
                for (long long j = m - 1; j >= 0; j--) {
                    if (b[j] == e) {
                        num_ends++;
                    } else if (b[j] == s) {
                        num += num_ends;
                    }
                }
            } else {
                for (long long j = m - 1; j >= 0; j--) {
                    if (b[j] == e) {
                        num_ends++;
                        num += (num_ends);
                    }
                }
            }
        }
        std::cout << num << "\n";
    }
    return 0;
}