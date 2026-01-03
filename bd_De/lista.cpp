#pragma GCC optimize("Ofast")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

// #define int long long int
#define vi vector<int>
#define ii pair < int , int >
#define endl "\n"
#define tp(x) fixed << setprecision(x)

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , n , x) for(int i = n ; i >= x ; --i)

#define fi first
#define se second
#define pb push_back
const long double pi = 3.141592654;
const int oo = 1e9 + 7 ;
const int MOD = 1e9 + 7 ;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 
    freopen("lista.inp", "r", stdin);
    freopen("lista.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 2, -1);
    vector<int> b(n + 2, -1);
    FOR(i , 0 , n) {
        if (i == 0) {
            b[i] = 1;
        } else if (i == n + 1) {
            a[i] = n - 1;
        } else {
            a[i] = i - 1;
            b[i] = i + 1;
        }
    }
    while (m--) {
        char type;
        int x, y;
        cin >> type >> x >> y;
        if (type == 'A') {
            if (a[y] == x) {
                continue;
            } else {
                b[a[x]] = b[x];
                a[b[x]] = a[x];
                b[a[y]] = x;
                a[x] = a[y];
                b[x] = y;
                a[y] = x;
            }
        } else {
            if (b[y] == x) {
                continue;
            } else {
                b[a[x]] = b[x];
                a[b[x]] = a[x];
                a[b[y]] = x;
                b[x] = b[y];
                a[x] = y;
                b[y] = x;
            }
        }
    }
    vector<int> x;
    int tmp = b[0];
    while (tmp != n + 1) {
        x.emplace_back(tmp);
        tmp = b[tmp];
    }
    vector<int> F(n, 2e9), dp(n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = lower_bound(F.begin(), F.begin() + res + 1, x[i]) - F.begin();
        res = max(res, dp[i] + 1);
        F[dp[i]] = x[i];
    }
    cout << n - res;
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
