// #pragma GCC optimize("Ofast")
// #pragma GCC optimization ("unroint-loops")
// #pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

//----------------------------------------------------------------------
#define int long long
#define vi vector<int>
#define ii pair < int , int >
#define endl "\n"

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , n , x) for(int i = n ; i >= x ; --i)

#define fi first
#define se second
#define pb push_back
const long double pi = 3.141592654;
const int oo = 1e9 + 7;
const int MOD = 1e9 + 7;
//----------------------------------------------------------------------
int n , q , m;
int check[1005];
multiset <pair <int , ii>> S;
int giatri[1005];
vi a[1005];
set <ii> dapan;

void BFS(int u , int z) {
    if(check[u] == 1)return;
    REP(v , a[u].size()) {
        if (a[u][v] == z)continue;
        auto it = S.find({giatri[u] + giatri[a[u][v]] , {min(u , a[u][v]) , max(u , a[u][v])}});
        if ((*it).fi == giatri[u] + giatri[a[u][v]]) {
            S.erase(it);
            S.insert({giatri[a[u][v]] , {min(u , a[u][v]) , max(u , a[u][v])}});
        }
    }
    check[u] = 1;
}

signed main() {
    // freopen("problem2.inp", "r", stdin);
    // freopen("problem2.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    FOR(i , 1 , n)cin >> giatri[i];
    int u , v;
    FOR(i , 1 , m) {
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
        S.insert({giatri[u] + giatri[v] , {min(u , v) , max(u , v)}});
    }
    int sum = 0 , res = 0 , cnt;
    while (!S.empty()) {
        u = (*S.begin()).se.fi;
        v = (*S.begin()).se.se;
        if (check[u] + check[v] == 0)res += 2;
        else res += 1;
        sum += (*S.begin()).fi;
        cnt = (*S.begin()).fi;
        BFS(u , v);
        BFS(v , u);
        S.erase(S.find({cnt , {min(u , v) , max(u , v)}}));
        dapan.insert({sum , res});
    }
    dapan.insert({0 , 0});
    set <ii> ::iterator it;
    cin >> q;
    while(q --){
        cin >> cnt;
        dapan.insert({cnt , oo});
        it = dapan.find({cnt , oo});
        it --;
        dapan.erase({cnt , oo});
        cout << (*it).se << endl;
    }
    // for(auto it = dapan.begin() ; it != dapan.end() ; it ++){
    //     cout << (*it).fi << " " << (*it).se << endl;
    // }
    // for(auto it = S.begin() ; it != S.end() ; it ++){
    //     cout << (*it).fi << " " << (*it).se.fi << " " << (*it).se.se << endl;
    // }
    return 0;
}
/*
╔══╗                ▐▀▄       ▄▀▌   ▄▄▄▄▄▄▄
╚╗╔╝                ▌▒▒▀▄▄▄▄▄▀▒▒▐▄▀▀▒██▒██▒▀▀
╔╝(¯’v´¯)          ▐▒▒▒▒▀▒▀▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄
╚══’.¸.            ▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▒▒▒▒▒▒▒▒▒▒▒▒▀▄
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