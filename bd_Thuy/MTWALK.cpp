#include <bits/stdc++.h>

bool vis[101][101];

int main() {
    freopen("mtwalk.inp", "r", stdin);
    freopen("mtwalk.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }
    std::queue<std::pair<int, int>> que;
    std::vector<int> dx{0, 0, -1, 1};
    std::vector<int> dy{-1, 1, 0, 0};
    int low = 0, hig = 111, res = 111;
    while (low <= hig) {
        int mid = (low + hig) / 2;
        bool ok = 0;
        for (int k = 0; k <= 111; k++) {
            int min = k;
            int max = k + mid;
            if (a[0][0] < min || a[0][0] > max) {
                continue;
            }
            memset(vis, 0, sizeof vis);
            que.emplace(0, 0);
            vis[0][0] = 1;
            while (!que.empty()) {
                std::pair<int, int> u = que.front();
                que.pop();
                for (int i = 0; i < 4; i++) {
                    int vx = u.first + dx[i];
                    int vy = u.second + dy[i];
                    if (vx >= 0 && vy >= 0 && vx < n && vy < n && !vis[vx][vy] && a[vx][vy] >= min && a[vx][vy] <= max) {
                        vis[vx][vy] = 1;
                        que.emplace(vx, vy);
                    }
                }
            }
            if (vis[n - 1][n - 1]) {
                ok = 1;
                break;
            }
        }
        if (ok) {
            hig = mid - 1;
            res = std::min(res, mid);
        } else {
            low = mid + 1;
        }
    }
    std::cout << res;
    return 0;
}