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
int n, m, k;
char a[15][15];
char b[15][15];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("rot.inp", "r", stdin);
    // freopen("rot.out", "w", stdout);
    cin >> n >> m;
    FOR(i , 1 , n) {
        FOR(j , 1 , m) cin >> a[i][j];
    }
    cin >> k;
    if (k == 360 || k == 0) {
        FOR(i , 1 , n) {
            FOR(j , 1 , m)cout << a[i][j];
            cout << endl;
        }
    }
    else if (k == 90) {
        for (int j = 1; j <= m; j += 1) {
            for (int i = n; i >= 1; i -= 1)cout << a[i][j];
            cout << endl;
        }
    }
    else if (k == 180) {
        for (int i = n; i >= 1; i -= 1) {
            for (int j = m; j >= 1; j -= 1)cout << a[i][j];
            cout << endl;
        }
    }
    else if (k == 270) {
        for (int i = m; i >= 1; i -= 1) {
            for (int j = 1; j <= n; j += 1) cout << a[j][i];
            cout << endl;
        }
    }
    else if (k == 45) {
        int dc = min(n , m) , kc = dc * 2 , i = 1, j , x , dem;
        while (i <= n) {
            j = i;
            dem = 0;
            while (j >= 1 ) {
                dem += 1;
                j -= 1;
            }
            FOR(i , 1 , (kc - dem * 2) / 2)cout << " ";
            j = 1; x = i;
            while (x >= 1 ) {
                cout << a[x][j] << " ";
                j += 1;
                x -= 1;
            }
            cout << endl;
            i += 1;
        }
        j = 2; dem = 1;
        while (j <= m) {
            FOR(z , 1 , dem)cout << " ";
            dem += 1;
            x = j; i = n;
            while (x <= m) {
                cout << a[i][x] << " ";
                x += 1;
                i -= 1;
            }
            cout << endl;
            j += 1;
        }
    }
    else if (k == 135) {
        int dc = min(n , m) , kc = dc * 2 , i, j = 1, x , dem , check = 0;
        while (j <= m) {
            i = j;
            dem = 0;
            while (i >= 1 ) {
                dem += 1;
                i -= 1;
            }
            if ((kc - dem * 2) / 2 == 0)check = 1;
            FOR(i , 1 , (kc - dem * 2) / 2)cout << " ";
            if (check != 0) {
                FOR(i , 1 , check - 1)cout << " ";
                check += 1;
            }
            i = n; x = j;
            while (x >= 1) {
                cout << a[i][x] << " ";
                x -= 1;
                i -= 1;
            }
            cout << endl;
            j += 1;
        }
        i = n - 1;
        while (i >= 1) {
            j = m; x = i;
            FOR(i , 1 , check - 1)cout << " ";
            check += 1;
            while (x >= 1) {
                cout << a[x][j] << " ";
                x -= 1;
                j -= 1;
            }
            cout << endl;
            i -= 1;
        }
    }
    else if(k == 225){
        FOR(i , 1 , n){
            FOR(j , 1 , m){
                b[i][j] = a[n - i + 1][m - j + 1];
            }
        }
        FOR(i , 1 , n){
            FOR(j , 1 , m)a[i][j] = b[i][j];
        }
        int dc = min(n , m) , kc = dc * 2 , i = 1, j , x , dem;
        while (i <= n) {
            j = i;
            dem = 0;
            while (j >= 1 ) {
                dem += 1;
                j -= 1;
            }
            FOR(i , 1 , (kc - dem * 2) / 2)cout << " ";
            j = 1; x = i;
            while (x >= 1 ) {
                cout << a[x][j] << " ";
                j += 1;
                x -= 1;
            }
            cout << endl;
            i += 1;
        }
        j = 2; dem = 1;
        while (j <= m) {
            FOR(z , 1 , dem)cout << " ";
            dem += 1;
            x = j; i = n;
            while (x <= m) {
                cout << a[i][x] << " ";
                x += 1;
                i -= 1;
            }
            cout << endl;
            j += 1;
        }
    }
    else{
        FORD(i , m , 1){
            FOR(j , 1 , n)b[i][j] = a[j][m - i + 1];
        }
        FOR(i , 1 , m){
            FOR(j , 1 , n)a[i][j] = b[i][j];
        }
        int dc = min(n , m) , kc = dc * 2 , i = 1, j , x , dem;
        while (i <= n) {
            j = i;
            dem = 0;
            while (j >= 1 ) {
                dem += 1;
                j -= 1;
            }
            FOR(i , 1 , (kc - dem * 2) / 2)cout << " ";
            j = 1; x = i;
            while (x >= 1 ) {
                cout << a[x][j] << " ";
                j += 1;
                x -= 1;
            }
            cout << endl;
            i += 1;
        }
        j = 2; dem = 1;
        while (j <= m) {
            FOR(z , 1 , dem)cout << " ";
            dem += 1;
            x = j; i = n;
            while (x <= m) {
                cout << a[i][x] << " ";
                x += 1;
                i -= 1;
            }
            cout << endl;
            j += 1;
        }
    }
}
/*
───────────────────────────────────────
───▐▀▄───────▄▀▌───▄▄▄▄▄▄▄─────────────
───▌▒▒▀▄▄▄▄▄▀▒▒▐▄▀▀▒██▒██▒▀▀▄──────────
──▐▒▒▒▒▀▒▀▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄────────
──▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▒▒▒▒▒▒▒▒▒▒▒▒▀▄──────
▀█▒▒▒█▌▒▒█▒▒▐█▒▒▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌─────
▀▌▒▒▒▒▒▒▀▒▀▒▒▒▒▒▒▀▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐───▄▄
▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌▄█▒█
▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒█▀─
▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▀───
▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌────
─▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐─────
─▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌─────
──▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐──────
──▐▄▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▌──────
────▀▄▄▀▀▀▀▀▄▄▀▀▀▀▀▀▀▄▄▀▀▀▀▀▄▄▀────────
*/
