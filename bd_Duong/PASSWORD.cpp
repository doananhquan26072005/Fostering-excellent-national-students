#include<bits/stdc++.h>
using namespace std;
string xau;
bool snt(int n){
    if(n<2)return false;
    for(int i=2;i<=sqrt(n);i+=1)
        if(n%i==0)return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("PASSWORD.inp","r",stdin);
    freopen("PASSWORD.out","w",stdout);
    cin>>xau;int x=1,y=1,Max=0;int mang[100005],mang2[100005];
    for(int i=0;i<xau.size();i+=1){
        if(xau[i]>='0'&&xau[i]<='9'){mang[x]=xau[i]-48;x+=1;}
        if(xau[i]<'0'||xau[i]>'9'){mang[x]=0;x+=1;}
    }
    for(int i=1;i<=x;i+=1){
        if(snt(mang[i])==1)if(mang[i]>Max)Max=mang[i];
    }
    for(int i=1;i<x;i+=1){
        mang2[y]=mang[i]*10+mang[i+1];
        y+=1;
    }
    for(int i=1;i<=y;i+=1){
        if(snt(mang2[i])==1)if(mang2[i]>Max)Max=mang2[i];
    }
    cout<<Max;
    return 0;
}
