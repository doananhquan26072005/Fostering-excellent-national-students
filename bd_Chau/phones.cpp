#include <bits/stdc++.h>
using namespace std;
const long lm = 4*1e3+9;
long t[lm], d[lm], dp[lm][lm], n, k, l;
int main(){
    freopen("phones.inp","r",stdin);
    freopen("phones.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    if(n==0){
        cout<<86400;
        return 0;
    }
    for (long i=1; i<=n; i++) cin>>t[i]>>d[i];
    long ans=t[1]-1;
    dp[0][0] = 0;
    for (long i=1; i<=n; i++){
        dp[i][0]=dp[i-1][0]+d[i]; 
    }
    for (long i=1; i<=n; i++){
        for (long j=i; j>=0; j--){
            if(j-1>=0){
                dp[i][j]=min(dp[i-1][j-1],max(t[i]+d[i]-1,dp[i-1][j]+d[i]));
            }
            else dp[i][j]=max(dp[i-1][j] +d[i], t[i]+d[i]-1);
        }
    } 
    for (long i=1; i<=n; i++) ans=max(ans,t[i+1]-dp[i][min(i,k)]-1);
    cout<<max(ans, 86400-dp[n][k]);
    return 0;
}