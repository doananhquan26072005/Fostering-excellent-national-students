#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen("HOHANG.inp","r",stdin);
    //freopen("HOHANG.out","w",stdout);
    string s;cin>>s;long long kq=0;
    for(int i=0;i<s.size();i+=1){
        kq+=int(s[0]);
    }
    cout<<kq;
return 0;
}
