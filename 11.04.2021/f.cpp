#include <iostream>
#include <vector>
 
int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
 
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
 
    if (n == 1) {
        std::cout << "Yes\n";
    } else {
        // удаляем 2
        for (int i = 1; i < n - 1; i++) {
            if (a[i] == 2) {
                a[i] = 0;
                if (a[i - 1] - 1 < 0 || a[i + 1] - 1 < 0) {
                    std::cout << "No\n";
                    return 0;
                } else {
                    a[i - 1]--;
                    a[i + 1]--;
                }
            }
        }
        if (a[0] == 2) {
            a[0] = 0;
            if (a[1] - 1 < 0) {
                std::cout << "No\n";
                return 0;
            } else {
                a[1]--;
            }
        }
        if (a[n - 1] == 2) {
            a[n - 1] = 0;
            if (a[n - 2] - 1 < 0) {
                std::cout << "No\n";
                return 0;
            } else {
                a[n - 2]--;
            }
        }
        // удаляем 2
        // удаляем 1
        int start = 0;
        int finish = n - 2;
        if (a[0] == 1) {
            for (int i = 0; i < n; i++) {
                if (a[i] == 0) {
                    start = i;
                    break;
                }
            }
        } 
        if (start == n) {
            std::cout << "Yes\n";
            return 0;
        }
        if (a[n - 1] == 1) {
            for (int i = n - 1; i >= 0; i--) {
                if (a[i] == 0) {
                    finish = i;
                    break;
                }
            }
        }
        for (int i = start; i <= finish; i++) {
            if (a[i] == 1) {
                if (a[i + 1] == 0) {
                    std::cout << "No\n";
                    return 0;
                }
                a[i] = a[i + 1] = 0;
            }
        }
        std::cout << "Yes\n";
        // удаляем 1
    }
 
    return 0;
}