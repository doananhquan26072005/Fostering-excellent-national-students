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

int n;
struct ht {
    int x , y , z , stt;
} A[100005];
int cha[100005];

bool sx(ht q , ht p) {
    return q.x < p.x;
}

bool sy(ht q , ht p) {
    return q.y < p.y;
}

bool sz(ht q , ht p) {
    return q.z < p.z;
}

bool cmp(ht q , ht p) {
    return min(q.x , min(q.y , q.z)) < min(p.x , min(p.y , p.z));
}

int tim(int u) {
    if (u != cha[u])u = tim(cha[u]);
    return cha[u];
}

bool ghep(int u, int v) {
    u = tim(u);
    v = tim(v);
    if (u == v)return false;
    else cha[u] = v;
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("cost.inp", "r", stdin);
    freopen("cost.out", "w", stdout);
    cin >> n;
    FOR(i , 1 , n)cin >> A[i].x >> A[i].y >> A[i].z;
    ht a[100005];
    sort(A + 1 , A + 1 + n , sx);
    FOR(i , 1 , n - 1)a[i].x = abs(A[i].x - A[i + 1].x);
    //
    sort(A + 1 , A + 1 + n , sy);
    FOR(i , 1 , n - 1)a[i].y = abs(A[i].y - A[i + 1].y);
    //
    sort(A + 1 , A + 1 + n , sz);
    FOR(i , 1 , n - 1)a[i].z = abs(A[i].z - A[i + 1].z);
    //
    FOR(i , 1 , n - 1)a[i].stt = i;
    sort(a + 1 , a + n , cmp);
    FOR(i , 1 , n)cha[i] = i;
    long long ans = 0;
    FOR(i , 1 , n - 1) {
        if (ghep(a[i].stt, (a[i].stt + 1)) == true)ans += min(a[i].x , min(a[i].y , a[i].z));
        // cout << a[i].x << endl;
    }
    cout << ans ;
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