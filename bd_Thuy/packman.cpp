    #include<bits/stdc++.h>
using namespace std;
string s;int a;
int l,r;
int tam;
int ans;


bool check(int mid){
    int lt=0,rt=0;
    for(int i=0;i<s.size();i+=1){
            if(s[i]=='*'&&lt==0&&i>rt) lt=i;
            else if(s[i]=='P'){
                tam=i-lt;
                if(tam<0) tam=0;
                rt=max(mid-2*tam+i,(mid-tam)/2+i);
                lt=0;
            }

        }
        if(lt!=0)return false;
        return true;
}


int main(){
freopen("packman.inp","r",stdin);
freopen("packman.out","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(NULL);
    cin>>a>>s;int mid;
    l=1;r=2*a;
    while(l<r){
        mid=(r+l)/2;
        if(check(mid)==true){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans;
return 0;
}
