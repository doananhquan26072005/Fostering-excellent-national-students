#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("NUMBER1.inp","r",stdin);
    freopen("NUMBER1.out","w",stdout);
    int k,n;cin>>k;
    for(int i=1;i<=k;i+=1){
        cin>>n;
        int dem=1;
        int du=1;
        while(du%n!=0){
            dem+=1;
            du=du*10+1;
            du=du%n;
        }
        cout<<dem<<endl;
    }
    return 0;
}
