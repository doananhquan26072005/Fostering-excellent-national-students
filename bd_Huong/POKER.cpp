#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
bool a[6][15];
int dem[5];

void dd(char c,int x){
    int y;
    if(c=='P')y=1;
    if(c=='K')y=2;
    if(c=='H')y=3;
    if(c=='T')y=4;
    if(a[y][x]==true){cout<<-1;exit(0);}
    else {a[y][x]=true;dem[y]-=1;}
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
freopen("POKER.inp","r",stdin);
freopen("POKER.out","w",stdout);
    memset(a,false,sizeof(a));
    for(int i=1;i<=4;i+=1)dem[i]=13;
    cin>>s;
    for(int i=0;i<s.size();i+=3)
        dd(s[i],(s[i+1]-48)*10+(s[i+2]-48));
    for(int i=1;i<=4;i+=1)cout<<dem[i]<<" ";
return 0;
}
