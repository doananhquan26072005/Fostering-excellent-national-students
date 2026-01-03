#include<bits/stdc++.h>
using namespace std;

string s;
long n,k,sum[357][357];
bool F[350][350][350];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	cin>>s;
	s=' '+s;
	for(long i=1; i<=n; i++){
		if(s[i]=='B') {F[i][i][1]=true; sum[i][i]=1;}
		else {F[i][i][0]=true; sum[i][i]=0;}
	}
	for(long len=1; len<n; len++){
		for(long i=1, j=len+i; j<=n; i++,j++){
			sum[i][j]=sum[i+1][j]+sum[i][j-1]-sum[i+1][j-1];
			for(long z=1; z<=sum[i][j]; z++){
				if(s[i]=='B' && F[i+1][j][sum[i][j]-z+1]) F[i][j][z]=true;
				if(s[i]=='W' && F[i+1][j][sum[i][j]-z]) F[i][j][z]=true;
				if(s[j]=='B' && F[i][j-1][sum[i][j]-z+1]) F[i][j][z]=true;
				if(s[j]=='W' && F[i][j-1][sum[i][j]-z]) F[i][j][z]=true;
			}
		}
	}
	for(long i=0; i<k ;i++){
		if(F[1][n][i]){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";




	return 0;
}