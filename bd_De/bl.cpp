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
int n;
ii a[300005];
ii F[300005];
ii A;

ii operator -(ii u , ii v){
    return {v.fi - u.fi , v.se - u.se};
} 

int operator *(ii u , ii v){
    return u.fi * v.se - u.se * v.fi;
}

// bool cmp(ii u , ii v){
//     return (u - A) * (v - A) > 0;
// }

bool check(ii A , ii B , ii C){
    return (B - A) * (C - B) > 0;
}

ii origin;
void operator-=(ii &A, ii B) {
    A.fi -= B.fi;
    A.se -= B.se;
}
bool ccw(ii O, ii A, ii B) {
    A -= O, B -= O;
    return A.fi * B.se > A.se * B.fi;
}
bool cmp(ii A, ii B) { return ccw(origin, A, B); }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("bl.inp", "r", stdin);
    // freopen("bl.out", "w", stdout);
    cin >> n;
    FOR(i , 1 , n) cin >> a[i].fi >> a[i].se;
    FOR(i , 2 , n) {
        if (a[i].se < a[1].se || (a[i].se == a[1].se && a[i].fi < a[1].fi)) {
            swap(a[i].fi , a[1].fi);
            swap(a[i].se , a[1].se);
        }
    }
    sort(a + 1 , a + 1 + n);
    A = a[1];
    sort(a + 2 , a + 1 + n , cmp);
    int m = 1;
    FOR(i , 1 , n){
        while(m >= 3 && check(F[m - 2] , F[m - 1] , a[i]) == false)m -= 1;
        F[m] = a[i];
        m += 1;
    }
    F[m] = F[1];
    int ans = 0;
    FOR(i , 1 , m - 1){
        ans += (F[i] * F[i + 1]);
    }
    ans = abs(ans);
    cout << ans / 2 << '.' << (ans % 2) * 5; 
    // cout << ans;
    // cout << endl;
    // FOR(i , 1 , n)cout << a[i].fi << ' ' << a[i].se << endl;
    return 0;
}
/*
╔══╗                ▐▀▄       ▄▀▌   ▄▄▄▄▄▄▄
╚╗╔╝                ▌▒▒▀▄▄▄▄▄▀▒▒▐▄▀▀▒██▒██▒▀▀
╔╝(¯’v´¯)          ▐▒▒▒▒▀▒▀▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄
╚══’.¸.**** **     ▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▒▒▒▒▒▒▒▒▒▒▒▒▀▄
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