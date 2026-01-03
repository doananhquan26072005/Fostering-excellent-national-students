#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105][105];


int main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
    freopen("BANG.inp","r",stdin);
    freopen("BANG.out","w",stdout);
    cin>>n>>m;
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i+=1)
        for(int j=1;j<=m;j+=1)cin>>a[i][j];
    for(int j=2;j<=m;j+=1)
        for(int i=1;i<=n;i+=1)
            a[i][j]=a[i][j]+max(max(a[i-1][j-1],a[i+1][j-1]),a[i][j-1]);
    int Max=-100;
    for(int i=1;i<=n;i+=1)Max=max(Max,a[i][m]);
    cout<<Max;
return 0;
}
