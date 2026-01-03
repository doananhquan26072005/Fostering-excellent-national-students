#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
long long dp[300000][2];
string a,b;
int k;
int main()
{
    freopen("Wordcut.inp","r",stdin);
    freopen("Wordcut.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin>>a>>b;
    scanf("%d",&k);
    if(a==b)dp[0][0]=1;
    else dp[0][1]=1;
    int x = 0;
    for(int i=0;i<a.size();i++)
    {
        int flag = 1;
        for(int j=0;j<a.size();j++)
        {
            if(a[(i+j)%a.size()]!=b[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag)x++;
    }
    for(int i=0;i<k;i++)
    {
        dp[i+1][0]=(x*dp[i][1]+(x-1)*dp[i][0])%mod;
        dp[i+1][1]=((a.size()-x)*dp[i][0]+(a.size()-x-1)*dp[i][1])%mod;
    }
    printf("%d\n",dp[k][0]);
}
