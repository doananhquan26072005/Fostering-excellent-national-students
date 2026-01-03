#include<bits/stdc++.h>
using namespace std;

#define superpower ios_base::sync_with_stdio(0);cin.tie(NULL)
#define f1n(a,b) for(long long i=a;i<=b;++i)
#define MAXN 1e9+7
//const double PI  =3.141592653589793238463;

long long n,m,ans,col,row,k,kq;

int main(){
    superpower;
    freopen("SQUARE.inp","r",stdin);
    freopen("SQUARE.out","w",stdout);
    cin>>n>>m;
    k=0;
    ans=1;
    kq=1;
    for(int i=2;i<=n;i++){
        kq+=i;
        if(m<=kq && k==0){
            col=i;
            row=1;
            ans=kq;
            k=1;
        }
    }
    for(int i=n-1;i>=1;i--){
        if(k==0){
            kq+=i;
            if(m<=kq){
                row=n-i+1;
                col=n;
                k=2;
                break;
            }
        }
    }
    if(k==1){
        col-=ans-m;
        row+=ans-m;
    }
    if(k==2){
        col-=kq-m;
        row+=kq-m;
    }
    cout<<row<<" "<<col;
    return 0;
}
