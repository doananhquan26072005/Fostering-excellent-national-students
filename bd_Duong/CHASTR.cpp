#include<bits/stdc++.h>
using namespace std;
string s;
int ans=0;
int dem=1;


int main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
    freopen("CHASTR.inp","r",stdin);
    freopen("CHASTR.out","w",stdout);
    cin>>s;
    if(s[0]=='1'&&s[1]=='0'){cout<<-1;return 0;}
    if(s[s.size()-2]=='0'&&s[s.size()-1]=='1'){cout<<-1;return 0;}
    for(int i=1;i<s.size();i+=1){
        if(s[i]=='1'){
            if(s[i-1]=='0'){
                if(s[i+1]=='0')ans+=1;
            }
            else if(s[i-1]=='1')dem+=1;
        }
        else if(s[i]=='0'){
            if(dem>=2){
                if(dem%2==0)ans+=(dem/2);
                else ans=ans+(dem/2)+1;
            }
            dem=1;
        }
    }
    cout<<ans;
return 0;
}
