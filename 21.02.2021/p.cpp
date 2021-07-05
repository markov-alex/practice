#include <bits/stdc++.h>

long long calc(long long n) {
    long long res = 1;
    while (n / 10 != 0) {
        res *= (n % 10);
        n /= 10;
    }
    res *= n;

    return res;
}

int main() {
    long long n;
    std::cin >> n;
    long long max = calc(n);

    long long mnozhitel = 10;
    long long tmp = n;

    long long res;
    while (tmp / 10 != 0) {
        n -= (n % mnozhitel + 1);
        res = calc(n);
        max = (res > max ? res : max);
        tmp /= 10;
        mnozhitel *= 10;
    }

    std::cout << max << "\n";

    return 0;
}