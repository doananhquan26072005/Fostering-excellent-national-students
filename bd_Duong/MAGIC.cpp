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

int t , n;
struct gt {
    int x , y;
    char z;
};
vector < gt > a;
int dx[30] , dy[30];


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("MAGIC.inp", "r", stdin);
    freopen("MAGIC.out", "w", stdout);
    dx['W'] = -1; dx['E'] = 1; dy['N'] = 1; dy['S'] = -1;
    dy['W'] = 0; dy['E'] = 0; dx['N'] = 0; dx['S'] = 0;
    cin >> t;
    while (t --) {
        cin >> n;
        int q , p , b;
        char c;
        a.clear();
        map < ii , ii > dd;
        FOR(i , 1 , n) {
            cin >> q >> b >> c;
            a.pb({q , b , c});
        }
        memset(dx , 0 , sizeof(dx));
        memset(dy , 0 , sizeof(dy));
        
        FOR(i , 1 , 2000) {
            q = -1; p = -1;
            dd.clear();
            REP(j , a.size()) {
                if(a[j].x + dx[a[j].z] * i >= 1000 || a[j].x + dx[a[j].z] * i <= -1000)continue;
                if(a[j].y + dy[a[j].z] * i >= 1000 || a[j].y + dy[a[j].z] * i <= -1000)continue;
                if (dd[ { a[j].x + dx[a[j].z] * i , a[j].y + dy[a[j].z] * i}] != 0) {
                    q = dd[ { a[j].x + dx[a[j].z] * i, a[j].y + dy[a[j].z] * i}] - 1;
                    p = j;
                }
                else dd[ { a[j].x + dx[a[j].z] * i, a[j].y + dy[a[j].z] * i}] = j + 1;
                // cout << a[j].x + dx[a[j].z] * i << " " << a[j].y + dy[a[j].z] * i <<" "<<dd[{ a[j].x + dx[a[j].z] * i , a[j].y + dy[a[j].z] * i}] << endl;
            }
            if (q != -1 && p != -1) {
                a.erase(a.begin() + q);
                a.erase(a.begin() + p - 1);
            }
        }
        // cout << p <<" "<<q<<endl;
        cout << a.size();
        // cout << 1;
    }
    return 0;
}/*
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