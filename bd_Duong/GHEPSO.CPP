#include<bits/stdc++.h>
using namespace std;
int n;
string a[100005];

int main() {
    freopen("GHEPSO.inp","r",stdin);
    freopen("GHEPSO.out","w",stdout);
     ios_base::sync_with_stdio(0);cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]+a[j]<a[j]+a[i]){
            string tmp = a[i];
            a[i]=a[j];
            a[j]=tmp;
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<a[i];

    return 0;
}
