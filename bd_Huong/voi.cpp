#pragma GCC optimize("Ofast")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

#define int long long int
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
const int oo = 1e9 + 7 ;
const int N = 2e5 + 5 ;
const int MOD = 1e9 + 7 ;

int n , m;
int a[505][505];
int check[505][505];
int val[505][505];
vector <ii> xet;
int dx[5] = {0 , 1 , -1 , 0 , 0};
int dy[5] = {0 , 0 , 0 , -1 , 1};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("voi.inp", "r", stdin);
    freopen("voi.out", "w", stdout);
    cin >> n >> m;
    FOR(i , 1, n){
        FOR(j , 1 , m){
            cin >> a[i][j];
        }
    }
    memset(check , 0 , sizeof(check));
    FOR(i , 1 , n){
        FOR(j , 1 , m){
            cin >> check[i][j];
            if(check[i][j] == 1)xet.pb({i , j});
            else check[i][j] = 2;
        }
    }
    int x , y;
    int ans = oo;
    REP(i , xet.size()){
        memset(val , oo , sizeof(val));
        val[xet[i].fi][xet[i].se] = 0;
        queue<ii> S;
        S.push({xet[i].fi , xet[i].se});
        while(!S.empty()){
            x = S.front().fi;
            y = S.front().se;
            S.pop();
            FOR(j , 1 , 4){
                if(check[x + dx[j]][y + dy[j]] == 0)continue;
                if(max(val[x][y] , abs(a[x][y] - a[x + dx[j]][y + dy[j]])) < val[x + dx[j]][y + dy[j]]){
                    val[x + dx[j]][y + dy[j]] = max(val[x][y] , abs(a[x][y] - a[x + dx[j]][y + dy[j]]));
                    S.push({x + dx[j] , y + dy[j]});
                }
            }
        }
        int res = -oo;
        REP(j , xet.size()){
            res = max(res , val[xet[j].fi][xet[j].se]);
        }
        ans = min(ans , res);
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
