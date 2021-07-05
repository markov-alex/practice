#include <bits/stdc++.h>

double distance(const std::pair<long long, long long> &p1, 
                   const std::pair<long long, long long> &p2) {
    return std::sqrt(std::pow((p2.first - p1.first), 2) + std::pow((p2.second - p1.second), 2));
}

int main() {
    int n;
    std::cin >> n;

    std::vector<bool> occupied(n);
    std::vector<std::pair<long long, long long>> figure_skaters(n);

    long long x, y;
    for (int i = 0; i < n; i++) {
        std::cin >> x >> y;
        figure_skaters[i] = std::make_pair(x, y);
        occupied[i] = false;
    }

    std::vector<std::pair<std::pair<int, int>, double>> distances;

    double dist;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            dist = distance(figure_skaters[i], figure_skaters[j]);
            distances.push_back(std::make_pair(std::make_pair(i, j), dist));
        }
    }

    std::sort(distances.begin(), distances.end(), [](std::pair<std::pair<int, int>, double> p1, std::pair<std::pair<int, int>, double> p2) {
        return p1.second < p2.second;
    });

    std::vector<std::pair<int, int>> res(n / 2);
    int cnt = 0;

    for (auto elem: distances) {
        if (!occupied[elem.first.first] && !occupied[elem.first.second]) {
            occupied[elem.first.first] =  true;
            occupied[elem.first.second] = true;
            res[cnt] = elem.first;
            cnt++;
        }
    }

    std::sort(res.begin(), res.end(), [](std::pair<int, int> p1, std::pair<int, int> p2) {
        if (p1.first < p2.first) {
            return true;
        } else if (p1.first > p2.first) {
            return false;
        } else {
            if (p1.second <= p2.second) {
                return true;
            } else {
                return false;
            }
        }
    });

    for (const auto &p : res) {
        std::cout << p.first + 1 << " " << p.second + 1 << "\n";
    }

    return 0;
}