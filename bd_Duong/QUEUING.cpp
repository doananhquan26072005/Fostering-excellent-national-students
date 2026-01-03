#include <iostream>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("QUEUING.inp","r",stdin);
    freopen("QUEUING.out","w",stdout);
    string s;cin>>s;char kitu=s[0];int x=0;
    for(int i=0;i<s.size()-1;i+=1){
        if(s[i]>s[i+1]){kitu=s[i];x=1;break;}
    }
    if(x==0){kitu=s[s.size()-1];}
    for(int i=0;i<s.size();i+=1)
        if(s[i]!=kitu)cout<<s[i];
    return 0;
}
