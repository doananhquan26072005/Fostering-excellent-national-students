#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int maxval = 1000000000;
const int lm = 20;
pair<int, int> A[lm];
int X[lm], n, m, cnt = 0;
int s = 0, b = 0, ans;
void ql(int x){
    for (int i=0; i<=1; i++){
        X[x] = i;
        if (i == 1){
            cnt += 1;
            if (s == 0) s = A[x].fi;
            else s *= A[x].fi;
            b += A[x].se;
        }
        if (x == n && cnt > 0){
            ans = min(ans, abs(s-b));
        }
        else if (x < n) ql(x+1);
        if (X[x] == 1){
            cnt -= 1;
            s /= A[x].fi;
            b -= A[x].se;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen("phohn.inp", "r", stdin);
    freopen("phohn.out", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> A[i].fi >> A[i].se; 
    }
    ans = abs(A[1].fi-A[1].se);
    ql(1);
    cout << ans << "\n";
    return 0;
}