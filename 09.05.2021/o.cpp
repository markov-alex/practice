#include <bits/stdc++.h>

int main() {
    int cnt_vowel = 0, cnt_cons = 0;
    int n = 0;

    std::string s;
    std::cin >> s;

    for (char ch : s) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || 
            ch == 'o' || ch == 'u') {
            ++cnt_vowel;
            ++n;
        } else if (ch != 'y') {
            ++cnt_cons;
            ++n;
        }
    }

    int res = n / 2 + 1 - cnt_vowel;
    if (res <= 0) {
        res = 0;
    }
    std::cout << res << "\n";

    return 0;
}