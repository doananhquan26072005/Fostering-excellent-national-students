#include<bits/stdc++.h>
using namespace std;

//----------------------------------------------------------------------
#define int long long
#define vi vector<int>
#define ii pair < int , int >
#define endl "\n"

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)

#define fi first
#define se second
#define pb push_back
//----------------------------------------------------------------------
int n;
ii a[1505];
struct diem {
    int x , y , goc;
} b[1505];
vector <pair<ii , int>> res;
int GOC[5];

int quaygoc(int i) {
    int dem = 0;
    while (b[i].x <= 0 || b[i].y < 0) {
        swap(b[i].x , b[i].y);
        b[i].y *= -1;
        dem += 1;
    }
    return dem;
}

bool cmp(diem u , diem v) {
    if (u.x == v.x)return u.y < v.y;
    return u.x < v.x;
}

signed main() {
    // freopen("RTRIANGLE.inp", "r", stdin);
    // freopen("RTRIANGLE.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    FOR(i , 1, n)cin >> a[i].fi >> a[i].se;
    int GCD , ans = 0 , goc1 , goc2 , goc3 , goc4;
    FOR(i , 1 , n) {
        res.clear();
        FOR(j , 1 , n) {
            b[j].x = a[j].fi - a[i].fi;
            b[j].y = a[j].se - a[i].se;
            b[j].goc = 1;
            if (j == i)continue;
            b[j].goc = quaygoc(j) + 1;
            GCD = __gcd(b[j].x , b[j].y);
            res.pb({{b[j].x / GCD , b[j].y / GCD} , b[j].goc});
        }
        sort(res.begin() , res.end());
        res.pb({ {-1 , -1} , 0});
        GOC[1] = 0; GOC[2] = 0; GOC[3] = 0; GOC[4] = 0;
        FOR(j , 0 , res.size() - 2) {
            if(res[j].fi.fi == res[j + 1].fi.fi && res[j].fi.se == res[j + 1].fi.se)GOC[res[j].se] += 1;
            else {
                GOC[res[j].se] += 1;
                ans += GOC[1] * GOC[2] + GOC[2] * GOC[3] + GOC[3] * GOC[4] + GOC[4] * GOC[1];
                GOC[1] = 0; GOC[2] = 0; GOC[3] = 0; GOC[4] = 0;
            }
        }
    }
    cout << ans;
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
