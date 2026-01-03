#include<bits/stdc++.h>
using namespace std;
int sochu(int n){
    int kq=1;
    while(n>9){
        kq+=1;n/=10;
    }
    return kq-1;
}
int sothap(int n){
    int kq=1;
    for(int i=1;i<=n;i+=1)kq*=10;
    return kq;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("CONNECT.inp","r",stdin);
    freopen("CONNECT.out","w",stdout);
    int n;cin>>n;string a[n+10];
    for(int i=1;i<=n;i+=1)cin>>a[i];
    for(int i=1;i<=n-1;i+=1)
        for(int j=i+1;j<=n;j+=1){
            if(a[i]+a[j]<a[j]+a[i])swap(a[i],a[j]);
        }
        for(int i=1;i<=n;i+=1)cout<<a[i];
    return 0;
}
