#include <bits/stdc++.h>

using namespace std;
//------------------------------------------------
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define DEC(i, a, b) for(int i=a; i>=b; i--)
const double pi = 3.141592654;
const long oo = INT_MAX;
const long nInf = INT_MIN;

//-------------------------------------------------
bool ans;
long test, n, A[1000][26], goal[26], cur[26], X[1000];
void init(long n){
    FOR(i, 1, n){
        FOR(j, 0, 25) A[i][j] = 0;
    }
    FOR(i, 0, 25){
        goal[i] = 0;
        cur[i] = 0;
    }
    return;
}
void ql(int x){
    FOR(i, 0, 1){
        X[x] = i;
        bool valid = true;
        if (X[x] == 1)
            FOR(j, 0, 25){
                cur[j] += A[x][j]; 
                if (cur[j] > goal[j]) valid = false;
            }
        if (valid && x<n) ql(x + 1);
        else
        if (x == n){
            bool validAns = true;
            FOR(j, 0, 25) if (cur[j] != goal[j]){
                validAns = false;
                break;
            }
            if (validAns){
                ans = true;
            }
        }
        if (X[x] == 1)
            FOR(j, 0, 25) cur[j] -= A[x][j];
    }
    return;
}
signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen("monster.inp", "r", stdin);
    freopen("monster.out", "w", stdout);
    cin >> test;
    while (test--){
        ans = false;
        cin >> n;
        init(n);
        string s;
        FOR(i, 1 , n){
            cin >> s;
            FOR(j, 0, s.length()-1) A[i][s[j]-'a'] += 1;
        }
        cin >> s;
        FOR(i, 0, s.length()-1) goal[s[i]-'a'] += 1;
        // cout << goal['w'];
        ql(1);
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}