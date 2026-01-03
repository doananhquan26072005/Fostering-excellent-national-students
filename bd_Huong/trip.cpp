#include<bits/stdc++.h>
using namespace std;
int n,d,a[100005],C[100005],dem=0,pos1,pos2;
int main(){
    freopen("TRIP.inp","r",stdin);
    freopen("TRIP.out","w",stdout);
    memset(C,true,sizeof(C));
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    pos1=1,pos2=n;
    while(pos1<=pos2){
        if(a[pos2]+a[pos1]<=d){
            pos2--;
            pos1++;
            dem++;
        }
        if(a[pos2]+a[pos1]>d){
            dem++;
            pos2--;
        }
    }
    cout<<dem;
}
