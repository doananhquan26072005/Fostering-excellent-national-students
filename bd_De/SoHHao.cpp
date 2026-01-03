#include <bits/stdc++.h>
#pragma GCC optmize("Ofast")
#define ll long long
using namespace std;
const long lm = 1e7+9;
ll l, r, F[lm];
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("sohhao.inp", "r", stdin);
	freopen("sohhao.out", "w", stdout);
	cin >> l >> r;
	memset(F, 0ll, sizeof(F));
	for (int i=1; i*2<=r; i++){
		for (int j=i*2; j<=r; j+=i) F[j] += i;
	}
	ll ans = 0ll;
	for (int i=l; i<=r; i++){
		ans += abs(i-F[i]);
		// cout << i << " " << abs(i-F[i]) << endl;
	}
	cout << ans << "\n";
	return 0;
}