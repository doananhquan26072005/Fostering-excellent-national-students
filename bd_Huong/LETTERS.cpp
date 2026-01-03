#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n;
string s;
int f[3][1000005];

int chuyen(char x){
    if(x=='a')return 1;
    else return 2;
}

int tinh(int x,int y){
    if(x==y)return 0;
    if(x<y)return 1;
    else return -1;
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
freopen("LETTERS.inp","r",stdin);
freopen("LETTERS.out","w",stdout);
    cin>>n>>s;
    s="*"+s;
    memset(f,0,sizeof(f));
    for(int i=2;i<=n;i+=1){
        if(s[i]!='?'&&s[i-1]!='?')f[chuyen(s[i])][i]=tinh(chuyen(s[i-1]),chuyen(s[i]));
    }
    for(int i=2;i<=n;i+=1){
        if(s[i]=='?'){
            if(s[i-1]=='?'){
                f[1][i]=max(f[1][i-1],f[2][i-1]);
                f[1][i]+=tinh(chuyen(s[i-1]),1);
                f[2][i]=max(f[1][i-1],f[2][i-1]);
                f[2][i]+=tinh(chuyen(s[i-1]),2);
            }
            else {
                f[1][i]=f[chuyen(s[i-1])][i-1]+tinh(chuyen(s[i-1]),1);
                f[2][i]=f[chuyen(s[i-1])][i-1]+tinh(chuyen(s[i-1]),2);
            }
        }
        else
            if(s[i-1]=='?')f[chuyen(s[i])][i]=max(f[1][i-1]+tinh(1,chuyen(s[i])),f[2][i-1]+tinh(2,chuyen(s[i])));
            else f[chuyen(s[i])][i]=f[chuyen(s[i-1])][i-1]+tinh(chuyen(s[i-1]),chuyen(s[i]));
    }
    if(s[n]=='?')cout<<max(f[1][n],f[2][n]);
    else cout<<f[chuyen(s[n])][n];
    /*for(int i=1;i<=n;i+=1)cout<<f[1][i]<< " ";
    cout<<endl;
    for(int i=1;i<=n;i+=1)cout<<f[2][i]<< " ";*/
return 0;
}
