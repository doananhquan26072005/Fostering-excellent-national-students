#include <bits/stdc++.h>

int main() {
    freopen("tg3mau.inp", "r", stdin);
    freopen("tg3mau.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test;
    std::cin >> test;
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<std::pair<int, int>> nxt(n);
    for (int i = 0; i < n; i++) {
        nxt[i] = {(i + 1) % n, s[i] - '0'};
    }
    std::vector<std::pair<std::pair<int, int>, int>> d(2 * (n - 3));
    for (int i = 0; i < n - 3; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--;
        b--;
        d[2 * i] = {{a, b}, c};
        d[2 * i + 1] = {{b, a}, c};
    }
    sort(d.begin(), d.end(), [&](std::pair<std::pair<int, int>, int> a, std::pair<std::pair<int, int>, int> b) {
        return (a.first.second - a.first.first + n) % n < (b.first.second - b.first.first + n) % n;
    });
    bool ok = true;
    for (int i = 0; i < n - 2; i++) {
        int a = d[i].first.first;
        int b = nxt[a].first;
        int c = d[i].first.second;
        int color_a = nxt[a].second;
        int color_b = nxt[b].second;
        int color_c = d[i].second;
        if (nxt[b].first != c) {
            std::cout << "neispravna triangulacija";
            return 0;
        }
        ok &= (color_a != color_b && color_b != color_c && color_a != color_c);
        nxt[a] = {c, color_c};
    }
    if (!ok) {
        std::cout << "neispravno bojenje";
    } else {
        std::cout << "tocno";
    }
    return 0;
}