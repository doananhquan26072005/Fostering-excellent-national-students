#include <iostream>
#include <vector>
using namespace std;


int main () {
	ios::sync_with_stdio (false); cin.tie (0);
	freopen("laodong.inp", "r", stdin);
    freopen("laodong.out", "w", stdout);
	int n, k; cin >> n >> k;

	vector < vector < long long> > C (n + 1, vector < long long> (n + 1));

	for (int i = 0; i <= n; i++) {
		C[i][0] = 1;
		C[i][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}

	cout << C[n][k];
	return 0;
}
