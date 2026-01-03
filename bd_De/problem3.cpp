// #pragma GCC optimize("Ofast")
// #pragma GCC optimization ("unroint-loops")
// #pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

//----------------------------------------------------------------------
#define int long long
#define vi vector<int>
#define ii pair < int , int >
#define endl "\n"

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , n , x) for(int i = n ; i >= x ; --i)

#define fi first
#define se second
#define pb push_back
const long double pi = 3.141592654;
const int oo = 1e9 + 7;
const int MOD = 1e9 + 7;
//----------------------------------------------------------------------
int n;
int a[200005];
int dd[200005];
int canh = 0 , nextnode = 3, xetdinh = 1 , lastcanh;
int canh1 , canh2 , canh3 , cnt1 , cnt2;

struct tamgiac {
    int x , y , z;
};
vector <tamgiac> mang;

signed main() {
    freopen("problem3.inp", "r", stdin);
    freopen("problem3.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    char x;
    FOR(i , 1 , n) {
        cin >> x;
        a[i] = x - '0';
    }
    lastcanh = a[1];
    while (dd[xetdinh] == false) {
        if (nextnode == xetdinh)break;
        if (nextnode == xetdinh - 1 || xetdinh == nextnode - 1)break;
        if (nextnode * xetdinh == n)break;
        // cout << xetdinh << " " << nextnode << " " << lastcanh << endl;
        if (dd[nextnode] == true) {
            int res;
            if (nextnode == 1)res = n;
            else res = nextnode - 1;
            if (res == xetdinh + 1) {
                mang.pb({xetdinh , nextnode , 6 - a[xetdinh] - a[res]});
                canh += 1;
            }
            xetdinh = nextnode;
            nextnode += 2;
            if (nextnode > n)nextnode %= n;
        }
        else if (lastcanh != a[nextnode - 1]) {
            // cout << lastcanh << " " << nextnode << endl;
            // dd[nextnode] = true;
            int res = 6 - (lastcanh + a[nextnode - 1]);
            mang.pb({xetdinh , nextnode , res});
            lastcanh = res;
            nextnode += 1;
            if (nextnode > n)nextnode %= n;
            canh += 1;
            if (dd[nextnode] == true) {
                canh1 = lastcanh;
                cnt1 = xetdinh;
                cnt2 = nextnode;
                if (nextnode == 1)canh2 = a[n];
                else canh2 = a[nextnode - 1];
            }
        }
        else if (lastcanh != a[xetdinh]) {
            // cout << "HEHE";
            dd[xetdinh] = true;
            xetdinh = nextnode - 1;
            if (nextnode == 1)xetdinh = n;
            nextnode = xetdinh + 2;
            if (nextnode > n)nextnode %= n;
            lastcanh = a[xetdinh];
            // cout << xetdinh << " " << nextnode << " " << lastcanh << endl;
        }
        else {
            // cout << "HAHA";
            dd[xetdinh] = true;
            xetdinh += 1;
            if (xetdinh > n)xetdinh %= n;
            nextnode = xetdinh + 2;
            if (nextnode > n)nextnode %= n;
            lastcanh = a[xetdinh];
        }
    }
    REP(i , mang.size()) {
        if (cnt1 == mang[i].x && cnt2 == mang[i].y)canh3 = mang[i].z;
        if (cnt1 == mang[i].y && cnt2 == mang[i].x)canh3 = mang[i].z;
        // cout << mang[i].x << " " << mang[i].y << " " << mang[i].z << endl;
    }
    if (mang.size() == 1) {
        canh1 = mang[0].z;
        canh2 = a[n];
        canh3 = a[n - 1];
    }
    if(canh1 * canh2 * canh3 != 6 && canh1 + canh2 + canh3 != 0)return cout << "NE" , 0;
    if (mang.size() == 3) {
        canh1 = mang[0].z;
        canh2 = mang[1].z;
        canh3 = mang[2].z;
    }
    if(canh1 * canh2 * canh3 != 6 && canh1 + canh2 + canh3 != 0)return cout << "NE" , 0;
    if(canh == n - 3)cout << "DA";
    else cout << "NE";
    // cout << canh;
    // cout << canh1 << " " << canh2 << " " << canh3;
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