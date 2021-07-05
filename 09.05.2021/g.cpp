#include <bits/stdc++.h>

int main() {
    int m, g, n;
    std::cin >> m >> g >> n;

    std::vector<std::vector<int>> A(m + 1);
    for (int i = 0; i < m + 1; ++i) {
        A[i].resize(g + 1);
    }

    std::vector<int> a(n);
    std::vector<int> b(n);
    std::vector<int> c(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i] >> b[i] >> c[i];
    }

    for (int u = 0; u < m + 1; ++u) {
        for (int v = 0; v < g + 1; ++v) {
            int max = 0;
            for (int k = 0; k < n; ++k) {
                int i = u - a[k];
                int j = v - b[k];
                if (i < 0 || j < 0) {
                    continue;
                } else {
                    int tmp = A[i][j] + c[k];
                    if (tmp > max) {
                        max = tmp;
                    }
                }
            }
            A[u][v] = max;
        }
    }

    std::cout << A[m][g] << "\n";

    return 0;
}