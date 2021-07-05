#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 1e5+5;
char a[maxn], b[maxn], aa[maxn], bb[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        scanf("%s", a+1);
        scanf("%s", b+1);
        int t = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] != b[i]) {
                aa[t] = a[i];
                bb[t] = b[i];
                t++;
            }
        }
        bool flag = true;
        for (int i = 0; i < t; ++i) {
            if (bb[i] == aa[(i + 1) % t])
                continue;
            else {
                flag = false;
                break;
            }
        }
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}