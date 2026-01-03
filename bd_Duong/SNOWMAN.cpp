#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
typedef pair<ll,ll>ii;
struct sn{
    ll f,s,t;
}ans[100005];
ll n,x,dem=0,cnt[100005],a[100005],b[5];
priority_queue<ii,vector<ii>>pq;

int main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);cout.tie(NULL);
    memset(cnt,0,sizeof(cnt));
    freopen("snowman.inp","r",stdin);
    freopen("Snowman.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(cnt[x]==0){
            dem++;
            a[dem]=x;
        }
        cnt[x]++;
    }
    for(int i=1;i<=dem;i++){
        pq.push({cnt[a[i]],a[i]});
    }
    ll run=0;
    while(pq.size()>2){
        b[1]=pq.top().s;
        cnt[b[1]]--;
        pq.pop();
        b[2]=pq.top().s;
        cnt[b[2]]--;
        pq.pop();
        b[3]=pq.top().s;
        cnt[b[3]]--;
        pq.pop();
        run++;
        sort(b+1,b+4,greater<ll>());
        ans[run].f=b[1];
        ans[run].s=b[2];
        ans[run].t=b[3];
        if(cnt[b[1]]>0)pq.push({cnt[b[1]],b[1]});
        if(cnt[b[2]]>0)pq.push({cnt[b[2]],b[2]});
        if(cnt[b[3]]>0)pq.push({cnt[b[3]],b[3]});
    }
    cout<<run<<endl;
    for(int i=1;i<=run;i++){
        cout<<ans[i].f<<" "<<ans[i].s<<" "<<ans[i].t<<endl;
    }
    return 0;
}
