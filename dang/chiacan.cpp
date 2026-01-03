#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct query{
	ll l, r, id;
};
const ll maxnum = 1e6+9;
const ll lm = 2*1e5+9;
ll A[lm], block, cnt[maxnum], ans[lm], n, m;
query Q[lm];
bool cmp(query x, query y){
	if (x.l/block == y.l/block) return x.r<y.r;
	return x.l/block < y.l/block;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i=0; i<=maxnum; i++) cnt[i] = 0;
	block = sqrt(n);
	for (int i=1; i<=n; i++) cin >> A[i];
	for (int i=1; i<=m; i++){
		cin >> Q[i].l >> Q[i].r;
		Q[i].id = i;
	}
	sort(Q+1, Q+m+1, cmp);
	ll l = Q[1].l, r = Q[1].r, temp = 0;
	for (int i=Q[1].l; i<=Q[1].r; i++){
		cnt[A[i]] += 1;
		temp = temp - A[i]*pow(cnt[A[i]]-1, 2) + A[i]*pow(cnt[A[i]], 2);
	}
	// cout << temp;
	ans[Q[1].id] = temp;
	for (int i=2; i<=m; i++){
		while (l < Q[i].l){
			temp = temp - A[l]*pow(cnt[A[l]], 2) + A[l]*pow(cnt[A[l]]-1, 2);
			cnt[A[l]] -= 1;
			l += 1;
		}
		while (l>Q[i].l){
			l-=1;
			cnt[A[l]] += 1;
			temp = temp - A[l]*pow(cnt[A[l]]-1, 2) + A[l]*pow(cnt[A[l]], 2);
		}
		while (r < Q[i].r){
			r += 1;
			cnt[A[r]] += 1;
			temp = temp - A[r]*pow(cnt[A[r]]-1, 2) + A[r]*pow(cnt[A[r]], 2);
		}
		while (r > Q[i].r){
			temp = temp - A[r]*pow(cnt[A[r]], 2) + A[r]*pow(cnt[A[r]]-1, 2);
			cnt[A[r]] -= 1;
			r -= 1;
		}
		ans[Q[i].id] = temp;
	}
	for (int i=1; i<=m; i++) cout << ans[i] << "\n";
	return 0;
}
