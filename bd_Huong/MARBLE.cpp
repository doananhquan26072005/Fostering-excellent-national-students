#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n,m;
int a[300005];
int ans;

main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);cout.tie(NULL);
freopen("MARBLE.inp","r",stdin);
freopen("MARBLE.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i+=1)cin>>a[i];
    int l=1,r=1e9,mid;
    int song;
    while(l<=r){
        mid=(l+r)/2;
        song=0;
        for(int i=1;i<=m;i+=1){
            song+=(a[i]+mid-1)/mid;
        }
        if(song<=n){r=mid-1;ans=mid;}
        else l=mid+1;
    }
    cout<<ans;
return 0;
}
