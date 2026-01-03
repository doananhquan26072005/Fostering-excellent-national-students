    #include<bits/stdc++.h>
using namespace std;
int n;
int a[25][25];
long long Min=1e9+9;
long long sum=0;
bool dd[25];
int x[25];
int c,d;
void xuat(){
    if(a[x[n]][1]!=0&&sum+a[x[n]][1]<Min)
        Min=sum+a[x[n]][1];
}


void quaylui(int i){
    for(int j=2;j<=n;j+=1){
        if(dd[j]==false&&a[x[i-1]][j]!=0){
            dd[j]=true;
            x[i]=j;
            sum+=a[x[i-1]][j];
            if(i==n)xuat();
            else if(sum<Min)quaylui(i+1);
            dd[j]=false;
            sum-=a[x[i-1]][j];
        }
    }
}


int main(){
freopen("TSP.inp","r",stdin);
freopen("TSP.out","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(NULL);
    memset(dd,false,sizeof(dd));
    x[1]=1;x[n+1]=1;
    cin>>n;
    for(int i=1;i<=n;i+=1){
        for(int j=1;j<=n;j+=1){
            cin>>a[i][j];
        }
    }
    quaylui(2);
    cout<<Min;
return 0;
}
