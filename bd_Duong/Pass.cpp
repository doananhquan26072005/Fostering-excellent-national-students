#include <bits/stdc++.h>
using namespace std;
using namespace std;
#define oo (int) 1e9+7
#define mo (int) 1e5

int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(NULL);cout.tie(NULL);
     freopen("pass.inp","r",stdin);
     freopen("pass.out","w",stdout);
    int n,k,m;
    cin >> n >> k;
    cin >> m;
    vector <int> a(m+1);
    for (int i=1;i<=m;i++)p9o] cin >> a[i];
    vector <int> f(100001,oo);
    queue <int> q;
    q.emplace(n);
    f[n]=0;
    while (q.size())
    {
        int u=q.front();
        q.pop();
        if (u==k) break;
        for (int i=1;i<=m;i++)
        {
            int tmp=(u*a[i])%mo;
            if (f[tmp]==oo)
            {
                f[tmp]=f[u]+1;
                q.emplace(tmp);
            }
        }
    }
    if (f[k]==oo) cout << -1;
    else cout << f[k];
    return 0;
}