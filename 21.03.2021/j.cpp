#include <bits/stdc++.h>

#define ull unsigned long long

std::vector<std::list<int>> adjacency_list;
std::vector<bool> visited;
std::vector<int> first_set;
std::vector<int> second_set;

void dfs_visit(int u, int set) {
    visited[u] = true;
    if (set == 1) {
        first_set.push_back(u);
    } else {
        second_set.push_back(u);
    }
    for (int v : adjacency_list[u]) {
        if (!visited[v]) {
            if (set == 1) {
                dfs_visit(v, 2);
            } else {
                dfs_visit(v, 1);
            }
        }
    }
}

void dfs() {
    visited[0] = true;
    first_set.push_back(0);
    for (int u : adjacency_list[0]) {
        if (!visited[u]) {
            dfs_visit(u, 2);
        }
    }
}

ull res = 0;

int main() {
    int n;
    std::cin >> n;
    adjacency_list.resize(n);
    visited.assign(n, false);

    int from, to;
    for (int i = 0; i < n - 1; i++) {
        std::cin >> from >> to;
        adjacency_list[from - 1].push_back(to - 1);
        adjacency_list[to - 1].push_back(from - 1);
    }

    dfs();

    if (first_set.size() < second_set.size()) {
        for (int v : first_set) {
            res += second_set.size() - adjacency_list[v].size();
        }
    } else {
        for (int v : second_set) {
            res += first_set.size() - adjacency_list[v].size();
        }
    }

    std::cout << res << "\n";

    return 0;
}