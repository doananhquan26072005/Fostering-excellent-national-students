#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define tp(x) fixed << setprecision(x)
#define ll long long
#define ul unsigned long long
#define BASE 1000000000000000000ull
#define ii pair < int , int >
#define iii tuple< int , int , int >
#define iv pair tuple< int , int , int , int>
#define vi vector <int>
#define vii vector <vi>
#define vp vector <ii>
#define vpp vector <vp>

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , n , x) for(int i = n ; i >= x ; --i)
#define FORC(v , a) for(auto v : a)

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define fast ios::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
#define fill_a(x , i) memset(x , i ,sizeof x) ;
#define ar array
const long double pi = 3.141592654;
const int oo = 1e9 + 7 ;
const int N = 2e5 + 5 ;
const int MOD = 1e9 + 7 ;

int n , k;
int a[25][25];
int F[150000][25];

int getbit(int s , int i){
    if((s & (1 << (n - i))) == 0)return 0;
    return 1;
}

signed main() {
    fast;
    freopen("DONNUOC.inp","r",stdin);
    freopen("DONNUOC.out","w",stdout);
    // input
    cin >> n >> k;
    FOR(i , 1 , n){
        FOR(j , 1 ,n){
            cin >> a[i][j];
        }
    }
    // TH dac biet
    if(n == k){
        cout << 0;
        return 0;
    }
    //  cai dat
    FOR(mask , 1 , (1 << n) - 1){
        FOR(i , 1 , n){
            F[mask][i] = oo;
        }
    }
    // bai toan co so
    FOR(mask , 1 , (1 << n) - 1){
        if(__builtin_popcount(mask) != 1)continue;
        FOR(i , 1 , n){
            if(getbit(mask , i) == 0)continue;
            FOR(j , 1 , n){
                if(i != j)F[mask][i] = min(a[j][i] , F[mask][i]);
            }
        }
    }
    //quy hoach dong
    FOR(mask , 1 , (1 << n) - 1){
        FOR(i , 1 , n){
            if(getbit(mask , i) == 0)continue;
            FOR(j , 1 , n){
                if(i != j && getbit(mask , j) == 0)
                    F[mask | (1 << (j - 1))][i] = min(F[mask | (1 << (j - 1))][i] , F[mask][i] + a[j][i]);
            }
        }
    }
    // tim ans
    int ans = oo;
    FOR(mask , 1 , (1 << n) - 1){
        if(__builtin_popcount(mask) != (n - k))continue;
        FOR(i , 1 , n){
            if(getbit(mask , i) == 0)continue;
                ans = min(ans , F[mask][i]);
        }
    }
    cout << ans;
    return 0;
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
