#include<bits/stdc++.h>
using namespace std;
int a[36]={0};
int cs2(int n){
    int kq=0;
    while(1){
        kq+=n/2;
        n/=2;
        if(n==1)break;
    }
    return kq;
}
int cs5(int n){
    int kq=0;
    while(1){
        kq+=n/5;
        n/=5;
        if(n<5)break;
    }
    return kq;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen("DIGIT0.inp","r",stdin);
    //freopen("DIGIT0.out","w",stdout);
    string s;cin>>s;
    for(int i=0;i<s.size();i+=1)
        a[s[i]-96]+=1;
    int tu =min(cs2(s.size()),cs5(s.size()));
    int mau=1;
    for(int i=1;i<=26;i+=1){
        if(a[i]!=0)mau*=min(cs2(a[i]),cs5(a[i]));
    }
    cout<<mau;
    return 0;
}
