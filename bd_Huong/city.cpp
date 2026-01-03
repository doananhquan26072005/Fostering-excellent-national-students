#include<iostream>
#include<algorithm>
using namespace std;
struct canh{int u,v,val,stt;bool nhan;};
int cha[10010];
int dem=0;


bool qmp(canh x,canh y){
    return x.stt<y.stt;
}
bool cmp(canh x,canh y){
    return x.val<y.val;
}
int tim(int u){
    if(u!=cha[u])u=tim(cha[u]);
    return cha[u];
}
bool ghep(int u,int v){
    u=tim(u);
    v=tim(v);
    if(u==v)return false;
    else cha[u]=v;
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen("city.inp","r",stdin);
    //freopen("city.out","w",stdout);
    int n,m;cin>>n>>m;canh a[m+10];
    for(int i=1;i<=n;i+=1)a[i].nhan=false;
    for(int i=1;i<=m;i+=1)cin>>a[i].u>>a[i].v>>a[i].val;
    for(int i=1;i<=n;i+=1)cha[i]=i;
    for(int i=1;i<=n;i+=1)a[i].stt=i;
    sort(a+1,a+m+1,cmp);
    int kq=0;
    for(int i=1;i<=m;i+=1){
        if(ghep(a[i].u,a[i].v)==true){
            kq+=a[i].val;
            dem+=1;
            a[i].nhan=true;
        }
    }
    cout<<dem<<" "<<kq<<endl;
    sort(a+1,a+m+1,qmp);
    for(int i=1;i<+n;i+=1)
        if(a[i].nhan=true)cout<<a[i].u<<" "<<a[i].v<<endl;
    return 0;
}
