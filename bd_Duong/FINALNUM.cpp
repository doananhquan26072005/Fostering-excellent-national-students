#include<bits/stdc++.h>
using namespace std;
int rutgon(int n){
    int kq=n%10;
    while(n>9){
        n/=10;
        kq+=n%10;
    }
    if(kq>9)return rutgon(kq);
    else return kq;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("FINALNUM.inp","r",stdin);
    freopen("FINALNUM.out","w",stdout);
    string s;cin>>s;
    int kq=(s[0]-48)+(s[1]-48);
    kq=rutgon(kq);
    for(int i=2;i<s.size();i+=1){
        kq+=s[i]-48;
        kq=rutgon(kq);
    }
    cout<<kq;
return 0;
}
