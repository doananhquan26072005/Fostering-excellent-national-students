#pragma GCC optimize("Ofast")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define ii pair < int , int >
#define endl "\n"
#define tp(x) fixed << setprecision(x)

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , n , x) for(int i = n ; i >= x ; --i)

#define fi first
#define se second
#define pb push_back
const long double pi = 3.141592654;
const int oo = 1e9 + 7 ;
const int MOD = 1e9 + 7 ;

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("tomau.inp","r",stdin);
	freopen("tomau.out","w",stdout);
	long long a, b;
	cin >> a >> b;
	long long m1=sqrt(a+1);
	long long n1=sqrt(b+1);
	long long s=a+b;
	long long k=sqrt(s)+1;
	while (k>1)
	{
		while (s%k!=0) k--;
		while (m1>k||a%m1!=0) m1--;
		while (n1>k||b%n1!=0) n1--;
		long long x=s/k;
		long long m2=a/m1;
		long long n2=b/n1;
		if (x>=m2||x>=n2) break;
		k--;
	}
	cout << 2*k+2*(s/k);
	return 0;
}
/*
╔══╗                ▐▀▄       ▄▀▌   ▄▄▄▄▄▄▄
╚╗╔╝                ▌▒▒▀▄▄▄▄▄▀▒▒▐▄▀▀▒██▒██▒▀▀
╔╝(¯’v´¯)          ▐▒▒▒▒▀▒▀▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄
╚══’.¸.Kien An     ▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▒▒▒▒▒▒▒▒▒▒▒▒▀▄
╔♫═╗╔╗ ♥          ▀█▒▒▒█▌▒▒█▒▒▐█▒▒▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌
╚╗╔╝║║♫═╦╦╦╔╗     ▀▌▒▒▒▒▒▒▀▒▀▒▒▒▒▒▒▀▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐   ▄▄
╔╝╚╗♫╚╣║║║║╔╣     ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌▄█▒█
╚═♫╝╚═╩═╩♫╩═╝     ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒█▀
┊　　┊　　┊　　┊   ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▀
┊　　┊　　┊　　┊   ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌
┊　　┊　　┊　　★   ▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐
┊　　┊　　☆        ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌
┊　　★              ▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐
☆                   ▐▄▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▌
                      ▀▄▄▀▀▀▀▀▄▄▀▀▀▀▀▀▀▄▄▀▀▀▀▀▄▄▀
*/