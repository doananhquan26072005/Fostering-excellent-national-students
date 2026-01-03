#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s="*";
char x;


main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
    freopen("kenre.inp","r",stdin);
    freopen("kenre.out","w",stdout);
    cin>>n;
    for(int i=1;i<=2*n;i+=1){cin>>x;s+=x;}
    int dem=0;string s1=s;
    sort(s1.begin(),s1.end());
    while(s!=s1){
        dem+=1;
        if(dem%2==1)for(int i=2;i<=2*n;i+=2)swap(s[i],s[i-1]);
        else
            for(int i=1;i<=n;i+=1)swap(s[i],s[i+n]);
    }
    cout<<dem;
return 0;
}
