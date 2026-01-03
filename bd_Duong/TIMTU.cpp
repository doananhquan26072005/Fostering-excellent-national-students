#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("TIMTU.inp","r",stdin);
    freopen("TIMTU.out","w",stdout);
    string xau;getline(cin,xau);int Max=0,dem=0,x=0,y=0,z;
    for(int i=0;i<xau.size();i+=1){
        dem+=1;
        if(dem>Max){Max=dem;z=x;y=i;}
        if(xau[i+1]==' '){dem=-1;x=i+2;}
    }
    for(int i=z;i<=y;i+=1)cout<<xau[i];
    return 0;
}
