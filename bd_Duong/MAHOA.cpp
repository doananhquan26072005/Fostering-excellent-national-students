#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen("MAHOA.inp","r",stdin);
    //freopen("MAHOA.out","w",stdout);
    int n;cin>>n;cin.ignore();int x=0;
    getline(cin,s);string newstr=s;
    if(s[0]>='a'&&s[0]<='z')x=1;
    if(s[0]>='A'&&s[0]<='Z') x=2;
    if(x==1){
        for(int i=0;i<newstr.size();i+=1)
                if(newstr[i]>='a'&&newstr[i]<='z'){
                        if(newstr[i]+n>'z')newstr[i]='a'+n-('z'-newstr[i])-1;
                        else newstr[i]+=n;
                }
    }
    if(x==2){
        for(int i=0;i<newstr.size();i+=1)
                if(newstr[i]>='A'&&newstr[i]<='B'){
                        if(newstr[i]+n>'Z')newstr[i]='A'+n-('Z'-newstr[i])-1;
                        else newstr[i]+=n;
                }
    }
    cout<<newstr;
return 0;
}
