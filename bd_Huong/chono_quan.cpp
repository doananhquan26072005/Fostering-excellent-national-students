#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
#define int long long int
#define tp(x) fixed<<setprecision(x)
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
#define REP(i , n) for(int i = 1 ; i <= n ; ++i)
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

int n;
int a[100005][6];
int F[35][100005];
vector<int> S = {0};

int getbit(int s , int i){
    if((s & (1 << (i-1) )) == 0)return 0;
    return 1;
}

signed main(){
fast;
freopen("test.inp","r",stdin);
freopen("test.out","w",stdout);
    cin >> n;
    REP( i , 5){
        REP(j , n)cin >> a[i][j];
    }
    fill_a(F , 0); int mask , T , k;
    REP(mask , 31){
        if(getbit(mask , 1) == getbit(mask , 2 ) && getbit(mask , 2 ) == 1)continue;
        if(getbit(mask , 2) == getbit(mask , 3 ) && getbit(mask , 3 ) == 1)continue;
        if(getbit(mask , 3) == getbit(mask , 4 ) && getbit(mask , 4 ) == 1)continue;
        if(getbit(mask , 4) == getbit(mask , 5 ) && getbit(mask , 5 ) == 1)continue;
        S.pb(mask);
    }
    FOR(i , 1 , n){
        FOR(s ,0, S.size() - 1){
            mask = S[s] ;
            REP(j , 5)
                if(getbit(mask , j ) == 1)
                    F[mask][i] += a[j][i];
        }
    }
    FOR(i ,2, n){
        FOR(s ,0, S.size() - 1){
            mask = S[s] , k = LLONG_MIN;
            FOR(t ,0, S.size() - 1){
                T = S[t] & mask;
                if(T == 0)k = max(k , F[S[t]][i - 1]);
            }
            F[mask][i] = max(k+ F[mask][i],F[mask][i]);
        }
    }
    int ans = -oo;
    FOR(s ,0, S.size() - 1){
        mask = S[s];
        ans = max(ans , F[mask][n]);
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
