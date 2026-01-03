#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[100005];
int l=1,r=0;

bool kt(int x){
int dem=0;
for(int i=1;i<=n;i+=1)dem+=a[i]/x;
return dem>=k;
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
freopen("WIRES.inp","r",stdin);
freopen("WIRES.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i+=1){
        cin>>a[i];
        r=max(r, a[i]);
    }
    while(l<=r){
        int mid=(l+r)/2;
        if(kt(mid)) l=mid+1;
        else r=mid-1;
    }
    if(l<=r)cout<<l-1;
    else cout<<0;
return 0;
}
