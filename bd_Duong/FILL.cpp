#include<bits/stdc++.h>
using namespace std;
string a,b,c;
int x=0;
int an=0;
int quan=0;


int chuyen(string s){
    int ans=0;
    for(int i=0;i<s.size();i+=1)ans=ans*10+(s[i]-48);
    return ans;
}


int dapan(int p,string q){
    int z=0;
    while(p>10){
        if(q[z]=='?')return p%10;
        z+=1;
        p/=10;
    }
    if(q[z]=='?')return p%10;
}


int main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
    freopen("FILL.inp","r",stdin);
    freopen("FILL.out","w",stdout);
    cin>>a>>b>>c;
    for(int i=0;i<a.size();i+=1)if(a[i]=='?'){x=1;break;}
    if(x==0)for(int i=0;i<b.size();i+=1)if(b[i]=='?'){x=2;break;}
    if(x==0)for(int i=0;i<c.size();i+=1)if(c[i]=='?'){x=3;break;}
    if(x==1)an=chuyen(c)-chuyen(b);
    if(x==2)an=chuyen(c)-chuyen(a);
    if(x==3)an=chuyen(a)+chuyen(b);
    while(an>10){
        quan=(quan*10)+(an%10);
        an/=10;
    }
    quan=(quan*10)+(an%10);
    if(x==1)cout<<dapan(quan,a);
    if(x==2)cout<<dapan(quan,b);
    if(x==3)cout<<dapan(quan,c);
return 0;
}
