#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    long long a, b;
    for (int i = 0; i < t; i++) {
        std::cin >> a >> b;
        long long last = 3000000;
        int j = 0;
        long long res = 0;
        while (true) {
            long long aa = a;
            long long bb = b + j;
            long long cnt = 0;
            if (bb == 1) {
                j++;
                continue;
            }
            while (aa > 0) {
                aa /= bb;
                cnt++;
            } 
            res = cnt + j;
            if (res > last) {
                res = last;
                break;
            }
            last = res;
            j++;
        }
        std::cout << res << "\n";
    }
    return 0;
}