#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
int n;
struct td{double x,y;};
td a[100005];

bool cmp(td q,td p){
    return q.x<p.x;
}

double kc(int i,int j){
    double z1=a[i].x-a[j].x;
    double z2=a[i].y-a[j].y;
    return sqrt(z1*z1+z2*z2);
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
freopen("NEAREST.inp","r",stdin);
freopen("NEAREST.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i+=1)cin>>a[i].x>>a[i].y;
    sort(a,a+1+n,cmp);
    double Min=100005;
    for(int i=2;i<=n;i+=1){
        if(kc(i,i-1)<Min)Min=kc(i,i-1);
    }
    cout<<fixed<<setprecision(3)<<Min;
return 0;
}
