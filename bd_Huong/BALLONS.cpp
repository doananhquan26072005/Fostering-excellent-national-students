#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n;
int a[1000005];
int dd[1000005];

main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);cout.tie(NULL);
freopen("BALLONS.inp","r",stdin);
freopen("BALLONS.out","w",stdout);
    cin>>n;
    memset(dd,0,sizeof(dd));
    for(int i=1;i<=n;i+=1)cin>>a[i];
    for(int i=1;i<=n;i+=1)dd[a[i]]+=1;
    int ans=0;int dem,vt;
    for(int i=1;i<=n;i+=1){
        if(dd[a[i]]>0){
            ans+=1;
            dem=a[i]-1;
            a[i]=0;dd[a[i]]-=1;
            vt=i;
            while(vt<=n){
                vt+=1;
                if(a[vt]==dem){a[vt]=0;dem-=1;}
            }
        }
    }
    cout<<ans;
return 0;
}
