#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("mangtot.inp","r",stdin);
    //freopen("mangtot.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;cin>>t;
    while(t>0){
int n;cin>>n;
    int a[n+1];
    int dem=0;
    int d=0,x=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]<=a[i+1]) dem++;
    }
    for(int i=n;i>=1;i--){
        if(a[i]<=a[i-1]) d++;
        else {
            x=i;
            break;
        }
    }

    for(int i=x;i>=1;i--){
        if(a[i]>a[i-1]) d--;
        else {
            x=i;
            break;
        }
    }
    if(d==n || dem==n){cout<<0<<endl;}
    else cout<<n-(n-x)-1<<endl;

t--;
    }
return 0;
}
