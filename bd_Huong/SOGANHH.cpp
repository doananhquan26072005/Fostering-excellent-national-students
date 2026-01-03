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

int n;
int a[105];

int sol(int x){
    int sum = 0;
    FOR(i , 1 ,sqrt(x)){
        if(x%i == 0){
            sum =sum + i + x/i;
            if(i == x/i)sum -= i;
            //cout << i <<" "<<x/i<< " ";
        }
    }
    if(sum >= 2*x)return 1;
    return 0;
}

signed main() {
    fast;
    freopen("SOGANHH.inp", "r", stdin);
    freopen("SOGANHH.out", "w", stdout);
    cin >> n;
    FOR(i, 1, n)cin >> a[i];
    FOR(i , 1 ,n){
        cout << sol(a[i]) << endl;
    }
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
