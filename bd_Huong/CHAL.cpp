#pragma GCC optimize("Ofast")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define ii pair < int , int >
#define endl "\n"

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , n , x) for(int i = n ; i >= x ; --i)

#define fi first
#define se second
#define pb emplace_back
const long double pi = 3.141592654;
const int oo = 1e9 + 7 ;
const int N = 2e5 + 5 ;
const int MOD = 1e9 + 7 ;

int n , m ;
int a[1005][1005];
int check[100005];
vi ngto;

int snt(int n) {
    if (n < 2)return 2;
    for (int i = 2; i * i <= n; i += 1)
        if (n % i == 0)return 2;
    return 1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("CHAL.inp", "r", stdin);
    freopen("CHAL.out", "w", stdout);
    cin >> n >> m;
    int Max = -oo;
    FOR(i , 1 , n) {
        FOR(j , 1 , m) {
            cin >> a[i][j];
            Max = max(Max , a[i][j]);
        }
    }
    memset(check , 0 , sizeof(check));
    // 1 là so nguyen to , 2 la khong phai
    check[1] = 1;
    FOR(i , 2 , Max) {
        if (check[i] == 0) {
            check[i] = snt(i);
            if (check[i] == 1)ngto.pb(i);
        }
        for (int j = 2; j * i <= Max ; j += 1) {
            check[i * j] = 2;
        }
    }
    FOR(i , Max + 1 , 1e9) {
        if (snt(i) == 1) {
            ngto.pb(i);
            break;
        }
    }
    FOR(i , 2,  Max) {
        if (check[i] == 1)check[i] = 0;
        else {
            check[i] = abs(i - ngto[upper_bound(ngto.begin() , ngto.end() , i) - ngto.begin()]);
        }
    }
    int ans = oo;
    int cot[1005];
    memset(cot , 0 , sizeof(cot));
    FOR(i , 1 , n) {
        FOR(j , 1 , m)cot[i] += check[a[i][j]];
    }
    int hang[1005];
    memset(hang , 0 , sizeof(hang));
    FOR(i , 1 , n) {
        FOR(j , 1 , m)hang[j] += check[a[i][j]];
    }
    FOR(i , 1,  m)ans = min(ans , hang[i]);
    FOR(i , 1 , n)ans = min(ans , cot[i]);
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
