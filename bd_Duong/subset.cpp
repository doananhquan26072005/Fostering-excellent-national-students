#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("subset.inp", "r", stdin);
	freopen("subset.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long k;
	cin >> k;
	int siz1 = n / 2;
	vector<long long> x1;
	for (int bit = 1; bit < (1 << siz1); bit++) {
		long long sum = 0;
		for (int i = 0; i < siz1; i++) {
			if ((bit >> i) & 1) {
				sum += a[i];
			}
		}
		x1.emplace_back(sum);
	}
	int siz2 = n - siz1;
	vector<long long> x2;
	for (int bit = 1; bit < (1 << siz2); bit++) {
		long long sum = 0;
		for (int i = 0; i < siz2; i++) {
			if ((bit >> i) & 1) {
				sum += a[siz1 + i];
			}
		}
		x2.emplace_back(sum);
	}
	sort(x2.begin(), x2.end());
	long long res = (int)x2.size() - (lower_bound(x2.begin(), x2.end(), k) - x2.begin());
	for (int i = 0; i < (int)x1.size(); i++) {
		if (x1[i] >= k) {
			res += 1;
		}
		int pos = lower_bound(x2.begin(), x2.end(), k - x1[i]) - x2.begin();
		res += (int)x2.size() - pos;
	}
	cout << res;
	return 0;
}