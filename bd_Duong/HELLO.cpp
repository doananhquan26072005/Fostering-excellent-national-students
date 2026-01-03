#include<bits/stdc++.h>
using namespace std;
string s;
int a=0;
char x='h';


void chuyen(){
    if(x=='h'){x='e';a+=1;}
    if(x=='e'){x='l';a+=1;}
    if(x=='l'){a+=1;}
    if(a==4){x='o';a+=1;}
    return;
}


int main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
    freopen("HELLO.inp","r",stdin);
    freopen("HELLO.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i+=1){
        if(s[i]==x)chuyen();
        if(a==5){cout<<"YES";return 0;}
    }
    cout<<"NO";
return 0;
}
