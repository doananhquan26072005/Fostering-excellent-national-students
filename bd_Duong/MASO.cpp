#include<bits/stdc++.h>

using namespace std;
#define int long long
int dd[70005];
int n,k;
int x;


main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
    freopen("MASO.INP","r",stdin);
    freopen("MASO.out","w",stdout);
    memset(dd,0,sizeof(dd));
    cin>>n>>k;
    for(int i=1;i<=n;i+=1){
        cin>>x;
        dd[x]=1;
    }
    for(int i=1;i<=70000;i+=1){
        if(dd[i]==0){
            cout<<i<<endl;;
            k-=1;
        }
        if(k==0)break;
    }
return 0;
}
