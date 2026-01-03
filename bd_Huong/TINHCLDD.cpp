#pragma GCC optimize("Ofast")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ii pair < int , int >
#define endl "\n"

#define fi first
#define se second
const int oo = 1e9 + 7 ;

int n , m , q;
bool dd[500005];
int L[500005];
priority_queue <ii> S;
int u , v , val;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("TINHCLDD.inp", "r", stdin);
    freopen("TINHCLDD.out", "w", stdout);
    cin >> n >> m >> q;
    vector < ii > a[n + 1];
    L[1] = 0;
    for (int i = 2 ; i <= n ; i += 1)L[i] = -oo;

    for (int i  = 1; i <= m; i += 1) {
        cin >> u >> v >> val;
        a[u].push_back({v , val});
        a[v].push_back({u , val});
       if (u == 1)L[v] = val;
        else if (v == 1)L[u] = val;
    }
    int Max = -oo;
    for (int i = 2 ; i <= n ; i += 1) {
        if (L[i] > Max) {Max = L[i]; v = i;}
    }
    S.push({Max , v});
    memset(dd , false , sizeof(dd));
    dd[1] = true;
    while (!S.empty()) {
        u = S.top().se;
        S.pop();
        for (v = 0 ; v < a[u].size(); v += 1) {
            if (a[u][v].fi == 1)continue;
            if (L[a[u][v].fi] < min(L[u] , a[u][v].se)) {
                L[a[u][v].fi] = min(L[u] , a[u][v].se);
                S.push({L[a[u][v].fi] , a[u][v].fi});
                dd[a[u][v].fi] = true;
            }
            if (dd[a[u][v].fi] == false) {
                S.push({L[a[u][v].fi] , a[u][v].fi});
                dd[a[u][v].fi] = true;
            }
        }
    }
    for (int z = 0 ; z < q; z += 1) {
        cin >> u;
        cout << L[u] << endl;
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
