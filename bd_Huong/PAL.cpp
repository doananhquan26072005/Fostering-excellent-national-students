#include<bits/stdc++.h>
using namespace std;

#define dungxkun ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl '\n'

string s;
ll f[255][255];

int main(){
    dungxkun;
    freopen("PAL.inp","r",stdin);
    freopen("PAL.out","w",stdout);
    cin>>s;
    ll n=s.size()-1;
    for(ll i=n;i>=0;i--){
        for(ll j=i;j<=n;j++){
            if(i==j) f[i][j]=1;
            if(i==j-1){
                if(s[i]==s[j])f[i][j]=3;
                else f[i][j]=2;
            }
            else{
                f[i][j]=f[i+1][j]+f[i][j-1]-f[i+1][j-1];
                if(s[i]==s[j]){
                    f[i][j]+=f[i+1][j-1]+1;
                }
            }
        }
    }
    cout<<f[0][n];

    return 0;
}
