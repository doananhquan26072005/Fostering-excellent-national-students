#include<bits/stdc++.h>
using namespace std;

#define superpower ios_base::sync_with_stdio(0);cin.tie(NULL)
#define ll long long
//#define f1n(a,b) for(long long i=a;i<=b;++i)
//#define MAXN 1e9+7
//const double PI  =3.141592653589793238463;

ll n,m,a[100005],f[100005],Max=-1e5;

int main(){
    superpower;
    freopen("XYT.inp","r",stdin);
    freopen("XYT.out","w",stdout);
    memset(f,0,sizeof(f));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=a[i];j--){
            if(f[j-a[i]]==1 && f[j]==0){
                f[j]=1;
            }
            if(f[j]==1 && j>Max)Max=j;
            if(Max==m) {
                cout<<m;
                return 0;
            }
        }
    }
   if(Max>0) cout<<Max;
    else cout<<-1;


    return 0;
}
