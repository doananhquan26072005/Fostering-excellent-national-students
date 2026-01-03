#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

#define int long long
// #define double long double
#define ii pair < int , int >
#define vi vector < int >
#define tp(x) fixed << setprecision(x)
#define endl "\n"

#define FOR(i , x , n) for(int i = x ; i <= n ; ++ i)
#define FORD(i , n , x) for(int i = n ; i >= x ; --i)
#define REP(i , n) for(int i = 0 ; i < n ; += 1i)

#define fi first
#define se second
#define pb emplace_back
const double pi = 3.141592654;
const int oo = 1e9 + 7 ;
const int MOD = 1e9 + 7 ;

int n, m, u;
struct canh {
    int next;
    int dm;
} p[100006];
int i , j , a[100006], d[100006], s[100006], f[100006];


signed main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    freopen("COUNTER.inp", "r", stdin);
    freopen("COUNTER.out", "w", stdout);
    cin >> n >> m;
    FOR(i , 1 , n ) a[i] = -1;
    int path = 0;
    int x , y;
    for (i = 1; i <= m; i+= 1) {
        cin >> x >> y;
        path+= 1;
        p[path].next = y;
        p[path].dm = a[x];
        a[x] = path;
        path+= 1;
        p[path].next = x;
        p[path].dm = a[y];
        a[y] = path;
    }
    int top = 0;
    FOR(i , 1 , n ) {
        cin >> d[i];
        if (d[i] == 0) {
            top+= 1;
            s[top] = i;
        }
    }
    int k = 0;
    while (top > 0) {
        u = s[top];
        top--;
        if (d[u] != 0) continue;
        k+= 1; f[k] = u;
        d[u]--;
        i = a[u];
        while (i != -1) {
            if (--d[p[i].next] == 0) {top+= 1; s[top] = p[i].next;}
            i = p[i].dm;
        }
    }
    cout << k << endl;
    FOR(i , 1 , k - 1 ) cout << f[i] << " ";
    if (k != 0) cout << f[k];
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
