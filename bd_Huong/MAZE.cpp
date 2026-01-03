// #pragma GCC optimize("Ofast")
// #pragma GCC optimization ("unroint-loops")
// #pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

//----------------------------------------------------------------------
#define int long long
#define vi vector<int>
#define ii pair < int , int >
#define matrix vector < vi >
#define endl "\n"
#define tp(x) fixed << setprecision(x)

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , n , x) for(int i = n ; i >= x ; --i)

//stoi() : string -> int
//stoi() : string -> double
//a.erase(unique(begin(a), end(a)), end(a)) xoa cac phan tu trung lap
//string s = bitset<8>(n).to_string() chuyen 1 so thanh dang nhi phan
//to_string chyen 1 so thanh xau

#define fi first
#define se second
#define pb push_back
const long double pi = 3.141592654;
const int oo = 1e9 + 7;
const int MOD = 1e9 + 7;
//----------------------------------------------------------------------
int n , m;
char a[1000005];
int dd[1000005];
int dem = 0;
vi adj[1000005];
int F[1000005][25];
int deep[1000005];
int Pow[25];
int cha[1000005];

void BFS(int u){
    queue <int> S;
    S.push(u);
    dem += 1;
    dd[u] = dem;
    while(!S.empty()){
        u = S.front();
        S.pop();
        for(int v : adj[u]){
            if(v < 1 || v > n * n) continue;
            if(dd[v] == 1 || a[v] == '1') continue;
            F[v][0] = u;
            if(deep[v] == 0)deep[v] = deep[u] + 1;
            cha[v] = u;
            dd[v] = 1;
            S.push(v);
        }
    }
}

int LCA(int u , int v){
    int res = 0;
    if(deep[u] < deep[v])swap(u , v);
    FORD(i , 20 , 0){
        if(deep[F[u][i]] >= deep[v] && F[u][i] != 0) {
            u = F[u][i];
            res += Pow[i];
        }
    }
    if(u == v)return res + 1;
    FORD(i , 20 , 0){
        if(F[u][i] != F[v][i]){
            u = F[u][i];
            v = F[v][i];
            res += Pow[i];
        }
    }
    return res + 1;
    // return F[u][0];
}

int tim(int u) {
    if(u == cha[u])return u;
    cha[u] = tim(cha[u]);
    return cha[u];
}

signed main() {
//     freopen("MAZE.inp", "r", stdin);
//     freopen("MAZE.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    Pow[0] = 1;
    FOR(i , 1 , 20) Pow[i] = Pow[i - 1] * 2;
    cin >> n >> m;
    FOR(i , 1 , n * n) cha[i] = i;
    FOR(i , 1 , n){
        FOR(j , 1 , n - 1) {
            adj[(i - 1) * n + j].pb((i - 1) * n + j + 1);
            adj[(i - 1) * n + j + 1].pb((i - 1) * n + j);
        }
    }
    FOR(i , 1 , n - 1){
        FOR(j , 1 , n) {
            adj[(i - 1) * n + j].pb((i - 1) * n + j + n);
            adj[(i - 1) * n + j + n].pb((i - 1) * n + j);
        }
    }
    FOR(i , 1 , n * n) cin >> a[i];
    FOR(i , 1 , n * n){
        if(dd[i] == 0 && a[i] == '0') BFS(i);
    }

    FOR(i , 1 , 20){
        FOR(u , 1 , n * n)F[u][i] = F[F[u][i - 1]][i - 1];
    }

    int type , u , v , x , y;
    while(m --){
        cin >> type;
        if(type == 2){
            cin >> u >> v >> x >> y;
            if(tim((u - 1) * n + v) == tim((x - 1) * n + y)) cout << LCA((u - 1) * n + v , (x - 1) * n + y) << endl;
            else cout << -1 << endl;
        }
        else {
            cin >> u >> v;
            cha[(u - 1) * n + v] = 0;
            
        }
    }
    return 0;
}
/*                                                           _____________
╔══╗                ▐▀▄       ▄▀▌   ▄▄▄▄▄▄▄                /             \
╚╗╔╝                ▌▒▒▀▄▄▄▄▄▀▒▒▐▄▀▀▒██▒██▒▀▀             / uoc gi duoc   \
╔╝(¯’v´¯)          ▐▒▒▒▒▀▒▀▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄          \  Tham trap    /
╚══’.¸.            ▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▒▒▒▒▒▒▒▒▒▒▒▒▀▄         \  ___________/
╔♫═╗╔╗ ♥Tham      ▀█▒▒▒█▌▒▒█▒▒▐█▒▒▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌       |/
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
