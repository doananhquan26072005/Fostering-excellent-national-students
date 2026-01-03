#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n;
int a[300005];
int f[300005],g[300005];
priority_queue<int>Max;
priority_queue<int,vector<int>,greater<int>>Min;

main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
freopen("SEQ3N.inp","r",stdin);
freopen("SEQ3N.out","w",stdout);
    cin>>n;
    for(int i=1;i<=3*n;i+=1)cin>>a[i];
    int sum=0;
    for(int i=1;i<=3*n;i+=1){
        Min.push(a[i]);
        sum+=a[i];
        while(Min.size()>n){
            sum-=Min.top();
            Min.pop();
        }
        f[i]=sum;
    }
    sum=0;
    for(int i=3*n;i>=1;i-=1){
        Max.push(a[i]);
        sum+=a[i];
        while(Max.size()>n){
            sum-=Max.top();
            Max.pop();
        }
        g[i]=sum;
    }
    int ans=LLONG_MIN;
    for(int i=n;i<=2*n;i+=1)ans=max(ans,f[i]-g[i+1]);
    cout<<ans;
return 0;
}
