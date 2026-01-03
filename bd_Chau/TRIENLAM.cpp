#include<bits/stdc++.h>
using namespace std;
int n;
struct canh{int s,f;};
canh a[10005];
int ans[10005];
int dp[10005];


bool cmp(canh x,canh y){
    return x.s<y.s;
}


int main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
    //freopen("TRIENLAM.inp","r",stdin);
    //freopen("TRIENLAM.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i+=1)cin>>a[i].s>>a[i].f;
    sort(a,a+1+n,cmp);
    dp[1]=0;dp[0]=0;
    for(int i=1;i<=n;i+=1)ans[i]=a[i].f-a[i].s;
    for(int i=1;i<=n;i+=1)dp[i]=ans[i];
    for(int i=2;i<=n;i+=1)
        for(int j=i-1;j>=1;j-=1){
            if(a[i].s>=a[j].f){
                dp[i]=max(dp[i],ans[j]+ans[i]);
            }
        }
    int Max=-100;
    for(int i=1;i<=n;i+=1)Max=max(Max,dp[i]);
    cout<<Max;
    return 0;
}
