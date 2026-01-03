#include <bits/stdc++.h>

int main() {
    // freopen("binary.inp", "r", stdin);
    // freopen("binary.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test;
    std::cin >> test;
    std::vector<int> f(61);
    std::vector<int> pre(61);
    f[0] = 0;
    f[1] = 1;
    pre[1] = 1;
    for (int i = 2; i <= 60; i++) {
        f[i] = f[i - 1] + f[i - 2];
        pre[i] = pre[i - 1] + f[i];
    }
    while (test--) {
        int n;
        std::cin >> n;
        int len = lower_bound(pre.begin(), pre.end(), n) - pre.begin();
        std::string res;
        for (int i = 0; i < len; i++) {
            res += '0';
        }
        int pos = 0;
        while (n) {
            int x = 0;
            while (pre[x + 1] < n) {
                x += 1;
            }
            n -= pre[x] + 1;
            res[len - x - 1] = '1';
        }
        std::cout << res << '\n';
    }
    return 0;
}