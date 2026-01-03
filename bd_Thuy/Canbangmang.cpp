#pragma GCC optimize("Ofast")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

#define int long long int
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

int n , m;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("canbangmang.inp", "r", stdin);
    freopen("canbangmang.out", "w", stdout);
    cin >> n;
    vi a(n + 1);
    int sum1 = 0;
    FOR(i , 1 , n) {
        cin >> a[i];
        sum1 += a[i];
    }
    cin >> m;
    vi b(m + 1);
    int sum2 = 0;
    FOR(i , 1 , m) {
        cin >> b[i];
        sum2 += b[i];
    }
    if (sum1 != sum2) return cout << -1, 0;
    int i = 1, j = 1, ans = 0;
    sum1 = 0, sum2 = 0;
    while (i <= n && j <= m) {
        if (sum1 != sum2) {
            if (sum1 < sum2) {
                i += 1;
                sum1 += a[i];
            }
            else {
                j += 1;
                sum2 += b[j];
            }
            if (sum1 == sum2) {
                i += 1;
                j += 1;
                ans += 1;
                sum1 = sum2 = 0;
                continue;
            }
        }
        else if (sum1 == sum2 && a[i] == b[j]) {
            i += 1;
            j += 1;
            sum1 = 0;
            sum2 = 0;
            ans += 1;
            continue;
        }
        else if (sum1 == sum2 && a[i] != b[j])
        {
            sum1 += a[i];
            sum2 += b[j];
        }
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