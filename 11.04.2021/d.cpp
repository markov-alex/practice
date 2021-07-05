#include <bits/stdc++.h>

bool in(char ch, const std::vector<char> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (ch == vec[i])
            return true;
    }
    return false;
}

int main() {
    long long n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::vector<char> vowel{'a', 'i', 'o', 'u', 'e', 'y'};

    // 0 - должны искать гласную. 1 - должны искать согласную. 2 - сброс.
    int help = 2;
    long long res = 0;

    for (long long i = 0; i < n; i++) {
        if (help == 2) {
            if (in(s[i], vowel)) {
                help = 1;
            } else {
                help = 0;
            }
        } else if (help == 0) {
            if (in(s[i], vowel)) {
                help = 2;
                res++;
            }
        } else if (help == 1) {
            if (!in(s[i], vowel)) {
                help = 2;
                res++;
            }
        }
    }

    std::cout << res << "\n";

    return 0;
}