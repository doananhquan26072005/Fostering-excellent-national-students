#include<bits/stdc++.h>

using namespace std;
#define int long long
string s;
int a[4];


main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
    freopen("MATHS.INP","r",stdin);
    freopen("MATHS.out","w",stdout);
    memset(a,0,sizeof(a));
    cin>>s;
    for(int i=0;i<s.size();i+=1)if(s[i]!='+')a[s[i]-48]+=1;
    if(a[1]!=0){
        for(int i=1;i<a[1];i+=1)cout<<1<<"+";
        cout<<1;
    }
    if(a[2]!=0){
        cout<<"+";
        for(int i=1;i<a[2];i+=1)cout<<2<<"+";
        cout<<2;
    }
    if(a[3]!=0){
        cout<<"+";
        for(int i=1;i<a[3];i+=1)cout<<3<<"+";
        cout<<3;
    }
return 0;
}
