#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[105][105];

main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
freopen("ROBOT.inp","r",stdin);
freopen("ROBOT.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=m+1;j++)a[i][j]=1e5+7;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>a[i][j];
    for(int i=2;i<=n;i++)a[i][1]+=a[i-1][1];
    for(int i=1;i<=n;i++)
        for(int j=2;j<=m;j++)
            a[i][j]=a[i][j]+ min(a[i][j-1],a[i-1][j]);
    cout<<a[n][m];
return 0;
}
