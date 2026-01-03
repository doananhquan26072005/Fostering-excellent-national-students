#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,x;
int a[200005];
int f[200005];
int z=1;

main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
freopen("GROUP.inp","r",stdin);
freopen("GROUP.out","w",stdout);
    cin>>n>>k>>x;
    for(int i=1;i<=n;i+=1)cin>>a[i];
    sort(a,a+1+n);
    int ans=1;
    for(int i=2;i<=n;i+=1)
        if((a[i]-a[i-1])>x){
            ans+=1;
            f[z]=a[i]-a[i-1];
            z+=1;
        }
    sort(f,f+z);
    for(int i=1;i<=z-1;i+=1){
        if(f[i]/x==1&&k>0&&k-(f[i]/x-1)>=0){k=k-f[i]/x;ans-=1;}
        else if(k-(f[i]/x-1)>=0&&k>0){
            k=k-(f[i]/x-1);
            ans-=1;
        }
        else break;
    }
    cout<<ans;
return 0;
}
