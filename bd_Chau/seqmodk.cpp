#include<bits/stdc++.h>
using namespace std;
int n,k;
int dp[500005];
int a[500005];
int sum=0;
int ans=-100005;
bool dd[500005];
int vitri[500005],x;


int main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
    freopen("seqmodk.inp","r",stdin);
    freopen("seqmodk.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i+=1)cin>>a[i];
    memset(dd,false,sizeof(dd));
    memset(vitri,0,sizeof(vitri));
    dp[0]=0;vitri[0]=0;dd[0]=true;

    for(int i=1;i<=n;i+=1)dp[i]=((dp[i-1]%k)+(a[i]%k))%k;
    for(int i=1;i<=n;i+=1){
        if(dd[dp[i]]==false){
                dd[dp[i]]=true;
                vitri[dp[i]]=i;
        }
         else if(dd[dp[i]]==true){
                if(i-vitri[dp[i]]>ans){
                        ans=i-vitri[dp[i]];
                        x=vitri[dp[i]]+1;
                        vitri[i]=vitri[dp[i]];
                }
         }
    }
    cout<<ans<<" "<<x;
    return 0;
}
