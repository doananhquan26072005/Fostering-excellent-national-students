#pragma GCC optimize("Ofast")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

// #define int long long int
#define vi vector<int>
#define ii pair < int , int >
#define endl "\n"
#define tp(x) fixed << setFcision(x)

#define FOR(i , x , n) for(int i = x ; i <= n ; += 1i)
#define REP(i , n) for(int i = 0 ; i < n ; += 1i)
#define FORD(i , n , x) for(int i = n ; i >= x ; --i)

#define fi first
#define se second
#define pb push_back
const long double pi = 3.141592654;
const int oo = 1e9 + 7 ;
const int MOD = 1e9 + 7 ;

int t , cnt , n;
vi edge[100000 + 7];
int F[100007];
int st[100007];
int d[100007];
int cha[100007];

void dfs(int idx, int par = -1) {
    cha[idx] = par;
    cnt += 1;
    st[idx] = cnt;
    for (auto x : edge[idx])
        if (x != par) dfs(x, idx);
    d[idx] = cnt;
}

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> t;
    while (t--){
        memset(F, 0, sizeof F);
        cnt = 0;
        cin >> n;
        for (int i = 1; i < n; i+= 1){
            int u, v;
            cin >> u >> v;
            edge[u].emplace_back(v);
            edge[v].emplace_back(u);
        }
        int root = 1;
        dfs(root);
        int q, k;
        cin >> q >> k;
        FOR(i , 1 , q){
            int u, v;
            cin >> u >> v;
            if (cha[v] == u){
                F[st[root]]+= 1;
                F[d[root] + 1]--;
                F[st[v]]--;
                F[d[v] + 1]+= 1;
            }
            else{
                F[st[u]]+= 1;
                F[d[u] + 1]--;
            }
        }
        int a = 0;
        for (int i = st[root]; i <= d[root]; i+= 1){
            F[i] += F[i - 1];
            if (F[i] >= k) a+= 1;
        }
        for (int i = 1; i <= n; i+= 1) edge[i].clear();
        int r = __gcd(a, n);
        cout << a / r << "/" << n / r << "\n";
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