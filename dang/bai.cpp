#include<bits/stdc++.h>
using namespace std;

#define long long long

long A[6],n,x,ans;


int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	while(n--){
		cin>>x;
		A[x%5]++;
	}
	ans=(A[0]*(A[0]-1)*(A[0]-2)/6)+(A[0]*A[1]*A[4])+(A[0]*A[2]*A[3])+(A[3]*(A[3]-1)/2*A[4])+(A[2]*(A[2]-1)/2*A[1])+(A[1]*(A[1]-1)/2*A[3])+(A[4]*(A[4]-1)/2*A[2]);
	cout<<ans;

	return 0;
}