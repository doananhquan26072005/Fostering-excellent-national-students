#include<bits/stdc++.h>
using namespace std;
#define long long long
#define lll pair<long,long>
#define f first
#define s second
const long N=1e5+10;
const long oo=1e18;
long D[N],A[N],n,m,x,y,c;
vector<lll> ds[N];
lll u;
priority_queue< lll,vector<lll>,greater<lll> > pq;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	while(m--){
		cin>>x>>y;
		ds[x].push_back({y,0});
		ds[y].push_back({x,0});
	}
	cin>>m;
	while(m--){
		cin>>c>>x>>y;
		ds[x].push_back({y,c});
		ds[y].push_back({x,c});
	}
	for(long i=2; i<=n; i++) D[i]=oo;
		D[1] = 0;
	pq.push({0,1});
	while(!pq.empty()){
		u=pq.top();
		pq.pop();
		//if(D[u.s]!=u.f) continue;
		for(lll v: ds[u.s]){
			if(v.s==0){
				if(D[v.f]>D[u.s]+1){
					D[v.f]=D[u.s]+1;
					pq.push({D[v.f],v.f});
				}
			}
			else if(v.s>=D[u.s]){
					if(D[v.f]>v.s) {
						D[v.f]=v.s;
						pq.push({D[v.f],v.f});
				}
			}
		}
	}
	if(D[n]==oo) cout<<-1;
	else cout<<D[n];
	return 0;
} 