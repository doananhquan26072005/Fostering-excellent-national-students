    #include<bits/stdc++.h>
using namespace std;
int n,m,test;
struct canh {int u,v;};
canh a[100010];
int dp[10005][10005];


int main(){
//freopen("thamquan.inp","r",stdin);
//freopen("thamquan.out","w",stdout);
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    cin>>n>>m>>test;
    for(int i=1;i<=m;i+=1){
        for(int j=1;j<=m;j+=1){
            if(i!=j)dp[i][j]=-1;
            else dp[i][j]=0;
        }
    }
    for(int i=1;i<=m;i+=1)  cin>>a[i].u>>a[i].v>>dp[a[i].u][a[i].v];
    for(int i=1;i<=n;i+=1){
        for(int j=1;j<=n;j+=1){
                dp[1][i]=max(dp[1][i],min(dp[1][j],dp[j][i]));
        }
    }
    int z;
    for(int i=1;i<=test;i+=1){
        cin>>z;
        cout<<dp[1][z]<<endl;
    }
return 0;
}
