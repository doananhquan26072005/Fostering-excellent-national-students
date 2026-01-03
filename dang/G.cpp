#include<bits/stdc++.h>
using namespace std;

const long N=1e5+10;
long n,m,A[N],mid,x,y;
vector<long> D[4*N];
void build(long id,long l,long r){
	if(l==r){
		D[id]=l;
		return;
	}

}
void xuly(long l,long r){

}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(long i=1; i<=n; i++){
		cin>>A[i];
	}
	build(1,1,n);
	cin>>m;
	while(m--){
		cin>>x>>y;
		xuly(x,y);
	}







	return 0;
}