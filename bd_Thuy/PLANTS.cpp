#include<bits/stdc++.h>
using namespace std;
int dp[100005]={1};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("PLANTS.inp","r",stdin);
    freopen("PLANTS.out","w",stdout);
    int n,m;cin>>n>>m;double b;
    int a[n+1];int Max=-1;
    for(int i=1;i<=n;i+=1)cin>>a[i]>>b;
    for(int i=1;i<=n;i+=1){
        for(int j=i-1;j>=1;j-=1){
            if(a[i]>=a[j]){dp[i]=max(dp[i],dp[j]+1);}
        }
    }
    for(int i=1;i<=n;i+=1)if(dp[i]>Max)Max=dp[i];
    cout<<n-Max-1;
    return 0;
}
