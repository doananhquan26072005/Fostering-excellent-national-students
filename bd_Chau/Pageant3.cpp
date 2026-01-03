// #pragma GCC optimize("Ofast")
// #pragma GCC optimization ("unroint-loops")
// #pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

//----------------------------------------------------------------------
#define int long long int
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
//a.erase(uniSe(begin(a), end(a)), end(a)) xoa cac phan tu trung lap
//string s = bitset<8>(n).to_string() chuyen 1 so thanh dang nhi phan
//to_string chyen 1 so thanh xau

#define fi first
#define se second
#define pb push_back
const long double pi = 3.141592654;
const int oo = 1e9 + 7;
const int MOD = 1e9 + 7;
//----------------------------------------------------------------------
int n , m , dem = 0;
char a[55][55];
int dd[55][55];
int check[55][55];
int dx[5] = {0 , 1 , -1 , 0 , 0};
int dy[5] = {0 , 0 , 0 , 1 , -1};
vector <ii> res;
int F[5][5];
vector <ii> cnt1 , cnt2 , cnt3;

void BFS(int u , int v) {
    dd[u][v] = dem;
    queue <ii> S;
    S.push({u , v});
    while (!S.empty()) {
        u = S.front().fi;
        v = S.front().se;
        S.pop();
        FOR(i , 1 , 4) {
            if (u + dx[i] < 1 || u + dx[i] > n)continue;
            if (v + dy[i] < 1 || v + dy[i] > m)continue;
            if (a[u + dx[i]][v + dy[i]] == '.')continue;
            if (dd[u + dx[i]][v + dy[i]] != 0)continue;
            dd[u + dx[i]][v + dy[i]] = dem;
            S.push({u + dx[i] , v + dy[i]});
        }
    }
}

void loang(int x , int y) {
    memset(check , 0 , sizeof(check));
    queue <ii> S;
    S.push({x , y});
    check[x][y] = 0;
    while (!S.empty()) {
        int u = S.front().fi;
        int v = S.front().se;
        S.pop();
        FOR(i , 1 , 4) {
            if (u + dx[i] < 1 || u + dx[i] > n)continue;
            if (v + dy[i] < 1 || v + dy[i] > m)continue;
            if (check[u + dx[i]][v + dy[i]] != 0)continue;
            check[u + dx[i]][v + dy[i]] = check[u][v] + 1;
            if (a[u + dx[i]][v + dy[i]] == 'X')
                F[dd[x][y]][dd[u + dx[i]][v + dy[i]]] = min(check[u + dx[i]][v + dy[i]] - 1, F[dd[x][y]][dd[u + dx[i]][v + dy[i]]]);
            else S.push({u + dx[i] , v + dy[i]});
        }
    }
}

int sol(int x , int y , int u , int v) {
    return abs(x - u) + abs(y - v);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("Pageant3.inp", "r", stdin);
    freopen("Pageant3.out", "w", stdout);
    F[1][2] = F[1][3] = oo;
    F[2][3] = F[2][1] = oo;
    F[3][1] = F[3][2] = oo;
    cin >> n >> m;
    FOR(i , 1 , n) {
        FOR(j , 1 , m)cin >> a[i][j];
    }
    FOR(i , 1 , n) {
        FOR(j , 1 , m) {
            if (a[i][j] == '.')continue;
            if (dd[i][j] != 0)continue;
            dem += 1;
            BFS(i , j);
        }
    }

    FOR(i , 1 , n) {
        FOR(j , 1 , m) if (dd[i][j] == 1) cnt1.pb({i , j});
    }

    FOR(i , 1 , n) {
        FOR(j , 1 , m) if (dd[i][j] == 2) cnt2.pb({i , j});
    }

    FOR(i , 1 , n) {
        FOR(j , 1 , m) if (dd[i][j] == 3) cnt3.pb({i , j});
    }

    FOR(i , 1 , n) {
        FOR(j , 1 , m) if (dd[i][j] == 1 || dd[i][j] == 2) res.pb({i , j});
    }
    REP(i , res.size()) {
        loang(res[i].fi , res[i].se);
    }
    priority_queue<int , vi , greater <int>> S;
    S.push(F[1][2]);
    S.push(F[1][3]);
    S.push(F[2][3]);
    int ans = 0;
    ans += S.top();
    S.pop();
    ans += S.top();

    int Min1 , Min2;

    FOR(i , 1 , n) {
        FOR(j , 1 , m) {
            if (a[i][j] == 'X')continue;
            Min1 = oo;
            REP(c1 , cnt1.size()) {
                Min1 = min(sol(i , j , cnt1[c1].fi , cnt1[c1].se) , Min1);
            }
            Min2 = oo;
            REP(c2 , cnt2.size()) {
                Min2 = min(sol(i , j , cnt2[c2].fi , cnt2[c2].se) , Min2);
            }
            REP(c3 , cnt3.size()) {
                ans = min(ans , Min1 + Min2 + sol(i , j , cnt3[c3].fi , cnt3[c3].se) - 2);
            }
        }
    }

    cout << ans;
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