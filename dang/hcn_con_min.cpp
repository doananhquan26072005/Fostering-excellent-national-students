#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 501;
int a[maxn][maxn];
int n,m;
int tr[maxn];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    int res = -1000000007;
    for (int i = 1; i <= n; i++){
        memset(tr, 0, sizeof(tr));
        for (int u = i; u <= n; u++){
            int sum = 0;
            int best = -1000000007;
            for (int j = 1; j <= m; j++){
                tr[j] += a[u][j];
                sum = max(tr[j], sum + tr[j]);
                best = max(best, sum);
            }
            res = max(best, res);
        }
    }

    cout << res;
}
