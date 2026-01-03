#include<bits/stdc++.h>
using namespace std;
#define int long long int
string s;
int t;
int f[1005];

main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
freopen("BINARYSTR.inp","r",stdin);
freopen("BINARYSTR.out","w",stdout);
cin>>t;
for(int z=1;z<=t;z+=1){
    cin>>s;int dau=0;
    for(int i=0;i<s.size();i+=1)
        if(s[i]=='1'){dau=1;break;}
    if(dau==0)cout<<-1<<endl;
    else{
        s="*"+s;int b=-1;
        memset(f,0,sizeof(f));f[0]=0;
        for(int i=1;i<s.size();i+=1){
            if(s[i]=='1'){
                if(b!=-1){f[i]=f[i-1];b=-1;}
                if(b==-1){
                    if(s[i+1]=='1')f[i]=f[i-1];
                    else{f[i]=f[i-1];b=i;}}
            }
            else{
                if(b==-1)f[i]=f[i-1];
                else f[i]=f[i-1]+1;
                }
        }
        if(s[s.size()-1]=='1')cout<<f[s.size()-1]<<endl;
        else
            for(int i=s.size()-1;i>=1;i-=1)if(s[i]=='1'){cout<<f[i]<<endl;break;}
    }
}
return 0;
}
