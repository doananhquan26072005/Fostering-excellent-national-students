#include <bits/stdc++.h>
using namespace std;
#define ll long long
    int t;
    ll n , m ;
    ll check[2000005];
    ll res[2000005];
    void SNT ( )
    {
        for ( ll i = 2 ; i <= 2000000 ; i++ )
            if ( check[i] == 0)
        {
            res[i]++;
            for ( ll j = i * 2 ; j <= 2000000 ; j+= i )
            {
                check[j] = 1;
                res[j]++;
            }
        }
    }
    int main()
    {
        freopen("MATRIX.INP","r",stdin);
        freopen("MATRIX.OUT","w",stdout);
        SNT();
        //check[1] = 1;
        //cout << res[2000000] <<" ";
        //cout << 6 / check[6];
        cin >> t;
        while (t--)
        {
            cin >> n >> m ;
            long long ans = 0;
            for ( ll i = 1 ; i <= m ; i++ )
            {
                ans += min ( i , n ) * 1ll * res[i + 1];
            }
            for ( ll i = 2 ; i <= n ; i++ )
            {
                ans += min ( m , n - i + 1 ) * 1ll * res[m + i];
            }
            cout << ans <<"\n";
        }
    }