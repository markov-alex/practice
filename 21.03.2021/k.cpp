#include <bits/stdc++.h>

std::vector<std::list<int>> adjacency_list;
std::vector<bool> visited;
std::vector<int> height;

void dfs_visit(int u, int h) {
    visited[u] = true;
    height[h]++;
    for (int v : adjacency_list[u]) {
        if (!visited[v]) {
            dfs_visit(v, h + 1);
        }
    }
}

void dfs() {
    visited[0] = true;
    height[0] = 1;
    for (int u : adjacency_list[0]) {
        if (!visited[u]) {
            dfs_visit(u, 1);
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    adjacency_list.resize(n);
    visited.assign(n, false);
    height.resize(n);

    int to;
    for (int i = 0; i < n - 1; i++) {
        std::cin >> to;
        adjacency_list[i + 1].push_back(to - 1);
        adjacency_list[to - 1].push_back(i + 1);
    }

    dfs();
    int res = 0;
    for (int i = 0; i < n && height[i] != 0; i++) {
        res += (height[i] % 2);
    }

    std::cout << res << "\n";

    return 0;
}