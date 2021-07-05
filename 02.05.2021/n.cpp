#include <bits/stdc++.h>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<bool>> input(n);
    for (int i = 0; i < n; i++) {
        input[i].resize(k);
    }

    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < k; j++) {
             if (s[j] == 'T') {
                 input[i][j] = true;
             } else {
                 input[i][j] = false;
             }
        }
    }

    std::vector<std::vector<bool>> tmp(n);
    for (int i = 0; i < n; i++) {
        tmp[i].resize(k);
    }

    int max_min = -1;
    for (int mask = 0; mask < static_cast<int>(std::pow(2, k)); mask++) {
        for (int i = 0; i < k; i++) {
            int res_mask = mask & (1 << i);
            if (res_mask == 0) {
                for (int j = 0; j < n; j++) {
                    tmp[j][k - i - 1] = input[j][k - i - 1];
                }
            } else {
                for (int j = 0; j < n; j++) {
                    if (input[j][k - i - 1]) {
                        tmp[j][k - i - 1] = false;
                    } else {
                        tmp[j][k - i - 1] = true;
                    }
                }
            }
        }
        int min;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < k; j++) {
                if (tmp[i][j])
                    cur++;
            }
            if (i == 0) {
                min = cur;
            } else if (cur < min) {
                min = cur;
            }
        }
        if (min > max_min) {
            max_min = min;
        }
    }

    std::cout << max_min << "\n";

    return 0;
}
