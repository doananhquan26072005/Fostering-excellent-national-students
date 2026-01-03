#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

// #define int long long
// #define double long double
#define vi vector<int>
#define ii pair < int , int >
#define tp(x) fixed << setprecision(x)
#define endl "\n"

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define FORD(i , n , x) for(int i = n ; i >= x ; --i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)

#define fi first
#define se second
#define pb emplace_back
const double pi = 3.141592654;
const int oo = 1e9 + 7 ;
const int MOD = 1e9 + 7 ;
int n;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("Move.inp", "r", stdin);
    freopen("Move.out", "w", stdout);
    cin >> n;
    vi F(n + 1), G(n + 1);
    FOR(i , 1 , n) cin >> F[i] >> G[i];
    int l = 0, r = 1e9, ans = oo;
    while (l <= r) {
        multiset <ii> S;
        int mid = (l + r) / 2;
        bool ok = 1;
        vector <ii> a(n + 1);
        FOR(i , 1 , n) {
            int gt = mid / G[i];
            a[i] = {(max(F[i] - gt, 1) ), (min(F[i] + gt, n))};
        }
        sort(a.begin() + 1, a.end());
        for (int i = 1, j = 0; i <= n; i += 1) {
            while (a[j + 1].fi <= i && j < n) {
                j += 1;
                S.insert({a[j].se, a[j].fi});
            }
            if (S.empty()) {ok = 0; break;}
            ii xet = *S.begin();
            S.erase(S.begin());
            if (xet.fi < i) {ok = 0; break;}
        }
        if (ok) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}
/*
╔══╗                ▐▀▄       ▄▀▌   ▄▄▄▄▄▄▄
╚╗╔╝                ▌▒▒▀▄▄▄▄▄▀▒▒▐▄▀▀▒██▒██▒▀▀
╔╝(¯’v´¯)          ▐▒▒▒▒▀▒▀▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄
╚══’.¸.Kien An     ▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▒▒▒▒▒▒▒▒▒▒▒▒▀▄
╔♫═╗╔╗ ♥          ▀█▒▒▒█▌▒▒█▒▒▐█▒▒▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌
╚╗╔╝║║♫═╦╦╦╔╗     ▀▌▒▒▒▒▒▒▀▒▀▒▒▒▒▒▒▀▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐   ▄▄
╔╝╚╗♫╚╣║║║║╔╣     ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌▄█▒█
╚═♫╝╚═╩═╩♫╩═╝     ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒█▀
┊　　┊　　┊　　┊   ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▀
┊　　┊　　┊　　┊   ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌
┊　　┊　　┊　　★   ▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐
┊　　┊　　☆        ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌
┊　　★              ▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐
☆                   ▐▄▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▌
                      ▀▄▄▀▀▀▀▀▄▄▀▀▀▀▀▀▀▄▄▀▀▀▀▀▄▄▀
*/
