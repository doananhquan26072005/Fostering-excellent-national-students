#include<bits/stdc++.h>
using namespace std;
#define int long long int
string n,m,a,b;

void check(){
    string s="";
    if(n.size()>m.size()){
        for(int i=m.size();i<=n.size()-1;i+=1)s+="0";
        m+=s;
    }
    if(n.size()<m.size()){
        for(int i=n.size();i<=m.size()-1;i+=1)s+="0";
        n+=s;
    }
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
freopen("COLLIDE.inp","r",stdin);
freopen("COLLIDE.out","w",stdout);
    cin>>n>>m;
    a="";b="";
    reverse(n.begin(),n.end());
    reverse(m.begin(),m.end());
    check();
    for(int i=0;i<=n.size()-1;i+=1){
        if(n[i]-48>m[i]-48)a+=n[i];
        if(n[i]-48<m[i]-48)b+=m[i];
        if(n[i]-48==m[i]-48){a+=n[i];b+=m[i];}
    }
    int dem=1;
    for(int i=a.size()-1;i>=0;i-=1){
        if(a[i]=='0')dem=0;
        else {dem=1;break;}
    }
    if (dem==0)cout<<0;
    else for(int i=a.size()-1;i>=0;i-=1)cout<<a[i];
    cout<<endl;
     dem=1;
    for(int i=b.size()-1;i>=0;i-=1){
        if(b[i]=='0')dem=0;
        else {dem=1;break;}
    }
    if (dem==0)cout<<0;
    else for(int i=b.size()-1;i>=0;i-=1)cout<<b[i];
return 0;
}
