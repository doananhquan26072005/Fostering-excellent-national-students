#include<bits/stdc++.h>
using namespace std;
int m,n,G[10005][10005],L[100005],u,v,val,sum=0,Min ;
bool C[100005];
#define oo 1e5;
int main(){
    freopen("prim.inp","r",stdin);
    freopen("prim.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    memset(C,false,sizeof(C));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            G[i][j]=oo;
            G[j][i]=oo;
            if(i==j) G[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>u>>v>>val;
        G[u][v]=val;
        G[v][u]=val;
    }
    C[1]=true;
    for(int i=2;i<=n;++i){
        if(G[1][i]==0){
            L[i]= oo;
        }
        else L[i]=G[1][i];
        }

    u=1;L[1]=0;
    for(int i=1;i<=n-1;++i){
        Min=oo;
        for(int v=2;v<=n;v++)
            if(L[v]<Min && !C[v]){
                Min=L[v];u=v;
            }
            sum+=L[u];C[u]=true;
                for(int j=1;j<=n;j++){
                    if(!C[j] && L[j]>G[u][j]){
                        L[j]=G[u][j];
                    }
                }
            }
    cout<<sum;
}
