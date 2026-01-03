#include <iostream>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("CERTIF.INP ","r",stdin);
    freopen("CERTIF.OUT ","w",stdout);
    int n;cin>>n;int a[n+1];long long kq=0;
    for(int i=0;i<n;i+=1)cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n-1;i+=1){
        if(a[i]!=0)
        kq=kq+(a[i]+1);
    }
    cout<<kq;
    return 0;
}


