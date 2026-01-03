// #pragma GCC optimize("Ofast")
// #pragma GCC optimization ("unroint-loops")
// #pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

//----------------------------------------------------------------------
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
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
int n , h;
ii a[1000005];
ii F[1000005];
ii k1[1000005];
ii k2[1000005];
vector <pair<ii , ii>> res;

int ccw (ii A, ii B, ii C) {
    return A.fi * (C.se - B.se) + B.fi * (A.se - C.se) + C.fi * (B.se - A.se);
}

ii giao(ii A , ii B) {
    if (A.fi * (A.se - B.se) + (B.fi - A.fi) * (A.se - h) < 0 && A.se - B.se < 0)
        return { - (A.fi * (A.se - B.se) + (B.fi - A.fi) * (A.se - h)) , - (A.se - B.se)};
    if (A.fi * (A.se - B.se) + (B.fi - A.fi) * (A.se - h) > 0 && A.se - B.se < 0)
        return { - (A.fi * (A.se - B.se) + (B.fi - A.fi) * (A.se - h)) , - (A.se - B.se)};
    return {A.fi * (A.se - B.se) + (B.fi - A.fi) * (A.se - h) , A.se - B.se};
}

bool cmp(pair <ii , ii> A , pair <ii , ii> B) {
    return A.se.fi * B.se.se < A.se.se * B.se.fi;
}

bool smaller(const ii& x, const ii& y) {
    return x.fi * y.se < y.fi * x.se;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("leonui.inp", "r", stdin);
    // freopen("leonui.out", "w", stdout);
    cin >> n >> h;
    FOR(i , 1 , n) cin >> a[i].fi >> a[i].se;
    int m = 2;
    F[1] = a[1];
    FOR(i , 2 , n - 2) {
        while (m >= 3 && ccw(F[m - 1] , F[m] , a[i]) <= 0) m -= 1;
        if (i & 1)k1[i] = giao(a[i] , F[m]);
        F[++ m] = a[i];
    }

    m = 1;
    F[1] = a[n];
    FORD(i , n - 1 , 3) {
        while (m >= 3 && ccw(F[m - 1] , F[m] , a[i]) >= 0) m -= 1;
        if (i & 1)k2[i] = giao(a[i] , F[m]);
        F[++ m] = a[i];
    }

    for (int i = 3 ; i <= n - 2 ; i += 2) res.pb({k1[i] , k2[i]});
    sort(res.begin() , res.end() , cmp);

    // int ans = 0;
    // int j = 0;
    // REP(i , res.size()) {
    //     j = i + 1;
    //     ans += 1;
    //     while (j < res.size() && res[j].fi.fi * res[i].se.se <= res[i].se.fi * res[j].fi.se) j += 1;
    //     i = j - 1;
    // }
    // cout << ans;

    int dem = 0;
    ii last;
    bool is_first = true;
    for (auto& it : res) {
        if (is_first || smaller(last, it.fi)) {
            dem++;
            last = it.se;
            is_first = false;
        }
    }
    cout << dem;
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