#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int q1[1000005],q2[100005];
int m,x,l,r,pos;
struct stone{int qs,l,r;};
stone a[100005];

int sum1(int le,int ri){
    long long sum=0;
    for(int i=le;i<=ri;i++)sum+=q1[i];
    return sum;
}

int sum2(int le,int ri){
    long long sum=0;
    for(int i=le;i<=ri;i++)sum+=q2[i];
    return sum;
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
freopen("STONES.inp","r",stdin);
freopen("STONES.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>q1[i];
        q2[i]=q1[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++)cin>>a[i].qs>>a[i].l>>a[i].r;
    sort(q2+1,q2+n+1);
    for(int i=1;i<=m;i++){
        if(a[i].qs==1)cout<<sum1(a[i].l,a[i].r)<<endl;
        if(a[i].qs==2) cout<<sum2(a[i].l,a[i].r)<<endl;
    }
return 0;
}
