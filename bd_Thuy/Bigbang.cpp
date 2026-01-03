Nguyễn Tài Phú
#include <bits/stdc++.h>
using namespace std;

int n,x[500001],v[500001];

bool check(double t)
{
    double d=-1e20;
    for (int i=0;i<n;i++)
    {
        if (v[i]>0) d=max(d,x[i]+t*v[i]);
        else if (x[i]+t*v[i]<=d) return 1;
    }
    return 0;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("bigbang.inp","r",stdin);
    freopen("bigbang.out","w",stdout);
    cin >> n;
    for (int i=0;i<n;i++) cin >> x[i] >> v[i];
    double l=0.0,r=1e10;
    int t=0;
    while (t<=44)
    {
        t++;
        double mid=(l+r)/2;
        // cout << fixed << setprecision(9) << mid << "\n";
        if (check(mid)) r=mid;
        else l=mid;
    }
    if (r==1e10) return cout << "-1.000000000",0;
    cout << fixed << setprecision(9) << r; 
    return 0;
}