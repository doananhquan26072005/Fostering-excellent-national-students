#include <bits/stdc++.h>

int main() {
    freopen("vector.inp", "r", stdin);
    freopen("vector.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first >> a[i].second;
    }
    int u, v;
    std::cin >> u >> v;
    int len1 = n / 2;
    std::vector<std::pair<long long, long long>> x;
    for (int k = 1; k < (1 << (len1)); k++) {
        std::pair<long long, long long> sum = {0, 0};
        for (int i = 0; i < len1; i++) {
            if ((k >> i) & 1) {
                sum.first += a[i].first;
                sum.second += a[i].second;
            }
        }
        x.emplace_back(sum);
    }
    int len2 = n - (n / 2);
    std::vector<std::pair<long long, long long>> y;
    for (int k = 1; k < (1 << (len2)); k++) {
        std::pair<long long, long long> sum = {0, 0};
        for (int i = 0; i < len2; i++) {
            if ((k >> i) & 1) {
                sum.first += a[len1 + i].first;
                sum.second += a[len1 + i].second;
            }
        }
        y.emplace_back(sum);
    }
    std::map<std::pair<long long, long long>, int> mp;
    long long res = 0;
    for (int i = 0; i < x.size(); i++) {
        mp[{x[i].first, x[i].second}]++;
        if (x[i].first == u && x[i].second == v) {
            res++;
        }
    }
    for (int i = 0; i < y.size(); i++) {
        if (y[i].first == u && y[i].second == v) {
            res++;
        }
        res += mp[{u - y[i].first, v - y[i].second}];
    }
    std::cout << res;
    return 0;
}