#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen("DV007.inp","r",stdin);
    //freopen("DV007.out","w",stdout);
    int n,r;cin>>n>>r;
    for(int i=1;i<=n;i+=1)cin>>a[i];
    int kq=0;
    for(int i=n;i>=1;i-=1){
        for(int j=i-1;j>=1;j-=1)
            if(a[i]-a[j]>r){kq+=j;break;}
    }
    cout<<kq;
    return 0;
}
