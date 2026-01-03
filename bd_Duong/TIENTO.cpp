#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("TIENTO.inp","r",stdin);
    freopen("TIENTO.out","w",stdout);
    string xau1,xau2;cin>>xau1>>xau2;int dem=0, k=0,Max=0;
    if(xau1==xau2){cout<<xau1;return 0;}
        for(int i=0;i<xau1.size();i+=1){
            if(xau1[i]==xau2[k]){k+=1;dem+=1;if(dem>Max)Max=dem;}
            else if(xau1[i]!=xau2[k]){k=0;dem=0;}
        }
    if(Max==0){cout<<xau1<<xau2;return 0;}
    for(int i=0;i<xau1.size()-Max;i+=1)cout<<xau1[i];
    cout<<xau2;
    return 0;
}
