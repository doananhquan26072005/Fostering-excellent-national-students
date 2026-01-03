#include<iostream>
using namespace std;
int main(){
    freopen("bdxau.inp","r",stdin);
    freopen("bdxau.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string a,b;cin>>a>>b;
    int dp[a.size()+5][b.size()+5];
    for(int i=1;i<=a.size();i+=1)dp[i][0]=i;
    for(int j=1;j<=b.size();j+=1)dp[0][j]=j;
    for(int i=1;i<=a.size();i+=1){
        for(int j=1;j<=b.size();j+=1){
            if(a[i]==b[j])dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=min(dp[i][j-1]+1,min(dp[i-1][j]+1,dp[i-1][j-1]+1));
        }
    }
    cout<<dp[a.size()][b.size()];
    return 0;
}
