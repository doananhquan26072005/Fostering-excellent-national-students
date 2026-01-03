#include <iostream>
#include<algorithm>
using namespace std;
int dao(int n){
    int a[6],kq=0;
    while(n){
        kq*=10;
        kq+=n%10;
        n/=10;
    }
    return kq;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("FRIENUM.inp","r",stdin);
    freopen("FRIENUM.out","w",stdout);
    int a,b;cin>>a>>b;int kq=0;
    for(int i=a;i<=b;i+=1){
        if(__gcd(i,dao(i))==1)kq+=1;
    }
    cout<<kq;
    return 0;
}

