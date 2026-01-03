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
#define tp(x) fixed << setprecision(x)

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
const int MOD = 1e14 + 57;
//----------------------------------------------------------------------
int n, t;
int a[100005];
int tree[400005];
int lazy[400005];

void build(int id, int l, int r){
    if(l == r){
        tree[id] = a[l];
        return;
    }
    build(id * 2, l, (l + r) / 2);
    build(id * 2 + 1, (l + r) / 2 + 1 , r);
    tree[id] = max(tree[id * 2] , tree[id * 2 + 1]);
}

//ham update a[x] = val
// void update(int id, int l, int r, int x, int val){
//     if(x < l || x > r)return;
//     if(l == r){
//         tree[id] = val;
//         return;
//     }
//     update(id * 2, l, (l + r) / 2, x, val);
//     update(id * 2 + 1, (l + r) / 2 + 1, r, x, val);
//     tree[id] = max(tree[id * 2] , tree[id * 2 + 1]);
// }

//ham update nut con
void down(int id){
    int val = lazy[id];
    tree[id * 2] += val;
    lazy[id * 2] += val;

    tree[id * 2 + 1] += val;
    lazy[id * 2 + 1] += val;

    lazy[id] = 0;
}

//ham update cac gia tri tu u -> v them gia tri val
void update(int id , int l , int r , int u , int v , int val){
    if(v < l || u > r) return;
    if(u <= l && r <= v){
        tree[id] += val;
        lazy[id] += val;
        return;
    }
    down(id);
    update(id * 2 , l , (l + r) / 2 , u , v , val);
    update(id * 2 + 1 , (l + r) / 2 + 1 , r , u , v , val);
    tree[id] = max(tree[id * 2] , tree[id * 2 + 1]);
}

int get(int id , int l , int r , int u , int v){
    if(v < l || u > r)return -oo;
    if(u <= l && r <= v)return tree[id];
    down(id);
    return max(get(id * 2 , l , (l + r) / 2 , u , v) , get(id * 2 + 1, (l + r) / 2 + 1 , r , u , v));
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // freopen("test.inp","r",stdin);
    // freopen("IVAN.out","w",stdout);
    cin >> n;
    FOR(i , 1 , n)cin >> a[i];
    build(1, 1, n);
    cout << get(1, 1, n, 2, 6);
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
