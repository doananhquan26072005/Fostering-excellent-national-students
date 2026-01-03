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
int n , x;
int bit1[100005];
int bit2[100005];

void update_diem(int bit[] , int i , int val){
    for(; i <= n ; i += i & (-i)) bit[i] += val;
}

void update_range(int l , int r , int val){
    update_diem(bit1 , l , (n - l + 1) * val);
    update_diem(bit1 , r + 1 , -(n - r) * val);
    update_diem(bit2 , l , val);
    update_diem(bit2 , r + 1 , -val);
}

int get(int bit[] , int i){
    int sum = 0;
    for(; i >= 1 ; i -= i & (-i))sum += bit[i];
    return sum;
}

int sum(int u){
    return get(bit1 , u) - get(bit2 , u) * (n - u);
}

int sum_range(int l , int r){
    return sum(r) - sum(l - 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("TOMAU.inp", "r", stdin);
    // freopen("TOMAU.out", "w", stdout);
    cin >> n;
    FOR(i , 1 , n){
        cin >> x;
        update_range(i , i , x);
    }
    update_range(2 , 4 , 3);
    cout << sum_range(3 , 3) << endl << sum_range (3 , 5);
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