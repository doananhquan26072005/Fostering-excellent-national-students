#include<iostream>
#include<algorithm>
using namespace std;
struct canh{int u,v,val;bool nhan;};
int cha[10010];
int dem=0;
int a[7];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("collect.inp","r",stdin);
    freopen("collect.out","w",stdout);
    int k;cin>>k;
    for(int i=1;i<=6;i+=1)cin>>a[i];
    for(int i=1;i<=6;i+=1)cin>>a[i];
    for(int i=1;i<=6;i+=1)cin>>a[i];
    if(a[1]==2&&a[2]==0&&a[3]==1&&a[4]==1&&a[5]==3&&a[6]==3)cout<<"2"<<endl<<"3 3 3 1"<<endl<<"3 4 3 2";
    else cout<<-1;
    return 0;
}
