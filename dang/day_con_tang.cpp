#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

const ll N = 2e5 + 7;
ll n, a[N], f[N];

int main() {
    memset(f, 1000000007, sizeof(f));
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i];
    ll res = 1;
    f[1] = a[1];
    for (int i = 2; i <= n; i++) {
        ll pos = lower_bound(f + 1, f + res + 1, a[i]) - f;
        f[pos] = a[i];
        res = max(res, pos);
    }
    cout << res;
    // for(int i = 1 ;i <= n ; i += 1)cout << f[i] << " ";
    return 0;
}