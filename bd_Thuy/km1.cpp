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
int n , k;
int a[100005];
int tree[400005];
int F[100005];
int H[100005];

void build(int id, int l, int r){
    if(l == r){
        tree[id] = a[l];
        return;
    }
    build(id * 2, l, (l + r) / 2);
    build(id * 2 + 1, (l + r) / 2 + 1 , r);
    tree[id] = min(tree[id * 2] , tree[id * 2 + 1]);
}

void update(int id , int l , int r , int u , int v , int val){
    if(v < l || u > r) return;
    if(u <= l && r <= v){
        tree[id] += val;
        return;
    }
    update(id * 2 , l , (l + r) / 2 , u , v , val);
    update(id * 2 + 1 , (l + r) / 2 + 1 , r , u , v , val);
    tree[id] = min(tree[id * 2] , tree[id * 2 + 1]);
}

int get(int id , int l , int r , int u , int v){
    if(v < l || u > r)return oo;
    if(u <= l && r <= v)return tree[id];
    return min(get(id * 2 , l , (l + r) / 2 , u , v) , get(id * 2 + 1, (l + r) / 2 + 1 , r , u , v));
}

signed main() {
    freopen("km1.inp", "r", stdin);
    freopen("km1.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    FOR(i , 1 , n) cin >> a[i];
    FOR(i , 1 , n) H[i] = H[i - 1] + a[i];
    build(1 , 1 , n);
    FOR(i , 1 , k - 1) F[i] = F[i - 1] + a[i];
    FOR(i , k , n){
        F[i] = min(F[i - 1] + a[i] , F[i - k] + (H[i] - H[i - k]) - get(1 , 1 , n , i - k + 1 , i));
    }
    cout << F[n];
    // FOR(i , 1 , n) cout << F[i] << ' ';
    return 0;
}
/*                                                           _____________
╔══╗                ▐▀▄       ▄▀▌   ▄▄▄▄▄▄▄                /             \
╚╗╔╝                ▌▒▒▀▄▄▄▄▄▀▒▒▐▄▀▀▒██▒██▒▀▀             / uoc gi duoc   \
╔╝(¯’v´¯)          ▐▒▒▒▒▀▒▀▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄          \  Nhi trap     /
╚══’.¸.            ▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▒▒▒▒▒▒▒▒▒▒▒▒▀▄         \  ___________/
╔♫═╗╔╗ ♥Nhi       ▀█▒▒▒█▌▒▒█▒▒▐█▒▒▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌       |/
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
