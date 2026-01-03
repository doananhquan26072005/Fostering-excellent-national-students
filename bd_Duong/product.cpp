#include <bits/stdc++.h>
using namespace std;
#define int long long
    int c;
    vector < int > a;
    signed main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        freopen("product.inp","r",stdin);
        freopen("product.out","w",stdout);
        cin >> c;
        int n = c;
        a.push_back(0);
        while ( c > 0 )
        {
            a.push_back( c % 2 );
            c /= 2;
            //cout << a.back() <<" ";
        }
        int res = 0;
        for ( int i = 1 ; i <= n ; i++ )
        {
            int cnt = 0;
            int u = i;
            int s = 0;
            //cout << u <<" ";
            for ( int j = 1 ; j < a.size() ; j++ )
            {
                if ( a[j] != u % 2 )
                {
                    s = s + pow ( 1ll * 2 , cnt );
                }
                //cout << u % 2 <<" ";
                u /= 2;
                cnt++;
            }
            res = max ( res , s * i );
        }
        cout << res;
    }