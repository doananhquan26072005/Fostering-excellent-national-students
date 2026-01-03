#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n;
struct td{int x,y,stt;long double goc;};
td a[100005];

bool cmp(td q,td p){
    return q.goc<p.goc;
}

bool cmpp(td q,td p){
    return q.x<p.x;
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);cout.tie(NULL);
//freopen("POLYLINES.inp","r",stdin);
//freopen("POLYLINES.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i+=1)cin>>a[i].x>>a[i].y;
    for(int i=1;i<=n;i+=1)a[i].stt=i;
    sort(a+1,a+1+n,cmpp);
    /*for(int i=1;i<=n;i+=1){
        a[i].x-=a[1].x;
        a[i].y-=a[1].y;
    }

    for(int i=2;i<=n;i+=1)a[i].goc=double((1.00*a[i].y)/(a[i].x*1.00))*1.00;
    sort(a+2,a+1+n,cmp);
    cout<<1<<" "<<a[n/2+1].stt;*/
return 0;
}
