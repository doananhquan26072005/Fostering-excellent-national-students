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
int n , t;
int a[100005];
ii b[100005];
int c[100005];
struct truyvan {
    int l , r , stt;
} q[100005];
int dd[100005];// so lan xuat hien cua so i trong map
int dem[100005];//so lan xuat hien cua tan soi i trong mang
int ans[100005];

bool cmp(truyvan x , truyvan y) {
    if (x.l / ((int)(sqrt(n)) + 1) == y.l / ((int)(sqrt(n)) + 1))return x.r < y.r;
    return x.l / ((int)(sqrt(n)) + 1) < y.l / ((int)(sqrt(n)) + 1);
}

bool cpn(ii x, ii y){
    return x.se < y.se;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("FRESEQ.inp", "r", stdin);
    // freopen("FRESEQ.out", "w", stdout);
    cin >> n >> t;
    FOR(i , 1 , n)cin >> a[i];
    FOR(i , 1 , n) b[i].fi = a[i] , b[i].se = i;
    sort(b + 1 , b + 1 + n);
    int val = 0;
    b[0] = {-1e18 , 0};
    FOR(i , 1 , n){
        if(b[i].fi == b[i - 1].fi)c[i] = c[i - 1];
        else val += 1,c[i] = val;
    }
    FOR(i , 1 , n)b[i].fi = c[i];
    sort(b + 1 , b + 1 + n , cpn);
    FOR(i , 1 , n)a[i] = b[i].fi;
    FOR(i , 1 , t) {
        cin >> q[i].l >> q[i].r;
        q[i].stt = i;
    }
    sort(q + 1 , q + 1 + t , cmp);
    int base_L = 1, base_R = -1 , Max = 0;
    FOR(j , 1 , t) {
        FOR(i , base_L , q[j].l - 1) {
            dem[dd[a[i]]] -= 1;
            if (dd[a[i]] == Max && dem[dd[a[i]]] == 0) Max -= 1;
            dd[a[i]] -= 1;
            dem[dd[a[i]]] += 1;
        }
        FOR(i , q[j].l , base_L - 1) {
            dem[dd[a[i]]] -= 1;
            if (dd[a[i]] == Max) Max += 1;
            dd[a[i]] += 1;
            dem[dd[a[i]]] += 1;
        }

        FOR(i , q[j].r + 1 , base_R){
            dem[dd[a[i]]] -= 1;
            if(dd[a[i]] == Max && dem[dd[a[i]]] == 0) Max -= 1;
            dd[a[i]] -= 1;
            dem[dd[a[i]]] += 1;
        }

        FOR(i , base_R + 1 , q[j].r){
            dem[dd[a[i]]] -= 1;
            if(dd[a[i]] == Max) Max += 1;
            dd[a[i]] += 1;
            dem[dd[a[i]]] += 1;
        }

        ans[q[j].stt] = Max;
        base_L = q[j].l;
        base_R = q[j].r;
        // cout << q[j].l << ' ' << q[j].r << ' ' << endl;
    }
    FOR(i , 1 , t)cout << ans[i] << endl;
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