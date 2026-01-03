#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct toado{int x,y;};
toado a[105];
int ans;

bool cmp(toado q,toado p){
    return q.x<p.x;
}

void check(int i,int j,int k){
    if((a[j].x-a[i].x)*(a[k].y-a[i].y)==(a[k].x-a[i].x)*(a[j].y-a[i].y))
        ans+=1;
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
freopen("BADIEM.inp","r",stdin);
freopen("BADIEM.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i+=1)cin>>a[i].x>>a[i].y;
    sort(a,a+1+n,cmp);
    for(int i=1;i<=n-2;i+=1)
        for(int j=i+1;j<=n-1;j+=1)
            for(int k=j+1;k<=n;k+=1)check(i,j,k);
    cout<<ans;
return 0;
}
