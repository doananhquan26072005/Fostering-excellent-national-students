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
int n, m, cnt;
ii A[600005], B[600005];
ii F[600005];
int sum[600005];

int check(ii a, ii b, ii c) {
    int ans = a.fi * (b.se - c.se) + b.fi * (c.se - a.se) + c.fi * (a.se - b.se);
    if(ans > 0)return 1;
    if(ans < 0)return -1;
    return 0;
}

int find(int i, int x) {
    if (x < 0) x += cnt;
    if (x >= cnt) x -= cnt;
    int y = x + 1; if (y == cnt) y = 0;
    return check(A[i], F[x], F[y]);
}

int kc(ii a, ii b) {
    return a.fi * (int)b.se - a.se * (int)b.fi;
}

int dien_tich (int a, int b) {
    return sum[b] - sum[a] + kc(A[b], A[a]);
}

int pitago(ii a, ii b) {
    int dx = a.fi - b.fi, dy = a.se - b.se;
    return dx * dx + dy * dy;
}

bool cmp(ii x , ii y) {
    int s = check(B[0], x, y);
    if (s != 0) return s > 0;
    return pitago(B[0], x) < pitago(B[0], y);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("cutcake.inp", "r", stdin);
    freopen("cutcake.out", "w", stdout);
    cin >> n;
    REP(i, n) cin >> A[i].fi >> A[i].se;
    REP(i, n) A[i + n] = A[i];

    cin >> m;
    REP(i, m) cin >> B[i].fi >> B[i].se;

    sort(B, B + m);
    sort(B + 1, B + m, cmp);

    cnt = min((int)2, m);
    REP(i , cnt)F[i] = B[i];
    for (int i = 2; i < m; ++i) {
        while (cnt >= 2 && check(F[cnt - 2], F[cnt - 1], B[i]) <= 0) cnt -= 1;
        F[cnt ++] = B[i];
    }
    REP(i, cnt) F[i + cnt] = F[i];

    sum[0] = 0;
    REP(i, 2 * n) sum[i + 1] = sum[i] + kc(A[i], A[i + 1]);
    // REP(i , 2 * n)cout << sum[i] << ' ';

    int ans = 0;
    int x = 0, y;

    for (y = 0; y < cnt; y += 1) if (find(x, y) >= 0 && find(x, y - 1) <= 0)break;

    REP(x , n) {
        while (y < 2 * cnt && find(x, y) < 0) y += 1;

        int l = x, r = l + n , res;
        while (l <= r) {
            int mid = (l + r + 1) / 2;
            if (check(A[x], A[mid], F[y]) > 0){
                res = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        // cout << x << ' ' << l << endl;
        ans = max(ans, dien_tich(x, res));
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