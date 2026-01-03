#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("TIMSO.inp","r",stdin);
    freopen("TIMSO.out","w",stdout);
    string xau;cin>>xau;int mang[100005],x=-1,z=-1;char Max=0;
    for(int i=0;i<xau.size();i+=1){
        if(xau[i]>='0'&&xau[i]<='9'){
            if(xau[i]>Max){Max=xau[i];x=i+1;}
           }
    }
    cout<<Max; Max=0;
    for(int i=x;i<xau.size();i+=1){
        if(xau[i]>='0'&&xau[i]<='9'){
            if(xau[i]>Max){Max=xau[i];z=i+1;}
           }
    }
    cout<<Max;Max=0;
    for(int i=z;i<xau.size();i+=1){
        if(xau[i]>='0'&&xau[i]<='9'){
            if(xau[i]>Max){Max=xau[i];}
           }
    }
    cout<<Max;
    return 0;
}
