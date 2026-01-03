#include<bits/stdc++.h>
using namespace std;
const long max_mask=(1<<5)+7;
const long max_N=1e5+10;
long long ans,A[6][max_N],F[max_N][max_mask],N,t,k,l;
bool KT(long s){
	for(long t2=3; t2<(1<<5); t2=(t2<<1)){
		if((s & t2)==t2) return false;
	}
	return true;
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("CHONO.inp","r",stdin);
	freopen("CHONO.out","w",stdout);
	cin >> N;
	for(long i=1; i<=5; i++)
		for(long j=1; j<=N; j++)
			cin>>A[i][j];
	for(long i=1; i<=N; i++){
		for(long mask=0; mask<(1<<5); mask++){
			if(!KT(mask)) continue;
			t=1;
			for(long j=1; j<=(1<<4); j=(j<<1)){
					if(mask & j){
					F[i][mask]+=A[t][i];
				}
				t+=1;
			}
		}
	}
	for(long i=2; i<=N; i++)
		for(long masknew=0; masknew<(1<<5); masknew++){
				if(!(KT(masknew))) continue;
				k=F[i][masknew];
				for(long mask=0; mask<(1<<5); mask++){
					if(!(KT(mask))) continue;
					if(!(mask & masknew)){
						F[i][masknew]=max(F[i][masknew],F[i-1][mask]+k);
				}
			}
	}
	for(long j=1; j<(1<<5); j++){
		ans=max(ans,F[N][j]);
	}
	cout<<ans;
	return 0;
}
