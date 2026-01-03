#include <bits/stdc++.h>
using namespace std;
#define ii pair <int,int>
#define X first
#define Y second

int n,u,v,c,cnt[100001];
long long F[100001],ans;
vector <ii> a[100001];

void dfs (int p,int u) 
{
    cnt[u]=1;
    for (auto v:a[u]) 
    {
        if (v.X==p) continue;
        dfs(u,v.X);
        cnt[u]+=cnt[v.X];
    }
    for (auto v:a[u]) 
    {
        if (v.X==p) continue;
        F[u]+=F[v.X]+(long long)v.Y*cnt[v.X];
        ans+=F[v.X]*(long long)(cnt[u]-cnt[v.X]);
        ans+=(long long)v.Y*cnt[v.X]*(cnt[u]-cnt[v.X]);     
    }
}

int main() 
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i=1;i<n;i++) 
    {
        cin >> u >> v >> c;
        a[u].emplace_back(v,c);
        a[v].emplace_back(u,c);
    }
    dfs(0,1);
    cout << ans << "\n";
    return 0;
}