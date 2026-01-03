
#include <bits/stdc++.h>
using namespace std;

int n,a,k;
vector <int> p;
vector <bool> f(8000000);

int get_mod(int a) {return (a%n+n)%n;}

int get_forward(int x,int p) 
{
	if (x==0) return get_mod(p);
	if (x<=p%(n-1)) x=get_mod(x-1);
	x=get_mod(x-p/(n-1));
	return x;
}

int get_backward(int x,int p) 
{
	if (x==get_mod(p)) return 0;
	x=get_mod(x+p/(n-1));
	if (x<=p%(n-1)) x=get_mod(x+1);
	return x;
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("NEIGHBOR.inp","r",stdin);
	freopen("NEIGHBOR.out","w",stdout);
	for (int i=2;i*i<8000000;i++) 
		if (!f[i]) 
			for (int j=i*i;j<8000000;j+=i) f[j]=1;
	for (int i=2;i<8000000;i++) if (!f[i]) p.emplace_back(i);
	cin >> n >> k >> a;
	a--;
	for (int i=0;i<k;i++) a=get_forward(a,p[i]);
	int l=get_mod(a-1),r=get_mod(a+1);
	for (int i=k-1;i>=0;i--) l=get_backward(l,p[i]);
	for (int i=k-1;i>=0;i--) r=get_backward(r,p[i]);
	cout << r+1 << " " << l+1;
	return 0;
}