#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int t[60005];
int r[60005];
int dp[60005];

main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
freopen("NKTICK.inp","r",stdin);
freopen("NKTICK.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i+=1)cin>>t[i];
    for(int i=1;i<n;i+=1)cin>>r[i];
    dp[0]=0;dp[1]=t[1];
    for(int i=2;i<=n;i+=1)
        dp[i]=min(dp[i-1]+t[i],dp[i-2]+r[i-1]);
    cout<<dp[n];
return 0;
}
