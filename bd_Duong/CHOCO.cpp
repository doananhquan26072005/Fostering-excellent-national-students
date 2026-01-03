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
const long lm = 1e5+9;
//-------------------------------------------------
long test, n, k;
char ch[lm];
signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen("choco.inp", "r", stdin);
    freopen("choco.out", "w", stdout);
    cin >> test;
    while (test--){
        long ans = 1;
        cin >> n >> k;
        FOR(i, 1, n) cin >> ch[i];
        long p1 = 1, p2 = 1;
        map<long, long> cnt;
        cnt[(int)ch[1]] += 1;
        while (p2<=n){
            // cout << p1 << " " << p2 << "\n";
            priority_queue<long> pq;
            FOR(j, 'A', 'Z')
                if (cnt[j] != 0) pq.push(cnt[j]);
            FOR(j, 'a', 'z')
                if (cnt[j] != 0) pq.push(cnt[j]);
            bool ck = true;
            pq.pop();
            long changes = k;
            while (!pq.empty()){
                if (changes < pq.top()){
                    ck = false;
                    break;
                }
                changes -= pq.top();
                pq.pop();
            }
            if (ck){
                ans = max(ans, p2-p1+1);
                p2 += 1;
                cnt[(int)ch[p2]] += 1;
            }
            else{
                cnt[(int)ch[p1]] -= 1;
                p1 += 1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}