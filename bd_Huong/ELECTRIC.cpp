#include<bits/stdc++.h>
using namespace std;
int n,m;
int sum=0,k=0;
int dad[10005];
int dd[10005];
struct ck{
    int u,v,val,stt;
};
ck a[100005];
int findc(int u){
    if(u!=dad[u])u=findc(dad[u]);
    return dad[u];
}
int comp(ck a , ck b){
    return a.val>b.val;
}
int ghep(int u,int v){
    u=findc(u);
    v=findc(v);
    if(u==v)return false;
    dad[u]=v;
    return true;
}
int main(){
    freopen("ELECTRIC.inp","r",stdin);
    freopen("ELECTRIC.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    memset(dd,false,sizeof(dd));
    cin>>n>>m;
    for(int i=1;i<=m;i++){cin>>a[i].u>>a[i].v>>a[i].val;a[i].stt=i;}
    for(int i=1;i<=n;i++)dad[i]=i;
    sort(a+1,a+m+1,comp);
    for(int i=1;i<=m;i++){
        if(ghep(a[i].u,a[i].v)==true){
            sum+=a[i].val;
            k++;
            dd[k]=a[i].stt;
    }
    }
    cout<<sum<<endl;
    sort(dd+1,dd+k+1);
    for(int i=1;i<=k;i++){
        cout<<dd[i]<<endl;
    }
}
