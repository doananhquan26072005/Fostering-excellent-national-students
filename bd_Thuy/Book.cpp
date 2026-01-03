#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("Book.inp","r",stdin);
    freopen("Book.out","w",stdout);
    int n;cin>>n;int dem=0,xet=n,a[n+1];
    for(int i=1;i<=n;i+=1)cin>>a[i];
    for(int i=n;i>=1;i-=1){
        if(a[i]==xet){dem+=1;xet-=1;}
    }
    cout<<n-dem;
    return 0;
}
