#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("HCN.inp","r",stdin);
    freopen("HCN.out","w",stdout);
int t;cin>>t;
for(int i=1;i<=t;i+=1){
    int a[5];for(int i=1;i<=4;i+=1)cin>>a[i];
    sort(a+1,a+5);
    cout<<a[1]*a[3]<<endl;
}
return 0;
}
