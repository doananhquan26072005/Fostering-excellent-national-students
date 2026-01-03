#include<bits/stdc++.h>
using namespace std;
string s,s1,x;bool C[30]={false};
int n,dem=0;
void Try (int i)
{
    for(int j=0;j<n;j++)
    {
        if(!C[j])
        {
            x[i]=s[j];
            C[j]=true;
            if(i==n-1){
                dem++;
                if(x==s1) {cout<<dem;break;}
            }
            else Try(i+1);
        C[j]=false;
        }
    }
}
int main(){
    freopen("HOANVI.inp","r",stdin);
    freopen("HOANVI.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    cin>>s;
    s1=s;
    n=s.size();
    x=s;
    sort(s.begin(),s.end());
    Try(0);
}
