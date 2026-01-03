#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("matkhau.inp","r",stdin);
    freopen("matkhau.out","w",stdout);
    int t;cin>>t;
    while(t>0){
int n,m;cin>>n;
int a[10000],f1[10000],f2[10000],b[10000];
int Max1=0,Max2=0;
for(int i=1;i<=n;i++) cin>>a[i];
cin>>m;
for(int i=1;i<=m;i++) cin>>b[i];
f1[1]=a[1];
f1[2]=a[1]+a[2];
for(int i=3;i<=n;i++){
    f1[i]=f1[i-1]+a[i];
}
for(int i=1;i<=n;i++){
   Max1=max(Max1,f1[i]);
}
f2[1]=b[1];
f2[2]=b[1]+b[2];
for(int i=3;i<=m;i++){
    f2[i]=(f2[i-1]+b[i]);
}
for(int i=1;i<=m;i++){
    Max2=max(f2[i],Max2);
}
cout<<Max2+Max1<<endl;
t--;
    }
return 0;
}
