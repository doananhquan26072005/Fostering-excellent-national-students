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
const int MOD = 1e9 + 7;

int t;
int m, n, ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("Lcx2.inp", "r", stdin);
    freopen("Lcx2.out", "w", stdout);
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n >> m;
        vector <int> a(n + 1), b(m + 1);
        vector <int> q(n + 1), p(m + 1);
        FOR(i , 1 , n) cin >> a[i];
        FOR(i , 1 , m) cin >> b[i];
        REP(i , n)
            REP(j , m) {
                int gt = q[i];
                if (a[i] >= b[j] * 2) q[i] = max(q[i], p[j]);
                if (a[i] == b[j]) {
                    p[j] = gt + 1;
                    ans = max(ans, p[j]);
                }
            }
        cout << ans << endl;
    }
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
