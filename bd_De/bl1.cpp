// #pragma GCC optimize("Ofast")
// #pragma GCC optimization ("unroint-loops")
// #pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

//----------------------------------------------------------------------
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
int n;
ii a[300005];
multiset <ii> tung , hoanh;
char c[300005];
int diem[300005];
bool dd[300005];
int res[300005]; // dap an 
ii A; // phan tu dau tien cua mang
ii cnt[300005]; // vi tri 2 ben cua i khi bao loi

ii operator -(ii u , ii v) {
    return {v.fi - u.fi , v.se - u.se};
}

int operator *(ii u , ii v) {
    return u.fi * v.se - u.se * v.fi;
}

bool cmp(ii u , ii v) {
    return (u - A) * (v - A) > 0;
}

bool check(ii A , ii B , ii C) {
    return (B - A) * (C - B) > 0;
}

int sol(ii A , ii B , ii C) {
    return A.fi * (B.se - C.se) + B.fi * (C.se - A.se) + C.fi * (A.se - B.se);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("bl1.inp", "r", stdin);
    freopen("bl1.out", "w", stdout);
    cin >> n;
    FOR(i , 1 , n) cin >> a[i].fi >> a[i].se;
    FOR(i , 2 , n) {
        if (a[i].se < a[1].se || (a[i].se == a[1].se && a[i].fi < a[1].fi)) {
            swap(a[i].fi , a[1].fi);
            swap(a[i].se , a[1].se);
        }
    }
    A = a[1];
    sort(a + 2 , a + 1 + n , cmp);
    FOR(i , 1 , n) {
        dd[i] = true;
        hoanh.insert({a[i].fi , i});
        tung.insert({a[i].se , i});
    }
    multiset <ii> :: iterator it;
    FOR(i , 1 , n - 2) {
        cin >> c[i];
        if (c[i] == 'U') {
            it = tung.end();
            it --;
            diem[i] = (*it).se;
            hoanh.erase(hoanh.find({a[(*it).se].fi , (*it).se}));
            tung.erase(it);
        }
        else if (c[i] == 'D') {
            it = tung.begin();
            diem[i] = (*it).se;
            hoanh.erase(hoanh.find({a[(*it).se].fi , (*it).se}));
            tung.erase(it);
        }
        else if (c[i] == 'R') {
            it = hoanh.end();
            it --;
            diem[i] = (*it).se;
            tung.erase(tung.find({a[(*it).se].se , (*it).se}));
            hoanh.erase(it);
        }
        else {
            it = hoanh.begin();
            diem[i] = (*it).se;
            tung.erase(tung.find({a[(*it).se].se , (*it).se}));
            hoanh.erase(it);
        }
        dd[diem[i]] = false;
    }
    int x = 0 , y , u , v , t , ans = 0;
    FOR(i , 1 , n) {
        if (dd[i] == false)continue;
        if (x == 0)x = i;
        else y = i;
    }
    cnt[x].fi = cnt[x].se = y;
    cnt[y].fi = cnt[y].se = x;
    FORD(i , n - 2 , 1) {
        if (c[i] == 'U') {
            it = tung.end();
            it --;
            u = (*it).se;
            if (a[u].fi < a[diem[i]].fi) {
                cnt[diem[i]].fi = cnt[u].fi; cnt[diem[i]].se = u;
                cnt[cnt[u].fi].se = diem[i]; cnt[u].fi = diem[i];
            }
            else {
                cnt[diem[i]].fi = u; cnt[diem[i]].se = cnt[u].se;
                cnt[cnt[u].se].fi = diem[i]; cnt[u].se = diem[i];
            }
        }
        else if (c[i] == 'D') {
            it = tung.begin();
            u = (*it).se;
            if (a[u].fi < a[diem[i]].fi) {
                cnt[diem[i]].fi = u; cnt[diem[i]].se = cnt[u].se;
                cnt[cnt[u].se].fi = diem[i]; cnt[u].se = diem[i];
            }
            else {
                cnt[diem[i]].fi = cnt[u].fi; cnt[diem[i]].se = u;
                cnt[cnt[u].fi].se = diem[i]; cnt[u].fi = diem[i];
            }
        }
        else if (c[i] == 'L') {
            it = hoanh.begin();
            u = (*it).se;
            if (a[u].se < a[diem[i]].se) {
                cnt[diem[i]].fi = cnt[u].fi; cnt[diem[i]].se = u;
                cnt[cnt[u].fi].se = diem[i]; cnt[u].fi = diem[i];
            }
            else {
                cnt[diem[i]].fi = u; cnt[diem[i]].se = cnt[u].se;
                cnt[cnt[u].se].fi = diem[i]; cnt[u].se = diem[i];
            }
        }
        else {
            it = hoanh.end();
            it --;
            u = (*it).se;
            if (a[u].se < a[diem[i]].se) {
                cnt[diem[i]].fi = u; cnt[diem[i]].se = cnt[u].se;
                cnt[cnt[u].se].fi = diem[i]; cnt[u].se = diem[i];
            }
            else {
                cnt[diem[i]].fi = cnt[u].fi; cnt[diem[i]].se = u;
                cnt[cnt[u].fi].se = diem[i]; cnt[u].fi = diem[i];
            }
        }
        ans += abs(sol(a[cnt[diem[i]].fi] , a[diem[i]] , a[cnt[diem[i]].se]));

        if (i != n - 2) {
            v = cnt[diem[i]].fi;
            while (check(a[cnt[v].fi] , a[v] , a[diem[i]]) == false) {
                ans += abs(sol(a[diem[i]] , a[v] , a[cnt[v].fi]));
                v = cnt[v].fi;
            }
            cnt[diem[i]].fi = v; cnt[v].se = diem[i];

            t = cnt[diem[i]].se;
            while (check(a[diem[i]] , a[t] , a[cnt[t].se]) == false) {
                ans += abs(sol(a[diem[i]] , a[t] , a[cnt[t].se]));
                t = cnt[t].se;
            }
            cnt[diem[i]].se = t; cnt[t].fi = diem[i];
        }

        tung.insert({a[diem[i]].se , diem[i]});
        hoanh.insert({a[diem[i]].fi , diem[i]});
        res[i] = abs(ans);
    }
    FOR(i , 1 , n - 2)cout << res[i] / 2 << '.' << (res[i] % 2) * 5 << endl;
    // FOR(i , 1 , n)cout << cnt[i].fi << " " << cnt[i].se << endl;
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