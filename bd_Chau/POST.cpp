    #include<bits/stdc++.h>
using namespace std;
int n,k;
int x[10005];
int y[10005];
int a[25];
int kq=1e9;
int tong=0;
int Min=1e9;
int Min2=1e9;
int sum=0;


void ghinghiem(){

    for(int i=1;i<=n;i+=1)sum+=x[i];
    if(sum<Min){
        Min=sum;
        for(int i=1;i<=n;i+=1)y[i]=x[i];
    }
}


void chiaqua(int i){
    for(int j=0;j<=Min;j++){
        //if(tong+a[i]*j){
            x[i]=j;
            tong+=(a[i]*j);
            if(i==n) {if(tong==k) ghinghiem();}
            else  chiaqua(i+1);
            tong-=(a[i]*j);
        //}
    }
}


int main(){
    //freopen("POST.inp","r",stdin);
    //freopen("POST.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i+=1){
        cin>>a[i];
        Min=min(Min,a[i]);
    }
    Min=k/Min+1;
    chiaqua(1);
    for(int i=1;i<=n;i+=1)cout<<y[i]<<" ";
    return 0;
}
