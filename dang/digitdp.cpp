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
// tinh so cac so tu 1 den a sao cho moi so co dung k chu so b
int a , b , k;
int F[20][20][2];
// xet den chu so thu i (trai sang phai)
// xet xem co bao nhieu chu so b 
// xet dieu kien so dang xet co < a hay khong (true la < , false la =)
vi number;
// phan tich tung chu so cua a

int sol(int i , int cnt , bool ok){
    if(i == number.size()){
    // xet den chu so cuoi cua a xem co thoa dk
        if(cnt == k)return 1;
        // co k so b trong so dang xet nen nhan 1 gia tri
        return 0;
        // nguoc lai nhan 0 gia tri
    }
    if(cnt > k)return 0;
    // neu co nhieu hon k so b trong day thi nhan 0 gia tri
    if(F[i][cnt][ok] != -1)return F[i][cnt][ok];
    // neu da co kq san thi return kq
    int res = 0 , limit = 9;
    // res la so cac so thoa man
    // limit la gia tri lon nhat chu so thu i co the nhan (neu ok = true thi nhan moi gia tri tu 0 -> 9)
    if(ok == false)limit = number[i];
    //ok = false: cac so phia trc = vi tri cua no cua a nen o vi tri i nhan max la vi tri i cua a
    FOR(digit , 0 , limit){
        // chay bien digit : la chu so co the gan tai vi tri i hien tai
        int newok = ok;
        int newcnt = cnt;
        // tao 1 newok va newcnt de xet vi tri i + 1
        if(digit < limit)newok = true;
        // neu digit < limit thi tu vi tri i + 1 khong can quan tam den digit (no da be hon a)
        if(digit == b)newcnt += 1;
        // neu digit == b tang newcnt len 1 de xet vitri i + 1
        res += sol(i + 1 , newcnt , newok);
        // xet vi tri i + 1 voi newok , newcnt
    }
    return F[i][cnt][ok] = res;
    // cap nhap F[i][cnt][ok] theo res
}

signed main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> a >> b >> k;
    memset(F , -1 , sizeof(F));
    // gan mang F = -1
    while(a > 0){
        number.pb(a % 10);
        a /= 10;
    }
    reverse(number.begin() , number.end());
    // tach cac chu so cua a vao vecto
    cout << sol(0 , 0 , 0);
    // tinh ket qua
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