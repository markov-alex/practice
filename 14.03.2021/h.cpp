#include <bits/stdc++.h>

#define ll long long

bool check_special(ll num) {
    if (num == 0) {
        return false;
    }
    while (true) {
        if (num % 10 != 0) {
            if (num / 10 == 0) {
                return true;
            } else {
                return false;
            }
        }
        num /= 10;
    }
}

std::pair<ll, ll> slagaemye(ll num) {
    if (num == 0) {
        return std::make_pair(5, -5);
    }
    bool negative = false;
    ll a = num;
    if (a < 0) {
        negative = true;
        a *= -1;
    }
    std::string str_a = std::to_string(a);
    std::string a_tail = str_a.substr(1, str_a.size());
    int first_head = (str_a[0] - '0') + 1;
    ll first_slag = static_cast<long long>(first_head * std::pow(10, a_tail.size()));
    ll second_slag = a - first_slag;
    
    if (negative) 
        return std::make_pair(-1 * first_slag, -1 * second_slag);
    else
        return std::make_pair(first_slag, second_slag);
}

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        ll a, b;
        std::cin >> a >> b;

        std::list<ll> first_slag;
        first_slag.push_back(a);
        while (!check_special(first_slag.back())) {
            std::pair<ll, ll> slag = slagaemye(first_slag.back());
            first_slag.pop_back();
            first_slag.push_back(slag.first);
            first_slag.push_back(slag.second);
        }

        std::list<ll> second_slag;
        second_slag.push_back(b);
        while (!check_special(second_slag.back())) {
            std::pair<ll, ll> slag = slagaemye(second_slag.back());
            second_slag.pop_back();
            second_slag.push_back(slag.first);
            second_slag.push_back(slag.second);
        }

        bool first = true;
        for (ll num1: first_slag) {
            for (ll num2: second_slag) {
                if (first) {
                    std::cout << num1 << " x " << num2;
                    first = false;
                } else {
                    if ((num1 < 0 && num2 > 0) || (num1 > 0 && num2 < 0)) {
                        std::cout << " - " << std::abs(num1) << " x " << std::abs(num2);
                    } else {
                        std::cout << " + " << std::abs(num1) << " x " << std::abs(num2);
                    }
                }
            }
        }
        std::cout << "\n";
    }

    return 0;
}