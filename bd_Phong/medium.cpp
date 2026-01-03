#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

// #define int long long
// #define double long double
#define ii pair < int , int >
#define tp(x) fixed << setprecision(x)
#define endl "\n"

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define FORD(i , n , x) for(int i = n ; i >= x ; --i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)

#define fi first
#define se second
#define pb emplace_back
const double pi = 3.141592654;
const int oo = 1e9 + 7 ;
const int MOD = 1e9 + 7 ;


int n, w;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> w;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i+= 1) {
        int m;
        cin >> m;
        a[i].resize(m);
        for (int j = 0; j < m; j+= 1) {
            cin >> a[i][j];
        }
    }
    while (w--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int mid = 0;
        int lx = 0, rx = a[x].size() - 1;
        int ly = 0, ry = a[y].size() - 1;
        while (1) {
            if ((rx - lx + 1) + (ry - ly + 1) == 2) {
                if (rx - lx + 1 == 0) cout << a[y][ly] + a[y][ry] << endl;
                else if (ry - ly + 1 == 0) cout << a[x][lx] + a[x][rx] << endl;
                else cout << a[y][ly] + a[x][lx] << endl;
                break;
            }
            if ((rx - lx + 1) + (ry - ly + 1) == 1) {
                if (rx - lx + 1 == 0) cout << 2 * a[y][ly] << endl;
                else cout << 2 * a[x][lx] << endl;
                break;
            }
            if (rx - lx + 1 == 0) {
                ly+= 1;
                ry--;
            } else if (ry - ly + 1 == 0) {
                lx+= 1;
                rx--;
            } else {
                if (a[x][lx] < a[y][ly]) lx+= 1;
                else ly+= 1;
                if (a[x][rx] < a[y][ry]) ry--;
                else rx--;
            }
        }
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
