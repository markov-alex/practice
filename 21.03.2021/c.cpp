#include <bits/stdc++.h>

std::vector<std::list<int>> adjacency_list;
std::vector<bool> visited;
std::vector<bool> leaf;
int res = 0;

void dfs_visit(int u) {
    visited[u] = true;
    int cnt = 0;
    int son = 0;
    for (int v : adjacency_list[u]) {
        if (!visited[v]) {
            cnt++;
            son = v;
            dfs_visit(v);
        }
    }

    if (cnt == 0) {
        leaf[u] = true;
    } else if (cnt == 1) {
        if (leaf[son]) {
            res++;
        }
    }

}

void dfs() {
    visited[0] = true;
    for (int u : adjacency_list[0]) {
        if (!visited[u]) {
            dfs_visit(u);
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    adjacency_list.resize(n);
    visited.assign(n, false);
    leaf.assign(n, false);

    int from, to;
    for (int i = 0; i < n - 1; i++) {
        std::cin >> from >> to;
        adjacency_list[from - 1].push_back(to - 1);
        adjacency_list[to - 1].push_back(from - 1);
    }

    dfs();
    std::cout << res << "\n";

    return 0;
}