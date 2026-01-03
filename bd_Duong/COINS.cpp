#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n;
int sang[1000006];

main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);cout.tie(NULL);
freopen("COINS.inp","r",stdin);
freopen("COINS.out","w",stdout);
    cin>>n;
    if(n==1){cout<<1<<endl<<1;;return 0;}
    int m=n;
    memset(sang,0,sizeof(sang));
    int dem=1;
    for(int i=2;i<=max((int)sqrt(n),n/2);i+=1){
        while(m%i==0){
            m/=i;
            sang[i]+=1;
            dem+=1;
        }
        if(m==1)break;
    }
    if(dem==1){cout<<2<<endl<<n<<" "<<1;return 0;}
    cout<<dem<<endl<<n<<" ";
    m=n;
    for(int i=2;i<=max((int)sqrt(n),n/2);i+=1){
        while(sang[i]>0){
            cout<<m/i<<" ";
            sang[i]-=1;
            m/=i;
        }
        if(m==1)break;
    }
return 0;
}
