#include <bits/stdc++.h>

int main() {
    std::string s;
    std::cin >> s;

    std::vector<int> met(26, 0);

    for (char ch: s) {
        if (met[static_cast<int>(ch) - 97] != 0) {
            std::cout << 0 << "\n";
            return 0;
        } else {
            ++met[static_cast<int>(ch) - 97];
        }
    }

    std::cout << 1 << "\n";

    return 0;
}