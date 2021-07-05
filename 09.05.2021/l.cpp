#include <bits/stdc++.h>

int main() {
    int alpha, beta;
    std::cin >> alpha >> beta;

    int res = 1;
    int gamma1 = 180 - alpha - beta;
    if (gamma1 <= alpha) {
        res = 0;
    }
    while (gamma1 > alpha) {
        ++res;
        int gamma2 = 90 - alpha;
        gamma1 = gamma1 + gamma2 - 90;
    }

    std::cout << res << "\n";

    int res = 0;
    int s;
    while (true) {
        if (res % 2 == 0) {
            s = 180 - alpha - beta;
        }
    }

    return 0;
}