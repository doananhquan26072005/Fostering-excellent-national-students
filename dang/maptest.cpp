    #include<bits/stdc++.h>
using namespace std;
map<double,int>Map;
int n;
double x;


int main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
//freopen(".inp","r",stdin);
//freopen(".out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i+=1){
        cin>>x;
        Map[x]+=1;
    }
    map<double ,int>::iterator it;
    for(it=Map.begin();it!=Map.end();it++)
        cout<<fixed<<setprecision(2)<<it->first<<":"<<it->second<<endl;
    return 0;
}
