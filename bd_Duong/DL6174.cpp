#include<bits/stdc++.h>
using namespace std;
long long x,y,z,n,dem=1,a[100005];
string s;
int sxtd(long long n){
    long long sum=0;
    for(int i=1;i<=4;i++){
        a[i]=n%10;
        n/=10;
    }
    sort(a+1,a+5);
    for(int i=1;i<=4;i++){
        sum*=10;
        sum+=a[i];
    }
    return sum;
}
int sxgd(long long k){
    long long tong=0;
    sort(a+1,a+5,greater<int>());
    for(int i=1;i<=4;i++){
        tong*=10;
        tong+=a[i];
    }
    return tong;
}
int main(){
    freopen("DL6174.inp","r",stdin);
    freopen("DL6174.out","w",stdout);
    cin>>n;
    y=sxtd(n);
    x=sxgd(y);
    while(n!=6174){
        n=x-y;
        y=sxtd(n);
        x=sxgd(y);
        dem++;
    }
    cout<<dem;

}
