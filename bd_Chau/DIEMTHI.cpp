#include<bits/stdc++.h>
using namespace std;
#define int long long
int s,m,n;
int a[25][25];
int x[25];
int sum=0;

void ghinghiem(){
    cout<<"YES"<<endl;
    for(int i=1;i<=m;i+=1)cout<<x[i]<<" ";
    exit(0);
}

void quaylui(int i){
    for(int j=1;j<=n;j+=1){
        if(sum+a[j][i]<=s&&a[j][i]>=x[i-1]){
            x[i]=a[j][i];
            sum+=a[j][i];
            if(i==m&&sum==s)ghinghiem();
            else quaylui(i+1);
            sum-=a[j][i];
        }
    }
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
freopen("DIEMTHI.inp","r",stdin);
freopen("DIEMTHI.out","w",stdout);
    cin>>s>>m>>n;
    memset(a,0,sizeof(a));
    x[0]=0;
    for(int i=1;i<=n;i+=1)
        for(int j=1;j<=m;j+=1)cin>>a[i][j];
    quaylui(1);
    cout<<"NO";
return 0;
}
