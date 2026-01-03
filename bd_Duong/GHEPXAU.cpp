#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("GHEPXAU.inp","r",stdin);
    freopen("GHEPXAU.out","w",stdout);
    string s1,s2,s3;cin>>s1>>s2;s3=s1;
    int solan=s2.size()/s1.size();
    for(int i=1;i<solan;i+=1)s1+=s3;
    if(s1==s2)cout<<solan ;
    else cout<<0;
    return 0;
}
