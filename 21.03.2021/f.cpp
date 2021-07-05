#include <bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n, m;

    std::vector<std::vector<int>> mtrx(n);
    for (int i = 0; i < n; i++) {
        mtrx[i].resize(m);
    }

    int min_i = 0, min_j = 0;
    bool first = true;
    int area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            std::cin >> ch;
            if (ch == '#') {
                if (first) {
                    min_i = i;
                    min_j = j;
                    first = false;
                }
                mtrx[i][j] = 1;
                area += 1;
            }
        }
    }

    if (area == 1) {
        std::cout << -1 << "\n";
    }

    return 0;
}