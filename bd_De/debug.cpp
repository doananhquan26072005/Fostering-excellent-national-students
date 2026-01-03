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
char a[305][305];
int F[305][305][4];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int check(int i, int j, int cnt) {
    if (i < 0 || i + cnt >= n) return 0;
    if (j < 0 || j + cnt >= m) return 0;
    FOR(k , 0 , 1){
        int r1 = i, c1 = j;
        int r2 = i + cnt, c2 = j + cnt;

        for (int s = cnt + 1; s > 0; s -= 64 ) {
            int x = F[r1][c1][k];
            int y = F[r2][c2][k + 2];

            if (s >= 64) {
                if (x ^ y) return 0;
            } else {
                if((x ^ y) & ((1 << s) - 1)) return 0;
            }

            r1 += 64 * dx[k]; c1 += 64 * dy[k];
            r2 -= 64 * dx[k]; c2 -= 64 * dy[k];
        }
    }
    return 1;
}

signed main() {
    // freopen("debug.inp", "r", stdin);
    // freopen("debug.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    REP(i , n) cin >> a[i];

    int x , y;
    FORD(i , n - 1 , 0) {
        FORD(j , m - 1 , 0) {
            FOR(k , 0 , 1) {
                x = i + dx[k];
                y = j + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < m)
                    F[i][j][k] = F[x][y][k] * 2;
                else F[i][j][k] = 0;
                F[i][j][k] |= a[i][j] == '1';
            }
        }
    }

    REP(i , n) {
        REP(j , m) {
            FOR(k , 2 , 3) {
                x = i + dx[k];
                y = j + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < m)
                    F[i][j][k] = F[x][y][k] * 2;
                else F[i][j][k] = 0;
                F[i][j][k] |= a[i][j] == '1';
            }
        }
    }

    int res = 0 , cnt;
    REP(i , n) {
        REP(j , m) {
            FOR(k , 0 , 1) {
                if (2 * min(min(i + 1 , j + 1), min(n - i, m - j)) <= res) continue;
                cnt = k;
                while(check(i - cnt / 2 , j - cnt / 2 , cnt)) cnt += 2;
                res = max(res , cnt - 1);
            }
        }
    }

    if(res > 1) cout << res;
    else cout << -1;
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
