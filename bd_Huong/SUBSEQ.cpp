#include <bits/stdc++.h>

int main() {
    freopen("subseq.inp", "r", stdin);
    freopen("subseq.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n, k;
    std::cin >> n >> k;
    std::vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        a[i] += a[i - 1];
    }
    long long res = 0;
    for (int i = k; i <= n; i++) {
        res = std::max(res, a[i] - a[i - k]);
    }
    std::cout << res;
    return 0;
}