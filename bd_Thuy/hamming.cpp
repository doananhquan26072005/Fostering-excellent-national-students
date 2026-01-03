#include <bits/stdc++.h>
using namespace std;

int n,m,k,ans;
string a,b;

int hamming(int x)
{
	int res=0;
	for (int i=0;i<m&&res<ans;i++,x++)
		if (a[x%n]!=b[i]) res++;
	return res;
}

int main() 
{
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("hamming.inp","r",stdin);
	// freopen("hamming.out","w",stdout);
	cin >> n >> m >> k;
	cin >> a;
	ans=m;
	while (k--)
	{
		cin >> b;
		for (int i=0;i<n;i++) ans=min(ans,hamming(i));
	}
	cout << ans;
	return 0;
}