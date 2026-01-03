// #pragma GCC optimize("Ofast")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

//----------------------------------------------------------------------
#define int long long int
#define vi vector<int>
#define ii pair < int , int >
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
#define pb emplace_back
const long double pi = 3.141592654;
const int oo = 1e9 + 7 ;
const int MOD = 1e9 + 7 ;
//----------------------------------------------------------------------
int t;
int n , m , c , k;
int ans , res , cow , cnt;
int x[105];

void quaylui(const int &i) {
    FOR(j , 0 , 1) {
        x[i] = j;
        res += x[i];
        cnt = 0;
        if (x[i]) {
            if (m != 1 && i % m != 1) cnt += x[i - 1];
            if (i > m) cnt += x[i - m];
        }
        if (res > c || cow + cnt > k) {
            res -= 1;
            return;
        }
        cow += cnt;
        if (i < n * m) quaylui(i + 1);
        else if (res == c)ans += 1;
        if (x[i]) {
            res -= 1;
            if (i % m != 1 && m != 1) cow -= x[i - 1];
            if (i > m) cow -= x[i - m];
        }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("SC5.inp", "r", stdin);
    freopen("SC5.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m >> c >> k;
        ans = 0; res = 0; cow = 0;
        quaylui(1);
        cout << ans << endl;
    }
    return 0;
}