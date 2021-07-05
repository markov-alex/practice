#include <bits/stdc++.h>

int len(int n) {
    int cnt = 1;
    while (n / 10 != 0) {
        n /= 10;
        ++cnt;
    }

    return cnt;
}

int main() {
    int n;
    std::string number;
    std::cin >> n >> number;

    int cur_number = 1;
    int l = 1;
    std::string cur_str_number = "";
    for (char ch: number) {
        cur_str_number += ch;
        --l;
        if (l == 0) {
            if (std::stoi(cur_str_number) == cur_number) {
                ++cur_number;
                l = len(cur_number);
                cur_str_number.clear();
            } else {
                std::cout << cur_number << "\n";
                return 0;
            }
        }
    }

    if (cur_number == n) {
        std::cout << n << "\n";
    }


    return 0;
}