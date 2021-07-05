#include <bits/stdc++.h>

int main() {
    int A, B;
    std::cin >> A >> B;
    int sz;

    if (A == 1) {
        sz = B + 1;
    } else {
        sz = B;
    }

    std::string res(sz, '0');
    if (A == 1) {
        res[0] = '1';
        std::cout << res << "\n";
    } else {
        for (int i = 0; i < sz - A + 1; i++) {
            res[i] = '9';
        }
        std::cout << res << "\n";
    }

    return 0;
}