//#pragma GCC optimize("Ofast")
//#pragma GCC optimization ("unroint-loops")
//#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

//----------------------------------------------------------------------
#define int long long int
#define vi vector<int>
#define ii pair < int , int >
#define endl "\n"
#define tp(x) fixed << Sprecision(x)

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , n , x) for(int i = n ; i >= x ; --i)

//stoi() : string -> int
//stoi() : string -> double
//a.erase(unique(begin(a), end(a)), end(a)) xoa cac phan tu trung lap
//string s = bitS<8>(n).to_string() chuyen 1 so thanh dang nhi phan
//to_string chyen 1 so thanh xau

#define fi first
#define se second
#define pb push_back
const long double pi = 3.141592654;
const int oo = 1e9 + 7;
const int MOD = 1e9 + 7;
//----------------------------------------------------------------------

signed main() {
    freopen("diferent.inp", "r", stdin);
    freopen("diferent.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ii> stk;
    vi leftMin(n);
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        while (!stk.empty() && stk.back().first > a[i]) {
            cnt += stk.back().second;
            stk.pop_back();
        }
        stk.emplace_back(a[i], cnt);
        leftMin[i] = cnt;
    }
    stk.clear();
    vi rightMin(n);
    for (int i = n - 1; i >= 0; i--) {
        int cnt = 1;
        while (!stk.empty() && stk.back().first >= a[i]) {
            cnt += stk.back().second;
            stk.pop_back();
        }
        stk.emplace_back(a[i], cnt);
        rightMin[i] = cnt;
    }
    stk.clear();
    vi leftMax(n);
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        while (!stk.empty() && stk.back().first < a[i]) {
            cnt += stk.back().second;
            stk.pop_back();
        }
        stk.emplace_back(a[i], cnt);
        leftMax[i] = cnt;
    }
    stk.clear();
    vi rightMax(n);
    for (int i = n - 1; i >= 0; i--) {
        int cnt = 1;
        while (!stk.empty() && stk.back().first <= a[i]) {
            cnt += stk.back().second;
            stk.pop_back();
        }
        stk.emplace_back(a[i], cnt);
        rightMax[i] = cnt;
    }
    long long sumMax = 0, sumMin = 0;
    for (int i = 0; i < n; i++) {
        sumMin += 1LL * a[i] * leftMin[i] * rightMin[i];
        sumMax += 1LL * a[i] * leftMax[i] * rightMax[i];
    }
    cout << sumMax - sumMin;
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