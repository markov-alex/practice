#include <bits/stdc++.h>

int main() {
    int n, L;
    std::cin >> n >> L;

    int res[2] = {0, 0};

    int t, d, plus;
    for (int i = 0; i < n; i++) {
        std::cin >> t >> d;
        if (d == -1) {
            plus = 1;
        } else if (d < L) {
            plus = 2;
        } else {
            plus = 3;
        }
        res[t - 1] += plus;
    }

    std::cout << res[0] << ":" << res[1] << "\n";

    return 0;
}
