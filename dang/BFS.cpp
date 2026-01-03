#include<bits/stdc++.h>
using namespace std;
int n, s;
queue <int>qu;
int dinh[100005];
int u, v;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    memset(dinh, 0, sizeof(dinh));
    cin >> n >> s;
    vector<int> a[n + 1];
    for (int i = 1; i <= n - 1; i += 1) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dinh[s] = 1;
    qu.push(s);
    while (qu.empty() == false) {
        int u = qu.front();
        qu.pop();
        for (int v = 0; v < a[u].size(); v += 1) {
            if (dinh[a[u][v]] == 0) {
                dinh[a[u][v]] = dinh[u] + 1;
                qu.push(a[u][v]);
            }
        }
    }
    int ans = -1;
    for (int i = 1; i <= n; i += 1)ans = max(ans, dinh[i]);
    cout << ans - 1;
    return 0;
}
