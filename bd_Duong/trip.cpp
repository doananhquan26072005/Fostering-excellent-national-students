#include<bits/stdc++.h>

using namespace std;
int n,d;
int a[100005];


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);cout.tie(NULL);
freopen("trip.inp","r",stdin);
freopen("trip.out","w",stdout);
    cin>>n>>d;
    int sum=0;
    for(int i=1;i<=n;i+=1){
        cin>>a[i];
        sum+=a[i];
    }
    int ans=sum/d;
    if(sum%d!=0)ans+=1;
    cout<<ans;
return 0;
}
