#include <bits/stdc++.h>

#define vv std::vector<std::vector<long long>>
#define vvp std::vector<std::vector<std::pair<int, int>>>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<long long> c(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        std::cin >> c[i];
    }

    int size = (m > k) ? m + 1: k + 1;

    vv dp(size + 1);
    for (int i = 0; i < size + 1; ++i) {
        dp[i].resize(size + 1);
    }

    vvp path(size + 1);
    for (int i = 0; i < size + 1; ++i) {
        for (int j = 0; j < size + 1; ++j) {
            path[i].push_back(std::make_pair(-1, -1));
        }
    }

    
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (i == 0 && j == 0) {
                continue;
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][j] + c[i + 2 * j];
                path[i][j] = std::make_pair(i - 1, j);
            } else if (i == 0) {
                dp[i][j] = dp[i][j - 1] + c[i + 2 * j];
                path[i][j] = std::make_pair(i, j - 1);
            } else if (dp[i - 1][j] + c[i + 2 * j] > dp[i][j - 1] + c[i + 2 * j]) {
                dp[i][j] = dp[i - 1][j] + c[i + 2 * j];
                path[i][j] = std::make_pair(i - 1, j);
            } else {
                dp[i][j] = dp[i][j - 1] + c[i + 2 * j];
                path[i][j] = std::make_pair(i, j - 1);
            }
        }
    }

    std::cout << dp[m][k] << "\n";
    std::stack<int> st;
    int i = path[m][k].first, j = path[m][k].second;
    st.push(m + 2 * k);
    while (i != -1 && j != -1) {
        st.push(i + 2 * j);
        int cur_i = i;
        i = path[i][j].first;
        j = path[cur_i][j].second;
    }

    while (!st.empty()) {
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << "\n";

    return 0;
}