#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
int n;
struct td {int x, y;};
td a[1005];
double G[1005][1005];
bool dinh[1005];
vector<int>v[1005];

void DFS(int s) {
    dinh[s] = true;
    for (int i = 0; i < v[s].size(); i += 1) {
        if (dinh[v[s][i]] == false)DFS(v[s][i]);
    }
}

bool lienthong(int r) {
    memset(dinh, false, sizeof(dinh));
    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= n; j += 1) {
            if (r * 2 >= G[i][j]) {
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    DFS(1);
    for (int i = 1; i <= n; i += 1) {
        if (dinh[i] == false)return false;
    }
    return true;
}

double tinh(int i, int j) {
    a[i].x *= 1.00; a[i].y *= 1.00;
    a[j].x *= 1.00; a[j].y *= 1.00;
    double kq1 = (a[i].x - a[j].x);
    kq1 = kq1 * kq1;
    double kq2 = (a[i].y - a[j].y);
    kq2 = kq2 * kq2;
    return sqrt(kq1 + kq2);
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//freopen("TRAMPHAT.inp","r",stdin);
//freopen("TRAMPHAT.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i += 1)cin >> a[i].x >> a[i].y;
    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= n; j += 1)G[i][j] = G[j][i] = tinh(i, j);
    }
    double l = 0, r = 1e9, kq;
    while (r - l > 0.0000001) {
        kq = (r - l) / 2;
        if (lienthong(kq) == true) {r = kq;}
        else l = kq;
    }
    cout << fixed << setprecision(7) << kq;
    return 0;
}
