#pragma GCC optimize("Ofast")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

//----------------------------------------------------------
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

#define fi first
#define se second
#define pb push_back
const long double pi = 3.141592654;
const int oo = 1e9 + 7 ;
const int MOD = 1e9 + 7 ;
//-----------------------------------------------------------
string cong(string a, string b)
{
    string res = "";
    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;
    int carry = 0;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        int tmp = a[i] - 48 + b[i] - 48 + carry;
        carry = tmp / 10;
        tmp = tmp % 10;
        res = (char)(tmp + 48) + res;
    }
    if (carry > 0) res = "1" + res;
    return res;
}

string tru(string a, string b)
{
    string res = "";
    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;
    bool neg = false;
    if (a < b)
    {
        swap(a, b);
        neg = true;
    }
    int borrow = 0;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        int tmp = a[i] - b[i] - borrow;
        if (tmp < 0)
        {
            tmp += 10;
            borrow = 1;
        }
        else borrow = 0;
        res = (char)(tmp % 10 + 48) + res;
    }
    while (res.length() > 1 && res[0] == '0') res.erase(0, 1);
    if (neg) res = "-" + res;
    return res;
}

string nhan(string a, string b)
{
    string res = "";
    int n = a.length();
    int m = b.length();
    int len = n + m - 1;
    int carry = 0;
    for (int i = len; i >= 0; i--)
    {
        int tmp = 0;
        for (int j = n - 1; j >= 0; j--)
            if (i - j <= m && i - j >= 1)
            {
                int a1 = a[j] - 48;
                int b1 = b[i - j - 1] - 48;
                tmp += a1 * b1;
            }
        tmp += carry;
        carry = tmp / 10;
        res = (char)(tmp % 10 + 48) + res;
    }
    while (res.length() > 1 && res[0] == '0') res.erase(0, 1);
    return res;
}
//-----------------------------------------------------------
int n , m;
string F[40][40];

string sol(int x, int y) {
    if (F[x][y] == "-1") {
        F[x][y] = "0";
        if (x == 0) F[x][y] = "1";
        else if (y == 0) F[x][y] = "0";
        REP(i , x) F[x][y] = cong(F[x][y] , nhan(sol(i, y - 1) , sol(x - 1 - i, y - 1)));
    }
    return F[x][y];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("trees.inp", "r", stdin);
    freopen("trees.out", "w", stdout);
    cin >> n >> m;
    FOR(i , 0 , n)
    FOR(j , 0 , n) F[i][j] = "-1";
    cout << tru(sol(n, n) , sol(n, m - 1));
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